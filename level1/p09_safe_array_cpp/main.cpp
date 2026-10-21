#include<bits/stdc++.h>
using namespace std;
template<typename T>
class SafeArray{
	T* a;
	int n;
public:
	SafeArray(int size){
		n=size;
		a=new T[n];
	}
	~SafeArray(){
		delete[] a;
	}
	int size(){return n;}
	T& operator[](int i){
		if(i<0||i>=n){
			cout<<"下标越界!\n";
			exit(0);
		}
		return a[i];
	}
};
int main(){
	SafeArray<int> a(5);
	for(int i=0;i<a.size();i++) a[i]=i;
	int sum=0;
	for(int i=0;i<a.size();i++) sum+=a[i];
	cout<<sum<<'\n';//测试数组基本功能 
	SafeArray<double> b(3);//功能3 
	b[0]=1.5;b[1]=2.5;b[2]=3.5;
	cout<<b[0]<<' '<<b[1]<<' '<<b[2]<<'\n';
	cout<<"测试越界\n";//同时实现功能要求12
	a[10]=100;
	return 0;
}
