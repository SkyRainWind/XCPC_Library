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
#define int LL

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=1005;

int n,m,k,a[maxn][maxn];
int mx[maxn][maxn], mx2[maxn][maxn];
int mn[maxn][maxn], mn2[maxn][maxn];

namespace s1{
	int qu[maxn],qu2[maxn],qu3[maxn],qu4[maxn];
	void solve(){
		for(int i=1;i<=n;i++){
			int hd=1, tl=0;
			for(int j=1;j<=m;j++){
				while(hd <= tl && qu[tl] <= a[i][j])-- tl;
				qu[++ tl] = a[i][j];
				qu2[tl] = j;
				if(j < k)continue;
				while(hd <= tl && j - qu2[hd] >= k) ++ hd;
				mx[i][j - k + 1] = qu[hd];
			}
		}
		for(int j=1;j<=m-k+1;j++){
			int hd=1, tl=0;
			for(int i=1;i<=n;i++){
				while(hd <= tl && qu3[tl] <= mx[i][j]) -- tl;
				qu3[++ tl] = mx[i][j];
				qu4[tl] = i;
				if(i < k)continue;
				while(hd <= tl && i - qu4[hd] >= k) ++ hd;
				mx2[i - k + 1][j] = qu3[hd];
			}
		}
//		for(int i=1;i<=n-k+1;i++,puts(""))
//			for(int j=1;j<=m-k+1;j++)printf("%d ",mx2[i][j]);
	}
};

namespace s2{
	int qu[maxn],qu2[maxn],qu3[maxn],qu4[maxn];
	void solve(){
		for(int i=1;i<=n;i++){
			int hd=1, tl=0;
			for(int j=1;j<=m;j++){
				while(hd <= tl && qu[tl] >= a[i][j])-- tl;
				qu[++ tl] = a[i][j];
				qu2[tl] = j;
				if(j < k)continue;
				while(hd <= tl && j - qu2[hd] >= k) ++ hd;
				mn[i][j - k + 1] = qu[hd];
			}
		}
		for(int j=1;j<=m-k+1;j++){
			int hd=1, tl=0;
			for(int i=1;i<=n;i++){
				while(hd <= tl && qu3[tl] >= mn[i][j]) -- tl;
				qu3[++ tl] = mn[i][j];
				qu4[tl] = i;
				if(i < k)continue;
				while(hd <= tl && i - qu4[hd] >= k) ++ hd;
				mn2[i - k + 1][j] = qu3[hd];
			}
		}
//		for(int i=1;i<=n-k+1;i++,puts(""))
//			for(int j=1;j<=m-k+1;j++)printf("%d ",mn2[i][j]);
	}
};

signed main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	s1::solve();
	s2::solve();
	LL ans = 1e18;
	for(int i=1;i<=n-k+1;i++)
		for(int j=1;j<=m-k+1;j++)
			ans = min(ans, mx2[i][j] - mn2[i][j]);
	printf("%lld\n",ans);

	return 0;
}


