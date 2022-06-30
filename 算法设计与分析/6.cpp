#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
constexpr auto MAX = 200;
typedef int Grade;
typedef struct linknode
{
 int number;  //学号 
 char name[20];   //姓名 	
 Grade chinese,math,english,physical,chemical,biological,total;//链表数据 语数英物化生 
 struct linknode  *next;
}LinkList;

typedef struct linkgrade
{
 int number;  //学号 
 char name[20];   //姓名 	
	//链表数据 语数英物化生 
 Grade chinese,math,english,physical,chemical,biological,threetotal,total;
 int threetotalrank,totalrank;
}LinkGrade;


void ShowAllGrade(LinkList *head);
void ShowOneGrade(LinkList *head);
void InsertOneGrade(LinkList *head); 
void oneshow(LinkList *head);
void FindInNumber(LinkList *head,int number);
void FindInName(LinkList *head,char *name);
void Save(LinkList *head);
void twoshow(LinkList *head);
void UpdateGrade(LinkList *head,int UpdateNumber);
void DeleteGrade(LinkList *head,int DeleteNumber);
void SortGrade(LinkList *head,int sort);
void back(LinkList *head);

//初始化链表 
LinkList *InitList()
{
	LinkList *head;
	head = (LinkList*)malloc(sizeof(LinkList));
	head->next = NULL;
	return head; 
}

//选择返回 
void back(LinkList *head)
{   int ok;
	printf("\n                                      按0返回主菜单！\n");
 
 for(int i=1;i<=100;i++)
 {
 
  	scanf("%d",&ok);
	if(ok==0)
    {
  		system("cls");
		oneshow(head); 
	}
	else
	{
		printf("                                      错误，请重新选择！\n"); 
		
	}
  }
}

//插入数据DAO(按学号)
void Insert(LinkList *head , int number ,char *name, Grade chinese, Grade math, Grade english, Grade physical, Grade chemical, Grade biological)
{
	LinkList *p,*s;
	p=head;
	while(p->next != NULL && p->next->number<number)
	{
		p=p->next;
	}
	if(p!=NULL)
    {
        s=(LinkList *)malloc(sizeof(LinkList));
        s->number=number;
        strcpy(s->name,name);
        s->chinese=chinese;
        s->math=math;
        s->english=english;
        s->physical=physical;
        s->chemical=chemical;
        s->biological=biological;
        s->next=p->next;
        p->next=s;
        printf("                                      插入成功！");
    }
    else
        printf("                                      插入失败！");
    Save(head);
}

//插入数据Controller(按学号)
void InsertOneGrade(LinkList *head)
{
	int ok;
	int number;  //学号 
    char name[20];   //姓名 	
	//语数英物化生 
    Grade chinese,math,english,physical,chemical,biological;
	
    printf("                                      请输入学生姓名：\n");
    scanf("%s",name);
   	printf("                                      请输入学生学号：\n");
	scanf("%d",&number);		
	printf("                                      请输入语文成绩：\n");
	scanf("%d",&chinese); 
    if(chinese<0 || chinese>150)
    {
	printf("                                      请重新输入语文成绩（0~150分）：\n");
	scanf("%d",&chinese); 
    } 
	printf("                                      请输入数学成绩：\n");
	scanf("%d",&math); 
    if(math<0 || math>150)
    {
	printf("                                      请重新输入数学成绩（0~150分）：\n");
	scanf("%d",&math); 
    } 
	printf("                                      请输入英语成绩：\n");
	scanf("%d",&english); 
    if(english<0 || english>150)
    {
	printf("                                      请重新输入英语成绩（0~150分）：\n");
	scanf("%d",&english); 
    } 
	printf("                                      请输入物理成绩：\n");
	scanf("%d",&physical); 
    if(physical<0 || physical>100)
    {
	printf("                                      请重新输入物理成绩（0~100分）：\n");
	scanf("%d",&physical); 
    } 
	printf("                                      请输入化学成绩：\n");
	scanf("%d",&chemical); 
    if(chemical<0 || chemical>100)
    {
	printf("                                      请重新输入化学成绩（0~100分）：\n");
	scanf("%d",&chemical); 
    } 
	printf("                                      请输入生物成绩：\n");
	scanf("%d",&biological); 
    if(biological<0 || biological>100)
    {
	printf("                                      请重新输入生物成绩（0~100分）：\n");
	scanf("%d",&biological); 
    } 
	Insert(head,number,name,chinese,math,english,physical,chemical,biological); 
    back(head);   
}

//查看单个学生成绩DAO (按学号)
void FindInNumber(LinkList *head,int number)
{

	int ok;
	LinkList *p;
	p=head->next;
	while(p!=NULL && p->number!=number)
	{
		p=p->next;
	}
	if(p!=NULL)
	{
 	    printf("\n-----------------------------------------------------------------------------------------------------");
	    printf("\n|      学号     姓名     语文     数学     英语     物理     化学     生物     小三科     总分      |");
        printf("\n|      %-9d%-10s%-10d%-8d%-8d%-9d%-9d%-9d%-11d%-9d |",p->number,p->name,p->chinese,p->math,p->english,p->physical,p->chemical,p->biological,p->chinese+p->math+p->english,p->chinese+p->math+p->english+p->physical+p->chemical+p->biological);
		printf("\n|---------------------------------------------------------------------------------------------------|\n");
	}
		else
	{
		printf("\n                                      Sorry，找不到该学生~\n"); 
		ShowOneGrade(head);
	}
    back(head);
} 

//查看单个学生成绩DAO(按姓名)
void FindInName(LinkList *head, char *name)
{
	int ok;
    LinkList *p;
	p=head->next;
	while(p!=NULL && strcmp(p->name,name)!=0)
	{
		p=p->next;
	}
	if(p!=NULL)
	{
		printf("\n-----------------------------------------------------------------------------------------------------");
	    printf("\n|      学号     姓名     语文     数学     英语     物理     化学     生物     小三科     总分      |");
        printf("\n|      %-9d%-10s%-10d%-8d%-8d%-9d%-9d%-9d%-11d%-9d |",p->number,p->name,p->chinese,p->math,p->english,p->physical,p->chemical,p->biological,p->chinese+p->math+p->english,p->chinese+p->math+p->english+p->physical+p->chemical+p->biological);
		printf("\n|---------------------------------------------------------------------------------------------------|\n");
	}
	else
	{
		printf("\n                                      Sorry，找不到该学生~\n"); 
		ShowOneGrade(head);
	}
   back(head);
}

//查看单个学生成绩Controller
void ShowOneGrade(LinkList *head)
{
	int choose;
	int number;
	char name[20];
	printf("                                      请选择查找方式：\n");
	printf("                                      1、按学号查找\n");
	printf("                                      2、按姓名查找\n"); 
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
	        printf("                                      请输入学号：\n");
	        scanf("%d",&number);
	        system("cls");
			FindInNumber(head,number);
			break;
		case 2:
			printf("                                      请输入姓名：\n");
			scanf("%s",name); 
			system("cls");
			FindInName(head,name);
			break;
	}
	
} 
 
 
//编辑学生成绩
void UpdateGrade(LinkList *head,int UpdateNumber)
{
    LinkList *p;
	p=head->next;
	while(p!=NULL && p->number!=UpdateNumber)
	{
		p=p->next;
	}
	if(p!=NULL)
	{
	    printf("\n-----------------------------------------------------------------------------------------------------");
	    printf("\n|      学号     姓名     语文     数学     英语     物理     化学     生物     小三科     总分      |");
        printf("\n|      %-9d%-10s%-10d%-8d%-8d%-9d%-9d%-9d%-11d%-9d |",p->number,p->name,p->chinese,p->math,p->english,p->physical,p->chemical,p->biological,p->chinese+p->math+p->english,p->chinese+p->math+p->english+p->physical+p->chemical+p->biological);
		printf("\n|---------------------------------------------------------------------------------------------------|\n");
	    printf("\n                                      请输入更新后的各科成绩：\n");
	    printf("                                      (输入格式：语文，数学，英语，物理，化学，生物)\n");
	    scanf("%d,%d,%d,%d,%d,%d",&p->chinese,&p->math,&p->english,&p->physical,&p->chemical,&p->biological);
	    printf("                                      更新成功！\n"); 
	    Save(head);
	    back(head);
	} 
	else
	{
		printf("                                      更新失败，找不到该学生！");
		back(head);
	 } 
} 

//删除学生成绩
void DeleteGrade(LinkList *head,int DeleteNumber)
{
	LinkList *p,*s;
	p=head;
	while(p->next!=NULL && p->next->number != DeleteNumber)
	{
		p=p->next;
	}
	if(p!=NULL)
	{
		s=p->next;
		p->next=s->next;
		free(s);
		printf("                                      删除成功！\n");
	    Save(head);
		back(head);
	
	}
     else
    {
          printf("                                      删除失败,找不到该学生！\n");
	      back(head);
    }
} 


//成绩排序
void SortGrade(LinkList *head,int sort)
{
	int ok;
	system("cls");
	LinkGrade aasort[MAX];
	LinkList *p;
	p=head->next;
    int i=1;
    int k,j;
	if(sort==1)
    {
    	while(p)
    	{
    		strcpy(aasort[i].name,p->name);
    		aasort[i].number=p->number;
    		aasort[i].chinese=p->chinese;
    		aasort[i].math=p->math;
    		aasort[i].english=p->english;
    		aasort[i].physical=p->physical;
    		aasort[i].chemical=p->chemical;
    		aasort[i].biological=p->biological;
    		aasort[i].threetotal=p->chinese+p->math+p->english;
    		aasort[i].total=p->chinese+p->math+p->english+p->physical+p->chemical+p->biological;
    		i++;
    		p=p->next;
		}
		for(k=2;k<i;k++)
		{
                strcpy(aasort[0].name,aasort[k].name);
				aasort[0].number=aasort[k].number;
				aasort[0].chinese=aasort[k].chinese;
				aasort[0].math=aasort[k].math;
				aasort[0].english=aasort[k].english;
				aasort[0].physical=aasort[k].physical;
				aasort[0].chemical=aasort[k].chemical;
				aasort[0].biological=aasort[k].biological;
				aasort[0].threetotal=aasort[k].threetotal;
				aasort[0].total=aasort[k].total;
			j=k-1;
			while(aasort[0].threetotal>aasort[j].threetotal)
			{
				strcpy(aasort[j+1].name,aasort[j].name);
				aasort[j+1].number=aasort[j].number;
				aasort[j+1].chinese=aasort[j].chinese;
				aasort[j+1].math=aasort[j].math;
				aasort[j+1].english=aasort[j].english;
				aasort[j+1].physical=aasort[j].physical;
				aasort[j+1].chemical=aasort[j].chemical;
				aasort[j+1].biological=aasort[j].biological;
				aasort[j+1].threetotal=aasort[j].threetotal;
				aasort[j+1].total=aasort[j].total;
				j=j-1;
			}
                strcpy(aasort[j+1].name,aasort[0].name);
				aasort[j+1].number=aasort[0].number;
				aasort[j+1].chinese=aasort[0].chinese;
				aasort[j+1].math=aasort[0].math;
				aasort[j+1].english=aasort[0].english;
				aasort[j+1].physical=aasort[0].physical;
				aasort[j+1].chemical=aasort[0].chemical;
				aasort[j+1].biological=aasort[0].biological;
				aasort[j+1].threetotal=aasort[0].threetotal;
				aasort[j+1].total=aasort[0].total;
			    aasort[k-1].threetotalrank=k-1;
				aasort[k].threetotalrank=k;
		}
		printf("\n\n\n                                      已按小三科成绩排序完毕！\n");
     	printf("\n----------------------------------------------------------------------------------------------------------------");
	    printf("\n|     小三科排名   学号     姓名     语文     数学     英语    物理     化学     生物     小三科     总分      |\n");
    	printf("\n----------------------------------------------------------------------------------------------------------------");
	    for(int t=1;t<i;t++)
	    {
	    	printf("\n|      %-12d%-8d%-10s%-10d%-8d%-8d%-9d%-9d%-9d%-11d%-9d |\n",aasort[t].threetotalrank,aasort[t].number,aasort[t].name,aasort[t].chinese,aasort[t].math,aasort[t].english,aasort[t].physical,aasort[t].chemical,aasort[t].biological,aasort[t].threetotal,aasort[t].total);
		    printf("\n----------------------------------------------------------------------------------------------------------------");
		}
		back(head);
}
		
	else
	{
		while(p)
    	{
    		strcpy(aasort[i].name,p->name);
    		aasort[i].number=p->number;
    		aasort[i].chinese=p->chinese;
    		aasort[i].math=p->math;
    		aasort[i].english=p->english;
    		aasort[i].physical=p->physical;
    		aasort[i].chemical=p->chemical;
    		aasort[i].biological=p->biological;
    		aasort[i].threetotal=p->chinese+p->math+p->english;
    		aasort[i].total=p->chinese+p->math+p->english+p->physical+p->chemical+p->biological;
    		i++;
    		p=p->next;
		}
		for(k=2;k<i;k++)
		{
                strcpy(aasort[0].name,aasort[k].name);
				aasort[0].number=aasort[k].number;
				aasort[0].chinese=aasort[k].chinese;
				aasort[0].math=aasort[k].math;
				aasort[0].english=aasort[k].english;
				aasort[0].physical=aasort[k].physical;
				aasort[0].chemical=aasort[k].chemical;
				aasort[0].biological=aasort[k].biological;
				aasort[0].threetotal=aasort[k].threetotal;
				aasort[0].total=aasort[k].total;
			j=k-1;
			while(aasort[0].total>aasort[j].total)
			{
				strcpy(aasort[j+1].name,aasort[j].name);
				aasort[j+1].number=aasort[j].number;
				aasort[j+1].chinese=aasort[j].chinese;
				aasort[j+1].math=aasort[j].math;
				aasort[j+1].english=aasort[j].english;
				aasort[j+1].physical=aasort[j].physical;
				aasort[j+1].chemical=aasort[j].chemical;
				aasort[j+1].biological=aasort[j].biological;
				aasort[j+1].threetotal=aasort[j].threetotal;
				aasort[j+1].total=aasort[j].total;
				j=j-1;
			}
                strcpy(aasort[j+1].name,aasort[0].name);
				aasort[j+1].number=aasort[0].number;
				aasort[j+1].chinese=aasort[0].chinese;
				aasort[j+1].math=aasort[0].math;
				aasort[j+1].english=aasort[0].english;
				aasort[j+1].physical=aasort[0].physical;
				aasort[j+1].chemical=aasort[0].chemical;
				aasort[j+1].biological=aasort[0].biological;
				aasort[j+1].threetotal=aasort[0].threetotal;
				aasort[j+1].total=aasort[0].total;
			    aasort[k-1].totalrank=k-1;
				aasort[k].totalrank=k;
		}
		printf("\n\n\n                                      已按总成绩排序完毕！\n");
	    printf("\n----------------------------------------------------------------------------------------------------------------");
	    printf("\n|     总排名      学号     姓名     语文     数学     英语     物理     化学     生物     小三科     总分      |\n");
	    printf("\n----------------------------------------------------------------------------------------------------------------");
	    for(int t=1;t<i;t++)
	    {
	    	printf("\n|      %-12d%-8d%-10s%-10d%-8d%-8d%-9d%-9d%-9d%-11d%-9d |\n",aasort[t].totalrank,aasort[t].number,aasort[t].name,aasort[t].chinese,aasort[t].math,aasort[t].english,aasort[t].physical,aasort[t].chemical,aasort[t].biological,aasort[t].threetotal,aasort[t].total);
		    printf("\n----------------------------------------------------------------------------------------------------------------");
		}
	 back(head);
	}
} 


//分类合计
void Category(LinkList *head)
{
	int i=1,j=1,k=1;
	LinkList *p;
	LinkGrade aasort[MAX],bbsort[MAX],ccsort[MAX];
	p=head->next;
	int a,b,c,d,e,f;
	printf("                                      请输入分类标准:\n");
	printf("                                      A等生区间：750分~~?分\n");
	scanf("%d",&a);
	printf("                                      C等生区间：?分~~0分\n");
	scanf("%d",&b);
	while(p)
	{
		if(p->chinese+p->math+p->english+p->physical+p->chemical+p->biological>a) 
		{
            strcpy(aasort[i].name,p->name);
    		aasort[i].number=p->number;
    		aasort[i].chinese=p->chinese;
    		aasort[i].math=p->math;
    		aasort[i].english=p->english;
    		aasort[i].physical=p->physical;
    		aasort[i].chemical=p->chemical;
    		aasort[i].biological=p->biological;
    		aasort[i].threetotal=p->chinese+p->math+p->english;
    		aasort[i].total=p->chinese+p->math+p->english+p->physical+p->chemical+p->biological;
    		i++;
		   p=p->next;
		}
		else if(p->chinese+p->math+p->english+p->physical+p->chemical+p->biological>b)
		{
			 strcpy(bbsort[j].name,p->name);
    		bbsort[j].number=p->number;
    		bbsort[j].chinese=p->chinese;
    		bbsort[j].math=p->math;
    		bbsort[j].english=p->english;
    		bbsort[j].physical=p->physical;
    		bbsort[j].chemical=p->chemical;
    		bbsort[j].biological=p->biological;
    		bbsort[j].threetotal=p->chinese+p->math+p->english;
    		bbsort[j].total=p->chinese+p->math+p->english+p->physical+p->chemical+p->biological;
    		j++;
		   p=p->next;
		}
		else
		{
			 strcpy(ccsort[k].name,p->name);
    		ccsort[k].number=p->number;
    		ccsort[k].chinese=p->chinese;
    		ccsort[k].math=p->math;
    		ccsort[k].english=p->english;
    		ccsort[k].physical=p->physical;
    		ccsort[k].chemical=p->chemical;
    		ccsort[k].biological=p->biological;
    		ccsort[k].threetotal=p->chinese+p->math+p->english;
    		ccsort[k].total=p->chinese+p->math+p->english+p->physical+p->chemical+p->biological;
    		k++;
		   p=p->next;
		}
		
	}
	    system("cls");
	    printf("\n\n\n                                      A等生(750~%d)如下（按学号排序）\n",a);
	    printf("\n----------------------------------------------------------------------------------------------------------------");
	    printf("\n|      学号     姓名     语文     数学     英语     物理     化学     生物     小三科     总分      |\n");
	    printf("\n----------------------------------------------------------------------------------------------------------------");
	     for(int t=1;t<i;t++)
	    {
	    	printf("\n|      %-8d%-10s%-10d%-8d%-8d%-9d%-9d%-9d%-11d%-9d |\n",aasort[t].number,aasort[t].name,aasort[t].chinese,aasort[t].math,aasort[t].english,aasort[t].physical,aasort[t].chemical,aasort[t].biological,aasort[t].threetotal,aasort[t].total);
		    printf("\n----------------------------------------------------------------------------------------------------------------");
		}
		printf("\n\n\n                                      B等生(%d~%d)如下（按学号排序）\n",a,b);
	    printf("\n----------------------------------------------------------------------------------------------------------------");
	    printf("\n|      学号     姓名     语文     数学     英语     物理     化学     生物     小三科     总分      |\n");
	    printf("\n----------------------------------------------------------------------------------------------------------------");
	     for(int t=1;t<j;t++)
	    {
	    	printf("\n|      %-8d%-10s%-10d%-8d%-8d%-9d%-9d%-9d%-11d%-9d |\n",bbsort[t].number,bbsort[t].name,bbsort[t].chinese,bbsort[t].math,bbsort[t].english,bbsort[t].physical,bbsort[t].chemical,bbsort[t].biological,bbsort[t].threetotal,bbsort[t].total);
		    printf("\n----------------------------------------------------------------------------------------------------------------");
		}
		printf("\n\n\n                                      C等生(%d~0)如下（按学号排序）\n",b);
	    printf("\n----------------------------------------------------------------------------------------------------------------");
	    printf("\n|      学号     姓名     语文     数学     英语     物理     化学     生物     小三科     总分      |\n");
	    printf("\n----------------------------------------------------------------------------------------------------------------");
	     for(int t=1;t<k;t++)
	    {
	    	printf("\n|      %-8d%-10s%-10d%-8d%-8d%-9d%-9d%-9d%-11d%-9d |\n",ccsort[t].number,ccsort[t].name,ccsort[t].chinese,ccsort[t].math,ccsort[t].english,ccsort[t].physical,ccsort[t].chemical,ccsort[t].biological,ccsort[t].threetotal,ccsort[t].total);
		    printf("\n----------------------------------------------------------------------------------------------------------------");
		}
		 back(head);
} 

 
//启动初始化页面
void oneshow(LinkList *head)  
{
	int Delete;
	printf("\n\n\n\n\n");
	printf("\n                                               欢迎进入学生成绩管理系统           \n");
	printf("\n                                      ============================================");
	printf("\n                                      |             请选择功能编号               |");
	printf("\n                                      |         1、查看所有学生成绩              |");
    printf("\n                                      |         2、查找单个学生成绩              |");
    printf("\n                                      |         3、插入单个学生成绩              |");
    printf("\n                                      |         4、删除单个学生成绩              |");
    printf("\n                                      |         5、     退出                     |");
    printf("\n                                      ============================================\n");
	int choose;
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
			system("cls");
			ShowAllGrade(head);
			break;
		case 2:
			system("cls");
			ShowOneGrade(head);
			break;
		case 3:
			system("cls");
			InsertOneGrade(head);
            break;
        case 4:
        	system("cls");
        	printf("\n                                      请选择需要删除的学生学号：(按0返回)\n");
			scanf("%d",&Delete);
			if(Delete==0)
			{ 
			  system("cls");
			  oneshow(head);
	        } 
		    DeleteGrade(head,Delete);
		    break;
		case 5:
		    exit(0); 
        default:
	        system("cls");
        	printf("错误！请重新选择：\n");
			oneshow(head); 
	}
}

//功能选择页面2
void twoshow(LinkList *head)
{
	int choose,sort;
	int UpdateNumber,DeleteNumber;
	printf("                                      可对当前成绩表单进行处理\n");
	printf("                                      选择功能编号：\n");
	printf("                                      0、返回主界面\n");
	printf("                                      1、编辑成绩\n");
	printf("                                      2、删除学生\n");
	printf("                                      3、成绩排序\n");
	printf("                                      4、分类合计\n");
 
    scanf("%d",&choose);
    switch(choose)
    {
    	case 1:
    		printf("                                      请选择要编辑的学生学号：\n");
			scanf("%d",&UpdateNumber);
			UpdateGrade(head,UpdateNumber);
			break;
	    case 2:
	    	printf("                                      请选择要删除的学生学号：\n");
	    	scanf("%d",&DeleteNumber);
	    	DeleteGrade(head,DeleteNumber);
	    	break;
    	case 3:
    		printf("                                      请选择排序方式：\n");
    		printf("                                      1、按小三科成绩排序\n");
    		printf("                                      2、按总成绩排序\n");
    		scanf("%d",&sort);
    		SortGrade(head,sort);
    		break; 
   		case 0:
   			system("cls");
   			oneshow(head);
   			break;
	    case 4:
	    	system("cls");
	    	Category(head);
	    	break;
	}
    
} 

//查看所有学生成绩页面 
void ShowAllGrade(LinkList *head){
	int ok;
	LinkList *nn;
	nn=head->next;
    printf("\n\n                                      1、处理当前数据\n");
    printf("                                      2、返回主菜单\n");
	printf("\n-----------------------------------------------------------------------------------------------------");
	printf("\n|      学号     姓名     语文     数学     英语     物理     化学     生物     小三科     总分      |");
	printf("\n-----------------------------------------------------------------------------------------------------");
	while(nn!=NULL)
	{
		printf("\n|      %-9d%-10s%-10d%-8d%-8d%-9d%-9d%-9d%-11d%-9d |",nn->number,nn->name,nn->chinese,nn->math,nn->english,nn->physical,nn->chemical,nn->biological,nn->chinese+nn->math+nn->english,nn->chinese+nn->math+nn->english+nn->physical+nn->chemical+nn->biological);
		printf("\n|---------------------------------------------------------------------------------------------------|\n");
		nn=nn->next;
    } 
    for(int i=1;i<=100;i++)
	{
	scanf("%d",&ok);
    if(ok==1)
       twoshow(head);
    else if(ok==2)
    {
    	system("cls");
    	oneshow(head);
	}
	else
	{
		printf("                                      错误，请重新选择！\n");
	}
    }
    
}

//数据存盘
void Save(LinkList *head){   
    FILE* fp;  
    LinkList *p;  
    int count=0;  
    fp=fopen("student.txt","wb");/*以只写方式打开二进制文件*/  
    p=head->next;  
    while(p)  
    {  
        if(fwrite(p,sizeof(LinkList),1,fp)==1)  
        {  
            p=p->next;  
            count++;  
        }  
        else break;  
    }  
    if(count>0)  
    {  
        printf("\n                                      当前还有%d名学生记录\n",count);  
         
    }  
    else  
        printf("                                      空文件，保存失败!!\n");  
    fclose(fp); //关闭此文件  
}  


//主函数 
int main()
{
	LinkList *r = InitList();
	LinkList *p,*head;
	head=r;
	FILE *fp; 
    fp=fopen("student.txt","ab+"); 
    while(!feof(fp))  
    {  
        p=(LinkList*)malloc(sizeof(LinkList));  
        if(fread(p,sizeof(LinkList),1,fp)==1) /*一次从文件中读取一条学生成绩记录*/  
        {  
            p->next=NULL;  
            r->next=p;  
            r=p;                            /*r指针向后移一个位置*/  
        }  
    }  
    fclose(fp); /*关闭文件*/  
	oneshow(head);
	return 0;
}



