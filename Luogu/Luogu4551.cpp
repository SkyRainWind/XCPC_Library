// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=100000 * 31 + 5;

int n;
vector<pii>g[100005];
int tr[maxn][2], totr;

int ans = 0;
void query(int x){
	int now = 0, r = 0;
	for(int i=30;i>=0;i--){
		int cc = (x & (1<<i));
		if(cc)cc = 1;
		int cur = tr[now][cc ^ 1];
		if(cur){
			r |= (1<<i); 
//			printf("?? %d %d\n",x,i);
			now = tr[now][cc ^ 1];
		}else now = tr[now][cc];
	}
	ans = max(ans ,r);
}

void upd(int x){
	int now = 0;
	for(int i=30;i>=0;i--){
		int cc = (x & (1<<i));
		if(cc) cc = 1;
//		int &cur = tr[now][cc];
		if(!tr[now][cc]){
//			printf("%d %d\n",i,cc);
			tr[now][cc] = ++ totr;
		}
		now = tr[now][cc];
	}
}

void dfs(int x,int cur = 0, int fat = -1){
	if(~fat)query(cur);
	upd(cur);
	for(pii u : g[x]){
		if(u.first == fat)continue;
		dfs(u.first, cur ^ u.second, x);
	}
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		g[x].push_back(mpr(y,z));g[y].push_back(mpr(x,z));
	}
	dfs(1);
	printf("%d\n",ans);

	return 0;
}


