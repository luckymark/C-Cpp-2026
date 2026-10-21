#include<bits/stdc++.h>
using namespace std;
struct Node{
	string id;
	int num;
}item[1005];
int cnt;
inline void load(){
	ifstream fin("inventory.txt");
	if(!fin) return;
	string id;
	int num;
	while(fin>>id>>num){
		cnt++;
		item[cnt].id=id;
		item[cnt].num=num;
	}
	fin.close();
}
inline void save(){
	ofstream fout("inventory.txt");
	for(int i=1;i<=cnt;i++){
		fout<<item[i].id<<" "<<item[i].num<<'\n';
	}
	fout.close();
}
inline void showcase(){
	if(!cnt) cout<<"\n仓库为空\n";
	for(int i=1;i<=cnt;i++){
		cout<<item[i].id<<"  数量:"<<item[i].num<<'\n';
	}
}
inline void add(){
	string id;
	int num;
	cout<<"请输入入库的型号和数量 (如: emerald 64): ";
	cin>>id>>num;
	int f=0;
	for(int i=1;i<=cnt;i++){
		if(item[i].id==id){
			item[i].num+=num;
			f=1;
			cout<<"\nok!\n"<<item[i].num<<'\n';
			break;
		}
	}
	if(!f){
		item[++cnt].id=id;
		item[cnt].num=num;
		cout<<"\nok!\n"<<num<<'\n';
	}
}
inline void del(){
	string id;
	int num;
	cout<<"请输入出库的型号和数量 (如: A001 5): ";
	cin>>id>>num;
	int f=0;
	for(int i=1;i<=cnt;i++){
		if(item[i].id==id){
			f=1;
			if(item[i].num>=num){
				item[i].num-=num;
				cout<<"ok! 型号 "<<id<<" 剩余数量: "<<item[i].num<<'\n';
			}else{
				cout<<"error！只有 "<<item[i].num<<"个"<<num<<'\n';
			}
			break;
		}
	}
	if(!f) cout<<"error! "<<id<<"不存在!"<<'\n';
}
int main(){
	load();
	int op;
	while(1){
		cout<<"1. 显示存货列表\n";
		cout<<"2. 入库\n";
		cout<<"3. 出库\n";
		cout<<"4. 退出程序\n";
		cout<<"请输入选项 (1-4): ";
		cin>>op;
		if(op==1) showcase();
		else if(op==2) add();
		else if(op==3) del();
		else if(op==4){
			save();
			break;
		}
		else if(op==12418){//Minecraft唱片彩蛋 
			string id;
			int num;
			id="Totem of Undying";
			num=64;
			int f=0;
			for(int i=1;i<=cnt;i++){
				if(item[i].id==id){
					item[i].num+=num;
					f=1;
					break;
				}
			}
			if(!f){
				item[++cnt].id=id;
				item[cnt].num=num;
			}
			cout<<"触发彩蛋!恭喜获得不死图腾*64!!!\n"; 
		}
		else cout<<"error!\n";
	}
	return 0;
}
