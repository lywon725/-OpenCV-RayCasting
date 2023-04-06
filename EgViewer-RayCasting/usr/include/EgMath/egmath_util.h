#pragma once

// Ŭ���� ����
class EgPos;
class EgVec;
class EgVec2;
class EgVec3;
class EgVec4;
class EgMat;
class EgQuat;
class EgTrans;
class EgLine;
class EgPlane;

/*!
*	\brief	���� v�� ���� w�� �翵��Ų ���͸� ���Ѵ�.
*
*	\param	v[in]	�翵 ����
*	\param	w[in]	���� ����
*
*	\return ���� v�� ���� w�� �翵��Ų ���͸� ��ȯ�Ѵ�.
*/
EgVec2 proj(const EgVec2 &v, const EgVec2 &w);

/*!
*	\brief	���� v�� 90�� ȸ���� ���� ���͸� ���Ѵ�.
*	\note	������ ������: 2020-07-05
*
*	\param	v[in]	ȸ���� ����
*	\param	CCW[in]	ȸ�� ����(�ݽð� ����: true, �ð� ����: false)
*
*	\return ���� v�� 90�� ȸ���� ���� ���͸� ��ȯ�Ѵ�.
*/
EgVec2 ortho(const EgVec2 &v, bool CCW);

/*!
*	\brief	�� ������ ���� ������ ���̸� ���Ѵ�.
*
*	\param	v[in]	ù ��° ����
*	\param	w[in]	�� ���� ����
*
*	\return ���� ���� (v - w)�� ���̸� ��ȯ�Ѵ�.
*/
double dist(const EgVec2 &v, const EgVec2 &w);

/*!
*	\brief	������ ũ�⸦ ���Ѵ�.
*
*	\param	v[in]	��� ����
*
*	\return ���� v�� ũ�⸦ ��ȯ�Ѵ�.
*/
double norm(const EgVec2 &v);

/*!
*	\brief	������ ũ�� ������ ���Ѵ�.
*
*	\param	v[in]	��� ����
*
*	\return ���� v�� ũ�� ������ ��ȯ�Ѵ�.
*/
double norm_sq(const EgVec2 &v);

/*!
*	\brief	�� ������ ���̰�(0 ~ 180)�� ���Ѵ�.
*
*	\param	v[in]		���� ����
*	\param	w[in]		�� ����
*	\param	radian[in]	������ ����(true: radian, false: degree)
*
*	\return ���� \a v���� ���� \a w������ ���̰��� ��ȯ�Ѵ�.
*/
double angle(const EgVec2 &v, const EgVec2 &w, bool radian = false);

/*!
*	\brief	���� v�� ���� w�� �翵��Ų ���͸� ���Ѵ�.
*
*	\param	v[in]	�翵 ����
*	\param	w[in]	���� ����
*
*	\return ���� v�� ���� w�� �翵��Ų ���͸� ��ȯ�Ѵ�.
*/
EgVec3 proj(const EgVec3 &v, const EgVec3 &w);

/*!
*	\brief	���� v�� ������ ���� ���͸� ���Ѵ�.
*
*	\param	v[in]	��� ����
*
*	\return ���� v�� ������ ���� ���͸� ���Ͽ� ��ȯ�Ѵ�.
*/
EgVec3 ortho(const EgVec3 &v);

/*!
*	\brief	���� v�� w�� ���̺����� ���̸� ���Ѵ�.
*
*	\param	v[in]	����
*	\param	w[in]	����
*
*	\return	���� \a v, \a w�� ���̺����� ���̸� ��ȯ�Ѵ�.
*/
double dist(const EgVec3 &v, const EgVec3 &w);

/*!
*	\brief	���� u, v, w�� ��Ľ��� ����Ѵ�.
*
*	\param	u[in]	����
*	\param	v[in]	����
*	\param	w[in]	����
*
*	\return ���� u, v, w�� ��Ľ��� ���� ��ȯ�Ѵ�.
*/
double det(const EgVec3 &u, const EgVec3 &v, const EgVec3 &w);

/*!
*	\brief	���� v�� ũ�⸦ ���Ѵ�.
*
*	\param	v[in]	��� ����
*
*	\return ���� \a v�� ũ�⸦ ��ȯ�Ѵ�.
*/
double norm(const EgVec3 &v);

/*!
*	\brief	���� v�� ũ���� ������ ����Ѵ�.
*
*	\param	v[in]	��� ����
*
*	\return ���� \a v�� ũ���� ������ ��ȯ�Ѵ�.
*/
double norm_sq(const EgVec3 &v);

/*!
*	\brief	�� ���� ������ ���̰�(0 ~ 180)�� ���Ѵ�.
*
*	\param	v[in]		���� ����
*	\param	w[in]		�� ����
*	\param	radian[in]	������ ����(true: radian, false: degree)
*
*	\return ���� \a v���� ���� \a w������ ���̰�(����, ���� �������)
*/
double angle(const EgVec3 &v, const EgVec3 &w, bool radian = false);

/*!
*	\brief	�� ���� ������ ���̰�(0 ~ 360)�� ���Ѵ�.
*
*	\param	v[in]		���� ����
*	\param	w[in]		�� ����
*	\param	up[in]		ȸ���� ����
*	\param	radian[in]	������ ����(true: radian, false: degree)
*
*	\return ���� \a v���� ���� \a w������ ���̰�(���� ���͸� ���� �ݽð� ����)
*/
double angle(const EgVec3 &v, const EgVec3 &w, const EgVec3 &up, bool radian = false);

/*!
*	\brief	�� ���Ͱ� �������� �����Ѵ�.
*	\note	������ ������: 2021-05-08
*
*	\param	v[in]		ù ��° ����
*	\param	w[in]		�� ��° ����
*	\param	eps[in]		������ ��� ����
*
*	\return �� ���Ͱ� ����(���� ���� �Ǵ� �ݴ� ����)�̸� true, �ƴϸ� false�� ��ȯ�Ѵ�.
*/
bool is_parallel(EgVec3 v, EgVec3 w, double eps = 1.0e-14);

/*!
*	\brief	�� ���Ͱ� �������� �����Ѵ�.
*	\note	������ ������: 2021-05-08(���� ��Ȯ)
*
*	\param	v[in]		ù ��° ����
*	\param	w[in]		�� ��° ����
*	\param	eps[in]		������ ��� ����
*
*	\return �� ���Ͱ� �����̸� true, �ƴϸ� false�� ��ȯ�Ѵ�.
*/
bool is_ortho(EgVec3 v, EgVec3 w, double eps = 1.0e-14);

/*!
*	\brief	�� ���Ͱ� �� ��� ���� ���� �ִ��� �����Ѵ�.
*
*	\param	u[in]		ù ��° ����
*	\param	v[in]		�� ��° ����
*	\param	w[in]		�� ��° ����
*	\param	eps[in]		������ ��� ����
*
*	\return �� ���Ͱ� �� ��� ���� ���� �ִٸ� true, �ƴϸ� false�� ��ȯ�Ѵ�.
*/
bool is_coplanar(EgVec3 u, EgVec3 v, EgVec3 w, double eps = 1.0e-9);

/*!
*	\brief	���� v�� ũ�⸦ ���Ѵ�.
*
*	\param	v[in]	����
*
*	\return ���� \a v�� ũ�⸦ ��ȯ�Ѵ�.
*/
double norm(const EgVec4 &v);

/*!
*	\brief	���� v�� ũ�� ������ ���Ѵ�.
*
*	\param	v[in]	����
*
*	\return ���� \a v�� ũ�� ������ ��ȯ�Ѵ�.
*/
double norm_sq(const EgVec4 &v);

/*!
*	\brief	�� ������ ���̺����� ũ�⸦ ���Ѵ�.
*
*	\param	v[in]	����
*	\param	w[in]	����
*
*	\return �� ������ ���̺����� ũ�⸦ ��ȯ�Ѵ�.
*/
double dist(const EgVec4 &v, const EgVec4 &w);

/*!
*	\brief	����ġ�� �����Ͽ� ���� ��ǥ�� ��ȯ�Ѵ�: v=(x, y, z, w) -> v'=(wx, wy, wz, w)
*
*	\param	v[in]	��� ����
*
*	\return ���� ��ǥ v'=(wx, wy, wz, w)�� ��ȯ�Ѵ�.
*/
EgVec4 homogenize(const EgVec4 &v);

/*!
*	\brief	v=(wx, wy, wz, w) -> v'=(x, y, z, 1)
*
*	\param	v[in]	4���� ������ ����
*
*	\return v'=(x, y, z, 1)�� ��ȯ�Ѵ�.
*/
EgVec4 cartesianize(const EgVec4 &v);

/*!
*	\brief	���� ��ǥ v=(wx, wy, wz, w) -> v'=(x, y, z, w)�� ��ȯ�Ѵ�.
*
*	\param	v[in]	4���� ������ ����
*
*	\return ��ȯ�� ���� v'=(x, y, z, w)�� ��ȯ�Ѵ�.
*/
EgVec4 rationalize(const EgVec4 &v);

/*!
*	\brief	������ ũ�⸦ ���Ѵ�.
*
*	\param	v[in]	��� ����
*
*	\return ���� ũ�⸦ ��ȯ�Ѵ�.
*/
double norm(const EgVec &v);

/*!
*	\brief	������ ũ���� ������ ���Ѵ�.
*
*	\param	v[in]	��� ����
*
*	\return ���� ũ���� ������ ��ȯ�Ѵ�.
*/
double norm_sq(const EgVec &v);

/*!
*	\brief	�� ������ ���̺����� ũ�⸦ ���Ѵ�.
*
*	\param	v[in]	ù ��° ����
*	\param	w[in]	�� ��° ����
*
*	\return �� ������ ���̺����� ũ�⸦ ��ȯ�Ѵ�.
*/
double dist(const EgVec &v, const EgVec &w);

/*!
*	\brief	����Ʈ�� \a p�� ���̸� ���Ѵ�.
*
*	\param	p[in]	����Ʈ
*
*	\return ����Ʈ \a p�� ���̸� ��ȯ�Ѵ�.
*/
double norm(const EgPos &p);

/*!
*	\brief	����Ʈ�� \a p�� ���� ������ ���Ѵ�.
*
*	\param	p[in]	����Ʈ
*
*	\return ����Ʈ \a p�� ���� ������ ��ȯ�Ѵ�.
*/
double norm_sq(const EgPos &p);

/*!
*	\brief	���� ������ ���̸� ���Ѵ�.
*
*	\param	Pts[in]	���� ������ �����ϴ� ������ ����
*
*	\return ���� ������ ���̸� ��ȯ�Ѵ�.
*/
double dist(std::vector<EgPos> &Pts);

/*!
*	\brief	�� \a p���� �� \a q������ �Ÿ��� ���Ѵ�.
*
*	\param	p[in]	ù ��° ��
*	\param	q[in]	�� ��° ��
*
*	\return �� \a p���� �� \a q������ �Ÿ��� ��ȯ�Ѵ�.
*/
double dist(const EgPos &p, const EgPos &q);

/*!
*	\brief	�� \a p���� �� \a q������ �Ÿ� ������ ���Ѵ�.
*
*	\param	p[in]	ù ��° ��
*	\param	q[in]	�� ��° ��
*
*	\return �� \a p���� �� \a q������ �Ÿ� ������ ��ȯ�Ѵ�.
*/
double dist_sq(const EgPos &p, const EgPos &q);

/*!
*	\brief	�� p�� q�� t : (1 - t)�� �����Ѵ�.
*
*	\param	p[in]	3���� ������ ��
*	\param	q[in]	3���� ������ ��
*
*	\return �� p�� q�� �������� ��ȯ�Ѵ�.
*/
EgPos lerp(const EgPos &p, const EgPos &q, double t);

/*!
*	\brief	������ affine combination�� ���Ѵ�
*
*	\param	Pts[in]		���� �迭�� ���� ������
*	\param	Wgts[in]	combination�� �����
*
*	\return ������ affine combination�� ����� ��ȯ�Ѵ�.
*/
EgPos affine_sum(std::vector<EgPos> &Pts, std::vector<double> &Wgts);

/*!
*	\brief	�ﰢ���� �а��ﰢ������ �˻��Ѵ�.
*	\note	����: ����ȣ(2019-02-03), Ȯ��: ������(2019-03-03)
*
*	\param	p[in]	�ﰢ���� ù ��° ����(�ݽð� ����)
*	\param	q[in]	�ﰢ���� �� ��° ����(�ݽð� ����)
*	\param	r[in]	�ﰢ���� �� ��° ����(�ݽð� ����)
*
*	\return ��(rpq)�� �а��� ��� 1, ��(pqr)�� �а��� ��� 2, ��(qrp)�� �а��ΰ�� 3, �а��� �ƴѰ�� 0�� ��ȯ�Ѵ�.
*/
int is_obtuse_tri(const EgPos &p, const EgPos &q, const EgPos &r); // ����ȣ 2019 02 03 �߰�

/*!
*	\brief	�ﰢ���� �ܽ�(circumcenter)�� ���Ѵ�.
*	\note	����: ����ȣ(2019-02-03), Ȯ��: ������(2019-03-03)
*
*	\param	p[in]	�ﰢ���� ù ��° ����(�ݽð� ����)
*	\param	q[in]	�ﰢ���� �� ��° ����(�ݽð� ����)
*	\param	r[in]	�ﰢ���� �� ��° ����(�ݽð� ����)
*
*	\return �ﰢ���� �ܽ��� ��ġ�� ��ȯ�Ѵ�.
*/
EgPos circumcenter(const EgPos &p, const EgPos &q, const EgPos &r); // ����ȣ 2019 02 03 �߰�

/*!
*	\brief	�ﰢ���� ���̸� ���Ѵ�
*
*	\param	p[in]	�ﰢ���� ù ��° ����(�ݽð� ����)
*	\param	q[in]	�ﰢ���� �� ��° ����(�ݽð� ����)
*	\param	r[in]	�ﰢ���� �� ��° ����(�ݽð� ����)
*
*	\return �ﰢ���� ���̸� ���Ͽ� ��ȯ�Ѵ�.
*/
double area_tri(const EgPos &p, const EgPos &q, const EgPos &r); // ����ȣ 2019 02 03 �߰�

/*!
*	\brief	���� p, q, r�� ���ǵǴ� �ﰢ���� �������� pt�� barycentric ��ǥ�� ����Ѵ�.
*	\note	����: pt�� (p, q, r)�� ���ǵǴ� ��� ���� �����Ѵٰ� ����
*	\note	������ ������: 2021-04-29
*
*	\param	pt[in]	������ ���� ��ǥ
*	\param	p[in]	�ﰢ���� ù ��° ����(�ݽð� ����)
*	\param	q[in]	�ﰢ���� �� ��° ����(�ݽð� ����)
*	\param	r[in]	�ﰢ���� �� ��° ����(�ݽð� ����)
*
*	\return pt�� barycentric ��ǥ (alpha, beta, gamma)�� ��ȯ�Ѵ� (pt = alpha * p + beta * q + gamma * r = r + alpha(p - r) + beta(q - r)).
*/
EgVec3 get_barycentric_coords(EgPos pt, EgPos p, EgPos q, EgPos r);

/*!
*	\brief	�� p�� ��ǥ�� �־��� �ڸ�������(�ݿø��Ͽ�) ��Ÿ��
*
*	\param	p[in]		3���� ������ ��
*	\param	place[in]	�ݿø��� �ڸ���
*
*	\return �ݿø��� ���� ǥ���� ��ȯ�Ѵ�.
*/
EgPos round_off(const EgPos &p, int place);

/*!
*	\brief	��ġ����� ��ȯ�Ѵ�.
*
*	\param	m[in]	���
*
*	\return ��� \a m�� ��ġ����� ��ȯ�Ѵ�.
*/
EgMat tr(const EgMat &m);

/*!
*	\brief	����� row-echelon ���� ��ȯ�Ѵ�.
*
*	\param	m[in]	���
*
*	\return row-echelon ���� ��ȯ�Ѵ�.
*/
EgMat ref(const EgMat &m);

/*!
*	\brief	����� reduced row-echelon ���� ��ȯ�Ѵ�.
*
*	\param	m[in]	���
*
*	\return reduced row-echelon ���� ��ȯ�Ѵ�.
*/
EgMat rref(const EgMat &m);

/*!
*	\brief	��� \a m�� Null ������ ������ �� ���ͷ� ���� ����� ��ȯ�Ѵ�.
*
*	\param	m[in]	���
*
*	\return ��� \a m�� Null ������ ������ �� ���ͷ� ���� ����� ��ȯ�Ѵ�.
*/
EgMat basis_null(const EgMat &m);

/*!
*	\brief	����� rank (������ ������ Ȥ�� �຤���� ��)�� ���
*
*	\param	m[in]	���
*
*	\return ������ ����� rank�� ��ȯ�Ѵ�.
*/
int rank(const EgMat &m);

/*!
*	\brief	����� nullity �� ���
*
*	\param	m[in]	���
*
*	\return ������ nullity�� ��ȯ�Ѵ�.
*/
int nullity(const EgMat &m);

/*!
*	\brief	LU ���ظ� ����, ��� A�� ��Ľ��� ���Ѵ�.
*
*	\param	A[in]	n x n ��� ���
*
*	\return ��Ľ��� ���� ��ȯ�Ѵ�.
*/
double det(const EgMat &A);

/*!
*	\brief	LU ���ظ� ����, ��� A�� ������� ���Ѵ�.
*
*	\param	A[in]	n x n ������.
*
*	\return ��� A�� ������� ��ȯ�Ѵ�.
*/
EgMat inv(const EgMat &A);

/*!
*	\brief	��� A�� �κ������ ��ȯ�Ѵ�.
*
*	\param	A[in]	���
*	\param	r0[in]	���� ���� �ε���
*	\param	c0[in]	���� ���� �ε���
*	\param	r1[in]	�� ���� �ε���
*	\param	c1[in]	�� ���� �ε���
*
*	\return ��� A�� �κ������ ��ȯ�Ѵ�.
*/
EgMat sub(const EgMat &A, int r0, int c0, int r1, int c1);

/*!
*	\brief	��� A�� L(�ϻﰢ���)�� U(��ﰢ���)�� ������ ����
*
*	\param	A[in]	��� �������
*	\param	L[out]	�ϻﰢ����� �����
*	\param	U[out]	��ﰢ����� �����
*
*	\return ����: true, ����: false
*/
int dcmp_lu(const EgMat &A, EgMat &L, EgMat &U);

/*!
*	\brief	��� A�� L(�ϻﰢ���)�� U(��ﰢ���)�� ��ȯ(�κ��Ǻ���(�౳ȯ)�� ����)
*			���� ��, lin_sys_lu(A, x, b, Idx)�� ȣ���Ͽ� ���� �ý��� Ax = b �� �����ϴ� ���� x�� ����
*
*	\param	A[in\out]	n by n ������� LU ���·� ��ȯ�ȴ�.
*	\param	Idx[out]	�� ��ȯ ������ ����ȴ�.
*	\param	d[out]		�� ��ȯ���� ¦���̸� 1, Ȧ���̸� -1 �� ����ȴ�.
*
*	\return �����ϸ� true, �����ϸ� false�� ��ȯ�Ѵ�.
*/
int dcmp_lu(EgMat &A, EgVec &Idx, double &d);

/*!
*	\brief	��� A�� Householder ����� ����Ͽ� Q * R�� ����
*
*	\param	A[in]	m x n ������
*	\param	Q[out]	m x m �������
*	\param	R[out]	m x n ��ﰢ���
*
*	\return �����ϸ� -1, �����ϸ� householder ����� ������ ȸ���� ��ȯ�Ѵ�.
*/
int dcmp_qr(const EgMat &A, EgMat &Q, EgMat &R);

/*!
*	\brief	SVD�� �̿��Ͽ� ��� A�� A = U * W * tr(V)�� ����
*
*	\param	A[in]	m x n ��� (m >= n)
*	\param	U[out]	m x n ��ķμ� �����ʹ� A�� �������� ���������� ����ȴ�.
*	\param	S[out]	Ư�̰��� ����� n ��������. W�� S�� ���ҷ� �����Ǵ� �밢�� ���
*	\param	V[out]	n x n ��ķμ� �����ʹ� A�� ����� �� �ΰ����� ���������� ����ȴ�.
*/
void dcmp_sv(const EgMat &A, EgMat &U, EgVec &S, EgMat &V);

/*!
*	\brief	���� ������ Ax = b�� �ظ� ���Ѵ�.
*
*	\param	A[in]		LU�� ���ص� ���(dcmp_lu(A, Idx, d)�� ���)
*	\param	x[out]		�ذ� ����� ����
*	\param	b[in]		��� ����
*	\param	Idx[in]		���� ��ȯ������ ������ ����(dcmp_lu(A, Idx, d)�� ���)
*/
void lin_sys_lu(const EgMat &A, EgVec &x, const EgVec &b, const EgVec &Idx);

/*!
*	\brief	���������� Ax = b �� �����ϴ� minimum length least square �ظ� ����
*
*	\param	A[in]	m x n ��� (m >= n)
*	\param	x[out]	�ذ� ����ȴ�.
*	\param	b[in]	�������
*
*	\return ���Ǽ�(condition number)�� ��ȯ�Ѵ�.
*/
double lin_sys_sv(const EgMat &A, EgVec &x, const EgVec &b);

/*!
*	\brief	���������� Ax = b �� �����ϴ� minimum length least square �� x�� ���Ѵ�.\n
*			- �� �Լ��� ȣ���ϱ� ����, dcmp_sv(A, U, S, V)�� ȣ���Ͽ� ��� A�� ���ص� ����� ����Ѵ�.
*			- �ѹ� ���ص� ��� A�� ������� b�� �ٲٸ鼭 �ظ� ���ϰ� �ȴ�.
*
*	\param	U[in]	m x n ��ķ� dcmp_sv(A, U, S, V)�� ���
*	\param	S[in]	n ���� ���ͷ� dcmp_sv(A, U, S, V)�� ���
*	\param	V[in]	n x n ��ķ� dcmp_sv(A, U, S, V)�� ���
*	\param	x[out]	�ذ� ����� n ���� ����
*	\param	b[in]	m ���� �������
*
*	\return ���Ǽ�(condition number)�� ��ȯ�Ѵ�.
*/
double lin_sys_sv(const EgMat &U, const EgVec &S, const EgMat &V, EgVec &x, const EgVec &b);

/*!
*	\brief	Conjugate gradient ����� ����Ͽ� ���������� Ax = b �� Ǭ��.\n
*			- ��� A�� ��Ī����̾�� �Ѵ�.
*			- sparse �����ý����� Ǯ������ ȿ������ ����̴�.
*
*	\param	A[in]		n x n ��Ī���.
*	\param	x[in/out]	n ���� �ʱ� �� ����.
*	\param	b[in]		n ���� ��� ����.
*	\param	iter[in]	�ݺ�ȸ��, ���� �ݺ�ȸ���� n�̸� ��Ȯ�� �ظ� ���Ѵ�.
*
*	\return ���� �ݺ�ȸ���� ��ȯ�Ѵ�.
*/
int lin_sys_cg(const EgMat &A, EgVec &x, const EgVec &b, int iter);

/*!
*	\brief	QR ���ع��� �̿��Ͽ� ���������� Ax = b�� least square �ظ� ã�´�.
*
*	\param	A[in]	m x n ���.
*	\param	x[out]	n ���� �� ����.
*	\param	b[in]	n ���� ��� ����.
*
*	\return 1: ����, 0: ����.
*/
int lin_sys_qr(const EgMat &A, EgVec &x, const EgVec &b);

/*!
*	\brief	��纯ȯ(similarity transformation)�� ����Ͽ� �Ǽ���Ī����� ��� eigenvector�� eigenvalue�� ���Ѵ�.
*
*	\param	A[in]	n x n ��Ī���.
*	\param	D[out]	n���� eigenvalue�� ����ȴ�.
*	\param	V[out]	n���� eigenvector (������)�� ����ȴ�.
*
*	\return ��纯ȯ�� ȸ���� ��ȯ�Ѵ�.
*/
int eigen_sys(const EgMat &A, EgVec &D, EgMat &V);

/*!
*	\brief	dcmp_sv �� ����Ͽ� �ּ��� (principle component)�� ã�´�.
*	\note	�Լ�ȣ�� ��, Data ������ ����� ������ ��ġ�ϵ��� �̵��ȴ�.
*
*	\param	Data[in]		m x n ������ ��� (m: �������� ����, n: �������� ����)
*	\param	PC[out]			�����ͷ� ǥ���� �ּ���.
*	\param	SigVal[out]		�ּ��к����� Ư�̰��� ������ n ���� ����.
*	\param	Mean[out]		��պ���
*/
void pca(EgMat &Data, EgMat &PC, EgVec &SigVal, EgVec &Mean);

/*!
*	\brief	���ʹϿ��� ũ�⸦ ���Ѵ�.
*
*	\param	q[in] ��� ���ʹϿ�
*
*	\return ���ʹϿ��� ũ�⸦ ��ȯ�Ѵ�.
*/
double norm(const EgQuat &q);

/*!
*	\brief	���ʹϿ��� ������ ���ϴ� �Լ�.
*
*	\param	q[in] ��� ���ʹϿ�
*
*	\return ���ʹϿ��� ������ ��ȯ�Ѵ�.
*/
EgQuat inv(const EgQuat &q);

/*!
*	\brief	����(pure imaginary ���ʹϿ�)�� exponential mapping�� ���Ѵ�.
*
*	\param	v[in]	���ʹϿ� q = (0, v)
*
*	\return ����ȸ���� v/||v|| �� �߽����� 2 * ||v|| �� ȸ������ ���� ���ʹϿ��� ��ȯ�Ѵ�.
*/
EgQuat exp(const EgVec3 &v);

/*!
*	\brief	���ʹϿ� q�� �αװ��� ���Ѵ�.
*
*	\param	q[in]	��� ���ʹϿ�
*
*	\return ����� ���ʹϿ��� ����κ� Log(q) = (0, x, y, z)�� ��ȯ�Ѵ�.
*/
EgVec3 log(const EgQuat &q);

/*!
*	\brief  �� ���ʹϿ��� �����Ѵ�.
*
*	\param	q1[in]	���ʹϿ�
*	\param	q2[in]	���ʹϿ�
*
*	\return �������� ��ȯ�Ѵ�.
*/
double quat_dot(const EgQuat &q1, const EgQuat &q2);

/*!
*	\brief	���ʹϿ� q1, q2�� Spherical linear interpolation �Ѵ�.
*
*	\param	q1[in]	���ʹϿ�
*	\param	q2[in]	���ʹϿ�
*	\param	t[in]	������ �ð�
*
*	\return ������ ���ʹϿ��� ��ȯ�Ѵ�.
*/
EgQuat slerp(EgQuat q1, EgQuat q2, double t);

/*!
*	\brief	�� ������ ���������� �Ÿ��� ���Ѵ�.
*
*	\param	l[in]	����
*	\param	q[in]	�� ��
*
*	\return �� \a q���� ���� \a l������ �����Ÿ�
*/
double dist(const EgLine &l, const EgPos &q);

/*!
*	\brief	�� ���� l1(t)�� l2(t)������ �ִ� �Ÿ��� ���Ѵ�.
*
*	\param	l1[in]	ù ��° ����
*	\param	l2[in]	�� ��° ����
*	\param	t1[in]	�ִ� �Ÿ��� ����� l1�� �ĸ����� ���� �����
*	\param	t2[in]	�ִ� �Ÿ��� ����� l2�� �ĸ����� ���� �����
*
*	\return �� ���� ������ �ִܰŸ��� ����Ͽ� ��ȯ�Ѵ� (�� ������ ������ ��� -1.0�� ��ȯ�Ѵ�).
*/
double dist(EgLine &l0, EgLine &l1, double &t1, double &t2);

/*!
*	\brief	�� ������ ���� ��ġ�� �ִ��� �����Ѵ�.
*
*	\param	l0[in]	ù ��° ����
*	\param	l1[in]	�� ��° ����
*
*	\return �� ������ ���� ��ġ�� �ִٸ� true, �ƴϸ� false�� ��ȯ�Ѵ�.
*/
bool is_skew(EgLine &l0, EgLine &l1);

/*!
*	\brief	��� pi���� �� p������ ��ȣ�ִ� �Ÿ��� ����Ѵ�.
*
*	\param	pi[in]	����� ��ü
*	\param	p[in]	��� ���� ����.
*
*	\return ��� \a pi���� �� \a p������ ��ȣ�ִ� �Ÿ�
*/
double dist(EgPlane &pi, EgPos &p);

/*!
*	\brief	�� p�� ��� pi�� �翵��Ų ���� ���Ѵ�.
*
*	\param	p[in]	��� ���� ��
*	\param	pi[in]	���
*
*	\return	�� p�� ��� pi�� �翵��Ų ���� ��ȯ�Ѵ�.
*/
EgPos proj(EgPos &p, EgPlane &pi);

/*!
*	\brief	��ü��ȯ�� ����ȯ�� ���Ѵ�.
*
*	\param	X[in]	��� ��ü
*
*	\return X�� ����ȯ�� ��ȯ�Ѵ�.
*/
EgTrans inv(const EgTrans &X);

/*!
*	\brief	��ü��ȯ�� �̵������� ���Ѵ�.
*
*	\param	X[in]	��ü��ȯ ��ü
*
*	\return X�� �̵������� ��ȯ�Ѵ�.
*/
EgVec3 part_trans(const EgTrans &X);

/*!
*	\brief	��ü��ȯ�� ȸ�������� ���Ѵ�.
*
*	\param	X[in]	��ü��ȯ ��ü
*
*	\return X�� ȸ�������� ��ȯ�Ѵ�.
*/
EgQuat part_rot(const EgTrans &X);

/*!
*	\brief	��ȯ X�� ũ�⸦ ���Ѵ�.
*
*	\param	X[in]	��ü��ȯ
*
*	\return ��ȯ X�� ũ�⸦ ��ȯ�Ѵ�.
*/
double norm(const EgTrans &X);

/*!
*	\brief	�� ��ȯ ������ �Ÿ��� ���Ѵ�
*
*	\param	X1[in]		ù ��° ��ȯ
*	\param	X2[in]		�� ��° ��ȯ
*
*	\return X1���� X2��ȯ������ �Ÿ��� ��ȯ�Ѵ�.
*/
double dist(const EgTrans &X1, const EgTrans &X2);

/*!
*	\brief	X ��ǥ�迡�� ǥ���� ��ȯ dX�� Y ��ǥ�迡�� ǥ���� ��ȯ���� ����Ѵ�.
*
*	\param	X[in]		������ǥ��
*	\param	dX[in]		������ǥ�� X���� ǥ���� ��ȯ
*	\param	Y[in]		�����ǥ��
*
*	\return X���� ǥ���� ��ȯ dX�� Y���� ǥ������ ��ȯ�Ͽ� ��ȯ�Ѵ�.
*/
EgTrans ad(const EgTrans &X1, const EgTrans &dX, const EgTrans &X2);

/*!
*	\brief	�� ��ȯ�� �����Ѵ�.
*
*	\param	X1[in]		ù ��° ��ȯ
*	\param	X2[in]		�� ��° ��ȯ
*	\param	t[in]		���� �Ķ����(0 ~ 1)
*
*	\return ������ ��ȯ�� ��ȯ�ȴ�.
*/
EgTrans lerp(EgTrans X1, EgTrans X2, const double t);

/*!
*	\brief Gift Wrap�˰����� �̿��Ͽ� 2���� convex hull�� ���Ѵ�.
*
*	\param InPts[in]	�Է� ����
*	\param OutPts[out]	convex hull�� �������� �ݽð� �������� �����
*/
void find_convexhull_2d(const std::vector<EgPos> &InPts, std::vector<EgPos> &OutPts);

/*!
*	\brief	�־��� ������ �ٰ��� ���ο� ���ԵǴ��� ���θ� �Ǵ�
*	\note	�׽�Ʈ �ʿ�
*
*	\param	Pts[in]		�ٰ����� �̷�� ������ ����Ʈ(�ݽð� ����)
*	\param	p[in]		���� ���θ� ������ ����
*
*	\return �ٰ��� ���ο� ���Ե� ��� true, �׷��� ������ false�� ��ȯ
*/
bool pt_in_polygon(const std::vector<EgPos> &Pts, EgPos const &p);
