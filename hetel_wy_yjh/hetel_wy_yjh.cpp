#include"hotel.h"
/*
2022.1.9版本:ver1.0(大体框架已完成)
	函数功能:
		1.增加房间信息（除了房间号和价格 其他信息初始化为0）参考函数AddRoom
		2.预定房间	参考函数book
		3.游客入住房间（预定后入住）	参考函数checkin
		4.退房			参考函数checkout
		5.查询系统	（根据房间信息查询或者入住人信息查询）	参考函数queryMenu		(这是一系列函数嵌套在一起)
		6.显示		显示所有房间信息	参考函数showALL
	目前版本bug:
		1.遍历list 从begin到end会多出最后一个（showALL进行测试），因为end()指向列表最后一个元素的下一个位置所以会多出来一个玩意跟最后一个元素一模一样..
		目前无法解决！可以用比较麻烦的方法尝试
		2.排版问题！
		3.文字显示颜色可以多样性！没弄！
		4.用来判断输入是否合法 可以用异常处理来代替！
		5.没有写main函数 目前的main函数只是对各个函数功能的一个测试（各个函数逻辑没有问题）	（主要是写一个功能菜单（游客菜单）（管理员菜单））
		6.该系统需要分 游客 和 管理员  需要做一个登录系统
		7.后续bug有待yjh开发
*/
int main()
{
	list<room> listhotel;
	listhotel=read(listhotel,"1.txt");//读取
	showALL(listhotel);
	//listhotel = checkout(listhotel);//退房
	//queryMenu(listhotel);//查询
	//AddRoom(listhotel);//增加房间
	//AddToFile(listhotel, "1.txt");//保存
	//listhotel = book(listhotel, "1.txt");//预定
	//listhotel = checkin(listhotel);//登记入住
	//测试list
	list<room>::iterator i;
	//for (i = listhotel.begin(); i != listhotel.end(); i++)
	//{
	//	cout << i->returnnumber()<< endl;
	//}
	AddToFile(listhotel, "1.txt");
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
	listhotel.pop_front();//喵的去掉头节点！
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

list<room>& book(list<room>&List, const string& filename)
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
	for (int k = 0; k < j; k++)
	{
		cout << vacant_room[k] << endl;
	}
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

list<room>& checkin(list<room>&List)
{
	part1:
	string tempID, tempName, tempPhone;//用来保存输入的ID name phone
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//句柄
	cout.width(120);
	SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << "亲爱的游客，请验证你的身份！ " << endl;
	cout << "请输入你的姓名:" << endl;
	cin >> tempName;
	cout << "请输入你的ID:" << endl;
	cin >> tempID;
	cout << "请输入你的手机号码:" << endl;
	cin>> tempPhone;
	int flag = 0;//用来判断找到的房间个数
	list<room>::iterator i;
	for (i = List.begin(); i != List.end(); i++)
	{
		if (tempID == i->returnID()&&tempName == i->returnname()&&tempPhone == i->returnphone())
		{
			flag++;
		}
	}
	if (flag == 0)//也可以使用异常处理来写
	{
		cout << "亲爱的" << tempName << "先生\\女士，您输入的信息有误！" << endl;
		cout << "是否需要重新输入？(y\n)" << endl;
		char choice;
		cin >> choice;
		if (choice == 'y')
			goto part1;//回到这段函数的开头
		else//应该要退出		这里应该需要一个异常处理 choice是否合法
			exit(-1);
	}
	else
	{
		cout << "亲爱的" << tempName << "先生\\女士，您预定了" << flag<<"个房间"<< endl;
		ShowInfo(List, tempName);
		cout << "是否要登记入住？(y\\n)" << endl;
		char choice;
		cin >> choice;
		if (choice == 'y')
		{
			for (i = List.begin(); i != List.end(); i++)
			{
				if (tempID == i->returnID()&&tempName == i->returnname()&&tempPhone == i->returnphone())
				{
					i->getIfenter(true);
					i->showInfo();
				}
			}
		}
		else//应该要退出这个子功能回到主菜单		这里应该需要一个异常处理 choice是否合法
			return List;
	}

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

void queryMenu(list<room>&List)
{
	int choice;
	cout << "欢迎来到查询系统" << endl;
	cout << "请选择你的查询方式：" << endl;
	cout << "1.按房间信息查询" << endl;
	cout << "2.按入住人信息查询" << endl;
	cin >> choice;
	if (choice==1)
		queryMenu1(List);
	else
		queryMenu2(List);
}

void queryMenu1(list<room>&List)
{
	int choice;
	int temp_int = 101;
	bool temp_bool = false;
	cout << "欢迎来到查询子系统（房间信息）" << endl;
	cout << "请选择你的查询方式：" << endl;
	cout << "1.按房间号查询" << endl;
	cout << "2.按房间价格查询" << endl;
	cout << "3.按房间开始住时间查询" << endl;
	cout << "4.按房间结束住时间查询" << endl;
	cout << "5.按房间预约信息查询" << endl;
	cout << "6.按房间入住信息查询" << endl;
	cout << "0.退出" << endl;
	cin >> choice;
	if (choice >= 1 && choice <= 4)
	{
		cout << "请输入相应信息：" << endl;
		cin >> temp_int;
	}
	else if (choice >= 5 && choice <= 6)
	{
		cout << "请输入相应信息：" << endl;
		cin >> temp_int;
	}
	else if (choice == 0)	cout << "退出" << endl;
	else
	{
		cout << "不合法输入" << endl;
		return;
	}
	while (choice != 0)
	{
		switch (choice)/*因为前四种查询方式 所查的数据都是int型 就直接用一个函数就可以了   后俩种是bool型*/
		{
		case 1:
		case 2: 
		case 3: 
		case 4: ShowInfo(List, temp_int);  break;
		case 5:
		case 6: ShowInfo(List, temp_bool); break;
		case 0:return;
		}
		cout << "请选择你的查询方式：" << endl;
		cout << "1.按房间号查询" << endl;
		cout << "2.按房间价格查询" << endl;
		cout << "3.按房间开始住时间查询" << endl;
		cout << "4.按房间结束住时间查询" << endl;
		cout << "5.按房间预约信息查询" << endl;
		cout << "6.按房间入住信息查询" << endl;
		cout << "0.退出" << endl;

		cin >> choice;
		if (choice >= 1 && choice <= 4)
			cin >> temp_int;
		else if (choice >= 5 && choice <= 6)
			cin >> temp_bool;
		else if (choice == 0)	cout << "退出" << endl;
		else
		{
			cout << "不合法输入" << endl;
			return;
		}
	}
}
void queryMenu2(list<room>&List)
{
	int choice;
	string str;
	cout << "欢迎来到查询子系统（房间信息）" << endl;
	cout << "请选择你的查询方式：" << endl;
	cout << "1.按入住人姓名查询" << endl;
	cout << "2.按入住人ID查询" << endl;
	cout << "3.按入住人手机号查询" << endl;
	cout << "0.退出" << endl;

	cin >> choice;
	if(choice<0||choice>3)
	{
		cout << "不合法输入" << endl;
		return;
	}
	cout << "请输入相应信息:" << endl;
	cin >> str;
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:ShowInfo(List, str); break;
		case 2:ShowInfo(List, str); break;
		case 3:ShowInfo(List, str); break;

		case 0:return;
		}
		cout << "请选择你的查询方式：" << endl;
		cout << "1.按入住人姓名查询" << endl;
		cout << "2.按入住人ID查询" << endl;
		cout << "3.按入住人手机号查询" << endl;
		cout << "0.退出" << endl;

		cin >> choice;
		if (choice < 0 || choice>3)
		{
			cout << "不合法输入" << endl;
			return;
		}
		cout << "请输入相应信息:" << endl;
		cin >> str;
	}
}


void ShowInfo(list<room>&List, int Room_info_int)//根据str（可能是name也可以是phone也可以是ID）
{
	int flag = 0;
	list<room>::iterator i;
	for (i = List.begin(); i != List.end(); i++)
	{
		if (i->returnnumber() == Room_info_int || i->returnprice() == Room_info_int || i->returnstartdate() == Room_info_int || i->returnenddate() == Room_info_int)
		{
			i->showInfo();
			flag++;
		}
	}
	if (flag == 0)
	{
		cout << "没有符合要求的房间" << endl;
	}
	else
	{
		cout << "有以上" << flag << "个符合要求的房间" << endl;
	}
}

void ShowInfo(list<room>&List, bool Room_info_bool)//根据str（可能是name也可以是phone也可以是ID）
{
	int flag = 0;
	list<room>::iterator i;
	for (i = List.begin(); i != List.end(); i++)
	{
		if (i->returnorder() == Room_info_bool || i->returnIfenter() == Room_info_bool)
		{
			i->showInfo();
			flag++;
		}
	}
	if (flag == 0)
	{
		cout << "没有符合要求的房间" << endl;
	}
	else
	{
		cout << "有以上" << flag << "个符合要求的房间" << endl;
	}
}

void ShowInfo(list<room>&List, string str)//根据str（可能是name也可以是phone也可以是ID）
{
	int flag = 0;
	list<room>::iterator i;
	for (i = List.begin(); i != List.end(); i++)
	{
		if (i->returnname() == str || i->returnID() == str || i->returnphone() == str)
		{
			i->showInfo();
			flag++;
		}
	}
	if (flag == 0)
	{
		cout << "没有符合要求的房间" << endl;
	}
	else
	{
		cout << "有以上" << flag << "个符合要求的房间" << endl;
	}
}

list<room>& checkout(list<room>&List)//退房
{
	int num;
	cout << "请输入需要退房的房号：" << endl;
	cin >> num;
	list<room>::iterator i;
	for (i = List.begin(); i != List.end(); i++)
	{
		if (i->returnnumber() == num)
		{
			/*
			这应该算是管理员进行操作：暂时还没分管理员和游客
			*/
			i->getorder(false);
			i->getIfenter(false);
			i->getID("0");
			i->getname("0");
			i->getphone("0");
			i->getdate(0, 0);
			cout << "退房成功!" << endl;
			//order = false;
			//Ifenter = false;
			//start_date = 0;
			//end_date = 0;
			//name = "0";//信息为0表示初始化后还未被仍使用
			//ID = "0";
			//phone = "0";
		}
	}
	return List;
}

void showALL(list<room>&List)//展示所有房间信息
{
	if (List.empty())
	{
		cout << "列表为空！" << endl;
	}
	else
	{
		list<room>::iterator i;
		for (i = List.begin(); i != List.end(); i++)
		{
			i->showInfo();
		}
	}
}