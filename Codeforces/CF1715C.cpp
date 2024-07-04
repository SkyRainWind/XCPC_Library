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

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5;

int n,m;
int a[maxn];
LL bit[maxn];
void add(int x,LL y){for(int i=x;i<=n;i+=(i&(-i)))bit[i] += y;}
LL query(int x){LL res=0;for(int i=x;i;i-=(i&(-i)))res += bit[i];return res;}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=2;i<=n;i++){if(a[i] != a[i-1])add(i,1ll*(n-i+1)*(i-1));}
	while(m --){
		int p,x;scanf("%d%d",&p,&x);
		if(p != 1){
			if(x != a[p-1])add(p,a[p-1]==a[p]?1ll*(n-p+1)*(p-1):0);
			else add(p,a[p-1]==a[p]?0:-1ll*(n-p+1)*(p-1));
		}
		
		if(p != n){
			if(a[p+1] != x)add(p+1,a[p]==a[p+1]?1ll*(n-p)*p:0);
			else add(p+1,a[p]==a[p+1]?0:-1ll*(n-p)*p);
		}
		
		printf("%I64d\n",query(n)+1ll*n*(n-1)/2+1ll*n);
		a[p] = x;
	}

	return 0;
}


