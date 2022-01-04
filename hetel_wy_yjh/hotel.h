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

int RoomNumber = 100;//����Ŵ�101��ʼ

#define BASICPRICE 100
#define BIGPRICE   100


class room
{
	//static int count;
private:
	int roomnumber;//����� ��101-..
	int roomtype;//����۸�
	int price;//����۸�
	int start_date;//��ʼס������
	int end_date;//��������
	bool order;//�Ƿ�Ԥ�� 0��û��Ԥ�� 1�Ǳ�Ԥ��
	string name;//��ס�˵�����
	string ID;//��ס�˵����֤��
	string phone;//��ס�˵��ֻ���
public:
	/*
	һЩ�ⲿAPI ��������֮��ĵط���ö����һЩ��Ϣ
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
	friend ostream& operator <<(ostream& os, const room* u)//���������
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