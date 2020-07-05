//CTime.cpp
#include "CTime.h"
#include <iostream>
using namespace std;

//设置时钟
void CTime::setHour(int hour)
{
	if (hour > 24 || hour < 0)
	{
		cout << "hour 不合法" << endl;
		return;
	}
	this->hour = hour;
}

//获得小时 
int CTime::getHour()
{
	return this->hour;
}

//设置分钟
void CTime::setMinute(int minute)
{
	if (minute < 0 || minute > 60)
	{
		cout << "minute 不合法" << endl;
		return;
	}
	this->minute = minute;
}

//获得分钟
int CTime::getMinute()
{
	return this->minute;
}

//设置秒钟
void CTime::setSecond(int second)
{
	if (second < 0 || second > 60)
	{
		cout << "second 秒钟不合法" << endl;
		return;
	}
	this->second = second;
}

//获得秒钟
int CTime::getSecond()
{
	return this->second;
}

//显示时间
void CTime::displayTime()
{
	cout << this->hour << ":" << this->minute << ":" << this->second << endl;
}

//比较运算符重载
bool CTime::operator>(const CTime &another) const
{
	if (this->hour > another.hour)
		return true;
	else if (this->hour == another.hour && this->minute > another.minute)
		return true;
	else if (this->hour == another.hour && this->minute == another.minute && this->second > another.second)
		return true;
	else
		return false;
}
bool CTime::operator<(const CTime &another) const
{
	if (this->hour < another.hour)
		return true;
	else if (this->hour == another.hour && this->minute < another.minute)
		return true;
	else if (this->hour == another.hour && this->minute == another.minute && this->second < another.second)
		return true;
	else
		return false;
}
bool CTime::operator==(const CTime &another) const
{
	if (this->hour == another.hour && this->minute == another.minute && this->second == another.second)
		return true;
	return false;
}

//算数运算符重载
CTime CTime::operator+(const CTime &another) //succ
{
	CTime tmp;
	int plus_Second = 0; //记录秒进位
	int time = 0;		 //记录进位后的值
	plus_Second = (this->second + another.second) / 60;
	time = (this->second + another.second) % 60;
	tmp.setSecond(time);
	int plus_Minute = 0; //记录分进位
	plus_Minute = (this->minute + another.minute + plus_Second) / 60;
	time = (this->minute + another.minute + plus_Second) % 60;
	tmp.setMinute(time);
	time = (this->hour + another.hour + plus_Minute) % 24;
	tmp.setHour(time);
	return tmp;
}
CTime CTime::operator-(const CTime &another)
{
	int time_All_1 = this->second + this->minute * 60 + this->hour * 60 * 60;		//记录本对象的总秒数
	int time_All_2 = another.second + another.minute * 60 + another.hour * 60 * 60; //记录another对象的总秒数
	int time = time_All_1 - time_All_2;
	if (time < 0)
		time = (time + 24 * 60 * 60);
	int hour = time / (60 * 60);
	int minute = (time - hour * 60 * 60) / 60;
	int second = (time - hour * 60 * 60 - minute * 60);
	CTime tmp;
	tmp.hour = hour;
	tmp.minute = minute;
	tmp.second = second;
	return tmp;
}

//自增或自减内重合功能实现
void CTime::addition_Function()
{
	if (second >= 60)
	{
		second -= 60;
		minute++;
		if (minute >= 60)
		{
			minute -= 60;
			hour++;
			if (hour >= 24)
				hour -= 24;
		}
	}
}

//前置++
CTime CTime::operator++()
{
	second++;
	addition_Function();
	return *this;
}

//后置++
CTime CTime::operator++(int)
{
	return operator++();
}

//前置--
CTime CTime::operator--()
{
	second--;
	addition_Function();
	return *this;
}

//后置--
CTime CTime::operator--(int)
{
	return operator--();
}

CTime CTime::operator+=(int n)
{
	second += n;
	addition_Function();
	return *this;
}

CTime CTime::operator-=(int n)
{
	second -= n;
	if (second < 0)
	{
		second += 60;
		minute--;
		if (minute < 60)
		{
			minute += 60;
			hour--;
			if (hour < 24)
				hour += 24;
		}
	}
	return *this;
}