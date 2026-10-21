#include<bits/stdc++.h>
using namespace std;
inline void hanoi(int n,char a,char b,char c){
	//代表把n个圆盘从a搬到c的操作函数 
	if(!n) return;
	hanoi(n-1,a,c,b);//n-1 a->b
	cout<<a<<" -> "<<c<<'\n';//1 a->c
	hanoi(n-1,b,a,c);//n-1 b->c
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//int n=64; 虽题目要求是64但显然无法实现 因此采用输入n的形式 
	int n;
	cin>>n;
	hanoi(n,'A','B','C');
	return 0;
}
