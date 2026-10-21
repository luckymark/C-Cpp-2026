#include<bits/stdc++.h>
using namespace std;
struct Animal{
	virtual void shout(){}
	//virtual ~Animal(){}
};
struct Dog:Animal{
	void shout(){ cout<<"汪汪\n"; }
};
struct Cat:Animal{
	void shout(){ cout<<"喵喵\n"; }
};
struct Duck:Animal{
	void shout(){ cout<<"嘎嘎\n"; }
};
struct Human:Animal{
	void shout(){ cout<<"啊~\n"; }
};
struct Bird:Animal{
	void shout(){ cout<<"叽叽\n"; }
};
struct WolfDog:Dog{
	void shout(){ cout<<"嗷呜\n"; }
};
struct Zoo{
	Animal* a[105];
	int cnt=0;
	void add(Animal* p){ a[++cnt]=p; }
	void Call(){
		for(int i=1;i<=cnt;i++) a[i]->shout();
	}
};
int main(){
	Zoo z;
	z.add(new Dog());
	z.add(new Cat());
	z.add(new Duck());
	z.add(new Human());//开个玩笑 
	z.Call();
	cout<<"\n\n";
	z.add(new Bird());
	z.add(new WolfDog());
	z.Call();
	return 0;
}
