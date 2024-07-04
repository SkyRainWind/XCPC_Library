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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2005;

int n,m;
char s[400005];
int g[400005];
int dis[400005];
int pre[400005];
pii dr[] = {mpr(1,1), mpr(1,-1), mpr(-1,1), mpr(-1,-1)};

int ind(int x,int y){return (x-1) * m + y;}
int in(int x,int y){
	return x >= 1 && x <= n && y >=1 && y <= m;
}
int around(int x,int y){
	pii drr[] = {mpr(0,1),mpr(0,-1),mpr(1,0),mpr(-1,0)};
	for(int i=0;i<4;i++){
		int fx = x + drr[i].first, fy = y + drr[i].second;
		if(!in(fx, fy))continue;
		if(g[ind(fx, fy)])return 1;
	}
	return 0;
}

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		dis[i] = INF, g[i] = 0, pre[i] = -1;
	for(int i=1;i<=n;i++){
		scanf("%s", s + 1);
		for(int j = 1;j<=m;j++){
			if(s[j] == '#'){
				g[ind(i,j)] = 1;
			}
		}
	}
	deque<pii>dq; 
	for(int i=1;i<=n;i++){
		if(g[ind(i,1)] == 1)
			dis[ind(i,1)] = 0, dq.push_front(mpr(i,1));
		else if(!around(i,1))
			dis[ind(i,1)] = 1, dq.push_back(mpr(i, 1));
	}
	while(!dq.empty()){
		pii u = dq.front(); dq.pop_front();
//		printf("%d %d %d\n",u.first,u.second,dis[ind(u.first,u.second)]);
		for(int i=0;i<4;i++){
			int curx = u.first + dr[i].first, cury = u.second + dr[i].second;
			if(!in(curx, cury))continue;
			if(around(curx,cury))continue;
			int v = 0;
			if(g[ind(curx, cury)] == 0)v = 1;
			if(dis[ind(u.first, u.second)] + v < dis[ind(curx,cury)]){
				dis[ind(curx, cury)] = dis[ind(u.first, u.second)] + v;
				pre[ind(curx,cury)] = ind(u.first,u.second);
				if(v == 0)
					dq.push_front(mpr(curx,cury));
				else
					dq.push_back(mpr(curx, cury));
			}
		}
	}
	int ans = INF, ansi;
	for(int i=1;i<=n;i++){
		ans = min(ans, dis[ind(i,m)]);
		if(ans == dis[ind(i,m)])ansi = i;
	}
//	printf("%d %d\n",ansi,ans);
	if(ans == INF)puts("NO");
	else{
		puts("YES");
		int x = ind(ansi, m);
		while(~x){
			g[x] = 1;
			x = pre[x];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(g[ind(i,j)] == 1)putchar('#');
				else putchar('.');
			}
			puts("");
		}
	}
}

signed main(){
	int te;scanf("%d",&te);
	while(te-- )solve();

	return 0;
}


