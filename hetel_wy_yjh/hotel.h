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
using namespace std;

int RoomNumber = 100;//房间号从101开始

#define BASICPRICE 100
#define BIGPRICE   100


class room
{
	//static int count;
private:
	int roomnumber;//房间号 从101-..
	int roomtype;//房间价格
	int price;//房间价格
	int start_date;//开始住的日期
	int end_date;//结束日期
	bool order;//是否被预定 0是没被预定 1是被预定
	string name;//入住人的姓名
	string ID;//入住人的身份证号
	string phone;//入住人的手机号
public:
	/*
	一些外部API 用来在类之外的地方获得对象的一些信息
	*/
	void getnumber(int _number)
	{
		roomnumber = _number;
	}
	int returnnumber() const
	{
		return roomnumber;
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
	room(int _roomtype)
	{
		roomnumber = ++RoomNumber;
		roomtype = _roomtype;
		if (roomtype == 0)
		{
			price = BASICPRICE;
		}
		else if (roomtype == 1)
		{
			price = BIGPRICE;
		}
		order = 0;
		name = "0";
		ID = "0";
		phone = "0";
	}
	room() {};
};

void AddRoom(list<room> &listhotel);
void AddToFile(list<room>List, const string& filename);
list<room>& read(list<room>&List, const string& filename);
list<room>& CheckIn(list<room>&List, const string& filename);
int check(int a[], int size, int suspicion);