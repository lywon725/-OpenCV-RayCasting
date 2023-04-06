#pragma once

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
*	\brief	2���� ���͸� 3���� ���ͷ� ��ȯ�Ѵ�.
*
*	\param	v[in]	2���� ����
*
*	\return 3���� ���͸� ��ȯ�Ѵ�.
*/
EgVec3 cast_vec3(const EgVec2 &v);

/*!
*	\brief	4���� ���͸� 3���� ���� ���·� ��ȯ�Ѵ�.
*
*	\param	v[in] 4���� ����
*
*	\return 3���� ���͸� ��ȯ�Ѵ�.
*/
EgVec3 cast_vec3(const EgVec4 &v);

/*!
*	\brief	N ���� ���͸� 3���� ���ͷ� ��ȯ�Ѵ�.
*
*	\param	v[in]	N ���� ����
*
*	\return 3���� ���͸� ��ȯ�Ѵ�.
*/
EgVec3 cast_vec3(const EgVec &v);

/*!
*	\brief	���� ���ͷ� ��ȯ�Ѵ�.
*
*	\param	pt[in]	3���� ������ ��
*
*	\return ��ȯ�� ���͸� ��ȯ�Ѵ�.
*/
EgVec3 cast_vec3(const EgPos &p);

/*!
*	\brief	3���� ���͸� 4���� �������·� ��ȯ�Ѵ�.
*
*	\param	v[in]	3���� ����
*	\param	w[in]	4��° ��ǥ��
*
*	\return v�� Ȯ��� 4���� ���� ǥ���� ��ȯ�Ѵ�.
*/
EgVec4 cast_vec4(const EgVec3 &v, double w = 0.0);

/*!
*	\brief	�� pt�� ��ǥ�� 4���� ���ͷ� ��ȯ�Ѵ�.
*
*	\param	pt[in]	3���� ������ ��
*	\param	w[in]	4��° ��ǥ��
*
*	\return pt�� 4���� ���� ǥ���� ��ȯ�Ѵ�.
*/
EgVec4 cast_vec4(const EgPos &p, double w = 0.0);

/*!
*	\brief	���ʹϿ��� 4���� ���ͷ� ��ȯ�Ѵ�.
*
*	\param	q[in]	��� ���ʹϿ�
*
*	\return 4���� ���͸� ��ȯ�Ѵ�.
*/
EgVec4 cast_vec4(const EgQuat &q);

/*!
*	\brief	2���� ���� v�� ��ǥ�� �Ϲ����� ���� ���·� ��ȯ�Ѵ�.
*
*	\param	v[in]	2���� ����
*
*	\return 3���� ���� v�� ��ǥ�� �Ϲ����� ���� ���·� ��ȯ�Ѵ�.
*/
EgVec cast_vec(const EgVec2 &v);

/*!
*	\brief	3���� ���� v�� ��ǥ�� �Ϲ����� ���� ���·� ��ȯ�Ѵ�.
*
*	\param	v[in]	3���� ������ ����
*
*	\return 3���� ���� v�� ��ǥ�� �Ϲ����� ���� ���·� ��ȯ�Ѵ�.
*/
EgVec cast_vec(const EgVec3 &v);

/*!
*	\brief	4���� ���� v�� ��ǥ�� �Ϲ����� ���� ���·� ��ȯ
*
*	\param	v[in]	4���� ������ ����
*
*	\return 4���� ���� v�� ��ǥ�� �Ϲ� ���� ǥ���� ��ȯ�Ѵ�.
*/
EgVec cast_vec(const EgVec4 &v);

/*!
*	\brief	�� pt�� ��ǥ�� �������·� ��ȯ�Ѵ�.
*
*	\param	pt[in] 3���� ������ ��
*
*	\return pt�� ���� ǥ���� ��ȯ�Ѵ�.
*/
EgVec cast_vec(const EgPos &p);

/*!
*	\brief	���ʹϿ��� 4���� ���ͷ� ��ȯ�Ѵ�.
*
*	\param	q[in]	��� ���ʹϿ�
*
*	\return ���͸� ��ȯ�Ѵ�.
*/
EgVec cast_vec(const EgQuat &q);

/*!
*	\brief	���� v�� ��ǥ�� ����Ʈ ���·� ��ȯ�Ѵ�.
*
*	\param	v[in] 3���� ������ ����
*
*	\return v�� ��ǥ�� ����Ʈ ���·� ��ȯ�Ѵ�.
*/
EgPos cast_pos(const EgVec3 &v);

/*!
*	\brief	4���� ���� v�� ��ǥ�� 3���� ����Ʈ ���·� ��ȯ�Ѵ�.
*
*	\param	v[in]	4���� ������ ����
*
*	\return 4���� ���� v�� ��ǥ�� 3���� ����Ʈ ���·� ��ȯ�Ѵ�.
*/
EgPos cast_pos(const EgVec4 &v);

/*!
*	\brief	n ���� ���͸� 3���� ����Ʈ�� ���·� ��ȯ�Ѵ�.
*
*	\param	v[in]	����
*
*	\return v�� 3���� ����Ʈ ǥ���� ��ȯ�Ѵ�.
*/
EgPos cast_pos(const EgVec &v);

/*!
*	\brief	����� ���Ҹ� ���� �Ǽ��迭�� ��ȯ�Ѵ�.
*
*	\param	m[in]	���
*
*	\return ����� ���Ҹ� ������ �Ǽ� �迭�� ��ȯ�Ѵ�.
*/
double *cast_arr(EgMat &m);

/*!
*	\brief	���ʹϿ����� ǥ���Ǵ� ȸ���� 4 by 4 ��ķ� ��ȯ�Ѵ�.
*
*	\param	q[in]		������ʹϿ�
*	\param	isGL[in]	���� true �̸� ��Ŀ� OpenGL ���·� ���ȴ�.
*
*	\return ȸ���� ǥ���ϴ� ����� ��ȯ�Ѵ�.
*/
EgMat cast_mat(const EgQuat &q, bool isGL = true);

/*!
*	\brief ��ü��ȯ X�� �ش��ϴ� 4�� 4���� ������ǥ��ȯ��ķ� ��ȯ�Ѵ�.
*	\param X ��ü��ȯ
*	\param isGL ���� true �̸� ��Ŀ� OpenGL ���·� �����Ѵ�.
*
*	\return ��ü��ȯ�� ǥ���ϴ� ���
*/
EgMat cast_mat(const EgTrans &X, bool isGL = true);

/*!
*	\brief	���͸� ���ʹϿ��� ���·� ��ȯ�Ѵ�.
*
*	\param	v[in]	����
*
*	\return ��ȯ�� ���ʹϿ� (w, x, y, z) = (v[0], v[1], v[2], v[3])�� ��ȯ�Ѵ�.
*/
EgQuat cast_quat(const EgVec &v);

/*!
*	\brief	4���� ���͸� ���ʹϿ����� ��ȯ�Ѵ�.
*
*	\param	v[in]	4���� ����
*
*	\return ��ȯ�� ���ʹϿ� (w, x, y, z) = (v[0], v[1], v[2], v[3])�� ��ȯ�Ѵ�.
*/
EgQuat cast_quat(const EgVec4 &v);
