//CComplex.cpp
#include "CComplex.h"
#include <cmath>
#include <iostream>
using namespace std;

//复制构造函数
CComplex::CComplex(const CComplex &another)
{
	this->real = another.real;
	this->image = another.image;
}

//重置实部和虚部
void CComplex::setReal(double real)
{
	this->real = real;
}
void CComplex::setImage(double image)
{
	this->image = image;
}

//算数运算符重载
CComplex CComplex::operator+(const CComplex &another)
{
	return CComplex(this->real + another.real, this->image + another.image);
}
CComplex CComplex::operator-(const CComplex &another)
{
	return CComplex(this->real - another.real, this->image - another.image);
}
CComplex CComplex::operator*(const CComplex &another)
{
	double a = this->real;
	double b = this->image;
	double c = another.real;
	double d = another.image;
	return CComplex(a * c - b * d, a * d - b * c);
}
CComplex CComplex::operator/(const CComplex &another)
{
	double a = this->real;
	double b = this->image;
	double c = another.real;
	double d = another.image;
	double a1 = a * c + b * d;
	double a2 = b * c - a * d;
	double b0 = c * c + d * d;
	if (b0 <= 1e-6)
	{
		cout << "复数不合法，返回(-1,-1)" << endl;
		return CComplex(-1, -1);
	}
	return CComplex(a1 / b0, a2 / b0);
}

//比较运算符重载
bool CComplex::operator>(const CComplex &another) const
{
	double a = real * real + image * image;
	double b = another.real * another.real + another.image * another.image;

	if (a > b)
		return true;
	else
		return false;
}
bool CComplex::operator<(const CComplex &another) const
{
	return !CComplex::operator>(another);
}
bool CComplex::operator==(const CComplex &another) const
{
	if (fabs(this->real - another.real) < 1e-6 && fabs(this->image - another.image) < 1e-6)
		return true;
	else
		return false;
}
bool CComplex::operator!=(const CComplex &another) const
{
	return !operator==(another);
}

//
void CComplex::showComplex()
{
	cout << this->real << "+" << this->image << "i";
	cout << endl;
}