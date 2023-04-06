#pragma once

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cassert>
#include <stdarg.h>
#include "egmath_type.h"
#include "egmath_opt.h"
#include "egmath_util.h"
#include "egmath_cast.h"
#include "egmath_intersect.h"

// Ŭ���� ����
class EgVec2;
class EgVec3;
class EgVec4;
class EgVec;
class EgPos;
class EgMat;
class EgQuat;
class EgTrans;
class EgLine;
class EgPlane;

/*!
*	\class	EgVec2
*	\brief	2���� ���͸� ǥ���ϴ� Ŭ����
*
*	\author ������(shyun@dongguk.edu)
*	\date	01 Jan 2001
*/
class EgVec2
{
public:
	/*! \brief 2���� ������ ��ǥ �迭 */
	double m_Coords[2];

public:
	/*!
	*	\brief	������
	*
	*	\param	x[in]	������ x ��ǥ
	*	\param	y[in]	������ y ��ǥ
	*/
	EgVec2(double x = 0.0, double y = 0.0);

	/*!
	*	\brief	���� ������
	*
	*	\param	cpy[in]	����� ��ü
	*/
	EgVec2(const EgVec2 &cpy);

	/*!
	*	\brief	�Ҹ���
	*/
	~EgVec2();	

	/*!
	*	\brief	������ ��ǥ�� �����Ѵ�.
	*
	*	\param	x[in]	������ x ��ǥ
	*	\param	y[in]	������ y ��ǥ
	*
	*	\return ������ �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec2 &Set(double x, double y);

	/*!
	*	\brief	���͸� �������̷� ����ȭ�Ѵ�.
	*
	*	\return ����ȭ�� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec2 &Normalize();

	/*!
	*	\brief	���� ������
	*
	*	\param	rhs[in]	���Ե� ����
	*
	*	\return ���Ե� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec2 &operator =(const EgVec2 &rhs);

	/*!
	*	\brief	���͸� ���Ѵ�.
	*
	*	\param	rhs[in]	���� ����
	*
	*	\return ����� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec2 &operator +=(const EgVec2 &rhs);

	/*!
	*	\brief	���͸� ����.
	*
	*	\param	rhs[in]		�� ����
	*
	*	\return ����� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec2 &operator -=(const EgVec2 &rhs);

	/*!
	*	\brief	���͸� ����� �Ѵ�.
	*
	*	\param	s[in]	���
	*
	*	\return ����� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec2 &operator *=(const double &s);

	/*!
	*	\brief	���͸� ����� ������.
	*
	*	\param	s[in]	���
	*
	*	\return ����� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec2 &operator /=(const double &s);

	/*!
	*	\brief	���� ������(+)
	*
	*	\return ���� ��ȣ�� ���� ��ü�� ��ȯ�Ѵ�.
	*/
	EgVec2 operator +() const;

	/*!
	*	\brief	���� ������(-)
	*
	*	\return �ݴ� ��ȣ�� ���� ��ü�� ��ȯ�Ѵ�.
	*/
	EgVec2 operator -() const;

	/*!
	*	\brief	�ε��� ������([])
	*
	*	\param	idx[in]	��ǥ�� �ε���
	*
	*	\return ������ idx��° ������ ���۷����� ��ȯ�Ѵ�.
	*/
	double &operator [](const int &idx);

	/*!
	*	\brief	��� ��ü�� ���� �ε��� ������([])
	*
	*	\param	idx[in]	������ �ε���
	*
	*	\return ������ idx��° ������ ���۷����� ��ȯ�Ѵ�.
	*/
	const double &operator [](const int &idx) const;

	/*!
	*	\brief	�� ������ ���� ���Ѵ�.
	*
	*	\param	v[in]	ù ��° ����
	*	\param	w[in]	�� ��° ����
	*
	*	\return �� ������ �� ���͸� ��ȯ�Ѵ�.
	*/
	friend EgVec2 operator +(const EgVec2 &v, const EgVec2 &w);

	/*!
	*	\brief	�� ������ ���� ���Ѵ�.
	*
	*	\param	v[in]	ù ��° ����
	*	\param	w[in]	�� ��° ����
	*
	*	\return �� ������ �� ���͸� ��ȯ�Ѵ�.
	*/
	friend EgVec2 operator -(const EgVec2 &v, const EgVec2 &w);

	/*!
	*	\brief	�� ������ ������ ���Ѵ�.
	*
	*	\param	v[in]	ù ��° ����
	*	\param	w[in]	�� ��° ����
	*
	*	\return �� ������ ������ ��ȯ�Ѵ�.
	*/
	friend double operator *(const EgVec2 &v, const EgVec2 &w);

	/*!
	*	\brief	���͸� ����� �Ѵ�.
	*
	*	\param	v[in]	����
	*	\param	s[in]	���
	*
	*	\return ������ ����踦 ��ȯ�Ѵ�.
	*/
	friend EgVec2 operator *(const EgVec2 &v, double s);

	/*!
	*	\brief	���͸� ����� �Ѵ�.
	*
	*	\param	s[in]	���
	*	\param	v[in]	����
	*
	*	\return ������ ����踦 ��ȯ�Ѵ�.
	*/
	friend EgVec2 operator *(double s, const EgVec2 &v);

	/*!
	*	\brief	���͸� ����� ������
	*
	*	\param	v[in]	����
	*	\param	s[in]	���
	*
	*	\return ����� �������� ���͸� ��ȯ�Ѵ�.
	*/
	friend EgVec2 operator /(const EgVec2 &v, double s);

	/*!
	*	\brief	�� ���Ͱ� ������ �˻��Ѵ�.
	*
	*	\param	v[in]	ù ��° ����
	*	\param	w[in]	�� ��° ����
	*
	*	\return �� ���Ͱ� ������ true, �ٸ��� false�� �����Ѵ�.
	*/
	friend bool operator ==(const EgVec2 &v, const EgVec2 &w);

	/*!
	*	\brief	�� ���Ͱ� �ٸ��� �˻��Ѵ�.
	*
	*	\param	v[in]	ù ��° ����
	*	\param	w[in]	�� ��° ����
	*
	*	\return �� ���Ͱ� �ٸ��� true, ������ false�� ��ȯ�Ѵ�.
	*/
	friend bool operator !=(const EgVec2 &v, const EgVec2 &w);

	/*!
	*	\brief	���͸� �ܼ� â�� ����Ѵ�.
	*
	*	\param	os[in]	��� ��Ʈ��
	*	\param	v[in]	��� ����
	*
	*	\return ���Ͱ� ��µ� ��Ʈ���� ��ȯ�Ѵ�.
	*/
	friend std::ostream &operator <<(std::ostream &os, const EgVec2 &v);

	/*!
	*	\brief	������ ��ǥ�� �Է� �޴´�.
	*
	*	\param	is[in]	�Է� ��Ʈ��
	*	\param	v[out]	��� ����
	*
	*	\return �Է� ��Ʈ���� ��ȯ�Ѵ�.
	*/
	friend std::istream &operator >>(std::istream &is, EgVec2 &v);
};

/*!
*	\class	EgVec3
*	\brief	3���� ���͸� ǥ���ϴ� Ŭ����
*
*	\author ������(shyun@dongguk.edu)
*	\date	01 Jan 2001
*/
class EgVec3
{
public:
	/*! \brief 3���� ������ ��ǥ �迭 */
	double m_Coords[3];

public:
	/*!
	*	\brief	������
	*
	*	\param	x[in]	������ x ��ǥ
	*	\param	y[in]	������ y ��ǥ
	*	\param	z[in]	������ z ��ǥ
	*/
	EgVec3(double x = 0.0, double y = 0.0, double z = 0.0);

	/*!
	*	\brief	���� ������
	*
	*	\param	cpy[in]	����� ��ü
	*/
	EgVec3(const EgVec3 &cpy);

	/*!
	*	\brief	�Ҹ���
	*/
	~EgVec3();	

	/*!
	*	\brief	������ ��ǥ�� �����Ѵ�.
	*
	*	\param	x[in]	������ x ��ǥ
	*	\param	y[in]	������ y ��ǥ
	*	\param	z[in]	������ z ��ǥ
	*/
	EgVec3 &Set(double x, double y, double z);

	/*!
	*	\brief	�������ͷ� ����ȭ�Ѵ�.
	*
	*	\return ����ȭ�� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec3 &Normalize();
		
	/*!
	*	\brief	���� ������
	*
	*	\param	rhs[in]	���Ե� ��ü
	*
	*	\return ���Ե� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec3 &operator =(const EgVec3 &rhs);

	/*!
	*	\brief	���͸� ���Ѵ�.
	*
	*	\param	rhs[in]	���� ����
	*
	*	\return ����� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec3 &operator +=(const EgVec3 &rhs);

	/*!
	*	\brief	���͸� ����.
	*
	*	\param	rhs[in]	�� ����
	*
	*	\return ����� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec3 &operator -=(const EgVec3 &rhs);

	/*!
	*	\brief	���͸� ����� �Ѵ�.
	*
	*	\param	s[in]	���
	*
	*	\return ����� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec3 &operator *=(const double &s);

	/*!
	*	\brief	���͸� ����� ������.
	*
	*	\param	s[in]	���� ���
	*
	*	\return ����� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec3 &operator /=(const double &s);

	/*!
	*	\brief	���͸� �����Ѵ�.
	*
	*	\param	rhs[in]	������ ����
	*
	*	\return ����� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec3 &operator ^=(const EgVec3 &rhs);

	/*!
	*	\brief	���� ������(+)
	*
	*	\return ���Ϻ�ȣ�� ���� ��ü�� ��ȯ�Ѵ�.
	*/
	EgVec3 operator +() const;

	/*!
	*	\brief	���� ������(-)
	*
	*	\return �ݴ��ȣ�� ���� ��ü�� ��ȯ�Ѵ�.
	*/
	EgVec3 operator -() const;

	/*!
	*	\brief	�ε��� ������([])
	*
	*	\param	idx[in]		���� �ε���
	*
	*	\return ������ idx��° ������ ���۷����� ��ȯ�Ѵ�.
	*/
	double &operator [](const int &idx);

	/*!
	*	\brief	�����ü�� ���� �ε��� ������([])
	*
	*	\param	idx[in]	�ε���
	*
	*	\return ������ idx��° ������ ���۷����� ��ȯ�Ѵ�.
	*/
	const double &operator [](const int &idx) const;

	/*!
	*	\brief	�� ���͸� ���Ѵ�.
	*
	*	\param	v[in]	ù ��° ����
	*	\param	w[in]	�� ��° ����
	*
	*	\return �� ������ ���� ��ȯ�Ѵ�.
	*/
	friend EgVec3 operator +(const EgVec3 &v, const EgVec3 &w);

	/*!
	*	\brief	�� ���͸� ����.
	*
	*	\param	v[in]	ù ��° ����
	*	\param	w[in]	�� ��° ����
	*
	*	\return �� ������ ���� ��ȯ�Ѵ�.
	*/
	friend EgVec3 operator -(const EgVec3 &v, const EgVec3 &w);

	/*!
	*	\brief	���͸� ����� �Ѵ�.
	*
	*	\param	v[in]	����
	*	\param	s[in]	���
	*
	*	\return ������ ����踦 ��ȯ�Ѵ�.
	*/
	friend EgVec3 operator *(const EgVec3 &v, const double &s);

	/*!
	*	\brief	���͸� ����� �Ѵ�.
	*
	*	\param	s[in]	���
	*	\param	v[in]	����
	*
	*	\return ������ ����踦 ��ȯ�Ѵ�.
	*/
	friend EgVec3 operator *(const double &s, const EgVec3 &v);

	/*!
	*	\brief	�� ������ ������ ���Ѵ�.
	*
	*	\param	v[in]	ù ��° ����
	*	\param	w[in]	�� ��° ����
	*
	*	\return �� ������ ���� ����� ��ȯ�Ѵ�.
	*/
	friend double operator *(const EgVec3 &v, const EgVec3 &w);

	/*!
	*	\brief	���� ���͸� ���Ѵ�.
	*
	*	\param	s[in]	���
	*	\param	v[in]	����
	*
	*	\return ���� ���͸� ��ȯ�Ѵ�.
	*/
	friend EgVec3 operator /(const double &s, const EgVec3 &v);

	/*!
	*	\brief	���͸� ����� ������.
	*
	*	\param	v[in]	����
	*	\param	s[in]	���
	*
	*	\return ����� �������� ���͸� ��ȯ�Ѵ�.
	*/
	friend EgVec3 operator /(const EgVec3 &v, const double &s);

	/*!
	*	\brief	�� ������ ���� ���͸� ���Ѵ�.
	*
	*	\param	v[in]	ù ��° ����
	*	\param	w[in]	�� ��° ����
	*
	*	\return ���� ���� (v X w)�� ��ȯ�Ѵ�.
	*/
	friend EgVec3 operator ^(const EgVec3 &v, const EgVec3 &w);

	/*!
	*	\brief	�� ���Ͱ� ������ �����Ѵ�.
	*
	*	\param	v[in]	ù ��° ����
	*	\param	w[in]	�� ��° ����
	*
	*	\return �� ���Ͱ� ������ true, �ٸ��� false�� ��ȯ�Ѵ�.
	*/
	friend bool operator ==(const EgVec3 &v, const EgVec3 &w);

	/*!
	*	\brief	�� ���Ͱ� �ٸ��� �����Ѵ�.
	*
	*	\param	v[in]	ù ��° ����
	*	\param	w[in]	�� ��° ����
	*
	*	\return �� ���Ͱ� �ٸ��� ture, ������ false�� ��ȯ�Ѵ�.
	*/
	friend bool operator !=(const EgVec3 &v, const EgVec3 &w);

	/*!
	*	\brief	��� ������(<<)
	*
	*	\param	os[out]		��� ��Ʈ��
	*	\param	v[in]		����� ����
	*
	*	\return ���Ͱ� ��µ� ��Ʈ���� ��ȯ�Ѵ�.
	*/
	friend std::ostream &operator <<(std::ostream &os, const EgVec3 &v);

	/*!
	*	\brief	�Է� ������(>>)
	*
	*	\param	is[in]	�Է½�Ʈ��
	*	\param	v[out]	�Է°��� ����� ����
	*
	*	\return �Է°��� ���ŵ� �Է½�Ʈ���� ��ȯ�Ѵ�.
	*/
	friend std::istream &operator >>(std::istream &is, EgVec3 &v);
};

/*!
*	\class	EgVec4
*	\brief	4���� ���͸� ǥ���ϴ� Ŭ����
*
*	\author ������(shyun@dongguk.edu)
*	\date	01 Jan 2001
*/
class EgVec4
{
public:
	/*! \brief 4���� ������ ��ǥ �迭 */
	double m_Coords[4];

public:
	/*!
	*	\brief	������
	*
	*	\param	x[in]	������ x ��ǥ
	*	\param	y[in]	������ y ��ǥ
	*	\param	z[in]	������ z ��ǥ
	*	\param	w[in]	������ w ��ǥ
	*/
	EgVec4(double x = 0.0, double y = 0.0, double z = 0.0, double w = 0.0);
	
	/*!
	*	\brief	���� ������
	*
	*	\param	cpy[in]	����� ��ü
	*/
	EgVec4(const EgVec4 &cpy);

	/*!
	*	\brief	�Ҹ���
	*/
	~EgVec4();	

	/*!
	*	\brief	������ ��ǥ�� �����Ѵ�.
	*
	*	\param	x[in]	������ x ��ǥ
	*	\param	y[in]	������ y ��ǥ
	*	\param	z[in]	������ z ��ǥ
	*	\param	w[in]	������ w ��ǥ
	*
	*	\return ������ �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec4 &Set(double x, double y, double z, double w);

	/*!
	*	\brief	���͸� �������ͷ� ����ȭ�Ѵ�.
	*
	*	\return ����ȭ�� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec4 &Normalize();

	/*!
	*	\brief	���� ������
	*
	*	\param	rhs[in]	���Ե� ��ü
	*
	*	\return ���Ե� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec4 &operator =(const EgVec4 &rhs);

	/*!
	*	\brief	���͸� ���Ѵ�.
	*
	*	\param	rhs[in]	���� ����
	*
	*	\return ����� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec4 &operator +=(const EgVec4 &rhs);

	/*!
	*	\brief	���͸� ����.
	*
	*	\param	rhs[in]	�� ����
	*
	*	\return ����� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec4 &operator -=(const EgVec4 &rhs);

	/*!
	*	\brief	���͸� ����� �Ѵ�.
	*
	*	\param	s[in]	���
	*
	*	\return ����� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec4 &operator *=(const double &s);

	/*!
	*	\brief	���͸� ����� ������.
	*
	*	\param	s[in]	���
	*
	*	\return ����� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec4 &operator /=(const double &s);

	/*!
	*	\brief	+ ���� ������
	*
	*	\return ���Ϻ�ȣ�� ���� ��ü�� ��ȯ�Ѵ�.
	*/
	EgVec4 operator +() const;

	/*!
	*	\brief	- ���� ������
	*
	*	\return �ݴ��ȣ�� ���� ��ü�� ��ȯ�Ѵ�.
	*/
	EgVec4 operator -() const;

	/*!
	*	\brief	�ε��� ������([])
	*
	*	\param	idx[in]	�ε���
	*
	*	\return	������ idx��° ������ ���۷����� ��ȯ�Ѵ�.
	*/
	double &operator [](const int &idx);

	/*!
	*	\brief	��� ��ü�� ���� �ε��� ������([])
	*
	*	\param	idx[in]	�ε���
	*
	*	\return	������ idx��° ������ ���۷����� ��ȯ�Ѵ�.
	*/
	const double &operator [](const int &idx) const;

	/*!
	*	\brief	�� ���͸� ���Ѵ�.
	*
	*	\param	v[in]	ù ��° ����
	*	\param	w[in]	�� ��° ����
	*
	*	\return �� ������ ���� ��ȯ�Ѵ�.
	*/
	friend EgVec4 operator +(const EgVec4 &v, const EgVec4 &w);

	/*!
	*	\brief	�� ���͸� ����.
	*
	*	\param	v[in]	ù ��° ����
	*	\param	w[in]	�� ��° ����
	*
	*	\return �� ������ ���� ��ȯ�Ѵ�.
	*/
	friend EgVec4 operator -(const EgVec4 &v, const EgVec4 &w);

	/*!
	*	\brief	���͸� ����� �Ѵ�.
	*
	*	\param	v[in]	����
	*	\param	s[in]	���
	*
	*	\return ������ ����� ��ȯ�Ѵ�.
	*/
	friend EgVec4 operator *(const EgVec4 &v, const double &s);

	/*!
	*	\brief	���͸� ����� �Ѵ�.
	*
	*	\param	s[in]	���
	*	\param	v[in]	����
	*
	*	\return ������ ����� ��ȯ�Ѵ�.
	*/
	friend EgVec4 operator *(const double &s, const EgVec4 &v);

	/*!
	*	\brief	�� ������ ������ ���Ѵ�.
	*
	*	\param	v[in]	ù ��° ����
	*	\param	w[in]	�� ��° ����
	*
	*	\return �� ������ ������ ����� ��ȯ�Ѵ�.
	*/
	friend double operator *(const EgVec4 &v, const EgVec4 &w);

	/*!
	*	\brief	���͸� ����� ������.
	*
	*	\param	v[in]	����
	*	\param	s[in]	���
	*
	*	\return ������ ����� ��ȯ�Ѵ�.
	*/
	friend EgVec4 operator /(const EgVec4 &v, const double &s);

	/*!
	*	\brief	�� ���Ͱ� ������ �˻��Ѵ�.
	*
	*	\param	v[in]	ù ��° ����
	*	\param	w[in]	�� ��° ����
	*
	*	\return �� ���Ͱ� ���ٸ� true, �ٸ��� false�� ��ȯ�Ѵ�.
	*/
	friend bool operator ==(const EgVec4 &v, const EgVec4 &w);

	/*!
	*	\brief	�� ���Ͱ� �ٸ��� �˻��Ѵ�.
	*
	*	\param	v[in]	ù ��° ����
	*	\param	w[in]	�� ��° ����
	*
	*	\return �� ���Ͱ� �ٸ��� true, ������ false�� ��ȯ�Ѵ�.
	*/
	friend bool operator !=(const EgVec4 &v, const EgVec4 &w);

	/*!
	*	\brief	��� ������(<<)
	*
	*	\param	os[out]		��� ��Ʈ��
	*	\param	v[in]		��� ����
	*
	*	\return ���Ͱ� ��µ� ��Ʈ���� ��ȯ�Ѵ�.
	*/
	friend std::ostream &operator <<(std::ostream &os, const EgVec4 &v);

	/*!
	*	\brief	�Է� ������(>>)
	*
	*	\param	is[in]	�Է� ��Ʈ��
	*	\param	v[out]	�Է°��� ����� ����
	*
	*	\return �Է°��� ���ŵ� �Է½�Ʈ���� ��ȯ�Ѵ�.
	*/
	friend std::istream &operator >>(std::istream &is, EgVec4 &v);
};

/*!
*	\class	EgVec
*	\brief	n���� ���͸� ǥ���ϴ� Ŭ����
*
*	\author ������(shyun@dongguk.edu)
*	\date	01 Jan 2001
*/
class EgVec
{
public:
	/*! \brief ������ ��ǥ �迭 */
	std::vector<double> m_Coords;

public:
	/*!
	*	\brief	������
	*
	*	\param	dim[in]	������ ����
	*/
	EgVec(int dim = 3);

	/*!
	*	\brief	������
	*	\note	���Ҵ� ��� �Ǽ������� �����ؾ� ��
	*	\note	������ ������: 2021-05-30 (va_arg(ap, dim)->va_arg(ap, x))
	*
	*	\param	dim[in]	������ ����
	*	\param	x[in]	������ ù ��° ��ǥ
	*/
	EgVec(int dim, double x, ...);

	/*!
	*	\brief	������
	*	\note	���Ҵ� ��� ���������� �����ؾ� ��
	*	\note	������ ������: 2021-05-30 (va_arg(ap, dim)->va_arg(ap, x))
	*
	*	\param	dim[in]		������ ����
	*	\param	x[in]		������ ù ��° ��ǥ
	*/
	EgVec(int dim, int x, ...);

	/*!
	*	\brief	���� ������
	*
	*	\param	copy[in]	����� ��ü
	*/
	EgVec(const EgVec &cpy);

	/*!
	*	\brief	�Ҹ���
	*/
	~EgVec();

	/*!
	*	\brief	������ ���Ҹ� �����Ѵ�.
	*	\note	�Ű������� �Ǽ������� �־�� �Ѵ�. ��) 1: �Ұ���, 1.0: ����.
	*
	*	\param	x[in]	ù ��° ��ǥ
	*
	*	\return ������ �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec &Set(double x, ...);

	/*!
	*	\brief	������ ���Ҹ� �����Ѵ�.
	*	\note	�Ű������� ���������� �־�� �Ѵ�. ��) 1: ����, 1.0: �Ұ���.
	*
	*	\param	x[in]	ù ��° ��ǥ
	*
	*	\return ������ �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec &Set(int x, ...);

	/*!
	*	\brief	������ ���Ҹ� �����Ѵ�.
	*
	*	\param	Coords[in]	������ ��ǥ �迭
	*
	*	\return ������ �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec &Set(double *Coords);

	/*!
	*	\brief	���͸� ����ȭ�Ѵ�.
	*
	*	\return ����ȭ�� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec &Normalize();

	/*!
	*	\brief	���͸� �����ͷ� �����Ѵ�.
	*
	*	\return ������ �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec &SetZeros();

	/*!
	*	\brief	������ ������ ��ȯ�Ѵ�.
	*
	*	\return ������ ������ ��ȯ�Ѵ�.
	*/
	int GetDim() const;

	/*!
	*	\brief	���� ������
	*
	*	\param	rhs[in]	������ �ǿ�����
	*
	*	\return ���Ե� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec &operator =(const EgVec &rhs);

	/*!
	*	\brief	���͸� ���Ѵ�.
	*
	*	\param	rhs[in]	���� ����
	*
	*	\return ����� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec &operator +=(const EgVec &rhs);

	/*!
	*	\brief	���͸� ����.
	*
	*	\param	rhs[in]	�� ����
	*
	*	\return ����� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec &operator -=(const EgVec &rhs);

	/*!
	*	\brief	���͸� ����� �Ѵ�.
	*
	*	\param	s[in]	���
	*
	*	\return ����� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec &operator *=(const double &s);

	/*!
	*	\brief	���͸� ����� ������.
	*
	*	\param	s[in]	���
	*
	*	\return ����� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgVec &operator /=(const double &s);

	/*!
	*	\brief	+ ���� ������
	*
	*	\return ���Ϻ�ȣ ��ü�� ��ȯ�Ѵ�.
	*/
	EgVec operator +() const;

	/*!
	*	\brief	- ���� ������
	*
	*	\return �ݴ��ȣ ��ü�� ��ȯ�Ѵ�.
	*/
	EgVec operator -() const;

	/*!
	*	\brief	�ε��� ������([])
	*
	*	\param	idx[in]	�ε���
	*
	*	\return ������ idx ��° ������ ���۷����� ��ȯ�Ѵ�.
	*/
	double &operator [](const int &idx);

	/*!
	*	\brief	��� ��ü�� �ε��� ������([])
	*
	*	\param	idx[in]	�ε���
	*
	*	\return ������ idx ��° ������ ���۷����� ��ȯ�Ѵ�.
	*/
	const double &operator [](const int &idx) const;

	/*!
	*	\brief	�� ���͸� ���Ѵ�.
	*
	*	\param	v[in]	ù ��° ����
	*	\param	w[in]	�� ��° ����
	*
	*	\return �� ������ ���� ��ȯ�Ѵ�.
	*/
	friend EgVec operator +(const EgVec &v, const EgVec &w);

	/*!
	*	\brief	�� ���͸� ����.
	*
	*	\param	v[in]	ù ��° ����
	*	\param	w[in]	�� ��° ����
	*
	*	\return �� ������ ���� ��ȯ�Ѵ�.
	*/
	friend EgVec operator -(const EgVec &v, const EgVec &w);

	/*!
	*	\brief	�� ������ ������ ���Ѵ�.
	*
	*	\param	v[in]	ù ��° ����
	*	\param	w[in]	�� ��° ����
	*
	*	\return �� ������ �������� ��ȯ�Ѵ�.
	*/
	friend double operator *(const EgVec &v, const EgVec &w);

	/*!
	*	\brief	���͸� ����� �Ѵ�.
	*
	*	\param	v[in]	����
	*	\param	s[in]	���
	*
	*	\return ������ ����踦 ��ȯ�Ѵ�.
	*/
	friend EgVec operator *(const EgVec &v, const double &s);

	/*!
	*	\brief	���͸� ����� �Ѵ�.
	*
	*	\param	s[in]	���
	*	\param	v[in]	����
	*
	*	\return ������ ����踦 ��ȯ�Ѵ�.
	*/
	friend EgVec operator *(const double &s, const EgVec &v);

	/*!
	*	\brief	���͸� ����� ������.
	*
	*	\param	v[in]	����
	*	\param	s[in]	���
	*
	*	\return ������ ����� ��ȯ�Ѵ�.
	*/
	friend EgVec operator /(const EgVec &v, const double &s);

	/*!
	*	\brief	�� ������ ũ�⸦ ���Ѵ�.
	*
	*	\param	v[in]	���� ����
	*	\param	w[in]	������ ����
	*
	*	\return ���� ������ ũ�Ⱑ ������ ���ͺ��� ũ�� true, �ƴϸ� false�� ��ȯ�Ѵ�.
	*/
	friend bool operator >(const EgVec &v, const EgVec &w);

	/*!
	*	\brief	�� ������ ũ�⸦ ���Ѵ�.
	*
	*	\param	v[in]	���� ����
	*	\param	w[in]	������ ����
	*
	*	\return ���� ������ ũ�Ⱑ ������ ���ͺ��� ũ�ų� ������ true, �ƴϸ� false�� ��ȯ�Ѵ�.
	*/
	friend bool operator >=(const EgVec &v, const EgVec &w);

	/*!
	*	\brief	�� ������ ũ�⸦ ���Ѵ�.
	*
	*	\param	v[in]	���� ����
	*	\param	w[in]	������ ����
	*
	*	\return ���� ������ ũ�Ⱑ ������ ���ͺ��� ������ true, �ƴϸ� false�� ��ȯ�Ѵ�.
	*/
	friend bool operator <(const EgVec &v, const EgVec &w);

	/*!
	*	\brief	�� ������ ũ�⸦ ���Ѵ�.
	*
	*	\param	v[in]	���� ����
	*	\param	w[in]	������ ����
	*
	*	\return ���� ������ ũ�Ⱑ ������ ���ͺ��� �۰ų� ������ true, �ƴϸ� false�� ��ȯ�Ѵ�.
	*/
	friend bool operator <=(const EgVec &v, const EgVec &w);

	/*!
	*	\brief	�� ���Ͱ� ������ �����Ѵ�.
	*
	*	\param	v[in]	���� ����
	*	\param	w[in]	������ ����
	*
	*	\return �� ���Ͱ� ������ true, �ٸ��� false�� ��ȯ�Ѵ�.
	*/
	friend bool operator ==(const EgVec &v, const EgVec &w);

	/*!
	*	\brief	�� ���Ͱ� �ٸ��� �����Ѵ�.
	*
	*	\param	v[in]	���� ����
	*	\param	w[in]	������ ����
	*
	*	\return �� ���Ͱ� �ٸ��� true, ������ false�� ��ȯ�Ѵ�.
	*/
	friend bool operator !=(const EgVec &v, const EgVec &w);

	/*!
	*	\brief	��� ������(<<)
	*
	*	\param	os[out]		��� ��Ʈ��
	*	\param	v[in]		����� ����
	*
	*	\return ���Ͱ� ��µ� ��Ʈ���� ��ȯ�Ѵ�.
	*/
	friend std::ostream &operator <<(std::ostream &os, const EgVec &v);

	/*!
	*	\brief	�Է� ������(>>)
	*
	*	\param	is[in]	�Է� ��Ʈ��
	*	\param	v[out]	�Է°��� ����� ����
	*
	*	\return �Է°��� ���ŵ� �Է½�Ʈ���� ��ȯ�Ѵ�.
	*/
	friend std::istream &operator >>(std::istream &is, EgVec &v);
};

/*!
*	\class	EgPos
*	\brief	3���� ��ġ(position)�� ��Ÿ���� Ŭ����
*
*	\author ������(shyun@dongguk.edu)
*	\date	01 Jan 2001
*/
class EgPos
{
public:
	/*! \brief 3���� ��ǥ �迭 */
	double m_Coords[3];

public:
	/*!
	*	\brief	������
	*
	*	\param	x[in]	x ��ǥ
	*	\param	y[in]	y ��ǥ
	*	\param	z[in]	z ��ǥ
	*/
	EgPos(double x = 0.0, double y = 0.0, double z = 0.0);

	/*!
	*	\brief	���� ������
	*
	*	\param	cpy[in] ����� ��ü
	*
	*	\return ����� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgPos(const EgPos &cpy);

	/*!
	*	\brief  �Ҹ���
	*/
	~EgPos();

	/*!
	*	\brief	����Ʈ�� ��ǥ�� �����Ѵ�.
	*
	*	\param	x[in] x ��ǥ
	*	\param	y[in] y ��ǥ
	*	\param	z[in] z ��ǥ
	*
	*	\return ������ �ڽ��� ��ȯ�Ѵ�.
	*/
	EgPos &Set(double x, double y, double z);

	/*!
	*	\brief	���� ������
	*
	*	\param	rhs[in]		������ �ǿ�����
	*
	*	\return ���Ե� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgPos &operator =(const EgPos &rhs);

	/*!
	*	\brief	���͸� ���Ѵ�.
	*
	*	\param	v[in]	���� ����
	*
	*	\return ����� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgPos &operator +=(const EgVec3 &v);

	/*!
	*	\brief	���͸� ����.
	*
	*	\param	v[in]	�� ����
	*
	*	\return ����� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgPos &operator -=(const EgVec3 &v);

	/*!
	*	\brief	�ε��� ������([])
	*
	*	\param	idx[in] �ε���
	*
	*	\return ����Ʈ�� idx ��° ������ ���۷����� ��ȯ�Ѵ�.
	*/
	double &operator [](const int &idx);

	/*!
	*	\brief	��� ��ü�� �ε��� ������([])
	*
	*	\param	idx[in] �ε���
	*
	*	\return ����Ʈ�� idx ��° ������ ���۷����� ��ȯ�Ѵ�.
	*/
	const double &operator [](const int &idx) const;

	/*!
	*	\brief	�� ��ġ�� ���� ���͸� ���Ѵ�.
	*
	*	\param	p[in]	ù ��° ��ġ
	*	\param	q[in]	�� ��° ��ġ
	*
	*	\return q���� p�� ���ϴ� ���͸� ��ȯ�Ѵ�.
	*/
	friend EgVec3 operator -(const EgPos &p, const EgPos &q);

	/*!
	*	\brief	��ġ���� ���͸� ����.
	*
	*	\param	p[in]	��ġ
	*	\param	v[in]	����
	*
	*	\return ���ο� ��ġ�� ��ȯ�Ѵ�.
	*/
	friend EgPos operator -(const EgPos &p, const EgVec3 &v);

	/*!
	*	\brief	��ġ���� ���͸� ���Ѵ�.
	*
	*	\param	p[in]	��ġ
	*	\param	v[in]	����
	*
	*	\return ���ο� ��ġ�� ��ȯ�Ѵ�.
	*/
	friend EgPos operator +(const EgPos &p, const EgVec3 &v);

	/*!
	*	\brief	��ġ���� ���͸� ���Ѵ�.
	*
	*	\param	v[in]	����
	*	\param	p[in]	��ġ
	*
	*	\return ���ο� ��ġ�� ��ȯ�Ѵ�.
	*/
	friend EgPos operator +(const EgVec3 &v, const EgPos &p);

	/*!
	*	\brief	�� ��ġ�� ������ �����Ѵ�.
	*
	*	\param	p[in]	ù ��° ��ġ
	*	\param	q[in]	�� ���� ��ġ
	*
	*	\return �� ��ġ�� ������ true, �ٸ��� false�� �����Ѵ�.
	*/
	friend bool operator ==(const EgPos &p, const EgPos &q);

	/*!
	*	\brief	�� ��ġ�� �ٸ��� �����Ѵ�.
	*
	*	\param	p[in]	ù ��° ��ġ
	*	\param	q[in]	�� ���� ��ġ
	*
	*	\return �� ��ġ�� �ٸ��� true, ������ false�� �����Ѵ�.
	*/
	friend bool operator !=(const EgPos &p, const EgPos &q);

	/*!
	*	\brief	��� ������(<<)
	*
	*	\param	os[out]		��� ��Ʈ��
	*	\param	p[in]		����� ��ü
	*
	*	\return ��µ� ��Ʈ�� ��ü�� ��ȯ�Ѵ�.
	*/
	friend std::ostream &operator <<(std::ostream &os, const EgPos &p);

	/*!
	*	\brief	�Է� ������(>>)
	*
	*	\param	is[in]	�Է� ��Ʈ��
	*	\param	v[out]	�Է°��� ����� ����
	*
	*	\return �Է°��� ���ŵ� �Է� ��Ʈ���� ��ȯ�Ѵ�.
	*/
	friend std::istream &operator >>(std::istream &is, EgPos &p);
};

/*!
*	\class	EgMat
*	\brief	����� ǥ���ϴ� Ŭ����
*
*	\author ������(shyun@dongguk.edu)
*	\date	01 Jan 2001
*/
class EgMat
{
public:
	/*! \brief ����� ���� ���� */
	int m_nRow;

	/*! \brief ����� ���� ���� */
	int m_nCol;

	/*! \brief ����� ���Ҹ� �����ϴ� �迭 */
	std::vector<double> m_Data;	
	
public:
	/*!
	*	\brief	������
	*
	*	\param	r[in]		���� ��
	*	\param	c[in]		���� ��
	*	\param	elem[in]	����� ���� �迭
	*/
	EgMat(int r = 4, int c = 4, double *elem = NULL);

	/*!
	*	\brief	���� ������
	*
	*	\param	cpy[in]	����� ��ü
	*/
	EgMat(const EgMat &cpy);

	/*!
	*	\brief �Ҹ���
	*/
	~EgMat();	

	/*!
	*	\brief	����� ��ġ��ķ� ��ȯ�Ѵ�.
	*
	*	\return ��ȯ�� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgMat &SetTranspose();

	/*!
	*	\brief	������ķ� ��ȯ�Ѵ�.
	*	\note	��������� �ƴϸ� �ִ��� ������ķ� �����.
	*
	*	\return ��ȯ�� �ڽ��� �����Ѵ�.
	*/
	EgMat &SetIdentity();

	/*!
	*	\brief	����ķ� ��ȯ�Ѵ�.
	*
	*	\return ��ȯ�� �ڽ��� �����Ѵ�.
	*/
	EgMat &SetZeros();

	/*!
	*	\brief	�຤�͸� �����Ѵ�.
	*
	*	\param	idx[in]		������ ���� �ε���
	*	\param	v[in]		������ ����
	*
	*	\return ��ȯ�� �ڽ��� �����Ѵ�.
	*/
	EgMat &SetRowVec(const int idx, const EgVec &v);

	/*!
	*	\brief	�����͸� �����Ѵ�.
	*
	*	\param	idx[in]		������ ���� �ε���
	*	\param	v[in]		������ ����
	*
	*	\return ��ȯ�� �ڽ��� �����Ѵ�.
	*/
	EgMat &SetColVec(const int idx, const EgVec &v);

	/*!
	*	\brief	�� ���� ��ȯ�Ѵ�.
	*
	*	\param	idx0[in]	��ȯ�� ���� �ε���
	*	\param	idx1[in]	��ȯ�� ���� �ε���
	*
	*	\return ��ȯ�� �ڽ��� �����Ѵ�.
	*/
	EgMat &ExchangeRows(const int idx0, const int idx1);

	/*!
	*	\brief	�� ���� ��ȯ�Ѵ�.
	*
	*	\param	idx0[in]	��ȯ�� ���� �ε���
	*	\param	idx1[in]	��ȯ�� ���� �ε���
	*
	*	\return ��ȯ�� �ڽ��� �����Ѵ�.
	*/
	EgMat &ExchangeCols(const int idx0, const int idx1);

	/*!
	*	\brief	�຤�͸� ��ȯ�Ѵ�.
	*
	*	\param	idx[in]		���� �ε���
	*
	*	\return idx ��° �຤�͸� ��ȯ�Ѵ�.
	*/
	EgVec GetRowVec(const int idx) const;

	/*!
	*	\brief	�����͸� ��ȯ�Ѵ�.
	*
	*	\param	idx[in]		���� �ε���
	*
	*	\return idx ��° �����͸� ��ȯ�Ѵ�.
	*/
	EgVec GetColVec(const int idx) const;

	/*!
	*	\brief	���� ���� ��ȯ�Ѵ�.
	*
	*	\return ���� ���� ��ȯ�Ѵ�.
	*/
	int	GetRowNum() const;

	/*!
	*	\brief	���� ���� ��ȯ�Ѵ�.
	*
	*	\return ���� ���� ��ȯ�Ѵ�.
	*/
	int GetColNum() const;

	/*!
	*	\brief	������� ���θ� �����Ѵ�.
	*
	*	\return ��������� ��� true, ���簢����� ��� false�� ��ȯ�Ѵ�.
	*/
	bool IsSquare() const;

	/*!
	*	\brief	���� ������
	*
	*	\param	rhs[in] ���Ե� ��� ��ü
	*
	*	\return ���Ե� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgMat &operator =(const EgMat &rhs);

	/*!
	*	\brief	����� ���Ѵ�.
	*
	*	\param	rhs[in]	���� ���
	*
	*	\return ������ �ڽ��� ��ȯ�Ѵ�.
	*/
	EgMat &operator +=(const EgMat &rhs);

	/*!
	*	\brief	����� ����.
	*
	*	\param	rhs[in]	�� ���
	*
	*	\return ������ ���Ե� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgMat &operator -=(const EgMat &rhs);

	/*!
	*	\brief	����� ���Ѵ�.
	*
	*	\param	rhs[in]	���� ���
	*
	*	\return ������ �ڽ��� ��ȯ�Ѵ�.
	*/
	EgMat &operator *=(const EgMat &rhs);

	/*!
	*	\brief	����� ����� �Ѵ�.
	*
	*	\param	s[in]	���
	*
	*	\return ����� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgMat &operator *=(const double &s);

	/*!
	*	\brief	����� ����� ������.
	*
	*	\param	s[in]	���
	*
	*	\return ����� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgMat &operator /=(const double &s);

	/*!
	*	\brief	+ ���� ������
	*
	*	\return ���Ϻ�ȣ�� ���� ��ü�� ��ȯ�Ѵ�.
	*/
	EgMat operator +() const;

	/*!
	*	\brief	- ���� ������
	*
	*	\return �ݴ��ȣ�� ���� ��ü�� ��ȯ�Ѵ�.
	*/
	EgMat operator -() const;

	/*!
	*	\brief	�ε��� ������([])
	*
	*	\param	idx[in]		���� �ε���
	*
	*	\return idx ���� �迭�� ���� �ּҸ� ��ȯ�Ѵ�.
	*/
	double *operator [](const int idx);

	/*!
	*	\brief	�����ü�� �ε��� ������([])
	*
	*	\param	idx[in]		���� �ε���
	*
	*	\return idx ���� �迭�� ���� �ּҸ� ��ȯ�Ѵ�.
	*/
	const double *operator [](const int idx) const;

	/*!
	*	\brief	�� ����� ���Ѵ�.
	*
	*	\param	A[in]	ù ��° ���
	*	\param	B[in]	�� ��° ���
	*
	*	\return �� ����� ���� ��ȯ�Ѵ�.
	*/
	friend EgMat operator +(const EgMat &A, const EgMat &B);

	/*!
	*	\brief	�� ����� ����.
	*
	*	\param	A[in]	ù ��° ���
	*	\param	B[in]	�� ��° ���
	*
	*	\return �� ����� ���� ��ȯ�Ѵ�.
	*/
	friend EgMat operator -(const EgMat &A, const EgMat &B);

	/*!
	*	\brief	�� ����� ���Ѵ�.
	*
	*	\param	A[in]	ù ��° ���
	*	\param	B[in]	�� ��° ���
	*
	*	\return �� ����� ���� ��ȯ�Ѵ�.
	*/
	friend EgMat operator *(const EgMat &A, const EgMat &B);

	/*!
	*	\brief	����� ����� �Ѵ�.
	*
	*	\param	M[in]	���
	*	\param	s[in]	���
	*
	*	\return ����� ����踦 ��ȯ�Ѵ�.
	*/
	friend EgMat operator *(const EgMat &M, const double &s);

	/*!
	*	\brief	����� ����� �Ѵ�.
	*
	*	\param	s[in]	���
	*	\param	M[in]	���
	*
	*	\return ����� ����踦 ��ȯ�Ѵ�.
	*/
	friend EgMat operator *(const double &s, const EgMat &M);

	/*!
	*	\brief	��İ� ������ ���� ���Ѵ�.
	*
	*	\param	M[in]	���
	*	\param	v[in]	����
	*
	*	\return ��İ� ������ ��(����)�� ��ȯ�Ѵ�.
	*/
	friend EgVec operator *(const EgMat &M, const EgVec &v);

	/*!
	*	\brief	���Ϳ� ����� ���Ѵ�.
	*
	*	\param	v[in]	n by 1 ����
	*	\param	M[in]	1 by m ���
	*
	*	\return ���Ϳ� ����� ��(���)�� ��ȯ�Ѵ�.
	*/
	friend EgMat operator *(const EgVec &v, const EgMat &M);

	/*!
	*	\brief	����� ����� ������.
	*
	*	\param	M[in]	���
	*	\param	s[in]	���
	*
	*	\return ����� ����� ��ȯ�Ѵ�.
	*/
	friend EgMat operator /(const EgMat &A, const double &s);

	/*!
	*	\brief	�� ����� ������ �˻��Ѵ�.
	*
	*	\param	A[in]	���� ���
	*	\param	B[in]	������ ���
	*
	*	\return �� ����� ������ true, �ٸ��� false�� ��ȯ�Ѵ�.
	*/
	friend bool operator ==(const EgMat &A, const EgMat &B);

	/*!
	*	\brief	�� ����� �ٸ��� �˻��Ѵ�.
	*
	*	\param	A[in]	���� �ǿ�����
	*	\param	B[in]	������ �ǿ�����
	*
	*	\return �� ����� �ٸ��� true, ������ false�� ��ȯ�Ѵ�.
	*/
	friend bool operator !=(const EgMat &A, const EgMat &B);

	/*!
	*	\brief	��� ������(<<)
	*
	*	\param	os[out]	��� ��Ʈ��
	*	\param	M[in]	����� ���
	*
	*	\return ��µ� ��Ʈ�� ��ü�� ��ȯ�Ѵ�.
	*/
	friend std::ostream &operator <<(std::ostream &os, const EgMat &m);
};

/*!
*	\class	EgQuat
*	\brief	���ʹϿ� (q = W + iX + jY + kZ)�� ǥ���ϴ� Ŭ����
*
*	\author ������(shyun@dongguk.edu)
*	\date	01 Jan 2001
*/
enum TypeEuler
{
	EULER_XYZ = 0,
	EULER_ZYX = 1,
};
enum TypeArcBall
{
	ARCBALL_FREE = 0,
	ARCBALL_X,
	ARCBALL_Y,
	ARCBALL_Z
};
class EgQuat
{
public:
	/*! \brief ���ʹϿ��� �Ǽ��� */
	double m_W;

	/*! \brief ���ʹϿ��� i ����� */
	double m_X;

	/*! \brief ���ʹϿ��� j ����� */
	double m_Y;

	/*! \brief ���ʹϿ��� k ����� */
	double m_Z;

public:
	/*!
	*	\brief	������
	*
	*	\param	w[in]	�Ǽ���
	*	\param	x[in]	i �����
	*	\param	y[in]	j �����
	*	\param	z[in]	k �����
	*/
	EgQuat(double w = 1.0, double x = 0.0, double y = 0.0, double z = 0.0);

	/*!
	*	\brief	���� ������
	*
	*	\param	cpy[in]	����� ��ü
	*/
	EgQuat(const EgQuat &cpy);

	/*!
	*	\brief	������
	*
	*	\param	q[in]	������ ���ʹϿ��� ���Ҹ� ������ �迭
	*/
	EgQuat(const double *q);

	/*!
	*	\brief	ȸ���ฦ �߽����� ȸ���ϴ� �������ʹϿ��� �����Ѵ�.
	*
	*	\param	axis[in]	ȸ����
	*	\param	theta[in]	ȸ������
	*	\param	radian[in]	ȸ�������� �����̸� true, �ƴϸ� false
	*/
	EgQuat(EgVec3 axis, double theta, bool radian = false);

	/*!
	*	\brief	���Ϸ� ��(degree) �̿��Ͽ� ���ʹϿ��� �����Ѵ�.
	*
	*	\param	theta1[in]		ù ��°�࿡ ���� ȸ������(degree)
	*	\param	theta2[in]		�� ��°�࿡ ���� ȸ������(degree)
	*	\param	theta3[in]		�� ��°�࿡ ���� ȸ������(degree)
	*	\param	eulerType[in]	���Ϸ� �� Ÿ��(XYZ = RxRyRz, ZYX = RzRyRx, ...)
	*/
	EgQuat(double theta1, double theta2, double theta3, TypeEuler eulerType = EULER_XYZ);

	/*!
	*	\brief	������
	*
	*	\param	axis0[in]		ù ��° �� ����
	*	\param	axis1[in]		�� ��° �� ����
	*	\param	axis_type[in]	�Է� �� ������ ����(0: xy��, 1: yz��, 2: zx��)
	*/
	EgQuat(EgVec3 axis0, EgVec3 axis1, int axis_type);

	/*!
	*	\brief	�Ҹ���
	*/
	~EgQuat();

	/*!
	*	\brief	�Ǽ��ο� ������� ���� �����Ѵ�.
	*
	*	\param	w[in]	���ʹϿ��� �Ǽ���
	*	\param	x[in]	���ʹϿ��� i �����
	*	\param	y[in]	���ʹϿ��� j �����
	*	\param	z[in]	���ʹϿ��� k �����
	*
	*	\return	������ �ڽ��� ��ȯ�Ѵ�.
	*/
	EgQuat &Set(double w, double x, double y, double z);

	/*!
	*	\brief	�Ǽ��ο� ������� ���� �����Ѵ�.
	*
	*	\param	q[in]			������ ���� �迭
	*	\param	invOrder[in]	true: (w, x, y, z) = (q[3], q[0], q[1], q[2]), false: (w, x, y, z) = (q[0], q[1], q[2], q[3])
	*
	*	\return	������ �ڽ��� ��ȯ�Ѵ�.
	*/
	EgQuat &Set(double *q, bool invOrder = false);

	/*!
	*	\brief	ȸ������ �߽����� �Է°��� ��ŭ ȸ���ϴ� ���ʹϿ��� �����Ѵ�.
	*
	*	\param	theta[in]	�Է°���
	*	\param	axis[in]	ȸ����
	*	\param	radian[in]	�Է°����� �����̸� true, �ƴϸ� false
	*
	*	\return ������ �ڽ��� �����Ѵ�.
	*/
	EgQuat &SetFromAngleAxis(const double theta, EgVec3 axis, bool radian = false);

	/*!
	*	\brief	��ũ�� ���� �� p�� �� q�� ȸ���ϴ� ���ʹϿ��� �����Ѵ�.
	*
	*	\param	p[in]		��ũ�� ���� ��
	*	\param	q[in]		��ũ�� ���� ��
	*	\param	arcType[in]	��ũ���� Ÿ��
	*
	*	\return ������ �ڽ��� �����Ѵ�.
	*/
	EgQuat &SetFromArcBall(EgVec3 p, EgVec3 q, TypeArcBall arcType = ARCBALL_FREE);

	/*!
	*	\brief	���Ϸ� ��(degree) �̿��Ͽ� ���ʹϿ��� �����Ѵ�.
	*
	*	\param	theta1[in]		ù ��°�࿡ ���� ȸ������(degree)
	*	\param	theta2[in]		�� ��°�࿡ ���� ȸ������(degree)
	*	\param	theta3[in]		�� ��°�࿡ ���� ȸ������(degree)
	*	\param	eulerType[in]	���Ϸ���(XYZ = RxRyRz, ZYX = RzRyRx)
	*
	*	\return	������ �ڽ��� ��ȯ�Ѵ�.
	*/
	EgQuat &SetFromEulerAngle(double theta1, double theta2, double theta3, TypeEuler eulerType = EULER_XYZ);

	/*!
	*	\brief	��ǥ���� �� ������ ���ʹϿ��� �����Ѵ�.
	*
	*	\param	x_axis[in]	��ǥ���� x ��
	*	\param	y_axis[in]	��ǥ���� y ��
	*
	*	\return ������ �ڽ��� ��ȯ�Ѵ�.
	*/
	EgQuat &SetFromFrameXY(const EgVec3 &x_axis, const EgVec3 &y_axis);

	/*!
	*	\brief	��ǥ���� �� ������ ���ʹϿ��� �����Ѵ�.
	*
	*	\param	y_axis[in]	��ǥ���� y ��
	*	\param	z_axis[in]	��ǥ���� z ��
	*
	*	\return ������ �ڽ��� ��ȯ�Ѵ�.
	*/
	EgQuat &SetFromFrameYZ(const EgVec3 &y_axis, const EgVec3 &z_axis);

	/*!
	*	\brief	��ǥ���� �� ������ ���ʹϿ��� �����Ѵ�.
	*
	*	\param	z_axis[in]	��ǥ���� z ��
	*	\param	x_axis[in]	��ǥ���� x ��
	*
	*	\return ������ �ڽ��� ��ȯ�Ѵ�.
	*/
	EgQuat &SetFromFrameZX(const EgVec3 &z_axis, const EgVec3 &x_axis);

	/*!
	*	\brief	ȸ�� ��ķ� ���ʹϿ��� �����Ѵ�.
	*
	*	\param	mat[in]		4 by 4 ��ȯ����� ǥ���ϴ� �迭
	*	\parma	isGL[in]	OpenGL�� ��ȯ����̸� true, �ƴϸ� false
	*
	*	\return ������ �ڽ��� ��ȯ�Ѵ�.
	*/
	EgQuat &SetFromMatrix(double *mat, bool isGL);

	/*!
	*	\brief	���ʹϿ��� �׵������ �����Ѵ�.
	*
	*	\return ������ �ڽ��� ��ȯ�Ѵ�.
	*/
	EgQuat &SetIdentity();

	/*!
	*	\brief	���ʹϿ��� �������� �����Ѵ�.
	*
	*	\return ������ �ڽ��� ��ȯ�Ѵ�.
	*/
	EgQuat &SetInverse();

	/*!
	*	\brief	���ʹϿ��� conjugate �Ѵ�.
	*
	*	\return ������ �ڽ��� ��ȯ�Ѵ�.
	*/
	EgQuat &SetConjugate();

	/*!
	*	\brief	���ʹϿ��� negate �Ѵ�.
	*
	*	\return ������ �ڽ��� ��ȯ�Ѵ�.
	*/
	EgQuat &SetNegate();

	/*!
	*	\brief	���ʹϿ��� ���� ���ʹϿ����� �����Ѵ�.
	*
	*	\return ������ �ڽ��� ��ȯ�Ѵ�.
	*/
	EgQuat &Normalize();

	/*!
	*	\brief	���� ȸ����� ȸ������ ���Ѵ�.
	*
	*	\param	axis[out]	���� ȸ������ �����
	*	\param	angle[out]	ȸ������ �����
	*	\param	radian[in]	ȸ������ �������� ���Ϸ��� true, �ƴϸ� false
	*/
	void	GetAngleAxis(EgVec3 &axis, double &angle, bool radian = false) const;

	/*!
	*	\brief	ȸ���� ���Ϸ� ǥ���� ���Ѵ�.
	*
	*	\param	theta1[out]		ù ��° ȸ������ ������ �����
	*	\param	theta2[out]		�� ��° ȸ������ ������ �����
	*	\param	theta3[out]		�� ��° ȸ������ ������ �����
	*	\param	radian[in]		����Ǵ� ȸ������ �����̸� true, �ƴϸ� false
	*	\param	eulerType[in]	ȸ������ ����(EULER_XYZ �Ǵ� EULER_ZYX)
	*/
	void	GetEulerAngle(double &theta1, double &theta2, double &theta3, bool radian = false, TypeEuler eulerType = EULER_XYZ);

	/*!
	*	\brief	���� ���ʹϿ� ���θ� �����Ѵ�.
	*
	*	\return ���� ���ʹϿ��̸� true �ƴϸ� false�� ��ȯ�Ѵ�.
	*/
	bool	IsUnitQuater() const;

	/*!
	*	\brief	���� ���ʹϿ��� �׵������ ���θ� �����Ѵ�.
	*
	*	\return �׵���̸� true, �ƴϸ� false�� ��ȯ�Ѵ�.
	*/
	bool	IsIdentity() const;

	/*!
	*	\brief	���ʹϿ��� W ������ ��ȯ�Ѵ�.
	*
	*	\return ���ʹϿ��� W ������ ��ȯ�Ѵ�.
	*/
	double	W() const;

	/*!
	*	\brief	���ʹϿ��� X ������ ��ȯ�Ѵ�.
	*
	*	\return ���ʹϿ��� X ������ ��ȯ�Ѵ�.
	*/
	double	X() const;

	/*!
	*	\brief	���ʹϿ��� Y ������ ��ȯ�Ѵ�.
	*
	*	\return ���ʹϿ��� Y ������ ��ȯ�Ѵ�.
	*/
	double	Y() const;

	/*!
	*	\brief	���ʹϿ��� Z ������ ��ȯ�Ѵ�.
	*
	*	\return ���ʹϿ��� Z ������ ��ȯ�Ѵ�.
	*/
	double	Z() const;	

	/*!
	*	\brief	���� ������
	*
	*	\param	rhs[in]		���Ե� ��ü
	*
	*	\return ���Ե� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgQuat &operator =(const EgQuat &rhs);

	/*!
	*	\brief	���ʹϿ��� ���Ѵ�.
	*
	*	\param	rhs[in]		���� ��ü
	*
	*	\return ������ ���Ե� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgQuat &operator +=(const EgQuat &rhs);

	/*!
	*	\brief	���ʹϿ��� ����.
	*
	*	\param	rhs[in]		�� ��ü
	*
	*	\return ������ ���Ե� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgQuat &operator -=(const EgQuat &rhs);

	/*!
	*	\brief	���ʹϿ��� ���Ѵ�.
	*
	*	\param	rhs[in]		���� ��ü
	*
	*	\return	������ �ڽ��� ��ȯ�Ѵ�.
	*/
	EgQuat &operator *=(const EgQuat &rhs);

	/*!
	*	\brief	����� �Ѵ�.
	*
	*	\param	s[in]	���
	*
	*	\return ����� �� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgQuat &operator *=(const double s);

	/*!
	*	\brief	����� ������.
	*
	*	\param	s[in]	���
	*
	*	\return ����� �������� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgQuat &operator /=(const double s);

	/*!
	*	\brief	+ ���� ������
	*
	*	\return ���� ��ȣ�� ��ü�� ��ȯ�Ѵ�.
	*/
	EgQuat operator +() const;

	/*!
	*	\brief	- ���� ������
	*
	*	\return �ݴ� ��ȣ�� ��ü�� ��ȯ�Ѵ�.
	*/
	EgQuat operator -() const;

	/*!
	*	\brief	�� ���ʹϿ��� ���Ѵ�.
	*
	*	\param	q1[in]	ù ��° ���ʹϿ�
	*	\param	q2[in]	�� ��° ���ʹϿ�
	*
	*	\return �� ���ʹϿ��� ���� ��ȯ�Ѵ�.
	*/
	friend EgQuat operator +(const EgQuat &q1, const EgQuat &q2);

	/*!
	*	\brief	�� ���ʹϿ��� ���� ���Ѵ�.
	*
	*	\param	q1[in]	ù ��° ���ʹϿ�
	*	\param	q2[in]	�� ��° ���ʹϿ�
	*
	*	\return �� ���ʹϿ��� ���� ��ȯ�Ѵ�.
	*/
	friend EgQuat operator -(const EgQuat &q1, const EgQuat &q2);

	/*!
	*	\brief	�� ���ʹϿ��� ���Ѵ�.
	*
	*	\param	q1[in]	ù ��° ���ʹϿ�
	*	\param	q2[in]	�� ��° ���ʹϿ�
	*
	*	\return �� ���ʹϿ��� ���� ��ȯ�Ѵ�.
	*/
	friend EgQuat operator *(const EgQuat &q1, const EgQuat &q2);

	/*!
	*	\brief	ȸ���� ���͸� ����Ѵ�
	*	\note	���� ���ʹϿ��� �������ʹϿ��̾�� ��
	*
	*	\param	q[in]	���ʹϿ�
	*	\param	v[in]	ȸ����ų ����
	*
	*	\return ȸ���� ���͸� ��ȯ�Ѵ�.
	*/
	friend EgPos operator *(const EgQuat &q, const EgPos &p);

	/*!
	*	\brief	ȸ���� ���� ��ġ�� ����Ѵ�
	*	\note	���� ���ʹϿ��� �������ʹϿ��̾�� ��
	*
	*	\param	q[in]	���ʹϿ�
	*	\param	p[in]	ȸ����ų ���� ��ġ
	*
	*	\return ȸ���� ���͸� ��ȯ�Ѵ�.
	*/
	friend EgVec3 operator *(const EgQuat &q, const EgVec3 &v);

	/*!
	*	\brief	���ʹϿ��� ����� �Ѵ�.
	*
	*	\param	q[in]	���ʹϿ�
	*	\param	s[in]	���
	*
	*	\return ���ʹϿ��� ����踦 ��ȯ�Ѵ�.
	*/
	friend EgQuat operator *(const EgQuat &q, const double &s);

	/*!
	*	\brief	���ʹϿ��� ����� �Ѵ�.
	*
	*	\param	s[in]	���
	*	\param	q[in]	���ʹϿ�
	*
	*	\return ���ʹϿ��� ����踦 ��ȯ�Ѵ�.
	*/
	friend EgQuat operator *(const double &s, const EgQuat &q);

	/*!
	*	\brief	���ʹϿ��� ����� ������.
	*
	*	\param	q[in]	���ʹϿ�
	*	\param	s[in]	���
	*
	*	\return ���� ����� ��ȯ�Ѵ�.
	*/
	friend EgQuat operator /(const EgQuat &q1, const double s);

	/*!
	*	\brief	��ȣ������(==)
	*
	*	\param	q1[in]	���� �ǿ�����
	*	\param	q2[in]	������ �ǿ�����
	*
	*	\return �� ���ʹϿ��� ������ true, �ٸ��� false ��ȯ�Ѵ�.
	*/
	friend bool operator ==(const EgQuat &q1, const EgQuat &q2);

	/*!
	*	\brief	�ε�ȣ������(!=)
	*
	*	\param	q1[in]	���� �ǿ�����
	*	\param	q2[in]	������ �ǿ�����
	*
	*	\return �� ���ʹϿ��� �ٸ��� true, ������ false ��ȯ�Ѵ�.
	*/
	friend bool operator !=(const EgQuat &q1, const EgQuat &q2);

	/*!
	*	\brief	��� ������
	*
	*	\param	os[out]		��� ��Ʈ��
	*	\param	q[in]		����� ���ʹϿ�
	*
	*	\return ��µ� ��Ʈ���� ��ȯ�Ѵ�.
	*/
	friend std::ostream &operator <<(std::ostream &os, const EgQuat &q);

	/*!
	*	\brief	�Է� ������
	*
	*	\param	is[in]	�Է� ��Ʈ��
	*	\param	q[out]	�Է¹��� ���ʹϿ�
	*
	*	\return �Էµ� ��Ʈ���� ��ȯ�Ѵ�.
	*/
	friend std::istream &operator >>(std::istream &is, EgQuat &q);
};

/*!
*	\class	EgLine
*	\brief	3���� ������ ������ ��Ÿ���� Ŭ����
*
*	\author ������(shyun@dongguk.edu)
*	\date	01 Jan 2001
*/
class EgLine
{
public:
	/*! \brief ���� ���� �� �� */
	EgPos m_Pos;

	/*! \brief ������ ���� ���� l(t) = m_Pos + m_Dir * t */
	EgVec3 m_Dir;

public:
	/*!
	*	\brief	������
	*
	*	\param	Pos[in]		���� ���� �� ��
	*	\param	Dir[in]		������ ���� ����(���� ������ �ʿ� ����)
	*/
	EgLine(EgPos p = EgPos(0, 0, 0), EgVec3 v = EgVec3(0, 0, 0));

	/*!
	*	\brief	�� ���� ������ ������ �����ϴ� ������
	*
	*	\param	p[in]	���� ���� ��, l(0) = p
	*	\param	q[in]	���� ���� ��, l(1) = q
	*/
	EgLine(EgPos p, EgPos q);

	/*!
	*	\brief	���� ������
	*
	*	\param	cpy[in]		����� ��ü
	*/
	EgLine(EgLine &cpy);

	/*!
	*	\brief �Ҹ���
	*/
	~EgLine();	

	/*!
	*	\brief	���� ���� ���� ����Ѵ�.
	*
	*	\param	t[in]	�Ű�����
	*
	*	\return ���� ���� �� l(t)�� ��ȯ�Ѵ�.
	*/
	EgPos Eval(double t);

	/*!
	*	\brief	�� q�� ���� ���� ������ �����Ѵ�.
	*
	*	\param	q[in]	������ ��
	*
	*	\return �� q�� ���� ���� ���̸� true, �ƴϸ� false�� ��ȯ�Ѵ�.
	*/
	bool IsOnLine(EgPos &q);	

	/*!
	*	\brief	���� ������
	*
	*	\param	rhs[in]		������ ��ü
	*
	*	\return ���Ե� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgLine &operator =(const EgLine &rhs);

	/*!
	*	\brief	�� ������ ������ �����Ѵ�.
	*
	*	\param	lhs[in]		���� ����
	*	\param	rhs[in]		������ ����
	*
	*	\return ������ �����̸� true, �ƴϸ� false�� ��ȯ�Ѵ�.
	*/
	friend bool operator ==(EgLine &lhs, EgLine &rhs);

	/*!
	*	\brief	�� ������ �ٸ��� �����Ѵ�.
	*
	*	\param	lhs[in]		���� ����
	*	\param	rhs[in]		������ ����
	*
	*	\return �ٸ� �����̸� true, �ƴϸ� false�� ��ȯ�Ѵ�.
	*/
	friend bool operator !=(EgLine &lhs, EgLine &rhs);

	/*!
	*	\brief	��� ������
	*
	*	\param	os[out]		��� ��Ʈ��
	*	\param	l[in]		����� ��ü
	*
	*	\return ��µ� ��Ʈ���� ��ȯ�Ѵ�.
	*/
	friend std::ostream &operator <<(std::ostream &os, const EgLine &l);
};

/*!
*	\class	EgPlane
*	\brief	����� ǥ���ϴ� Ŭ����
*
*	\author ������(shyun@dongguk.edu)
*	\date	01 Jan 2001
*/
class EgPlane
{
public:
	/*! \brief ����� ������(ax + by + cz + d = 0)�� 4���� ������ǥ�� ǥ�� (a, b, c, d) */
	EgVec4 m_Coords;

public:
	/*!
	*	\brief	������
	*/
	EgPlane();

	/*!
	*	\brief	������
	*
	*	\param	n[in]	����� ��������
	*	\param	p[in]	��� ���� �� ��
	*/
	EgPlane(EgVec3 n, EgPos p);

	/*!
	*	\brief	�� �� p1, p2, p3 �� ������ ����� ������
	*
	*	\param	p1[in]	��� ���� ù ��° ��
	*	\param	p2[in]	��� ���� �� ��° ��
	*	\param	p3[in]	��� ���� �� ��° ��
	*/
	EgPlane(const EgPos &p1, const EgPos &p2, const EgPos &p3);

	/*!
	*	\brief	������
	*
	*	\param	a[in]	����� �������� ���
	*	\param	b[in]	����� �������� ���
	*	\param	c[in]	����� �������� ���
	*	\param	d[in]	����� �������� ���
	*/
	EgPlane(double a, double b, double c, double d);

	/*!
	*	\brief	���� ������
	*
	*	\param	cpy[in]		����� ��ü
	*/
	EgPlane(const EgPlane &cpy);

	/*!
	*	\brief �Ҹ���
	*/
	~EgPlane();

	/*!
	*	\brief	����� �Լ����� ����Ѵ�.
	*
	*	\param	p[in]	������ ��ǥ(x, y, z)
	*
	*	\return �Լ��� f(x, y, z) = ax + by + cz + d�� ��ȯ�Ѵ�.
	*/
	double Eval(EgPos p);

	/*!
	*	\brief	����� �����͸� ��ȯ�Ѵ�.
	*
	*	\param	bNormalize[in]	����ȭ ����
	*
	*	\return ����� �����͸� ��ȯ�Ѵ�.
	*/
	EgVec3 N(bool bNormalize = false);

	/*!
	*	\brief	����� ������(ax + by + cz + d = 0)�� ��� d�� ��ȯ�Ѵ�.
	*
	*	\return ����� ������(ax + by + cz + d = 0)�� ��� d�� ��ȯ�Ѵ�.
	*/
	double d();

	/*!
	*	\brief	���� ������ y ������ �ϴ� ������ ȸ���� ��ȯ�Ѵ�.
	*
	*	\return ���� ������ y ������ �ϴ� ������ ȸ���� ��ȯ�Ѵ�.
	*/
	EgQuat Rot();

	/*!
	*	\brief	�� p�� ��鿡 ���� �� ������ �����Ѵ�.
	*
	*	\param	p[in]		������ ��
	*	\param	eps[in]		������ ��� ����
	*
	*	\return �� p�� ��鿡 ���� ���̸� true, �ƴϸ� false�� ��ȯ�Ѵ�.
	*/
	bool IsOnPlane(const EgPos &p, double eps = 1.0e-14);

	/*!
	*	\brief	�� p�� ����� ���� �������� �����Ѵ�.
	*
	*	\param	p[in]		������ ��
	*	\param	eps[in]		������ ��� ����
	*
	*	\return �� p�� ����� ���� �� �ϰ�� true, �ƴϸ� false�� ��ȯ�Ѵ�.
	*/
	bool IsAbovePlane(const EgPos &p, double eps = 1.0e-14);

	/*!
	*	\brief	�� p�� ����� �Ʒ��� �������� �����Ѵ�.
	*
	*	\param	p[in]		������ ��
	*	\param	eps[in]		������ ��� ����
	*
	*	\return �� p�� ����� �Ʒ��� �� �ϰ�� true, �ƴϸ� false�� ��ȯ�Ѵ�.
	*/
	bool IsBelowPlane(const EgPos &p, double eps = 1.0e-14);

	/*!
	*	\brief	������ �ݴ��� ����� ��ȯ�Ѵ�.
	*
	*	\return ������ �ݴ��� ����� ��ȯ�Ѵ�.
	*/
	EgPlane GetReversePlane();

	/*!
	*	\brief	���� ������
	*
	*	\param	rhs[in]		���Ե� ��ü
	*
	*	\return ���Ե� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgPlane &operator =(const EgPlane &rhs);

	/*!
	*	\brief	�� ����� ������ �����Ѵ�.
	*
	*	\param	lhs[in]		ù ��° ���
	*	\param	rhs[in]		�� ��° ���
	*
	*	\return �� ����� ������ true, �ٸ��� false�� ��ȯ�Ѵ�.
	*/
	friend bool operator ==(const EgPlane &lhs, const EgPlane &rhs);

	/*!
	*	\brief	�� ����� �ٸ��� �����Ѵ�.
	*
	*	\param	lhs[in]		ù ��° ���
	*	\param	rhs[in]		�� ��° ���
	*
	*	\return �� ����� �ٸ��� true, ������ false�� ��ȯ�Ѵ�.
	*/
	friend bool operator !=(const EgPlane &lhs, const EgPlane &rhs);

	/*!
	*	\brief	��� ������
	*
	*	\param	os[out]		��� ��Ʈ��
	*	\param	pi[in]		��� ���
	*
	*	\return ��� ��Ʈ���� ��ȯ�Ѵ�.
	*/
	friend std::ostream &operator <<(std::ostream &os, const EgPlane &pi);
};

/*!
*	\class	EgTrans
*	\brief	��ü��ȯ(rigid-body transformation)�� ��Ÿ���� Ŭ����.
*
*	\author ������(shyun@dongguk.edu)
*	\date	2001�� 1�� 1��.
*/
class EgTrans
{
public:
	/*! \brief 3���� �̵���ȯ */
	EgVec3 m_T;

	/*! \brief 3���� ȸ����ȯ */
	EgQuat m_Q;

public:
	/*!
	*	\brief	������
	*
	*	\param	t[in]	�̵� ����
	*	\param	q[in]	ȸ�� ����
	*/
	EgTrans(const EgVec3 &t = EgVec3(0.0, 0.0, 0.0), const EgQuat &q = EgQuat(1.0, 0.0, 0.0, 0.0));

	/*!
	*	\brief	������
	*
	*	\param	mat[in]		��ȯ ���(4 X 4)
	*	\param	isGL[in]	��ȯ ����� OpenGL ����(row major) ����
	*/
	EgTrans(double *mat, bool isGL);

	/*!
	*	\brief	���� ������
	*
	*	\param	cpy[in]		����� ��ü
	*/
	EgTrans(const EgTrans &cpy);

	/*!
	*	\brief �Ҹ���
	*/
	~EgTrans();

	/*!
	*	\brief	ȸ���� negate�Ѵ�.
	*/
	void SetNegate();

	/*!
	*	\brief	�̵� ��ȯ�� �����Ѵ�.
	*
	*	\param	t[in] ������ �̵� ��ȯ
	*/
	void SetTrans(const EgVec3 &t);

	/*!
	*	\brief	ȸ�� ��ȯ�� �����Ѵ�.
	*
	*	\param	q[in] ������ ȸ�� ��ȯ
	*/
	void SetRot(const EgQuat &q);

	/*!
	*	\brief	���� ������
	*
	*	\param	rhs[in]		���Ե� ��ü
	*
	*	\return ����� �ڽ��� ��ȯ�Ѵ�.
	*/
	EgTrans &operator =(const EgTrans &rhs);

	/*!
	*	\brief	��ȯ�� ���Ѵ�.
	*
	*	\param	rhs[in]		������ ��ȯ
	*
	*	\return ������ �ڽ��� ��ȯ�Ѵ�.
	*/
	EgTrans &operator *=(const EgTrans &rhs);

	/*!
	*	\brief	�� ��ȯ�� ���Ѵ�.
	*
	*	\param	X1[in]	ù ��° ��ȯ
	*	\param	X2[in]	�� ��° ��ȯ
	*
	*	\return ���� ����� ��ȯ�Ѵ�.
	*/
	friend EgTrans operator *(const EgTrans &X1, const EgTrans &X2);

	/*!
	*	\brief	��ȯ�� ���� ���Ѵ�.
	*
	*	\param	X[in]	��ȯ ��ü
	*	\param	p[in]	��� ��
	*
	*	\return ���� ��ǥ�迡�� ǥ���� �� p�� ��ǥ�� ��ȯ�Ѵ�.
	*/
	friend EgPos operator *(const EgTrans &X, const EgPos &p);

	/*!
	*	\brief	��ȯ�� ���͸� ���Ѵ�.
	*
	*	\param	X[in]	��ȯ ��ü
	*	\param	v[in]	��� ����
	*
	*	\return ���� ��ǥ�迡�� ǥ���� ���� v�� ��ǥ�� ��ȯ�Ѵ�.
	*/
	friend EgVec3 operator *(const EgTrans &X, const EgVec3 &v);

	/*!
	*	\brief	��ȯ�� ������ ���Ѵ�.
	*
	*	\param	X[in]	��ȯ ��ü
	*	\param	l[in]	��� ����
	*
	*	\return ���� ��ǥ�迡�� ǥ���� ���� l�� ǥ���� ��ȯ�Ѵ�.
	*/
	friend EgLine operator *(const EgTrans &X, const EgLine &l);

	/*!
	*	\brief	��ȯ�� ����� ���Ѵ�.
	*
	*	\param	X[in]	��ȯ ��ü
	*	\param	pi[in]	��� ���
	*
	*	\return ���� ��ǥ�迡�� ǥ���� ��� pi�� ��ȯ�Ѵ�.
	*/
	friend EgPlane operator *(EgTrans &X, EgPlane &pi);

	/*!
	*	\brief	�� ��ȯ�� ������ �����Ѵ�.
	*
	*	\param	X1[in]	ù ��° ��ȯ
	*	\param	X2[in]	�� ��° ��ȯ
	*
	*	\return �� ��ȯ�� ������ true, �ٸ��� false�� ��ȯ�Ѵ�.
	*/
	friend bool operator ==(const EgTrans &X1, const EgTrans &X2);

	/*!
	*	\brief	�� ��ȯ�� �ٸ��� �����Ѵ�.
	*
	*	\param	X1[in]	ù ��° ��ȯ
	*	\param	X2[in]	�� ��° ��ȯ
	*
	*	\return �� ��ȯ�� �ٸ��� true, ������ false�� ��ȯ�Ѵ�.
	*/
	friend bool operator !=(const EgTrans &X1, const EgTrans &X2);

	/*!
	*	\brief	��� ������
	*
	*	\param	os[out]		��� ��Ʈ��
	*	\param	X[in]		��� ��ȯ
	*
	*	\return ��µ� ��Ʈ���� ��ȯ�Ѵ�.
	*/
	friend std::ostream &operator <<(std::ostream &os, const EgTrans &X);
};


