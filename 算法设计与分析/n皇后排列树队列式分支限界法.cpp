#include<bits/stdc++.h>
using namespace std;
struct node{
	char ceng;//当前正在填第ceng层 
	char a[15];//节约空间用一个字节的char数组 
	bool istrue(){//判断当前层放置的皇后是不是和之前的不同斜线 
		for(int i=1;i<ceng;i++){
			if(abs(ceng-i) == abs(a[ceng]-a[i])) return false;
		}
		return true;
	}
};
queue<node> q;
int main(){
	int n;
	cin>>n;
	node x;
	for(int i=1;i<=n;i++)
		x.a[i] = i;//初始化序列 
	x.ceng = 1;
	q.push(x);
	while(q.size()){
		node t = q.front();
		q.pop();
		if(t.ceng == n){
			if(!t.istrue()) continue;//如果第n层填的数不可以的话就继续搜 
			for(int i=1;i<=n;i++) cout<<(int)t.a[i]<<" ";
			cout<<endl;
			break;
		}
		for(int i=t.ceng;i<=n;i++){
			swap(t.a[i],t.a[t.ceng]);
			if(t.istrue()){//剪枝函数，与前面的已经选择的数不同斜线 
				t.ceng ++;//这层没问题，转向下一层 
				q.push(t);
				t.ceng --;
			}
			swap(t.a[i],t.a[t.ceng]);//恢复现场，以便循环的下一次使用 
		}
	}
	return 0;
}
