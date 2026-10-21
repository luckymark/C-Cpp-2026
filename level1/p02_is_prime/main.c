//Miller-Rabin 用七个合适质数确保了一定范围内的绝对正确性 避免随机性 
//复杂度7logn 支持1e18级别 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[7]={2,325,9375,28178,450775,9780504,1795265022};
ll fpow(ll a,ll b,ll mod){
	ll s=1;
	while(b){
		if(b&1) s=(__int128)s*a%mod;
		a=(__int128)a*a%mod;
		b>>=1;
	}
	return s;
}
int check(ll x){
	if(x==1) return 0;
	if(x==2) return 1;
	if(x%2==0) return 0;
	for(int i=0;i<7;i++){
    	ll d=x-1;
   		while(d%2==0) d>>=1;
    	ll t=fpow(a[i],d,x);
    	if(!t) continue;
    	while((d!=x-1)&&(t!=1)&&(t!=x-1)){
     		t=(__int128)t*t%x;
     		d=d<<1;
    	}
    	if(!((t==x-1)||(d%2))) return 0;
	}
	return 1;
}
int main(){
	ll x;
	cin>>x;
	if(check(x)) cout<<x<<" is a prime";
	else cout<<x<<" isn't a prime";
	return 0;
}
