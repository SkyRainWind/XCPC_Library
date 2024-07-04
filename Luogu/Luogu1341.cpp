// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 3005;

vector<int>g[maxn];
map<pii,int>mp;
int de[maxn];
int ans[maxn<<1];
int acnt=0;
namespace un_euler_path{
	int vis[maxn<<1];	// 注意 vis 记录的是边，双向边需开2倍 
	int hd[maxn];
	
	void dfs(int x){	// 当前搜到 x 号点 
		while(1){
			for(;hd[x]<g[x].size() && !mp[mpr(x,g[x][hd[x]])];)++ hd[x];
			if(hd[x] >= g[x].size())break;
			int v = g[x][hd[x]];
			-- mp[mpr(x, v)];
			-- mp[mpr(v, x)];
			++ hd[x];
			dfs(v);
		}
		ans[++ acnt] = x;
	}
}

signed main(){
	int m;
	scanf("%d",&m);
	set<char>ap, tr;
	for(int i=1;i<=m;i++){
		char s[5];scanf("%s",s + 1);
		g[s[1]].push_back(s[2]);
		g[s[2]].push_back(s[1]);
		++ de[s[1]]; ++ de[s[2]];
		ap.insert(s[1]), ap.insert(s[2]);
		++ mp[mpr(s[1], s[2])]; ++ mp[mpr(s[2], s[1])];
	}
	for(char q : ap){
		sort(g[q].begin(), g[q].end());
		if(de[q] & 1){
			tr.insert(q);
		}
	}
	if(tr.size() != 0 && tr.size() != 2)puts("No Solution");
	else{
		char start = tr.size() == 0 ? *ap.begin() : *tr.begin();
		un_euler_path::dfs(start);
		for(int i=acnt;i>=1;i--)printf("%c",ans[i]);puts("");
	}

	return 0;
}

