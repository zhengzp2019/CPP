//CTime.h
#ifndef CTIME_H
#define CTIME_H
class CTime{
public:
	CTime(){//无参构造函数
		hour = 0;
		minute = 0;
		second = 0;
	}
	void setHour(int);//设置小时
	int getHour();//获取小时
	void setMinute(int);//设置分钟
	int getMinute();//获取分钟
	void setSecond(int);//设置秒钟
	int getSecond();//获取秒钟
	void displayTime();//显示时间
	
    //时间运算符重载
	bool operator>(const CTime &) const;
	bool operator<(const CTime &) const;
	bool operator==(const CTime &) const;
	CTime operator+(const CTime &);
	CTime operator-(const CTime &);
	void addition_Function();//自增或自减内重合功能实现
	CTime operator++();//前置++
	CTime operator++(int);//后置++
	CTime operator--();//前置--
	CTime operator--(int);//后置--
	CTime operator+=(int);
	CTime operator-=(int);
private:
	int hour, minute, second;
};
#endif//!CTIME_H