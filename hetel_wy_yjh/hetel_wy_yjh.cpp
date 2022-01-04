#include"hotel.h"

int main()
{
	list<room> listhotel;
	//AddRoom(listhotel);
	//AddToFile(listhotel, "1.txt");
	listhotel=read(listhotel,"1.txt");
	listhotel = CheckIn(listhotel, "1.txt");

	//测试list
	list<room>::iterator i;
	for (i = listhotel.begin(); i != listhotel.end(); i++)
	{
		cout << i->returnnumber()<< endl;
	}
	system("pause");
	return 0;
}


void AddRoom(list<room> &listhotel)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//句柄
	SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);//设置背景和字体颜色(句柄控制)
	cout << "测试：先完成对酒店房间的创建\n ";

	list<room>::iterator i;
	int choice;
	cout << "请创建房间号为:" << RoomNumber + 1 << "的房间" << endl;
	cout << "请输入房间类型(输入0退出)" << endl;
	cin >> choice;//1标准房 2大床房 3双人床
	while (choice != 0)
	{
		//if (choice != 0 || choice != 1 || choice != 2 || choice != 3)
		//{
		//	throw out_of_range("Invalid type!!");
		//}
		room test1(choice);
		listhotel.push_back(test1);

		cout << "请创建房间号为:" << RoomNumber + 1 << "的房间" << endl;
		cout << "请输入房间类型(输入0退出)" << endl;
		cin >> choice;
	}
}

void AddToFile(list<room>List, const string& filename)
{
	list<room>::iterator i;
	ofstream os(filename, ios_base::binary);
	if (os)
	{
		for (i = List.begin(); i != List.end(); i++)
		{
			os << i->returnnumber() << '\n';
			os << i->returnprice() << '\n';
			os << i->returnstartdate() << '\n';
			os << i->returnenddate() << '\n';
			os << i->returnorder() << '\n';
			os << i->returnname() << '\n';
			os << i->returnID() << '\n';
			os << i->returnphone() << '\n';
		}
	}
	/*else
		throw file_exception(filename);*/
	os.close();

}

list<room>& read(list<room>&List, const string& filename)
{
	ifstream ifs;//构建输入流对象，以二进制形式打开，得到文件内容
	room temp;
	ifs.open(filename, ios_base::binary);

	while (!ifs.eof())
	{
		int roomnumber, price, start_date, end_date;
		bool order;
		string name;
		string ID;
		string phone;
		ifs >> roomnumber >> price >> start_date >> end_date >> order >> name >> ID >> phone;
		temp.getnumber(roomnumber);
		temp.getprice(price);
		temp.getdate(start_date, end_date);
		temp.getorder(order);
		temp.getname(name);
		temp.getID(ID);
		temp.getphone(phone);
		List.push_back(temp);
	}
	
	//cout << RoomNumber;
	//else
	//	throw file_exception(filename1);
	ifs.close();
	return List;
}

list<room>& CheckIn(list<room>&List, const string& filename)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//句柄
	cout.width(120);
	SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << "Welcome to this hotel!\nWe have standard room, suite room and kingsize room. \nThe reliable rooms are: " << endl;
	int vacant_room[100];//保存空闲房间房号的数组
	int j = 0;//遍历的数组下标
	list<room>::iterator i;
	int temp, temp1;//temp1保存临时找出来的空房间的房号
	string str;//临时存放用来输入的一些字符串 比如ID，name...
	for ( i = List.begin(); i != List.end(); i++)
	{
		if (i->returnorder() == 0)
		{
			temp1 = i->returnnumber();
			cout << temp1 << "、";
			vacant_room[j] = temp1;
			j++;
		}
	}
	cout << endl << "room 101-102 are standard room. Those price is 100 dollar per night" << endl;
	cout << "room 103-104 are suite room. Those price is 200 dollar per night" << endl;
	cout << "room 105-106 are kingsize room. Those price is 300 dollar per night" << endl;

	cout << "There are " << j << " vancant rooms altogether." << endl;
	cout << '\n' << setiosflags(ios_base::left) << " Please input the room number you expected." << endl;
	cin >> temp;
	check(vacant_room, j, temp);

	for (i = List.begin(); i != List.end(); i++)
	{
		if (i->returnnumber() == temp)
		{
			cout << "please input the date you cheak in" << endl;
			cin >> temp;
			cout << "please input the date you leave" << endl;
			cin >> temp1;
			i->getdate(temp, temp1);
			cout << "please input your name" << endl;
			cin >> str;
			i->getname(str);
			cout << "please input your ID" << endl;
			cin >> str;
			i->getID(str);
			cout << "please input your mobile phone" << endl;
			cin >> str;
			i->getphone(str);
			i->getorder(static_cast<bool>(1));
			cout << "The price is ";
			temp = i->sumprice();
			cout << temp << endl;
			break;
		}
	
	}
	AddToFile(List, "1.txt");
	return List;
}


int check(int a[], int size, int suspicion)//a是空闲房间号的数组 size是数组大小 ，suspicion是你选择的房间号 这个函数功能就是判断是否输入正确的房间号
{
	int judge = 0;
	for (int i = 0; i < size; i++)
	{
		if (suspicion == a[i])
			judge = 1;
	}
	if (judge == 0)
	{
		cout << "Wrong" << endl;
		exit(-1);
		//throw suspicion;
	}
	return 0;
}
