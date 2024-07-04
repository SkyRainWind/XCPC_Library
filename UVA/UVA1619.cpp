// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5;
int n,a[maxn],l[maxn],r[maxn];LL sum[maxn];
signed main(){
	int tt=0;
	while(scanf("%lld",&n) != EOF){
		if(++ tt >= 2)puts("");
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]), l[i] = r[i] = i, sum[i] = sum[i-1] + a[i];
		for(int i=1;i<=n;i++){
			while(l[i] > 1 && a[i] <= a[l[i] - 1])l[i] = l[l[i] - 1];
		}
		for(int i = n;i>=1;i--){
			while(r[i] < n && a[i] <= a[r[i] + 1])r[i] = r[r[i] + 1];
		}
		LL ans = 0,la=1,ra=1;
		for(int i=1;i<=n;i++){
			LL t = sum[r[i]] - sum[l[i] - 1];
			if(1ll * t * a[i] > ans){
				ans = 1ll*t*a[i]; 
				la = l[i], ra = r[i];
			}else if(1ll * t * a[i] == ans){
				if(r[i] - l[i] < ra - la){
					ra = r[i], la = l[i];
				}
			}
		}
		printf("%lld\n%lld %lld\n",ans,la,ra);
	}

	return 0;
}


