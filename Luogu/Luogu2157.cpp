// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1005;

int n,a[maxn],b[maxn];
ll dp[maxn][(1 << 8)+5][17];
int st[maxn][9];

void ck(ll &a,ll b){a = min(a, b);}

void solve(){
	memset(dp,0x3f,sizeof dp);
	memset(st,0,sizeof st);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]),st[i][0]=1;
	
	for(int k=1;k<=7;k++){
		for(int i=1;i+k<=n;i++){
			if(k <= b[i]){
				st[i][k] = 1;
				for(int j=i+1,t=k;j<=i+k-1;j++,t--){
					st[i][k] &= st[j][t-1];
				}
			}
		}
	}
	
	for(int k=0;k<=b[1];k++)if(st[1][k]){
		dp[1][1 << k][k + 8] = 0;
	}
	
	for(int i=1;i<=n;i++)
		for(int S=0;S<=(1 << b[i]+1)-1;S++){
			for(int k=max(-8, -i+1);k<=7&&i+k<=n;k++){
				if(S & 1){
					ck(dp[i+1][S >> 1][k+7], dp[i][S][k+8]);
					continue;
				}
				if(k >=0){
					if((S&(1<<k)) && k <= b[i]);
					else continue;
				}
				// k + 8
				int fi = inf;
				for(int l=0;l<=b[i]&&i+l<=n;l++)if((S&(1<<l)) == 0){
					if(i+l>fi)break; 
					fi = min(fi, i+l+b[i+l]);
					int T = S ^ (1<<l);
					ck(dp[i][T][l + 8], dp[i][S][k + 8] + (a[i+k]|a[i+l]) - (a[i+k]&a[i+l]));
				}
			}
		}
	ll res = inf;
	for(int i=-8;i<=0;i++)ck(res, dp[n][1][i + 8]);
	cout << res << '\n';
}

signed main(){
//	freopen("Luogu2157.in","r",stdin);
	int te=1;scanf("%d",&te);
	while(te--)solve();

	return 0;
}
