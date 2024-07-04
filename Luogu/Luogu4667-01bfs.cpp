// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <deque>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int n,m;
char s[505][505];
deque<pii>dq;
pii ds[] = {mpr(1,1),mpr(1,-1),mpr(-1,1),mpr(-1,-1)};	// 格点坐标 
pii is[] = {mpr(0,0),mpr(0,-1),mpr(-1,0),mpr(-1,-1)};	// 格子坐标 
char cds[] = "\\//\\";
int vis[300005];

int ind(pii x){return x.first * m + x.second;}
int in(pii x){
	return x.first >= 1 && x.first <=n+1 && x.second >=1 && x.second <= m+1;
}

void bfs(){
	memset(vis, 0x3f, sizeof vis);
	vis[ind(mpr(1,1))] = 0;
	dq.push_back(mpr(1,1));
	while(!dq.empty()){
		pii u = dq.front();dq.pop_front();
		for(int i=0;i<4;i++){
			if(cds[i] == s[u.first + is[i].first][u.second + is[i].second]){
				pii v = mpr(u.first + ds[i].first, u.second + ds[i].second);
				if(!in(v))continue;
				if(vis[ind(u)] < vis[ind(v)]){
					vis[ind(v)] = vis[ind(u)];
					dq.push_front(v);
				}
			}else{
				pii v = mpr(u.first + ds[i].first, u.second + ds[i].second);
				if(!in(v))continue;
				if(vis[ind(u)] + 1 < vis[ind(v)]){
					vis[ind(v)] = vis[ind(u)] + 1;
					dq.push_back(v);
				}
			}
		}
	}
	printf("%d\n",vis[ind(mpr(n+1,m+1))]);
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s", s[i] + 1); 
	if((n+m) & 1)return puts("NO SOLUTION"), 0;
	bfs();

	return 0;
}


