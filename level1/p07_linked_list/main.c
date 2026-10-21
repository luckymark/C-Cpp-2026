#include<bits/stdc++.h>
using namespace std;
struct Node{
	int v;
	Node* nxt;
};
Node* head;
inline void showcase(){
	Node* p=head;
	while(p){
		cout<<p->v<<" ";
		p=p->nxt;
	}
	cout<<'\n';
}
inline void Reverse(){
	Node* pre=0;
	Node* p=head;
	while(p){
		Node* nxt=p->nxt;
		p->nxt=pre;
		pre=p;
		p=nxt;
	}
	head=pre;
}
inline int First(){
	Node* p=head;
	int cnt=1;
	while(p){
		if(p->v==5) return cnt;
		p=p->nxt;
		cnt++;
	}
	return -1;
}
inline int Next(int pos){
	if(pos==-1) return -1;
	Node* p=head;
	int cnt=1;
	while(p&&cnt<=pos){
		p=p->nxt;
		cnt++;
	}
	while(p){
		if(p->v==5) return cnt;
		p=p->nxt;
		cnt++;
	}
	return -1;
}
int main(){
	int a[10]={1,3,1,4,5,2,1,5,2,1};
	Node* tail=0;
	for(int i=1;i<=10;i++){
		Node* p=new Node();
		p->v=a[i-1];
		p->nxt=0;
		if(!head) head=p;
		else tail->nxt=p;
		tail=p;
	}
	showcase();
	Reverse();
	showcase();
	int p1=First();
	if(p1==-1) cout<<"没有5!\n";
	else{
		cout<<"第一个5的位置: "<<p1<<'\n';
		int p2=Next(p1);
		if(p2==-1) cout<<"没有下一个5!\n";
		else cout<<"下一个5的位置: "<<p2<<'\n';
	}
	return 0;
}
