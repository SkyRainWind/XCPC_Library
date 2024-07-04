// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2e5+5;

int n,m,k;
int a[maxn],b[maxn];
LL temp[maxn], lst[maxn];

signed main(){
	LL ans = 0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int d = 31;d>=0;d--){
		for(int i=1;i<=n;i++){
			temp[i] = lst[i];
			if((a[i] >> d) & 1);
			else temp[i] += (1ll<<(d)) - (a[i] % (1ll<<(d)));
		}
		sort(temp+1,temp+n+1);
		LL sum = 0;
		for(int i=1;i<=k;i++)sum += temp[i];
		if(sum <= m){
//			printf("?? %d\n",d);
//			for(int i=1;i<=n;i++)printf("%d ",temp[i]);puts("");
			ans |= (1ll<<d);
			for(int i=1;i<=n;i++){
				if((a[i] & (1ll<<d)) == 0){
					lst[i] += ((1ll<<d) - (a[i]%(1ll<<d)));
					a[i] = 0;
				}
			}
		}
	}
	printf("%lld\n",ans);

	return 0;
}


