#include<iostream>
#include<cstring>
#include<iomanip>

using namespace std;
int count;

class Student
{
public:
	void Addstudent();
	void showscore();
	void Revise();
	int rnumber()
	{
		return number;
	}
	int rscore()
	{
		return total_score;
	}
	void rrank(int newrank)
	{
		rank = newrank;
	}
	void sum()
	{
		total_score = Chinese + Math + English + C_Language;
	}
	void show()
	{
		cout << number << setw(6) << name << setw(6) << Chinese << setw(7) << Math << setw(6) << English << setw(6) << C_Language << setw(6) << total_score << setw(7) << rank << endl;
	}
private:
	int number;
	string name;
	int Chinese;
	int Math; 
	int English;
	int C_Language;

	int total_score;
	int rank;
};

Student stu[100]; 

void Student::Revise()
{
	int subject;
	int new_score;
	cout << "请输入要修改的科目序号与新的成绩(1.语文，2.数学，3.英语，4.C语言)：" << endl;
	cin >> subject;
	cin >> new_score;
	switch (subject)
	{
	case 1:
		Chinese = new_score; 
		break;
	case 2:
		Math = new_score;
		break;
	case 3:
		English = new_score;
		break;
	case 4:
		C_Language = new_score;
		break;
	}
}

void Student::Addstudent()
{
	int i =::count;
	cout << "请输入学生成绩信息：学号 姓名 语文 数学 英语 C语言成绩：" << endl;
	cin >> stu[i].number >> stu[i].name >> stu[i].Chinese >> stu[i].Math >> stu[i].English >> stu[i].C_Language;
	stu[i].sum();
	::count++;
}

void Student::showscore()
{
	cout << "该生信息如下：" << endl;
	cout << "学号：     " << number << endl;
	cout << "姓名：     " << name << endl;
	cout << "语文成绩： " << Chinese << endl;
	cout << "数学成绩： " << Math << endl;
	cout << "英语成绩： " << English << endl;
	cout << "C语言成绩：" << C_Language << endl;
	cout << "总成绩：   " << total_score << endl;
	cout << "排名：     " << rank << endl;
}

void BubbleSort()
{
	int left=0, right=::count-1, shift=1, i=0;
	while (left < right)
	{
		for (i = left; i < right; i++)
		{
			if (stu[i].rscore() < stu[i + 1].rscore())
			{
				Student temp;
				temp = stu[i];
				stu[i] = stu[i + 1];
				stu[i + 1] = temp;
				shift = i;
			}
		}
		right = shift;
		for (i = right - 1; i >= left; i--)
		{
			if (stu[i].rscore() < stu[i + 1].rscore())
			{
				Student temp;
				temp = stu[i];
				stu[i] = stu[i + 1];
				stu[i + 1] = temp;
				shift = i + 1;
			}
		}
		left = shift;
	}
	for (i = 0; i < ::count; i++)
	{
		stu[i].rrank(i + 1);
	}
}

void QuickSort(int low,int high)
{
	if (low < high)
	{
		int i = low;
		int j = high;
		Student key = stu[i];
		while (i < j)
		{
			while (i < j && stu[j].rscore() <= key.rscore())
			{
				j--;
			}
			if (i < j)
			{
				stu[i] = stu[j];
			}
			while (i < j && stu[i].rscore() > key.rscore())
			{
				i++;
			}
			if (i < j)
			{
				stu[j] = stu[i];
			}
		}
		stu[i] = key;
		QuickSort(low, i-1);
		QuickSort(i+1, high);
	}
}

void group_sort(int ipos, int istep)
{
	Student itmp;
	int j;
	for (int i = ipos + istep; i < ::count; i++)
	{
		itmp = stu[i];
		for (j = i - istep; j >= 0; j -= istep)
		{
			if (stu[j].rscore() >= itmp.rscore())
			{
				break;
			}
			stu[j + istep] = stu[j];
		}
		stu[j + istep] = itmp;
	}
}
void ShellInsertSort()
{
	int istep = ::count / 2;
	while (istep > 0)
	{
		for (int i = 0; i < istep; i++)
		{
			group_sort(i, istep);
		}
		istep /= 2;
	}
	for (int i = 0; i < ::count; i++)
	{
		stu[i].rrank(i + 1);
	}
}

void Down(int i,int n)
{
	int child = 2 * i + 1;
	Student key = stu[i];
	while (child < n)
	{
		if (child + 1 < n && stu[child].rscore() > stu[child + 1].rscore())
		{
			child++;
		}
		if (key.rscore() > stu[child].rscore())
		{
			Student temp;
			temp = stu[i];
			stu[i] = stu[child];
			stu[child] = temp;
			i = child;
		}
		else
		{
			break;
		}
		child = child * 2 + 1;
	}
}

void BuildHeap()
{
	for (int i = ::count / 2 - 1; i >= 0; i--)
	{
		Down(i,::count);
	}
}

void HeapAdjust()
{
	BuildHeap();
	for (int i = ::count - 1; i > 0; i--)
	{
		Student temp;
		temp = stu[0];
		stu[0] = stu[i];
		stu[i] = temp;
		Down(0, i);
	}
	for (int i = 0; i < ::count; i++)
	{
		stu[i].rrank(i + 1);
	}
}

void menu()
{
	while (1)
	{
		cout << "   ***学生成绩处理系统***" << endl;
		cout << "      1.学生信息录入  " << endl;
		cout << "      2.学生信息查询  " << endl;
		cout << "      3.学生信息修改  " << endl;
		cout << "      4.学生成绩排序  " << endl;
		cout << "      5.学生成绩输出  " << endl;
		cout << "      0.结束程序      " << endl;

		int i;
		cin >> i;
		switch (i)
		{
		case 1:
			system("cls"); stu[::count].Addstudent(); break;
		case 2:
			system("cls");
			cout << "请输入要查询学生的学号：" << endl;
			int no;
			cin >> no;
			for (int i = 0; i < ::count; i++)
			{
				if (stu[i].rnumber() == no)
				{
					stu[i].showscore();
					break;
				}
			}
			break;
		case 3:
			system("cls");
			cout << "请输入要修改学生的学号：" << endl;
			no=0;
			cin >> no;
			for (int i = 0; i < ::count; i++)
			{
				if (stu[i].rnumber() == no)
				{
					stu[i].Revise();
					stu[i].sum();
					break;
				}
			}
			break;
		case 4:
			system("cls");
			cout << "请选择排序方式：1.双向冒泡排序 2.快速排序 3.希尔排序 4.堆排序：" << endl;
			cin >> i;
			switch (i)
			{
			case 1:
				BubbleSort();
				break;
			case 2:
				QuickSort(0, ::count - 1);
				for (i = 0; i < ::count; i++)
				{
					stu[i].rrank(i + 1);
				}
				break;
			case 3:
				ShellInsertSort();
				break;
			case 4:
				HeapAdjust();
				break;
			}
			break;
		case 5:
			system("cls");
			cout << "学号   姓名   语文  数学  英语  C语言 总分  排名" << endl;
			for (int i = 0; i < ::count; i++)
			{
				stu[i].show();
			}
			break;
		case 0:
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
/*
2020201 孙新斌 149 148 130 100
2020202 刘泳良 148 134 120 98
2020203 王博 100 30 100 68
2020204 李乐乐 140 139 148 99
2020205 王天天 97 23 98 60
2020206 李思雨 101 36 110 71
2020207 周波 69 76 39 10
2020208 李鑫 120 78 69 73
*/