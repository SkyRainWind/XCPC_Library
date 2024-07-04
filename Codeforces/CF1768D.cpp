// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5 + 5;

vector<int>g[maxn];
int vis[maxn], n, a[maxn];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),g[i].clear(),vis[i]=0;
	for(int i=1;i<=n;i++)g[i].push_back(a[i]);
	int ans = 0, gg = 0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			set<int>S;
			int x=i,nx=a[i],sz = 1;
			S.insert(x);vis[x] = 1;
			
			while(x != nx){
				++ sz;
				S.insert(nx);
				vis[nx] = 1;
				nx = a[nx];
			}
			
			for(auto now : S)
				if(S.count(now-1))gg = 1;
			ans += sz - 1;
		}
	}
	if(!gg)printf("%d\n",ans + 1);
	else printf("%d\n",ans - 1);
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

