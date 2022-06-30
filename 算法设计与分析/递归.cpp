#include<iostream>

using namespace std;

#define MAX 50

int table[MAX][MAX];

void fillTable(int x, int y, int step)
{
	if (step == 1)
		return;
	step /= 2;
	fillTable(x, y, step);    //填写左上的表格
	fillTable(x + step, y, step);    //填写左下的表格
	for (int i = 0; i < step; i++)
		for (int j = 0; j < step; j++) 
		{
			table[x + step + i][y + step + j] = table[x + i][y + j];  //左上表拷贝至右下表
			table[x + i][y + step + j] = table[x + step + i][y + j];  //左下表拷贝至右上表
		}
}

int main()
{
	int n;   //人数

	cout << "请输入比赛的选手数量:" << endl;
	cin >> n;

	for (int i = 1; i <= n; i++)//初始化第一列
		table[i][1] = i;

	fillTable(1, 1, n);//递归排列表格

	//打印
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= n; j++)
			cout << table[i][j] << "  ";
		cout << endl;
	}

	system("pause");
	return 0;
}