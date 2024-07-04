// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1005;

int n;
string s[maxn];
struct node{
	int to;
	int vid;
};
vector<node>g[maxn];
int in[maxn];
int st[maxn], tp;

namespace di_euler_path{	// 有向图欧拉路径
	int hd[maxn];
	void dfs(int id,int lst=0){
		for(int &i = hd[id];i<g[id].size();){i++;dfs(g[id][i-1].to, g[id][i-1].vid);}
		st[++ tp] = lst;
	}
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)cin >> s[i];
	sort(s+1,s+n+1);
	
	set<int>all;
	for(int i=1;i<=n;i++){
		node now;
		now.to = s[i][s[i].size() - 1];
		now.vid = i;
		int from = s[i][0];
		g[from].push_back(now);
		++ in[now.to];
		all.insert(s[i][0]), all.insert(s[i][s[i].size() - 1]);
	}
	
	int lst = 0;
	for(int i : all){
		if(abs((int)g[i].size() - in[i]) > 1){puts("***");return 0;}
		if(g[i].size() > in[i]){
			if(lst){puts("***");return 0;}
			else lst = i;
		}
	}
	
	di_euler_path::dfs(lst ? lst : s[1][0]);
	if(tp != n+1)puts("***");
	else{
		reverse(st+1,st+tp+1);
		for(int i=2;i<=tp;i++)cout<<s[st[i]]<<".\n"[i == tp];
	}

	return 0;
}

