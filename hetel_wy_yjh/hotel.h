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

int RoomNumber = 100;//����Ŵ�101��ʼ

#define BASICPRICE 100
#define BIGPRICE   100

/*
һ��Сtips������������������������������ڵ�˽�г�Ա 
1.���ȵ�һ�ַ�������������������õ��Ǹ�����Ϊ�������Ԫ����
2.���� ����������public����protected����ʽ�������������������ں����е������˽�г�Ա������ֱ�����ⲿ���øú����Ϳ���ֱ��ʹ�� �൱��ֱ�Ӷ�����һ���ⲿAPI	
protected�İ�ȫ�Ը���һЩ����ʹ�÷�Χ���� �����ڱ��ݻ�������������Ԫ���� ��public����������
*/

class room//����Ļ���
{
	//static int count;
private:
	int roomnumber;//����� ��101-..
	int roomtype;//��������
	int price;//����۸�
	int start_date;//��ʼס������
	int end_date;//��������
	bool order;//�Ƿ�Ԥ�� 0��û��Ԥ�� 1�Ǳ�Ԥ��
	bool Ifenter;//�Ƿ���ס 0��û��ס 1����ס
	string name;//��ס�˵�����
	string ID;//��ס�˵����֤��
	string phone;//��ס�˵��ֻ���
public:
	/*
	һЩ�ⲿAPI ��������֮��ĵط���ö����һЩ��Ϣ
	*/

	void getnumber(int _number)//����÷���ķ���
	{
		roomnumber = _number;
	}
	int returnnumber() const//���ط����
	{
		return roomnumber;
	}
	void getroomtype(int _type)//����÷���ķ���
	{
		roomtype = _type;
	}
	int returnroomtype() const//���ط����
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
		cout << "����ţ�" << roomnumber << endl;
		cout << "����۸�" << price << endl;
		cout << "���俪ʼ���ڣ�" << start_date << endl;
		cout << "����������ڣ�" << end_date << endl;
		cout << "�����Ƿ�Ԥ����" ;
		if (order == true)
		{
			cout << "�ѱ�Ԥ��" << endl;
		}
		else
		{
			cout << "δ��Ԥ��" << endl;
		}
		cout << "��ס���Ƿ��Ѿ���ס��" ;
		if (Ifenter == true)
		{
			cout << "�Ѿ���ס" << endl;
		}
		else
		{
			cout << "��δ��ס" << endl;
		}
		cout << "��ס��������" << name << endl;
		cout << "��ס��ID��" << ID << endl;
		cout << "��ס����ϵ�绰��" << phone << endl;

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
	room(int _roomtype)//��ʼ��������Ϣ(����˵����������)
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
		name = "0";//��ϢΪ0��ʾ��ʼ����δ����ʹ��
		ID = "0";
		phone = "0";
	}
	room() {};
};

void AddRoom(list<room> &listhotel);//���ӷ���
void AddToFile(list<room>List, const string& filename);//�ѷ�����Ϣȫ��д���ļ���
list<room>& read(list<room>&List, const string& filename);//���ļ��е���Ϣ�����ڴ�
list<room>& book(list<room>&List, const string& filename);//userԤ������
list<room>& checkout(list<room>&List);//�˷�
list<room>& checkin(list<room>&List);//user��ס����
void ShowInfo(list<room>&List, string str);//����str��������nameҲ������phoneҲ������ID��
void ShowInfo(list<room>&List, int Room_info_int);//����str��������nameҲ������phoneҲ������ID��
void ShowInfo(list<room>&List, bool Room_info_bool);//����str��������nameҲ������phoneҲ������ID��
int check(int a[], int size, int suspicion);//�жϷ���������Ƿ�Ϸ�

void queryMenu(list<room>&List);//��ѯ���˵�
void queryMenu1(list<room>&List);
void queryMenu2(list<room>&List);

void showALL(list<room>&List);//չʾ���з�����Ϣ