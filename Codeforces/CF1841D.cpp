// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 4005;

int n;
struct segm{int l,r;}a[maxn];
int b[maxn],dp[maxn];
int ok[maxn][maxn];

void solve(){
	scanf("%d",&n);
	int cnt = 0;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].l,&a[i].r),b[++ cnt] = a[i].l, b[++ cnt] = a[i].r;
	sort(b+1,b+cnt+1);
	for(int i=1;i<=cnt;i++)
		for(int j=1;j<=cnt;j++)
			ok[i][j] = 0;

	for(int i=1;i<=n;i++)
		a[i].l = lower_bound(b+1,b+cnt+1,a[i].l) - b,
		a[i].r = lower_bound(b+1,b+cnt+1,a[i].r) - b;

	sort(a+1,a+n+1,[&](segm a,segm b){return a.l < b.l;});
//	for(int i=1;i<=n;i++)printf("%d %d\n",a[i].l,a[i].r);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(a[i].r >= a[j].l && a[i].r <= a[j].r)
				ok[a[i].l][a[j].r] = 1;
			else if(a[i].r >= a[j].r)
				ok[a[i].l][a[i].r] = 1;
		}
	for(int l=1;l<=cnt;l++)
		for(int i=1;i+l-1<=cnt;i++){
			int j = i+l-1;
			if(j<n)ok[i][j+1] |= ok[i][j];
			if(i>1)ok[i-1][j] |= ok[i][j];
		}
	
	int curs = 0, lstcurs = 1;
	dp[0] = 0;
	for(int i=1;i<=cnt;i++){
		dp[i] = dp[i-1];
		for(int j=i-1;j>=0;j--){
			// [j+1, i]
			if(ok[j+1][i])dp[i] = max(dp[i],dp[j] + 1);
		}
	}
//	printf("! %d %d %d %d\n",ok[1][3],dp[3],dp[9],cnt);
	cout << n - 2*dp[cnt] << '\n';
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}
