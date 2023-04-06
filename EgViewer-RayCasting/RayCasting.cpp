
#include "EgViewer.h"
#include "gmath.h"

// 볼륨 데이터 변수
int Width;
int Height;
int Depth;
unsigned char *pVolData;
GVec3 *pNormal;
float *pColor;
float *pOpacity;

// 불투명도 함수 제어 변수
unsigned char d0 = 40, d1 = 100;
float alpha = 0.9;

// 이미지 평면 변수
#define H 600
#define W 600
unsigned char Image[H * W];

// 테스트 1
 //unsigned char d0 = 70, d1 = 120;
 //float alpha = 0.7;

// 테스트 2 (뼈)
//unsigned char d0 = 120, d1 = 190;
//float alpha = 0.9;

// 장면 조작을 위한 변수들
int ManipulateMode = 0; // 1: 회전, 2: 이동
int StartPt[2];
float Axis[3] = { 1.0, 0.0, 0.0 };
float Angle = 0.0;
float RotMat[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
float Zoom = 0.0;
float Pan[3] = { 0.0, 0.0, 0.0 };

// 콜백 함수 선언
void Reshape(int w, int h);
void Render();
void MouseWheel(int button, int dir, int x, int y);
void Mouse(int glut_button, int state, int x, int y);
void Motion(int x, int y);
void PassiveMotion(int x, int y);

// 사용자 정의 함수 선언
void LoadVolData();
void ComputeNormal();
void AssignOpacity();
void ComputeColor(GVec3 L, GVec3 V);
void CreateImage();
bool IntersectRayBox(GLine &Ray, GPos3 minPt, GPos3 maxPt, double &t);
int GetPixelIdx(int j, int k);
int GetVoxelIdx(int i, int j, int k);
void RenderFps();
void GetSphereCoord(int x, int y, float *px, float *py, float *pz);
void GetViewTransform(GPos3 &orig, GVec3 &x_axis, GVec3 &y_axis, GVec3 &z_axis);

int main(int argc, char **argv)
{
	// 메모리 누수 감지 옵션을 설정한다.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// GLUT 초기화 및 디스플레이 모드 설정한다.
	glutInit(&argc, argv);
	glutInitWindowSize(W, H);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

	// OpenGL 윈도우 생성한다.
	glutCreateWindow("CT Viewer");

	// ImGui를 초기화 한다.
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsDark();
	ImGui_ImplGLUT_Init();
	ImGui_ImplOpenGL2_Init();
	ImGui::GetIO().Fonts->AddFontFromFileTTF("./usr/fonts/Roboto-Medium.ttf", 15.0f);

	// 콜백 함수를 등록한다.
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Render);
	glutMouseWheelFunc(MouseWheel);
	glutMouseFunc(Mouse);
	glutMotionFunc(Motion);
	glutPassiveMotionFunc(PassiveMotion);

	LoadVolData();		// 볼륨 데이터 로딩
	ComputeNormal();	// 법선벡터 계산
	AssignOpacity();	// 불투명도 할당
	CreateImage();		// 이미지를 생성

	// 메시지 루프에 진입한다.
	glutMainLoop();

	// ImGui 메뉴를 정리한다.
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplGLUT_Shutdown();
	ImGui::DestroyContext();

	// 메모리 해제
	delete[] pVolData;
	delete[] pNormal;
	delete[] pColor;
	delete[] pOpacity;
	return 0;
}

void LoadVolData()
{
	// 볼륨 헤더(*.txt) 파일을 읽는다.
	FILE *fp;
	fopen_s(&fp, "./data/bighead.txt", "r");
	fscanf_s(fp, "%d%d%d", &Width, &Height, &Depth);
	fclose(fp);

	// 렌더링에 필요한 배열을 할당한다.
	pVolData = new unsigned char[Depth * Height * Width];  // 배열[Depth][Height][Width]
	pNormal = new GVec3[Depth * Height * Width];
	pColor = new float[Depth * Height * Width];
	pOpacity = new float[Depth * Height * Width];

	// 볼륨 데이터를 바이너리 형태로 읽는다.
	fopen_s(&fp, "./data/bighead.den", "rb");
	fread(pVolData, sizeof(unsigned char), Depth * Height * Width, fp);
	fclose(fp);
}

void ComputeNormal()
{
	for (int i = 1; i < Depth - 1; ++i)
	{
		for (int j = 1; j < Height - 1; ++j)
		{
			for (int k = 1; k < Width - 1; ++k)
			{
				int vidx = GetVoxelIdx(i, j, k);
				double dx = (pVolData[GetVoxelIdx(i, j, k + 1)] - pVolData[GetVoxelIdx(i, j, k - 1)]) / 2.0;
				double dy = (pVolData[GetVoxelIdx(i, j - 1, k)] - pVolData[GetVoxelIdx(i, j + 1, k)]) / 2.0;
				double dz = (pVolData[GetVoxelIdx(i - 1, j, k)] - pVolData[GetVoxelIdx(i + 1, j, k)]) / 2.0;
				pNormal[vidx].Set(-dx, -dy, -dz);
				pNormal[vidx].Normalize();
			}
		}
	}
}

void AssignOpacity()
{
	for (int i = 0; i < Depth * Height * Width; ++i)
	{
		unsigned char d = pVolData[i];
		if (d > d0 && d < d1)
		{
			double t = (double)(d1 - d) / (double)(d1 - d0);
			if (t <= 0.2)
				pOpacity[i] = alpha * t / 0.2;
			if (t > 0.2 && t < 0.8)
				pOpacity[i] = alpha;
			if (t >= 0.8)
				pOpacity[i] = alpha * (5.0 - 5.0 * t);
		}
		else
			pOpacity[i] = 0.0;
	}
}

void ComputeColor(GVec3 L, GVec3 V)
{
	GVec3 HalfH = (V + L).Normalize();
	double ns = 16.0;
	float diff_color = 0.6;
	float spec_color = 0.8;
	for (int i = 0; i < Depth * Height * Width; ++i)
	{
		GVec3 N = pNormal[i];
		pColor[i] = diff_color * MAX(N * L, 0.0) +spec_color * pow(MAX(N * HalfH, 0.0), ns);
	}
}
void CreateImage()
{
	// 이미지 평면의 원점과 축 계산
	GPos3 orig;
	GVec3 x_axis, y_axis, z_axis;
	GetViewTransform(orig, x_axis, y_axis, z_axis);

	// 볼륨 데이터 색상 계산
	ComputeColor(z_axis, z_axis);

	// 이미지 평면에서 광선 생성 및 색상 누적
	double h = (H + Zoom);
	double w = (W + Zoom);
	for (int i = 0; i < H; ++i)
	{
		double y = h * (0.5 - (double)i / (H - 1)); // 0.5h ~ -0.5h
		for (int j = 0; j < W; ++j)
		{
			double x = w * (-0.5 + (double)j / (W - 1));	// -0.5w ~ 0.5w		
			// 광선 생성
			GPos3 p = orig + x * x_axis + y * y_axis;
			GLine ray(p, -z_axis);
			double t = 0.0;
			float alpha_out = 0.0;
			float color_out = 0.0;
			// 광선이 볼륨 경계와 교차하는지 조사
			if (IntersectRayBox(ray, GPos3(-130.0, -130.0, -120.0), GPos3(130.0, 130.0, 120.0), t))
			{
				// 구현
				while (true)
				{
					GPos3 pos = ray.Eval(t);
					// 구현
					t += 1.0;
				}
			}
			int idx = GetPixelIdx(i, j);
			color_out = MIN(color_out, 1.0);
			Image[idx] = (unsigned char)(color_out * 255);
		}
	}
}

bool IntersectRayBox(GLine &Ray, GPos3 minPt, GPos3 maxPt, double &t)
{
	GPos3 orig = Ray.p;
	GVec3 invDir(1.0 / Ray.v[0], 1.0 / Ray.v[1], 1.0 / Ray.v[2]);
	int sign[3];
	sign[0] = (invDir[0] < 0.0) ? 1 : 0;
	sign[1] = (invDir[1] < 0.0) ? 1 : 0;
	sign[2] = (invDir[2] < 0.0) ? 1 : 0;

	GPos3 bounds[2];
	bounds[0] = minPt;
	bounds[1] = maxPt;

	double tmin = (bounds[sign[0]][0] - orig[0]) * invDir[0];
	double tmax = (bounds[1 - sign[0]][0] - orig[0]) * invDir[0];
	double tymin = (bounds[sign[1]][1] - orig[1]) * invDir[1];
	double tymax = (bounds[1 - sign[1]][1] - orig[1]) * invDir[1];

	if ((tmin > tymax) || (tymin > tmax))
	{
		t = DBL_MAX;
		return false;
	}

	if (tymin > tmin)
		tmin = tymin;
	if (tymax < tmax)
		tmax = tymax;

	double tzmin = (bounds[sign[2]][2] - orig[2]) * invDir[2];
	double tzmax = (bounds[1 - sign[2]][2] - orig[2]) * invDir[2];

	if ((tmin > tzmax) || (tzmin > tmax))
	{
		t = DBL_MAX;
		return false;
	}

	if (tzmin > tmin)
		tmin = tzmin;
	if (tzmax < tmax)
		tmax = tzmax;

	t = tmin;
	if (t < 0)
	{
		t = tmax;
		if (t < 0)
		{
			t = DBL_MAX;
			return false;
		}
	}
	return true;
}


void Reshape(int w, int h)
{
	// ImGui의 Reshape 이벤트 정보를 설정한다.
	ImGuiIO &io = ImGui::GetIO();
	io.DisplaySize = ImVec2((float)w, (float)h);

	// 장면의 뷰포트를 설정한다.
	glViewport(0, 0, w, h);
}

void Render()
{
	// ImGui 프레임을 생성한다.
	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplGLUT_NewFrame();

	// 메인 메뉴를 생성한다.
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
			{
				ImGui_ImplOpenGL2_Shutdown();
				ImGui_ImplGLUT_Shutdown();
				ImGui::DestroyContext();
				exit(-1);
			}
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}

	// ImGui 데모 윈도우를 생성한다.
	//static bool show_demo_window = true;
	//ImGui::ShowDemoWindow(&show_demo_window);

	// 칼라 버퍼를 지우고,
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// 칼라 버퍼에 Image 데이터를 직접 그린다.
	glDrawPixels(W, H, GL_LUMINANCE, GL_UNSIGNED_BYTE, Image);
	RenderFps();

	// ImGui를 렌더링 한다.
	ImGui::Render();
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

	// 칼라 버퍼를 교환한다.
	glutSwapBuffers();
	glutPostRedisplay();
}

void GetViewTransform(GPos3 &orig, GVec3 &x_axis, GVec3 &y_axis, GVec3 &z_axis)
{
	// 관측 변환 수행
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -300.0);
	glRotatef(Angle, Axis[0], Axis[1], Axis[2]);
	glMultMatrixf(RotMat);
	glGetFloatv(GL_MODELVIEW_MATRIX, RotMat);
	RotMat[12] = RotMat[13] = RotMat[14] = 0.0;
	glTranslatef(Pan[0], Pan[1], Pan[2]);
	float MV[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, MV);
	orig.Set(-(MV[0] * MV[12] + MV[1] * MV[13] + MV[2] * MV[14]), 
			-(MV[4] * MV[12] + MV[5] * MV[13] + MV[6] * MV[14]), 
		-(MV[8] * MV[12] + MV[9] * MV[13] + MV[10] * MV[14]));
	x_axis.Set(MV[0], MV[4], MV[8]);
	y_axis.Set(MV[1], MV[5], MV[9]);
	z_axis.Set(MV[2], MV[6], MV[10]);
	x_axis.Normalize();
	y_axis.Normalize();
	z_axis.Normalize();
}

void Mouse(int glut_button, int state, int x, int y)
{
	// ImGui 마우스 이벤트 정보(위치, 버튼 정보, 상태)를 설정한다.
	ImGuiIO &io = ImGui::GetIO();
	io.MousePos = ImVec2((float)x, (float)y);
	int button = -1;
	if (glut_button == GLUT_LEFT_BUTTON) button = 0;
	if (glut_button == GLUT_RIGHT_BUTTON) button = 1;
	if (glut_button == GLUT_MIDDLE_BUTTON) button = 2;
	if (button != -1 && state == GLUT_DOWN)
		io.MouseDown[button] = true;
	if (button != -1 && state == GLUT_UP)
		io.MouseDown[button] = false;

	// ImGui 윈도우가 선택되었다면 리턴한다.
	if (ImGui::IsWindowHovered(ImGuiHoveredFlags_AnyWindow))
		return;

	// 마우스 버튼을 누른 경우,
	if (state == GLUT_DOWN)
	{
		StartPt[0] = x;
		StartPt[1] = y;
		if (glut_button == GLUT_LEFT_BUTTON)
			ManipulateMode = 1;	// 회전

		if (glut_button == GLUT_RIGHT_BUTTON)
			ManipulateMode = 2;	// 이동
	}

	// 마우스 버튼을 뗀 경우,
	if (state == GLUT_UP)
	{
		ManipulateMode = 0;	// 리셋
		StartPt[0] = StartPt[1] = 0;
		Angle = 0.0;
	}
}

void Motion(int x, int y)
{
	// ImGui 마우스 이벤트 정보를 설정한다.
	ImGuiIO &io = ImGui::GetIO();
	io.MousePos = ImVec2((float)x, (float)y);

	// ImGui 윈도우가 선택되었다면 리턴한다.
	if (ImGui::IsWindowHovered(ImGuiHoveredFlags_AnyWindow))
		return;

	// 회전축과 회전 각도 계산
	if (ManipulateMode == 1)
	{
		// 단위 구 위의 좌표 계산
		float px, py, pz, qx, qy, qz;
		GetSphereCoord(StartPt[0], StartPt[1], &px, &py, &pz);
		GetSphereCoord(x, y, &qx, &qy, &qz);

		// 회전 축과 각도 계산
		Axis[0] = py * qz - pz * qy;
		Axis[1] = pz * qx - px * qz;
		Axis[2] = px * qy - py * qx;
		Angle = 0.0;
		float len = Axis[0] * Axis[0] + Axis[1] * Axis[1] + Axis[2] * Axis[2];
		if (len > 0.000001) // 일정 변위 이상만 처리
			Angle = acos(px * qx + py * qy + pz * qz) * 180.0f / 3.141592f;
	}

	// 이동 변위 계산
	if (ManipulateMode == 2)
	{
		float dx = (float)(x - StartPt[0]) * 0.01f;
		float dy = (float)(StartPt[1] - y) * 0.01f;
		// 회전 행렬 및 역행렬
		// R = 0 4 8   invR = 0 1 2
		//     1 5 9          4 5 6    
		//     2 6 10         8 9 10
		// invR * (dx, dy, 0)
		Pan[0] += RotMat[0] * dx + RotMat[1] * dy;
		Pan[1] += RotMat[4] * dx + RotMat[5] * dy;
		Pan[2] += RotMat[8] * dx + RotMat[9] * dy;
	}

	StartPt[0] = x;	// Update startpt as current position
	StartPt[1] = y;
	CreateImage();

	// 화면을 갱신한다.
	glutPostRedisplay();
}

void MouseWheel(int button, int dir, int x, int y)
{
	// ImGui 마우스 이벤트 정보를 설정한다.
	ImGuiIO &io = ImGui::GetIO();
	io.MousePos = ImVec2((float)x, (float)y);
	if (dir > 0)
		io.MouseWheel += 1.0;
	else if (dir < 0)
		io.MouseWheel -= 1.0;

	if (dir > 0)
		Zoom += 30.0;
	else
		Zoom -= 30.0;

	CreateImage();
	glutPostRedisplay();
}

void PassiveMotion(int x, int y)
{
	// ImGui 마우스 이벤트 정보를 설정한다.
	ImGuiIO &io = ImGui::GetIO();
	io.MousePos = ImVec2((float)x, (float)y);

	// ImGui 윈도우가 선택되었다면 리턴한다.
	if (ImGui::IsWindowHovered(ImGuiHoveredFlags_AnyWindow))
		return;

	// 화면을 갱신한다.
	glutPostRedisplay();
}

int GetPixelIdx(int i, int j)
{
	return ((H - 1 - i) * W + j);
}

int GetVoxelIdx(int i, int j, int k)
{
	// 1D 인덱스 변환: V[i][j][k] -> v[i * (H * W) + j * W + k]
	static int HW = Height * Width;
	return i * (HW) + j * Width + k;
}

void RenderFps()
{
	// 출력할 윈도우의 위치와 투명도를 설정한다.
	const float DISTANCE = 10.0f;
	static int corner = 3;
	ImGuiIO &io = ImGui::GetIO();
	if (corner != -1)
	{
		ImVec2 window_pos = ImVec2((corner & 1) ? io.DisplaySize.x - DISTANCE : DISTANCE, (corner & 2) ? io.DisplaySize.y - DISTANCE : DISTANCE);
		ImVec2 window_pos_pivot = ImVec2((corner & 1) ? 1.0f : 0.0f, (corner & 2) ? 1.0f : 0.0f);
		ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always, window_pos_pivot);
	}
	ImGui::SetNextWindowBgAlpha(0.35f);

	// 윈도우를 생성하고 메시지를 출력한다.
	bool open = true;
	bool *p_open = &open;
	if (ImGui::Begin("Example: Simple overlay", p_open, (corner != -1 ? ImGuiWindowFlags_NoMove : 0) | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav))
	{
		float fps = ImGui::GetIO().Framerate;
		ImGui::Text("Speed %.3f ms/frame (%.1f FPS)", 1000.0f / fps, fps);
		//ImGui::Text("Simple overlay\n" "in the corner of the screen.\n" "(right-click to change position)");
		//ImGui::Text("Slice Index: %d", SliceIdx);
		//ImGui::Separator();
		if (ImGui::IsMousePosValid())
			ImGui::Text("Mouse Position: (%.1f,%.1f)", io.MousePos.x, io.MousePos.y);
		else
			ImGui::Text("Mouse Position: <invalid>");
		if (ImGui::BeginPopupContextWindow())
		{
			if (ImGui::MenuItem("Custom", NULL, corner == -1)) corner = -1;
			if (ImGui::MenuItem("Top-left", NULL, corner == 0)) corner = 0;
			if (ImGui::MenuItem("Top-right", NULL, corner == 1)) corner = 1;
			if (ImGui::MenuItem("Bottom-left", NULL, corner == 2)) corner = 2;
			if (ImGui::MenuItem("Bottom-right", NULL, corner == 3)) corner = 3;
			if (p_open && ImGui::MenuItem("Close")) *p_open = false;
			ImGui::EndPopup();
		}
		ImGui::End();
	}
}

void GetSphereCoord(int x, int y, float *px, float *py, float *pz)
{
	*px = (2.0f * x - W) / W;
	*py = (-2.0f * y + H) / H;

	float r = (*px) * (*px) + (*py) * (*py); // 원점으로부터의 거리 계산
	if (r >= 1.0f)
	{
		*px = *px / sqrt(r);
		*py = *py / sqrt(r);
		*pz = 0.0f;
	}
	else
		*pz = sqrt(1.0f - r);  // 일반적인 경우
}