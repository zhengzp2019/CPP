//CComplex.h
#ifndef CCOMPLEX_H
#define CCOMPLEX_H
class CComplex {
public:
	CComplex() {//无参构造函数
		this->real = 0;
		this->image = 0;
	}
	CComplex(double real, double image) {//含参构造函数
		this->real = real;
		this->image = image;
	}
	CComplex(const CComplex &);//复制构造函数
	void setReal(double real);
	void setImage(double image);

    //复数运算符重载
	CComplex operator+(const CComplex &);
	CComplex operator-(const CComplex &);
	CComplex operator*(const CComplex &);
	CComplex operator/(const CComplex &);
	bool operator>(const CComplex &) const;
	bool operator<(const CComplex &) const;
	bool operator==(const CComplex &) const;
	bool operator!=(const CComplex &) const;
	void showComplex();//显示复数
private:
	double real;
	double image;
};
#endif//!CCOMPLEX_H