// by Balloons
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2e5+5;

int n,a[maxn];

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), a[i] -= i;
	sort(a+1, a+n+1);
	if(n == 1)return puts("0"), 0;
	int tmp = n/2, tmp2 = n/2+1;
	LL res1=0, res2=0;
	tmp = a[tmp], tmp2 = a[tmp2];
	for(int i=1;i<=n;i++)res1 += abs(a[i] - tmp);
	for(int i=1;i<=n;i++)res2 += abs(a[i] - tmp2);
	printf("%lld\n",min(res1, res2));

	return 0;
}


