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

int n,m,d[maxn],ds[maxn];
vector<int>g[maxn];

struct node{
	int x,dis;
};

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y), g[y].pb(x);
		++d[x], ++ d[y];
	}
	queue<node>Q;
	for(int i=1;i<=n;i++)if(d[i]==1)Q.push(node{i,1});
	int rest = n, ans=0;
	while(!Q.empty()){
		node u = Q.front();Q.pop();
		if(-- rest == m){
			printf("%d\n",u.dis);
			return 0;
		}
		int x = u.x;
		for(int v : g[x]){
			if(--d[v] == 1)
				Q.push(node{v,u.dis+1});
		}
	}

	return 0;
}

