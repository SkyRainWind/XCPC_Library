// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

signed main(){
	int aa = 2;
	int *p = &aa;
	printf("%p\n%p\n",&p,p);
	int a[3][3];
	for(int i=0;i<9;i++)scanf("%d",a + i);
	printf("%d\n",a[1][1]);
	int te;scanf("%d",&te);
	while(te--){
		int n;scanf("%d",&n);
		LL sum=0,mx=-1e18;;
		for(int i=1,x;i<=n;i++)scanf("%d",&x),sum+=x;
		for(int i=1,x;i<=n;i++)scanf("%d",&x),sum+=x,mx=max(mx,1ll*x);
		printf("%I64d\n",sum-mx);
	}

	return 0;
}
