// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int n,m,mod;
int f[105][35];

signed main(){
	scanf("%d%d%d",&n,&m,&mod);
	
	int ans = 0;
	for(int s=0;s<m;s++){
		memset(f,0,sizeof f);
		f[0][0] = 1;
		for(int i=1;i<=n;i++)
			for(int j=0;j<m;j++){
				if(f[i-1][j]){
					for(int k=0;k<m;k++)
						if(k != (s-k+m)%m)
							(f[i][(j+k)%m] += f[i-1][j]) %= mod;
				}
			}
		(ans += f[n][s]) %= mod;
	}
	int t = 1;
	for(int i=1;i<=n;i++)t = 1ll*t*m%mod;
	ans = (t - ans + mod) % mod;
	printf("%d\n",ans);

	return 0;
}

