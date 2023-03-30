#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

int main()
{
    system("chcp 65001");
	srand((unsigned)time(NULL));
	//存储num个字符串，每个不超50
	int choose = 0;
	int newx = 0;
	int num = 0;
	do
	{
        cout<<"请输入今日会晤的美女的人数："<<endl;
        cin>>num;
		string s[100];
		//输入数据（可以是字符串）
		for (int i = 0; i < num; i++)
		{
                cout<<"请输入美女姓名（每次输入一个英文名字）："<<endl;
                cin>>s[i];
		}
		choose = rand() % num;
		//打印数据
        cout<<"今日抽取的美女为："<<s[choose]<<endl;
        cout<<"是否需要重新抽取，输入1为重新抽取，0为结束"<<endl;
        cin>>newx;
		if(newx==1)
			system("cls");
	} 
	while (newx);
	system("pause");
	return 0;
}