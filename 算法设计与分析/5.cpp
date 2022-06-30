#include<iostream>
#include<cstdio>

using namespace std;
const int inf=0x3f3f3f3f;//预设各点之间的距离为无穷大
string citys[10]= {"0","北京","西安","郑州","徐州","成都","广州","上海"};

void build(int e[][10],int n,int m)
{
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			e[i][j]=(i==j)?0:inf;
	cout << "请输入各城市之间的距离：" << endl;
	for(int i=1; i<=m; i++) 
	{
		int t1,t2,d;//位置t1到位置t2的距离是d
		cin>>t1>>t2>>d;
		e[t1][t2]=e[t2][t1]=d;//无向图
	}
}

void Floyd(int e[][10],int n)//多源最短路,建立表格
{
	system("cls");
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			for(int k=1; k<=n; k++)
				if(e[i][k]+e[k][j]<e[i][j])
					e[i][j]=e[i][k]+e[k][j];

	/**
	cout << "两个城市之间的最短路径问题:" << endl;
	for(int i=1; i<=n; i++)
		cout<<"\t"<<citys[i];
	cout<<endl;
	for(int i=1; i<=n; i++) 
	{
		cout<<citys[i];
		for(int j=1; j<=n; j++)
			printf("%8d",e[i][j]);
		cout<<endl;
	}
	**/

	cout << "两个城市之间的最短路径为:" << endl;
	for (int i = 1; i <= n; i++)
		for (int j = 6; j > i; j--)
		{
			cout << citys[i] << "->" << citys[j] << ": " << e[i][j] << endl;
		}
		

	system("pause");
}

void Dijkstra(int e[][10],int n)//贪心思想
{
	int dis[10] = { 0 };//初始化单源最短数组dis,这里是1号顶点到其余各顶点的初始路径
	int book[10] = { 0 }; //所求结点到其他结点的最短路  记录当前结点是否已经判断过了
	for(int i=1; i<=n; i++)
		dis[i]=e[1][i];

	for(int i=2; i<=n; i++)
		book[i]=0;//未知最短路顶点
	book[1]=1;

	//Dijkstra 算法核心语句
	for(int i=1; i<=n-1; i++) 
	{
		int min=inf,t=0;
		for(int j=1; j<=n; j++)
			if(book[j]==0&&dis[j]<min) 
			{ //找出未判断结点中到1号结点（单源最短路起点）距离最小结点
				min=dis[j];
				t=j;
			}
		book[t]=1;//及时将选出的该结点标记为已判断过了
		for(int v=1; v<=n; v++) 
		{ //判断其他结点借助当前选出的结点，是否使得到1号结点的距离变短
			if(e[t][v]<inf) 
			{
				if(dis[v]>dis[t]+e[t][v])
					dis[v]=dis[t]+e[t][v];//记录借助当前选出结点使得到1号结点更短路径的新距离
			}
		}
	}

	cout<<"所求城市单源最短路径为:"<<endl;
	for(int i=2; i<=n; i++)
		cout<<citys[1]<<"->"<<citys[i]<<": "<<dis[i]<<endl;
}

void Inquiry(int e[][10],int n)
{
	int i;
	string t;
	cout<<"请输入你要查询的城市名：";
	cin>>t;
	for(i=1; i<=n; i++) 
	{
		if(citys[i]==t)
			break;
	}
	if(i==n+1) 
	{
		cout<<endl<<"所查城市不在交通网络图中"<<endl;
		return ;
	}
	cout<<endl<<"所求城市"<<citys[i]<<"单源最短路径为:"<<endl;
	for(int j=1; j<=n; j++) 
	{
		if(i==j) continue;
		cout<<citys[i]<<"->"<<citys[j]<<": "<<e[i][j]<<endl;
	}

}
void menu()
{
	int e[10][10];
	int n,m;//顶点个数  边的个数
	cout << "请输入城市个数与路线数量：" << endl;
	cin>>n>>m;
	build(e,n,m);
	Floyd(e,n);
	Dijkstra(e,n);
	while (1)
	{
		system("cls");
		Inquiry(e, n);
		system("pause");
	}
}

int main()
{
	menu();
	return 0;
}

/**
1 2 2553
1 3 692
1 4 704
2 3 511
3 4 349
2 5 812
3 6 1579
4 7 651
5 6 2368
6 7 1385
**/