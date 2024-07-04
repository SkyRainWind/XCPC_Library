// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5e5+5;

int n,q;
vector<pii>g[maxn];
int ans[maxn];

signed main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<n;i++){
		int x,y,w;scanf("%d%d%d",&x,&y,&w);
		g[x].pb(mpr(y,w)), g[y].pb(mpr(x,w));
		ans[x] ^= w, ans[y] ^= w;
	}
	while(q --){
		int op,x,y,w;scanf("%d",&op);
		if(op == 2){
			scanf("%d",&x);
			printf("%d\n",ans[x]);
		}else{
			scanf("%d%d%d",&x,&y,&w);
			ans[x] ^= w, ans[y] ^= w;
		}
	}

	return 0;
}

