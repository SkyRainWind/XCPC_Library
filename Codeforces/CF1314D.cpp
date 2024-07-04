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
double get_time(){return (double)clock()/CLOCKS_PER_SEC;}

int n,k,a[85][85];
vector<int>w[2];
ll f[15][85];

void ck(ll &a,ll b){a = min(a, b);}

signed main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	
	double time_limit = get_time() + 2.7;
	ll ans = 1e18;
	while(get_time() < time_limit){
		memset(f,0x3f,sizeof f);
		w[0].clear(), w[1].clear();
		for(int i=1;i<=n;i++)w[i == 1 ? 1 : rand()%2].pb(i);
		f[0][1] = 0;
		for(int i=1;i<=k;i++){
			for(int u : w[0])
				for(int v : w[1]){
					// i&1 -> v->u  other u->v
					if(i&1)ck(f[i][u],f[i-1][v] + a[v][u]);
					else ck(f[i][v],f[i-1][u] + a[u][v]);
				}
		}
		ans = min(ans, f[k][1]);
	}
	cout << ans << '\n';

	return 0;
}

