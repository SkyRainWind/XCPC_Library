// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 4e5+5;

int n,k;
int a[maxn], b[maxn];
ll dist[maxn][20], cost[maxn][20], sum[maxn];

int md(int x){
	if(x <= n)return x;
	return x-n;
}

void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), a[i+n] = a[i];
	for(int i=1;i<=n;i++)scanf("%d",&b[i]), b[i+n] = b[i];
	
	sum[0] = 0;
	for(int i=1;i<=2*n;i++)sum[i] = sum[i-1] + a[md(i)];
	
	int cnt = 0;
	
	for(int i=2*n;i>=1;i--){
		if(b[i] == 2){
			cost[i][0] = 2*a[i];
			dist[i][0] = 1;
		}else if(cnt == 0){
			cost[i][0] = a[i];
			dist[i][0] = 1;
		}else{
			int to = lower_bound(sum+i, sum+i+cnt+1, sum[i-1] + k) - sum;
			if(to == i+cnt+1){
				cost[i][0] = sum[i+cnt] - sum[i-1];
				dist[i][0] = cnt+1;
			}else{
				int delt = to - i;
				if(sum[to] == sum[i-1] + k){
					cost[i][0] = k;
					dist[i][0] = delt+1;
				}else{
					cost[i][0] = k + 2 * (sum[to] - sum[i-1] - k);
					dist[i][0] = delt+1;
				}
			}
		}
		if(b[i] == 2)++ cnt;
		else cnt = 0;
	}
	
	for(int j=1;j<=18;j++)
		for(int i=1;i<=n;i++){
			dist[i][j] = dist[i][j-1] + dist[md(i + dist[i][j-1])][j-1];
			cost[i][j] = cost[i][j-1] + cost[md(i + dist[i][j-1])][j-1];
		}
	
	for(int i=1;i<=n;i++){
		ll r = 0, now = i;
		int tot = 0;
		for(int j=18;j>=0;j--){
			if(tot+dist[now][j] <= n)
				r += cost[now][j],
				tot += dist[now][j],
				now = md(now + dist[now][j]);
		}
		if(tot < n){
			r += sum[i+n-1] - sum[i+tot-1];
		}
		printf("%lld ",r);
	}
	puts("");
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

