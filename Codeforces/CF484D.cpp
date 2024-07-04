// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e6+5;
int n,a[maxn];
LL f[maxn];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n == 1)return puts("0"), 0;
	if(n == 2)return printf("%d\n",abs(a[1] - a[2])), 0;
	f[1] = 0, f[2] = abs(a[1] - a[2]);
	for(int i=3;i<=n;i++){
		if((a[i]>=a[i-1]&&a[i-1]>=a[i-2]) || (a[i]<=a[i-1]&&a[i-1]<=a[i-2])){
			f[i] = f[i-1] + abs(a[i] - a[i-1]);
			// 不能用 f[i-2] 因为可能属于上一个单调区间里 
		}else{
			f[i] = max(f[i-1], f[i-2]+abs(a[i-1]-a[i]));
		}
	}
	printf("%lld\n",f[n]);

	return 0;
}
