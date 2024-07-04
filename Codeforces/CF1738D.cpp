// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e5 +5;

int n, a[maxn], nxt[maxn];
vector<int>v[maxn];

void solve(){
	int hd = 0;
	scanf("%d",&n);
	for(int i=0;i<=n+1;i++)v[i].clear();
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), v[a[i]].push_back(i);
	int st = n + 1;
	int state = 1;
	if(v[0].size() >= 1)st = state = 0;
	vector<int>ans;
	int cur = -1, mn = 1e9, mx = -1e9;
	int k = 0;
	for(int u : v[st]){
		if(state == 1)++ k;
		if(v[u].size())cur = u;
		else ans.push_back(u);
	}
	if(~cur)ans.push_back(cur);
	while(ans.size() < n){
		state ^= 1;
		int curv = -1;
		for(int u : v[cur]){
			if(state == 1)++ k;
			if(v[u].size())curv = u;
			else ans.push_back(u);
		}
		if(~curv)ans.push_back(curv);
		cur = curv;
	}
	printf("%d\n",k);
	for(int i : ans)printf("%d ",i);puts("");
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

