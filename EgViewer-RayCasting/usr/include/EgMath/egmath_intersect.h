#pragma once

/*!
*	\brief	������ ������ �������� ����Ѵ�.
*	\note	������ ������: 2021-05-08
*
*	\param	l0[in]		ù ��° ������ ������
*	\param	l1[in]		�� ��° ������ ������
*	\param	t0[out]		ù ��° ������ �������� �Ķ���� ���� �����
*	\param	t1[out]		�� ��° ������ �������� �Ķ���� ���� �����
*	\param	p[out]		�������� ����� ����
*
*	\return �� ������ �����ϸ� true, �������� ������(����, ���� ��ġ) false�� ��ȯ�Ѵ�.
*/
bool intersect_line_line(
	EgLine l0,	EgLine l1, 
	double &t0, double &t1, EgPos &p);

/*!
*	\brief	�� ���� (p0, p1), (q0, q1)�� ���� ���ο� �������� ����Ѵ�.
*	\noet	������ ������: 2021-05-04
*
*	\param	p0[in]	ù ��° ������ ������
*	\param	p1[in]	ù ��° ������ ����
*	\param	q0[in]	�� ��° ������ ������
*	\param	q1[in]	�� ��° ������ ����
*	\param	pt[out]	������ ��� �������� ����ȴ�.
*
*	\return �� ������ �����ϸ� true, �ƴϸ� false�� ��ȯ�Ѵ�.
*/
bool intersect_edge_edge(
	EgPos p0, EgPos p1, 
	EgPos q0, EgPos q1, 
	EgPos &pt);


/*!
*	\brief	������ �ﰢ�� (p1p2p3)�� �������� ����Ѵ�.
*	\note	������: Real-time rendering (pp. 581)
*
*	\param	p1[in]				�ﰢ���� ù ��° ����(�ݽð� ����)
*	\param	p2[in]				�ﰢ���� �� ��° ����(�ݽð� ����)
*	\param	p3[in]				�ﰢ���� �� ��° ����(�ݽð� ����)
*	\param	l[in]				������ ������
*	\param	t[out]				�������� ���� �Ķ���Ͱ� �����
*	\param	q[out]				�������� �����
*	\param	alpha[out]			barycentric ��ǥ�� �����
*	\param	beta[out]			barycentric ��ǥ�� �����
*	\param	gamma[out]			barycentric ��ǥ�� �����
*	\param	bCullBackFace[in]	������ �ﰢ���� �޸�� ������ ��츦 �����Ϸ���. (����Ʈ: true).
*	\note	q = alpha * p1 + beta * p2 + gamma * p3, (alpha + beta + gamma = 1)
*
*	\return true: ����, false: ������ �ﰢ���� �����ϰų� �������� �ﰢ���� �ܺο� �����ϴ� ���.
*/
bool intersect_line_tri(
	const EgPos &p1, const EgPos &p2, const EgPos &p3, 
	const EgLine &l, 
	double &t, 
	EgPos &q, 
	double &alpha, 
	double &beta, 
	double &gamma, 
	bool bCullBackFace = true);

/*!
*	\brief	������ �ﰢ�� (p1p2p3)�� �������� ����Ѵ�.
*	\note	������: Real-time rendering (pp. 581)
*
*	\param	p1[in]				�ﰢ���� ù ��° ����(�ݽð� ����)
*	\param	p2[in]				�ﰢ���� �� ��° ����(�ݽð� ����)
*	\param	p3[in]				�ﰢ���� �� ��° ����(�ݽð� ����)
*	\param	l[in]				������ ������
*	\param	q[out]				�������� �����
*	\param	bCullBackFace[in]	������ �ﰢ���� �޸�� ������ ��츦 �����Ϸ���. (����Ʈ: true).
*
*	\return true: ����, false: ������ �ﰢ���� �����ϰų� �������� �ﰢ���� �ܺο� �����ϴ� ���.
*/
bool intersect_line_tri(
	const EgPos &p1, const EgPos &p2, const EgPos &p3, 
	const EgLine &l,
	EgPos &q, 
	bool bCullBackFace = true);

/*!
*	\brief	�ﰢ�� T1 = (u0, u1, u2)�� T2 = (v0, v1, v2)�� ���� ���ο� �������� ����Ѵ�.
*	\note	������: Real-time rendering (ERIT ���)
*
*	\param	u0[in]	�ﰢ�� T1�� ù ��° ����(�ݽð� ����)
*	\param	u1[in]	�ﰢ�� T1�� �� ��° ����(�ݽð� ����)
*	\param	u2[in]	�ﰢ�� T1�� �� ��° ����(�ݽð� ����)
*	\param	v0[in]	�ﰢ�� T2�� ù ��° ����(�ݽð� ����)
*	\param	v1[in]	�ﰢ�� T2�� �� ��° ����(�ݽð� ����)
*	\param	v2[in]	�ﰢ�� T2�� �� ��° ����(�ݽð� ����)
*	\param	p[out]	�� �ﰢ���� ù ��° �������� ����ȴ�.
*	\param	q[out]	�� �ﰢ���� �� ��° �������� ����ȴ�.
*
*	\return �� �ﰢ���� �����ϸ� true, �ƴϸ� false�� ��ȯ�Ѵ�.
*/
bool intersect_tri_tri(
	EgPos u0, EgPos u1, EgPos u2, 
	EgPos v0, EgPos v1, EgPos v2, 
	EgPos &p, EgPos &q);

/*!
*	\brief	������ ����� �������� ����Ѵ�.
*
*	\param	p[in]		������ ������
*	\param	q[in]		������ ����
*	\param	pi[in]		��� ��ü
*	\param	pt[out]		�������� ����ȴ�.
*
*	\return ������ ����� �����ϸ� true, �ƴϸ� false�� ��ȯ�Ѵ�.
*/
bool intersect_edge_plane(EgPos p, EgPos q, EgPlane pi, EgPos &pt);

/*!
*	\brief	�ﰢ���� ��� ������ ���� ���θ� �˻��Ѵ�.
*	\note	������: Real-time rendering
*
*	\param	u0[in]			�ﰢ���� ù ��° ����
*	\param	u1[in]			�ﰢ���� �� ��° ����
*	\param	u2[in]			�ﰢ���� �� ��° ����
*	\param	box_min[in]		��� ������ �ּ���
*	\param	box_max[in]		��� ������ �ִ���
*
*	\return �ﰢ���� ��� ���ڰ� �����ϸ� true, �ƴϸ� false�� ��ȯ�Ѵ�.
*/
bool intersect_tri_box(EgPos u0, EgPos u1, EgPos u2, EgPos box_min, EgPos box_max);

/*!
*	\brief	������ ����� �������� ����Ѵ�.
*
*	\param	l[in]	���� ��ü
*	\param	pi[in]	��� ��ü
*	\param	pt[out]	�������� ����� ����
*
*	\return ���� ������ �����ϸ� true, �ƴϸ�(����, ������ ��鿡 ����) false�� ��ȯ�Ѵ�.
*/
bool intersect_line_plane(EgLine l, EgPlane pi, EgPos &pt);

/*!
*	\brief	������ ����� �������� ����Ѵ�.
*
*	\param	l[in]	���� ��ü
*	\param	pi[in]	��� ��ü
*	\param	pt[out]	�������� ����� ����
*
*	\return ���� ������ �����ϸ� true, �ƴϸ�(����, ������ ��鿡 ����) false�� ��ȯ�Ѵ�.
*/
bool intersect_ray_plane(EgLine l, EgPlane pi, EgPos &pt);

/*!
*	\brief	�� ����� ���� ������ ����Ѵ�.
*
*	\param	pi1[in]		ù ��° ���
*	\param	pi2[in]		�� ��° ���
*	\param	l[out]		�� ����� ���� ������ ����ȴ�.
*
*	\return �� ����� ������ ��� true, ������ ��� false�� ��ȯ�Ѵ�.
*/
bool intersect_plane_plane(EgPlane pi1, EgPlane pi2, EgLine &l);

/*!
*	\brief	�� ����� �������� ����Ѵ�.
*
*	\param	pi1[in]		ù ��° ���
*	\param	pi2[in]		�� ��° ���
*	\param	pi3[in]		�� ��° ���
*	\param	p[out]		�������� ����� �� ��ü.
*
*	\return �� ����� �� ������ �����ϸ� true, �ƴϸ� false�� ��ȯ�Ѵ�.
*/
bool intersect_three_planes(EgPlane &pi1, EgPlane &pi2, EgPlane &pi3, EgPos &pt);
