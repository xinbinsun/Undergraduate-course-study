#include <iostream>
#include <cstring>
#include <cstdio>
#include <fstream>//操作文件必写
#include <cstdlib>
using namespace std;
 
const int MAXN=10000;
const int p=23;
const string NULLKEY="NULLKEY";//定义空关键字值
const string DELKEY="DELKEY";//定义被删关键字值
string x[MAXN];//输入时的航班号
int hashlen=0;//哈希表长度
ifstream infile("read.txt",ios::in);
 
typedef struct
{
    string departure;//起点站
    string terminal;//终点站
    string schedule;//班期
    string start;//起飞时间
    string arrival;//到达时间
    string type;//机型
    double price;//票价
} Info;//说明信息类型
 
typedef struct
{
    string number;//航班号
    Info data;//说明信息
    int cnt;//探查次数
} Hash;//哈希表类型
Hash ha[MAXN];//定义一个哈希表
 
int Work();//功能选择表单
int GetNum(string k);//取出航班号中的数值部分
int Search(string key);//在哈希表中查找航班号
int Delete(string str);//删除指定的航班信息
void Insert1(string key);//自动插入航班信息
void Insert2(string key);//手动插入航班信息
void Create1();//文件自动读取
void Create2();//键盘手动输入
void Number(string key);//查询航班号
void Departure(string key);//查询起点站
void Terminal(string key);//查询到达站
void Start(string key);//查询起飞时间
void Arrival(string key);//查询到达时间
void FileOutput(int adr);//航班信息存入文件
void Output(int adr);//航班信息在屏幕上显示
void Input(int adr);//手动输入航班信息
 
/*
*函数名称：Work
*功能描述：航班信息查询和检索系统的选择功能菜单
*输入参数：无
*输出参数：无
*返回值：无
*其他说明：无
*/
int Work()
{
    while(1)
    {
        cout<<endl;//表单格式
        cout<<"\t"<<"\t"<<"\t"<<"*********欢迎使用航班信息查询和检索系统*********"<<endl;
        cout<<"\t"<<"\t"<<"\t"<<"\t"<<"①读入数据"<<"\t"<<"②删除数据"<<"\n";
        cout<<"\t"<<"\t"<<"\t"<<"\t"<<"③航班号"<<"\t"<<"④起点站"<<"\n";
        cout<<"\t"<<"\t"<<"\t"<<"\t"<<"⑤到达站"<<"\t"<<"⑥起飞时间"<<"\n";
        cout<<"\t"<<"\t"<<"\t"<<"\t"<<"⑦到达时间"<<"\t"<<"⑧退出系统"<<"\n";
        cout<<"\t"<<"\t"<<"\t"<<"************************************************"<<endl;
        cout<<endl;
        cout<<"请选择将要使用的功能(序号):";
        int t;//序号
        string temp;//航班号
        cin>>t;
        switch (t)
        {
        case 1://①读入数据
        {
            cout<<"请选择读取方式(1:自动读取/2:手动录入):";
            int choose;//选择读取方式
            cin>>choose;
            if(choose==1)
                Create1();//1:自动读取
            else if(choose==2)
                Create2();//2:手动录入
            else
                cout<<"序号错误！请查证后重新输入！"<<endl;
            cout<<"信息录入成功！"<<endl;
            break;
        }
        case 2://②删除数据
        {
            cout<<"请输入要删除的航班号及其所有信息:";
            string str;
            cin>>str;
            Delete(str);
            cout<<"删除成功！"<<endl;
            break;
        }
        case 3://③航班号
        {
            cout<<"请输入航班号:";
            cin>>temp;
            Number(temp);
            break;
            break;
        }
        case 4://④起点站
        {
            cout<<"请输入起点站:";
            cin>>temp;
            Departure(temp);
            break;
        }
        case 5://⑤到达站
        {
            cout<<"请输入终点站:";
            cin>>temp;
            Terminal(temp);
            break;
        }
        case 6://⑥起飞时间
        {
            cout<<"请输入起飞时间:";
            cin>>temp;
            Start(temp);
            break;
        }
        case 7://⑦到达时间
        {
            cout<<"请输入到达时间:";
            cin>>temp;
            Arrival(temp);
            break;
        }
        case 8://⑧退出系统
        {
            cout<<"程序结束！处理完毕，请打开文件查看结果！"<<endl;
            return 0;
            break;
        }
        default://输入的序号不在1~8之间的范围内
        {
            cout<<"序号错误！请查证后重新输入！"<<endl;
            break;
        }
        }
    }
    return 0;
}
 
/*
*函数名称：GetNum
*功能描述：取出航班号的数值部分
*输入参数：k-航班号
*输出参数：无
*返回值：getnum-返回航班编号
*其他说明：无
*/
int GetNum(string k)
{
    int getnum=0,temp=1000;
    getnum=(int(k[0])*10000000+int(k[1])*100000);
    for(int i=2; k[i]!='\0'; ++i)//略掉表示航空公司的名称的前两个大写字母
    {
        getnum+=(int(k[i]-'0')*temp);
        temp/=10;
    }
    return getnum;//返回航班编号
}
 
/*
*函数名称：Search
*功能描述：在哈希表中查找航班号
*输入参数：key-航班号
*输出参数：无
*返回值：0/-1-表示是/否查找成功
*其他说明：无
*/
int Search(string key)
{
    int i=0,adr;
    int k=GetNum(key);
    adr=k%p;
    while(ha[adr].number!=NULLKEY&&ha[adr].number!=key)
    {
        ++i;
        adr=(adr+1)%MAXN;//采用线性探查法找下一个地址
    }
    if(ha[adr].number==key)
        return adr;//查找成功
    else
        return -1;//查找失败
}
 
/*
*函数名称：Delete
*功能描述：在哈希表中删除指定的航班信息
*输入参数：key-航班号
*输出参数：hashlen-哈希表元素个数,ha[adr].number-标记是否被删除
*返回值：0/-1-表示是/否查找成功
*其他说明：无
*/
int Delete(string key)
{
    int adr;
    adr=Search(key);//在哈希表中找到该关键字
    if(adr!=-1)
    {
        ha[adr].number=DELKEY;
        --hashlen;//哈希表元素个数减一
        return 1;
    }
    else//在哈希表中未找到该关键字
        return 0;
}
 
/*
*函数名称：Insert1
*功能描述：在哈希表中自动插入航班信息
*输入参数：key-航班号
*输出参数：hashlen-哈希表元素个数,ha[adr].number-关键字,ha[adr].cnt-探查次数
*返回值：无
*其他说明：无
*/
void Insert1(string key)
{
    int i,adr;
    int k=GetNum(key);//取出数值部分
    adr=k%p;
    if(ha[adr].number==NULLKEY||ha[adr].number==DELKEY)
    {
        ha[adr].number=key;//直接放入哈希表中
        ha[adr].cnt=1;
        infile>>ha[adr].data.departure>>ha[adr].data.terminal>>ha[adr].data.schedule;
        infile>>ha[adr].data.start>>ha[adr].data.arrival>>ha[adr].data.type>>ha[adr].data.price;
    }
    else//发生冲突时采用线性探查法解决冲突
    {
        i=1;//元素i为插入时发生冲突的次数
        while(ha[adr].number!=NULLKEY&&ha[adr].number!=DELKEY)
        {
            adr=(adr+1)%p;
            ++i;
        }
        ha[adr].number=key;
        ha[adr].cnt=i;
        infile>>ha[adr].data.departure>>ha[adr].data.terminal>>ha[adr].data.schedule;
        infile>>ha[adr].data.start>>ha[adr].data.arrival>>ha[adr].data.type>>ha[adr].data.price;
    }
    ++hashlen;//哈希表的元素个数加一
}
 
/*
*函数名称：Insert2
*功能描述：在哈希表中由文件手动插入航班信息
*输入参数：key-航班号
*输出参数：hashlen-哈希表元素个数,ha[adr].number-关键字,ha[adr].cnt-探查次数
*返回值：无
*其他说明：无
*/
void Insert2(string key)
{
    int i,adr;
    int k=GetNum(key);
    adr=k%p;
    if(ha[adr].number==NULLKEY||ha[adr].number==DELKEY)
    {
        ha[adr].number=key;
        ha[adr].cnt=1;
        Input(adr);//手动输入剩下信息
    }
    else
    {
        i=1;
        while(ha[adr].number!=NULLKEY&&ha[adr].number!=DELKEY)
        {
            adr=(adr+1)%p;
            ++i;
        }
        ha[adr].number=key;
        ha[adr].cnt=i;
        Input(adr);//手动输入剩下信息
    }
    ++hashlen;
}
 
/*
*函数名称：Create1
*功能描述：在哈希表中自动插入航班关键字信息
*输入参数：key-航班号
*输出参数：ha[adr].number-关键字全部初始化为NULLKEY,ha[adr].cnt-探查次数全部初始化为0
*返回值：无
*其他说明：无
*/
void Create1()
{
    int i;
    for(i=0; i<MAXN; ++i)//初始化
    {
        ha[i].number=NULLKEY;
        ha[i].cnt=0;
    }
    cout<<"航班信息读取中…请稍后…"<<endl;//提示信息
    for(i=0;; ++i)
    {
        if(!infile)//测试文件打开操作是否成功
        {
            cerr<<"open error!"<<endl;
            exit(1); //打开不成功，则提示后退出
        }
        infile>>x[i];//从文件中读取
        string s=x[i];
        if(s=="00")
            break;//读入00时结束读取
        else
            Insert1(x[i]);//将关键字插入哈希表
    }
    infile.close();//读入完毕一定要关闭文件
}
 
/*
*函数名称：Create2
*功能描述：在哈希表中手动插入航班关键字信息
*输入参数：key-航班号
*输出参数：ha[adr].number-关键字全部初始化为NULLKEY,ha[adr].cnt-探查次数全部初始化为0
*返回值：无
*其他说明：无
*/
void Create2()
{
    int i;
    for(i=0; i<MAXN; ++i)
    {
        ha[i].number=NULLKEY;
        ha[i].cnt=0;
    }
    cout<<"请输入航班信息(输入00时录入结束)"<<endl;
    for(i=0;; ++i)
    {
        cin>>x[i];//从键盘手动输入关键字
        string s=x[i];
        if(s=="00") break;
        else Insert2(x[i]);
    }
}
 
/*
*函数名称：Number
*功能描述：在哈希表中查询航班号
*输入参数：key-航班号
*输出参数：ha[adr].number-航班号,ha[adr].data.departure-起点站,ha[adr].data.terminal-到达站,ha[adr].data.schedule-班期,
ha[adr].data.start-起飞时间,ha[adr].data.arrival-到达时间,ha[adr].data.type-机型,ha[adr].data.price-票价
*返回值：无
*其他说明：无
*/
void Number(string key)
{
    int i=0,adr;
    int k=GetNum(key);
    adr=k%p;
    while(ha[adr].number!=NULLKEY&&ha[adr].number!=key)//哈希查找
    {
        ++i;
        adr=(adr+1)%MAXN;
    }
    if(ha[adr].number==key&&ha[adr].number!=DELKEY)
    {
        Output(adr);//在屏幕上显示
        FileOutput(adr);//存入文件
    }
    else
        cout<<"对不起，查无此航班！"<<endl;
}
 
/*
*函数名称：Departure
*功能描述：在哈希表中查询起点站
*输入参数：key-起点站
*输出参数：ha[adr].number-航班号,ha[adr].data.departure-起点站,ha[adr].data.terminal-到达站,ha[adr].data.schedule-班期,
ha[adr].data.start-起飞时间,ha[adr].data.arrival-到达时间,ha[adr].data.type-机型,ha[adr].data.price-票价
*返回值：无
*其他说明：无
*/
void Departure(string key)//起点站
{
    int i,flag=0;
    for(i=0; i<MAXN; ++i)//顺序查找
    {
        if(flag) break;
        else if(ha[i].data.departure==key)
        {
            Output(i);
            FileOutput(i);
            flag=1;//标记是否查询到相关信息
        }
    }
    if(!flag)
        cout<<"对不起，查无此航班！"<<endl;
}
 
/*
*函数名称：Terminal
*功能描述：在哈希表中查询终点站
*输入参数：key-终点站
*输出参数：ha[adr].number-航班号,ha[adr].data.departure-起点站,ha[adr].data.terminal-到达站,ha[adr].data.schedule-班期,
ha[adr].data.start-起飞时间,ha[adr].data.arrival-到达时间,ha[adr].data.type-机型,ha[adr].data.price-票价
*返回值：无
*其他说明：无
*/
void Terminal(string key)//终点站
{
    int i,flag=0;
    for(i=0; i<MAXN; ++i)
    {
        if(flag)
            break;
        else if(ha[i].data.terminal==key)
        {
            Output(i);
            FileOutput(i);
            flag=1;
        }
    }
    if(!flag)
        cout<<"对不起，查无此航班！"<<endl;
}
 
/*
*函数名称：Start
*功能描述：在哈希表中查询起飞时间
*输入参数：key-起飞时间
*输出参数：ha[adr].number-航班号,ha[adr].data.departure-起点站,ha[adr].data.terminal-到达站,ha[adr].data.schedule-班期,
ha[adr].data.start-起飞时间,ha[adr].data.arrival-到达时间,ha[adr].data.type-机型,ha[adr].data.price-票价
*返回值：无
*其他说明：无
*/
void Start(string key)
{
    int i,flag=0;
    for(i=0; i<MAXN; ++i)
    {
        if(flag) break;
        else if(ha[i].data.start==key)
        {
            Output(i);
            FileOutput(i);
            flag=1;
        }
    }
    if(!flag)
        cout<<"对不起，查无此航班！"<<endl;
}
 
/*
*函数名称：Arrival
*功能描述：在哈希表中查询到达时间
*输入参数：key-到达时间
*输出参数：ha[adr].number-航班号,ha[adr].data.departure-起点站,ha[adr].data.terminal-到达站,ha[adr].data.schedule-班期,
ha[adr].data.start-起飞时间,ha[adr].data.arrival-到达时间,ha[adr].data.type-机型,ha[adr].data.price-票价
*返回值：无
*其他说明：无
*/
void Arrival(string key)
{
    int i,flag=0;
    for(i=0; i<MAXN; ++i)
    {
        if(flag) break;
        else if(ha[i].data.arrival==key)
        {
            Output(i);
            FileOutput(i);
            flag=1;
        }
    }
    if(!flag)
        cout<<"对不起，查无此航班！"<<endl;
}
 
/*
*函数名称：FileOutput
*功能描述：航班信息存入文件
*输入参数：哈希表中的位置
*输出参数：ha[adr].number-航班号,ha[adr].data.departure-起点站,ha[adr].data.terminal-到达站,ha[adr].data.schedule-班期,
ha[adr].data.start-起飞时间,ha[adr].data.arrival-到达时间,ha[adr].data.type-机型,ha[adr].data.price-票价
*返回值：无
*其他说明：无
*/
void FileOutput(int adr)
{
    ofstream outfile("search.dat",ios::app);//追加方式写入文件
    if(!outfile)//测试文件打开操作是否成功
    {
        cerr<<"open error!"<<endl;
        exit(1);//打开不成功，则提示后退出
    }
    outfile<<"航班号"<<"\t"<<"起点站"<<"\t"<<"到达站"<<"\t"<<"班期"<<"\t"<<"\t"<<"起飞时间"<<"\t";
    outfile<<"到达时间"<<"\t"<<"机型"<<"\t"<<"票价"<<"\n";
    outfile<<ha[adr].number<<"\t"<<ha[adr].data.departure<<"\t"<<ha[adr].data.terminal<<"\t"<<ha[adr].data.schedule<<"\t"<<"\t";
    outfile<<ha[adr].data.start<<"\t"<<"\t"<<ha[adr].data.arrival<<"\t"<<"\t"<<ha[adr].data.type<<"\t"<<ha[adr].data.price<<"\n";
    outfile.close();//关闭文件。用完了必须关闭，否则会丢失数据
}
 
/*
*函数名称：Output
*功能描述：航班信息在屏幕上显示
*输入参数：哈希表中的位置
*输出参数：ha[adr].number-航班号,ha[adr].data.departure-起点站,ha[adr].data.terminal-到达站,ha[adr].data.schedule-班期,
ha[adr].data.start-起飞时间,ha[adr].data.arrival-到达时间,ha[adr].data.type-机型,ha[adr].data.price-票价
*返回值：无
*其他说明：无
*/
void Output(int adr)
{
    cout<<"航班号"<<"\t"<<"起点站"<<"\t"<<"到达站"<<"\t"<<"班期"<<"\t"<<"\t"<<"起飞时间"<<"\t";
    cout<<"到达时间"<<"\t"<<"机型"<<"\t"<<"票价"<<"\n";
    cout<<ha[adr].number<<"\t"<<ha[adr].data.departure<<"\t"<<ha[adr].data.terminal<<"\t"<<ha[adr].data.schedule<<"\t"<<"\t";
    cout<<ha[adr].data.start<<"\t"<<"\t"<<ha[adr].data.arrival<<"\t"<<"\t"<<ha[adr].data.type<<"\t"<<ha[adr].data.price<<"\n";
}
 
/*
*函数名称：Input
*功能描述：手动输入航班信息
*输入参数：哈希表中的位置
*输出参数：ha[adr].number-航班号,ha[adr].data.departure-起点站,ha[adr].data.terminal-到达站,ha[adr].data.schedule-班期,
ha[adr].data.start-起飞时间,ha[adr].data.arrival-到达时间,ha[adr].data.type-机型,ha[adr].data.price-票价
*返回值：无
*其他说明：无
*/
void Input(int adr)
{
    cin>>ha[adr].data.departure>>ha[adr].data.terminal>>ha[adr].data.schedule;
    cin>>ha[adr].data.start>>ha[adr].data.arrival>>ha[adr].data.type>>ha[adr].data.price;
}
 
int main()
{
    Work();
    return 0;
}
