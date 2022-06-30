/*
* Copyright (c) 2022,Qingdao University
* All rights reserved.
* author: Sun Xinbin
* College:The College of Computer Science and Technology
* Completion date: 2022.5.20
*/
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>

using namespace std;
//读者类
class Reader {
//protected:
public:
	string number;
	string name;
	string sex;//性别
	string college;//隶属学院 
	int nu;//借阅数量
	string status;//状态 
public:
	friend void info_reader();
	friend void outfo_reader();
	friend void Select_reader();
	friend void readerstatus(string number);
	friend void readerstatus1(string number);
};

//图书类
class Books {
	//protected:
public:
	string number;
	string name;
	string author;
	string press;//出版社
	int nu;//数量 
public:
	bool Status();
	friend void info_information();
	friend void outfo_information();
	friend void Select_book();
	friend void bookstatus(string number);
	friend void bookstatus1(string number);
};

//借阅类
class Borrow {
//protected:
public:
	string bnumeber;//借阅号 
	string booknu;//书号
	string bookname;//书名
	string readernu;//借阅者学号
	string readername;//借阅者姓名
	long int btime;//借阅时间 

public:
	friend void info_br();
	friend void outfo_br();
	friend void Select_br(string readernu);
};

Books b[200];
Reader r[200];
Borrow bo[100];

int btop = 0;
int rtop = 0;
int botop = 0;

bool Books::Status()
{
	if (nu > 0)
		return true;
	return false;
}
void bookstatus(string number)
{
	for (int i = 0; i < btop; i++)
	{
		if (number == b[i].number)
			b[i].nu--;
	}
}
void readerstatus(string number)
{
	for (int i = 0; i < rtop; i++)
	{
		if (number == r[i].number)
			r[i].nu++;
	}
}

void bookstatus1(string number)
{
	for (int i = 0; i < btop; i++)
	{
		if (number == b[i].number)
			b[i].nu++;
	}
}
void readerstatus1(string number)
{
	//cout << number << endl;
	for (int i = 0; i < rtop; i++)
	{
		if (number == r[i].number)
		{
			r[i].nu--;
			//cout << "r" << endl;
		}
	}

}

void info_information()
{
	btop = 0;
	fstream file;
	file.open("book.txt", ios::in);
	if (!file)
	{
		cout << "文件打开失败" << endl;
		return;
	}
	while (file >> b[btop].number >> b[btop].name >> b[btop].author
		>> b[btop].press >> b[btop].nu)
		btop++;

	file.close();
	cout << "文件读取成功" << endl;
}

void info_reader()
{
	rtop = 0;
	fstream file;
	file.open("reader.txt", ios::in);
	if (!file)
	{
		cout << "文件打开失败" << endl;
		return;
	}
	while (file >> r[rtop].number >> r[rtop].name >> r[rtop].sex >> r[rtop].college)
	{
		r[rtop].nu = 0;
		r[rtop].status = "正常";
		rtop++;
	}

	file.close();
	cout << "文件读取成功" << endl;
}

void outfo_information()
{
	char number[20];
	string name;
	string author;
	string press;
	int nu;
	cout << "请输入要添加的图书信息：" << endl;
	cin >> number >> name >> author >> press >> nu;
	
	ofstream outfile;
	outfile.open("book.txt", ios::app);
	outfile << "\n" << number << " " << name << " " << author
		<< " " << press << " " << nu;
	btop++;

	outfile.close();
	cout << "数据写入成功" << endl;
}

void outfo_reader()
{
	string number;
	string name;
	string sex;
	string college;
	cout << "请输入要添加的读者信息：" << endl;
	
	cin >> number >> name >> sex >> college ;

	ofstream outfile;
	outfile.open("reader.txt", ios::app);
	outfile << "\n" << number << " " << name << " " << sex
		<< " " << college ;
	btop++;

	outfile.close();
	cout << "数据写入成功" << endl;
}

void info_br()
{
	botop = 0;
	fstream file;
	file.open("BR.txt", ios::in);
	if (!file)
	{
		cout << "文件打开失败" << endl;
		return;
	}
	while (file >> bo[botop].bnumeber >>  bo[botop].readernu 
		>> bo[botop].readername>> bo[botop].booknu >> bo[botop].bookname>> bo[botop].btime)
	{
		botop++;
	}
	file.close();
	cout << "文件读取成功" << endl;
}

bool reade_br(string number)
{
	info_br();
	int count = 0;
	for (int i = 0; i < botop; i++)
	{
		if (number == bo[i].bnumeber)
			count++;
	}
	//cout << count << endl;
	if (count == 1)
		return true;
	else if(count ==2)
		return false;
}

void outfo_br()
{
	string bnumber;
	string booknu;
	string bookname;
	string readernu;
	string readername;
	long int readerbtime;
	cout << "请对借阅记录进行登记：" << endl;;
	cin >> bnumber >> readernu >> readername >> booknu >> bookname >> readerbtime;

	ofstream outfile;
	outfile.open("BR.txt", ios::app);
	outfile << "\n" << bnumber << " " << readernu << " " << readername << " " 
		<< booknu << " " << bookname << " " << readerbtime;
	botop++;
	outfile.close();
	cout << "数据写入成功" << endl;
	if (reade_br(bnumber))
	{
		//cout << "1" << endl;
		bookstatus(booknu);
		readerstatus(readernu);
	}
	else
	{
		//cout << "1"<<endl;
		bookstatus1(booknu);
		readerstatus1(readernu);
	}
}

void Select_book()
{
	system("cls");
	while (1)
	{
		int n;
		string x;
		cout << "请输入要查询的类型：（1.书号，2.书名，3.作者，4.出版社，0.退出）" << endl;
		cin >> n;
		cin >> x;
		switch (n)
		{
		case 1:
			for (int i = 0; i < btop; i++)
			{
				if (b[i].number == x)
				{
					cout << b[i].number << " " << b[i].name << " " << b[i].author << " " << b[i].press << " " << b[i].nu << " ";
					if (b[i].Status())
						cout << "在库 可借出" << endl;
					else
						cout << "！！已全部借出！！" << endl;
				}
			}
			break;
		case 2:
			for (int i = 0; i < btop; i++)
			{
				if (b[i].name == x)
				{
					cout << b[i].number << " " << b[i].name << " " << b[i].author << " " << b[i].press << " " << b[i].nu << " ";
					if (b[i].Status())
						cout << "在库 可借出" << endl;
					else
						cout << "！！已全部借出！！" << endl;
				}
			}
			break;
		case 3:
			for (int i = 0; i < btop; i++)
			{
				if (b[i].author == x)
				{
					cout << b[i].number << " " << b[i].name << " " << b[i].author << " " << b[i].press << " " << b[i].nu << " ";
					if (b[i].Status())
						cout << "在库 可借出" << endl;
					else
						cout << "！！已全部借出！！" << endl;
				}
			}
			break;
		case 4:
			for (int i = 0; i < btop; i++)
			{
				if (b[i].press == x)
				{
					cout << b[i].number << " " << b[i].name << " " << b[i].author << " " << b[i].press << " " << b[i].nu << " ";
					if (b[i].Status())
						cout << "在库 可借出" << endl;
					else
						cout << "！！已全部借出！！" << endl;
				}
			}
			break;
		case 0:
			return;
		}
	}
}

void Select_reader()
{
	while (1)
	{
		int n;
		string x;
		cout << "请输入要查询的类型：（1.学号，2.姓名,0.退出）" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			system("cls");
			cout << "请输入学号：" ;
			cin >> x;
			for (int i = 0; i < rtop; i++)
			{
				if (r[i].number == x)
					cout << r[i].number << " " << r[i].name << " " << r[i].sex << " " << r[i].college << " " << r[i].status << endl;
			}
			break;
		case 2:
			system("cls");
			cout << "请输入姓名：";
			cin >> x;
			for (int i = 0; i < rtop; i++)
			{
				if (r[i].name == x)
					cout << r[i].number << " " << r[i].name << " " << r[i].sex << " " << r[i].college << " " << r[i].status << endl;
			}
			break;
		case 0:
			return;
		}
	}
}
void Select_br(string readernu)
{
	for (int i = 0; i < botop; i++)
	{
		if (bo[i].readernu == readernu)
			cout << bo[i].bnumeber<<" " << bo[i].booknu <<" " <<bo[i].bookname<<" " << bo[i].btime << endl;
	}
}

void Check_borrow()
{
	for (int i = 0; i < rtop;i++)
	{
		long int a=1, b=1;
		int flag=0;
		
		for (int j = 0; j < botop; j++)
		{
			//cout << bo[j].readernu << endl;
			if (r[i].number == bo[j].readernu && !flag)
			{
				flag = 1;
				a = bo[j].btime;
			}
			if (r[i].number == bo[j].readernu && flag)
			{
				flag = 1;
				b = bo[j].btime;
			}
		}
		long int x = b - a;
		//cout << x << endl;
		if (x > 10)
			r[i].status = "有逾期记录";
	}
}

void menu()
{
	while (1)
	{
		int n = 0;
		cout << "      欢迎进入青岛大学图书管理系统" << endl << endl;;
		cout << "请选择您的身份：（1.管理员，2.借阅者,0.退出）" << endl;
		cin >> n;
		system("cls");
		switch (n)
		{
		case 1:
			cout << "请选择您的操作：" << endl;
			cout << "1.读者信息查看与添加" << endl;
			cout << "2.图书信息查看与添加" << endl;
			cout << "3.借阅记录登记" << endl;
			cout << "4.借阅记录查看" << endl;
			cin >> n;
			switch (n)
			{
			case 1:
				system("cls");
				Select_reader();
				outfo_reader();
				break;
			case 2:
				system("cls");
				for (int i = 0; i < btop; i++)
				{
					cout << b[i].number << " " << b[i].name << " " << b[i].author << " " << b[i].press << " " << b[i].nu << endl;
				}
				outfo_information();
				break;
			case 3:
				info_br();
				system("cls");
				outfo_br();
				Check_borrow();
				break;
			case 4:
				info_br();
				system("cls");
				for (int i = 0; i < botop; i++)
				{
					//if (bo[i].readernu == readernu)
						cout << bo[i].bnumeber << " " <<bo[i].readernu<<" "<<bo[i].readername<<" "<< bo[i].booknu << " " << bo[i].bookname << " " << bo[i].btime << endl;
				}
				break;
			}
			break;
		case 2:
			cout << "请选择您的操作：" << endl;
			cout << "1.图书借阅查询" << endl;
			cout << "2.查询本人借阅记录" << endl;
			cin >> n;
			switch (n)
			{
			case 1:
				system("cls");
				Select_book();
				break;
			case 2:
				info_br();
				system("cls");
				string nu;
				cout << "请输入您的学号:";
				cin >> nu;
				Select_br(nu);
				break;
			}
			break;
		case 0:
			return;
		}
	}
}

int main()
{
	info_information();
	info_reader();
	info_br();
	system("cls");
	//Check_borrow();
	//cout << r[0].status << endl;
	menu();
	cout << "感谢您的使用" << endl;
	return 0;
}