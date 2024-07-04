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

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=1e5+5;

int n;
LL a[maxn];
LL s;

signed main(){
	scanf("%d%I64d",&n,&s);
	for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	int l = 1, r=1,res=0;
	LL sum=a[l];
	a[n+1] = 1e18;
	for(int i=1;i<=n;i++){
		while(r <= n && sum<=s){
			sum += a[++r];
		}
		sum -= a[l];
		res = max(res,r-l);
		++ l;
	} 
	printf("%d\n",res);

	return 0;
}


