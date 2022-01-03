#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<sstream>
#include<windows.h>
#include<stdexcept>  
#include<conio.h>

using namespace std;



#define BASICPRICE 100
#define BIGPRICE   100

class room
{
	static int count;
private:
	int roomnumber ;//房间号 从101-..
	int roomtype;//房间价格
	int price ;//房间价格
	int start_date ;//开始住的日期
	int end_date ;//结束日期
	bool order ;//是否被预定 0是没被预定 1是被预定
	string name;//入住人的姓名
	string ID;//入住人的身份证号
	string phone;//入住人的手机号
public:
	/*
	一些外部API 用来在类之外的地方获得对象的一些信息
	*/
	int returnnumber() const//返回房间号
	{
		return roomnumber;
	}
	int returnprice() const
	{
		return price;
	}
	int returnstartdate() const
	{
		return start_date;
	}
	int returnenddate() const
	{
		return end_date;
	}
	bool returnorder() const
	{
		return order;
	}
	string returnname() const
	{
		return name;
	}
	string returnID() const
	{
		return ID;
	}
	string returnphone() const
	{
		return phone;
	}
	int sumprice()
	{
		return price * (end_date - start_date);
	}
	friend ostream& operator<<(ostream& os, const room* u)//输出流重载
	{
		os << u->returnnumber() << '\n';
		os << u->returnprice() << '\n';
		os << u->returnstartdate() << '\n';
		os << u->returnenddate() << '\n';
		os << u->returnorder() << '\n';
		os << u->returnname() << '\n';
		os << u->returnID() << '\n';
		os << u->returnphone() << '\n';
		return os;
	}
	room(int _roomtype,int _price)
	{
		roomnumber = ++count;
		roomtype = _roomtype;
		if (roomtype == 0)
		{
			price = BASICPRICE;
		}
		else if (roomtype == 1)
		{
			price = BIGPRICE;
		}
		order = 0;//44
	}
}
static int room::count = 100;


int main()
{
	SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);//设置背景和字体颜色(句柄控制)
	cout << "Welcome to this hotel!.\n ";
	SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "if you want to quit safely ,please input 0. \n ";
	SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	cout << "if you want to check in, please input 1.\n ";
	SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
	cout << "if you want to depart, please input 2.\n";
	SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << "if you want to search for the information about any room,please input 3.\n";



}