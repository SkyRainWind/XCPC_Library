// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n,m;
char s[maxn][12];
int f[maxn], g[maxn];

signed main(){
	memset(f,0x3f,sizeof f);
	memset(g,0x3f,sizeof g);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s[i] + 1);
	f[1] = 0;
	for(int i=2;i<=n;i++){
		for(int j = max(1, i-m);j <= i-1;j++){
			if(s[j][i-j] == '1')f[i] = min(f[i], f[j] + 1);
		}
	}
	g[n] = 0;
	for(int i=n-1;i>=1;i--){
		for(int j = i+1;j<=min(n, i+m);j++){
			if(s[i][j-i] == '1')g[i] = min(g[i], g[j] + 1);
		}
	}
//	for(int i=1;i<=n;i++)printf("%d%c",f[i]," \n"[i==n]);
//	for(int i=1;i<=n;i++)printf("%d%c",g[i]," \n"[i==n]);

	vector<int>ans(n + 1);
	for(int k=2;k<=n-1;k++){
		ans[k] = 1e9;
		for(int i=max(1, k-m);i<=k-1;i++){
			for(int j=1;j<=m;j++){
				if(s[i][j] == '1' && i+j > k && i+j <= n-1)
					ans[k] = min(ans[k], f[i] + g[i+j] + 1);
				if(s[i][j] == '1' && i+j >= n)
					ans[k] = min(ans[k], f[i] + 1);
			}
		}
		for(int i=1;i<=m;i++){
			if(s[1][i] == '1' && 1+i > k)
				ans[k] = min(ans[k], g[1+i] + 1);
		}
		printf("%d ",ans[k] == (int)1e9 ? -1 : ans[k]);
	}

	return 0;
}

