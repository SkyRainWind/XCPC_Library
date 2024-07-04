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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 105;

int n,m,k;
struct stu{
	LL a,b;
	int c,d;
}a[maxn];
int cmp(stu a,stu b){return a.c <= b.c;}
LL dp[55][55][105];

void ckmx(LL &p,LL q){p = max(p, q);}

signed main(){
//	freopen("51nod1636.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%I64d%I64d%d",&a[i].a,&a[i].b,&a[i].c), a[i].d = a[i]. b - a[i].a;
	if(n == 1){
		printf("YES\n%I64d\n",a[1].b);
		return 0;
	}
	
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m-1;i++)
		for(int j=0;j<=a[i].d;j++)
			dp[1][i][j] = a[i].a + j;
	
	for(int i=2;i<=n;i++){
		for(int lst=i-1;lst<=m-1;lst++){
			for(int delt = 0;delt <= a[lst].d;delt++)if(dp[i-1][lst][delt]){
				for(int now = lst + 1;now <= m; now++)if(a[now].c > a[lst].c){
					LL lsth = a[lst].a + delt;
					if(lsth + k <= a[now].b && lsth + k >= a[now].a){
						ckmx(dp[i][now][lsth + k - a[now].a], dp[i-1][lst][delt] + lsth + k);
					}
					
					if(lsth * k <= a[now].b && lsth * k >= a[now].a){
						ckmx(dp[i][now][lsth * k - a[now].a], dp[i-1][lst][delt] + 1ll * lsth * k);
					}
				}
			}
		}
	}
	LL ans = -1; 
	for(int i=n;i<=m;i++)
		for(int j = 0; j <= a[i].d; j++)
			if(dp[n][i][j])ckmx(ans, dp[n][i][j]);
	if(ans == -1)puts("NO");
	else printf("YES\n%I64d\n",ans);

	return 0;
}

