// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

#define int LL

long long Mod_Mul(long long a,long long b,long long mod)
{
    long long sum=0;
    while(b)
    {
        if(b&1) sum=(sum+a)%mod;
        b>>=1;
        a = (a+a)%mod;
    }
    return sum;
}
int pw(int x,int y,int mod){
	if(!y)return 1;if(y==1)return x;
	int mid = pw(x,y>>1,mod);
	int r = Mod_Mul(mid,mid,mod);
	if(y&1)return Mod_Mul(r,x,mod);
	return r;
}

int exgcd(int a,int b,int &x,int &y){
	if(!b){
		x = 1, y = 0;
		return a;
	}
	int ret = exgcd(b,a%b,x,y);
	int t = x;
	x = y;
	y = t-a/b*y;
	return ret;
} 

signed main(){
	LL n,m,l;scanf("%lld%lld%lld",&n,&m,&l);
	LL res = l;
	int cur = pw(2,m,n+1);
	int x,y;exgcd(cur,n+1,x,y);
	x = (x%(n+1)+(n+1))%(n+1);
	res = Mod_Mul(res,x,n+1);
	printf("%lld\n",res);

	return 0;
}


