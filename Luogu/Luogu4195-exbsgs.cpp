// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

namespace exbsgs{
	map<int,int> f;
	int gcd(int a,int b){return !b?a:gcd(b,a%b);} 
	void exgcd(int a,int b,int &x,int &y){
		if(!b)x = 1, y = 0;
		else{
			exgcd(b,a%b,x,y);
			int t=x;x=y;y=t-a/b*y;
		}
	}
	int inv(int a,int b){
		int x,y;
		exgcd(a,b,x,y);
		return (x%b+b)%b;
	}
	
	int pw(int x,int y,int mod){
		if(!y)return 1;
		if(y==1)return x;
		int mid=pw(x,y>>1,mod);
		if(y&1)return 1ll*mid*mid%mod*x%mod;
		return 1ll*mid*mid%mod;
	}
	
	int bsgs(int a,int b,int p){	// a^x = b(mod p)
		f.clear();
		int m = ceil(sqrt(p));
		b %= p;
		for(int i=1;i<=m;i++){
			b=1ll*b*a%p;
			f[b] = i;
		}
		int tmp = pw(a, m, p);
		b = 1;
		for(int i=1;i<=m;i++){
			b = 1ll*b*tmp%p;
			if(f[b])return (i*m-f[b]+p)%p;
		}
		return -1;
	}
	
	int exbsgs(int a,int b,int p){
		a%=p, b%=p;
		if(b==1||p==1)return 0;
		int g=gcd(a,p),k=0,na=1;
		while(g>1){
			if(b%g != 0)return -1;
			++k;b/=g;p/=g;na=1ll*na*(a/g)%p;
			if(na == b)return k;
			g = gcd(a,p);
		}
		int f = bsgs(a, 1ll*b*inv(na,p)%p,p);
		if(f==-1)return -1;
		return f+k;
	}
}

void read(int &ff){
	int x=0,f=1;
	char ch=getchar();
	while(ch < '0' || ch>'9'){ch=='-'?f=-1:1;ch = getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	ff = x*f;
}

signed main(){
//	freopen("P4195.in","r",stdin);
//	freopen("P4195.out","w",stdout);
	int a,p,b;
	while(1){
		read(a);read(p);read(b);
		if(a+p+b==0)break;
		int t = exbsgs::exbsgs(a,b,p);
		if(t == -1)puts("No Solution");
		else printf("%d\n",t);
	}

	return 0;
}

