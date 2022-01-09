#pragma once

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<sstream>
#include<windows.h>
#include<stdexcept>  
#include<conio.h>
#include<list>
#include <algorithm>

using namespace std;

int RoomNumber = 100;//房间号从101开始

#define BASICPRICE 100
#define BIGPRICE   100

/*
一个小tips：如果你想在类体外面调用你的类体内的私有成员 
1.首先第一种方法就是声明在外面调用的那个函数为该类的友元函数
2.或者 在类体中以public或者protected的形式在类体中声明函数，在函数中调用类的私有成员，这样直接在外部调用该函数就可以直接使用 相当于直接定义了一个外部API	
protected的安全性更好一些不过使用范围有限 不能在本垒或者派生或者友元外用 而public基本都可以
*/

class room//房间的基类
{
	//static int count;
private:
	int roomnumber;//房间号 从101-..
	int roomtype;//房间类型
	int price;//房间价格
	int start_date;//开始住的日期
	int end_date;//结束日期
	bool order;//是否被预定 0是没被预定 1是被预定
	bool Ifenter;//是否入住 0是没入住 1是入住
	string name;//入住人的姓名
	string ID;//入住人的身份证号
	string phone;//入住人的手机号
public:
	/*
	一些外部API 用来在类之外的地方获得对象的一些信息
	*/

	void getnumber(int _number)//输入该房间的房号
	{
		roomnumber = _number;
	}
	int returnnumber() const//返回房间号
	{
		return roomnumber;
	}
	void getroomtype(int _type)//输入该房间的房号
	{
		roomtype = _type;
	}
	int returnroomtype() const//返回房间号
	{
		return roomtype;
	}
	void getprice(int _price)
	{
		price = _price;
	}
	int returnprice() const
	{
		return price;
	}
	void getdate(int s, int e)
	{
		//if (s < 1 || s>31 || e < 1 || e>31 || s >= e) throw runtime_error("Invalid date!");
		start_date = s;
		end_date = e;
	}
	int returnstartdate() const
	{
		return start_date;
	}
	int returnenddate() const
	{
		return end_date;
	}
	void getorder(bool _order)
	{
	//	if (!(_order == 0 || _order == 1)) throw out_of_range("Room's state is error!");
		order = _order;
	}
	bool returnorder() const
	{
		return order;
	}
	void getIfenter(bool _Ifenter)
	{
		Ifenter = _Ifenter;
	}
	bool returnIfenter() const
	{
		return Ifenter;
	}
	void getname(string _name)
	{
		name = _name;
	}
	string returnname() const
	{
		return name;
	}
	void getID(string id)
	{
//		if (id.size() < 18 || id.size() > 19) throw runtime_error("Your ID is error! Please input correct ID!");
		ID = id;
	}
	string returnID() const
	{
		return ID;
	}
	void getphone(string ph)
	{
//		if (ph.size() != 11) throw runtime_error("Your mobilephone's number is error! Please input correct number!");
		phone = ph;
	}
	string returnphone() const
	{
		return phone;
	}
	void showInfo()
	{
		cout << "房间号：" << roomnumber << endl;
		cout << "房间价格：" << price << endl;
		cout << "房间开始日期：" << start_date << endl;
		cout << "房间结束日期：" << end_date << endl;
		cout << "房间是否被预定：" ;
		if (order == true)
		{
			cout << "已被预订" << endl;
		}
		else
		{
			cout << "未被预订" << endl;
		}
		cout << "入住人是否已经入住：" ;
		if (Ifenter == true)
		{
			cout << "已经入住" << endl;
		}
		else
		{
			cout << "仍未入住" << endl;
		}
		cout << "入住人姓名：" << name << endl;
		cout << "入住人ID：" << ID << endl;
		cout << "入住人联系电话：" << phone << endl;

	}
	int sumprice()
	{
		return price * (end_date - start_date);
	}
	friend ostream& operator <<(ostream& os, const room* u)//输出流重载
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
	room(int _roomtype)//初始化房间信息(必须说明房间类型)
	{
		roomnumber = ++RoomNumber;
		roomtype = _roomtype;
		if (roomtype == 1)
		{
			price = BASICPRICE;
		}
		else if (roomtype == 2)
		{
			price = BIGPRICE;
		}
		order = false;
		Ifenter = false;
		start_date = 0;
		end_date = 0;
		name = "0";//信息为0表示初始化后还未被仍使用
		ID = "0";
		phone = "0";
	}
	room() {};
};

void AddRoom(list<room> &listhotel);//增加房间
void AddToFile(list<room>List, const string& filename);//把房间信息全部写入文件中
list<room>& read(list<room>&List, const string& filename);//把文件中的信息读入内存
list<room>& book(list<room>&List, const string& filename);//user预定房间
list<room>& checkout(list<room>&List);//退房
list<room>& checkin(list<room>&List);//user入住房间
void ShowInfo(list<room>&List, string str);//根据str（可能是name也可以是phone也可以是ID）
void ShowInfo(list<room>&List, int Room_info_int);//根据str（可能是name也可以是phone也可以是ID）
void ShowInfo(list<room>&List, bool Room_info_bool);//根据str（可能是name也可以是phone也可以是ID）
int check(int a[], int size, int suspicion);//判断房间号输入是否合法

void queryMenu(list<room>&List);//查询主菜单
void queryMenu1(list<room>&List);
void queryMenu2(list<room>&List);

void showALL(list<room>&List);//展示所有房间信息