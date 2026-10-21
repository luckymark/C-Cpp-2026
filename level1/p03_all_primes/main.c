#include<bits/stdc++.h>
using namespace std;
int isprime[1005],prime[1005],cnt;
inline void init(){
	for(int i=2;i<=1000;i++) isprime[i]=1;
	for(int i=2;i<=1000;i++){
		if(isprime[i]) prime[++cnt]=i;
		for(int j=1;j<=cnt&&prime[j]*i<=1000;j++){
			isprime[prime[j]*i]=0;
			if(i%prime[j]==0) break;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	clock_t start=clock();
	init();
	for(int i=1;i<=cnt;i++) cout<<prime[i]<<' ';
	cout<<'\n';
	clock_t end=clock();
	cout<<(end-start)*1000.0/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}
