/*
* Copyright (c) 2022,Qingdao University
* All rights reserved.
* anuthor: Sun Xinbin
* Completion date: 2022.4.23
*/
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>

using namespace std;
int count=0;

class Flight{
public:
	friend void Info_file();//文件读入
	friend void Info_self();//自主写入 
	friend void Search();//查询函数
	friend void Show();//展示全部信息
	void Print();//打印
private:
	string number;
	string Departure_Station;
	string Terminus;
	string Flight_schedule;
	int Departure_time;
	int Arrival_time;
	string Model;
	int Price;
};

Flight flight[100];

void Flight::Print()
{
	cout << number <<" " << Departure_Station << " " << Terminus << " " << Flight_schedule<<" " 
		<< Departure_time <<" " << Arrival_time << " " << Model << " " << Price<<endl;
}

void Info_file()
{
	fstream f;
	f.open("FlightInformation.txt", ios::in);
	if (!f)
	{
		cout << "文件打开失败" << endl;
	}
	while (f >> flight[::count].number >> flight[::count].Departure_Station >> flight[::count].Terminus
		>> flight[::count].Flight_schedule >> flight[::count].Departure_time >> flight[::count].Arrival_time>>flight[::count].Model
		>> flight[::count].Price)
		::count++;

	f.close();
	cout << "文件导入成功！" << endl;
}

void Info_self()
{
	Flight new_info;

		cout<<"请输入航班信息：（航班号,起点站,终点站,航班期,起飞时间,到达时间,机型,票价）"<<endl;
		cin>>new_info.number >> new_info.Departure_Station >> new_info.Terminus
		>> new_info.Flight_schedule >> new_info.Departure_time >> new_info.Arrival_time>>new_info.Model
		>> new_info.Price;
		flight[::count].number = new_info.number;
		flight[::count].Departure_Station = new_info.Departure_Station;
		flight[::count].Terminus = new_info.Terminus;
		flight[::count].Flight_schedule = new_info.Flight_schedule;
		flight[::count].Departure_time = new_info.Departure_time;
		flight[::count].Arrival_time = new_info.Arrival_time;
		flight[::count].Model = new_info.Model;
		flight[::count].Price = new_info.Price;
		
		ofstream outfile;
        outfile.open("FlightInformation.txt", ios::app);
        outfile<<"\n"<<new_info.number<<" "<< new_info.Departure_Station<<" "<< new_info.Terminus
		<<" "<< new_info.Flight_schedule <<" "<< new_info.Departure_time<<" "<< new_info.Arrival_time<<" "<<new_info.Model
		<<" "<< new_info.Price;
		::count++; 
}
//MA0011 青岛 杭州 天天班 1900 2130 K30 1700 

void Search()
{
	cout << "请输入查询信息：（1.航班号2.起点站3.终点站4.起飞时间5.到达时间）" << endl;
	int i = 0;
	int flag = 1;
	string no;
	string station;
	string station1;
	cin >> i;
	switch (i)
	{
	case 1:
		system("cls");
		cout << "请输入要查询的航班号：" << endl;
		cin >> no;
		for (int i = 0; i < ::count; i++)
		{
			if (no == flight[i].number)
			{
				flight[i].Print();
				flag = 0;
			}
		}
		break;
	case 2:
		system("cls");
		cout << "请输入要查询的起点站：" << endl;
		cin >> station;
		for (int i = 0; i < ::count; i++)
		{
			if (station == flight[i].Departure_Station)
			{
				flight[i].Print();
				flag = 0;
			}
		}
		break;
	case 3:
		system("cls");
		cout << "请输入要查询的终点站：" << endl;
		cin >> station1;
		for (int i = 0; i < ::count; i++)
		{
			if (station1 == flight[i].Terminus)
			{
				flight[i].Print();
				flag = 0;
			}
		}
		
		break;
	case 4:
		system("cls");
		cout << "请输入要查询的起飞时间：" << endl;
		int time;
		cin >> time;
		for (int i = 0; i < ::count; i++)
		{
			if (time == flight[i].Departure_time)
			{
				flight[i].Print();
				flag = 0;
			}
		}
		break;
	case 5:
		system("cls");
		cout << "请输入要查询的到达时间：" << endl;
		int time1;
		cin >> time1;
		for (int i = 0; i < ::count; i++)
		{
			if (time1 == flight[i].Arrival_time)
			{
				flight[i].Print();
				flag = 0;
			}
		}
		break;
	}
	if (flag)
		cout << "未查到相关航班信息" << endl;
}

void Show()
{
	for (int i = 0; i < ::count; i++)
	{
		cout << flight[i].number << " " << flight[i].Departure_Station << " " << flight[i].Terminus
			<< " " << flight[i].Flight_schedule << " " << flight[i].Departure_time << " " << flight[i].Arrival_time << " " << flight[i].Model
			<< " " << flight[i].Price << endl;;
	}
}

void menu()
{
	while (1)
	{
		cout << "    航班信息查询系统" << endl;
		cout << "     1.添加航班信息" << endl;
		cout << "     2.文件导入航班信息" << endl;
		cout << "     3.查询航班信息" << endl;
		cout << "     4.展示全部航班信息" << endl;
		cout << "     5.退出系统" << endl;
		int i;
		cin >> i;
		switch (i)
		{
		case 1:
			system("cls");
			Info_self();
			break;
		case 2:
			system("cls");
			Info_file();
			break;
		case 3:
			system("cls");
			Search();
			break;
		case 4:
			system("cls");
			Show();
			break;
		case 5:
			cout << "谢谢使用，欢迎下次光临 " << endl;
			system("pause");
			exit(0);
		default: cout << "输入错误" << endl;
			break;
		}
	}
}

int main()
{
	menu();

	return 0;
}
