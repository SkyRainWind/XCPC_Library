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
vector<pii>g[maxn];
vector<int>now;

void dfs(int x,int fat){
	for(auto it : g[x]){
		now.pb(it.second);
		dfs(it.first, x);
	}
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		g[x].pb(mpr(y,z));
	}
	
	int qw = 0;
	for(auto it : g[1]){
		now.clear();
		now.pb(it.second);
		dfs(it.first, 1);
		
		ll sum = 0;
		for(int i : now)sum += i;
		ll to = sum / now.size();
		printf("!! %lld\n",to);
		for(int i : now)
			if(i < to)qw += to - i;
	}
	printf("%d\n",qw);

	return 0;
}

