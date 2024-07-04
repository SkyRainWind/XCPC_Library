// by SkyRainWind
#include <cstdio>
#include <vector>
#include <deque>
#include <cstring>
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
pii dr[] = {mpr(-1,0),mpr(1,0),mpr(0,-1),mpr(0,1)};
int x1,y1,x2,y2, dis[505][505];
deque<pii>dq;

int in(int x,int y){
	return x >= 1 && x <=n && y >=1 && y <= m; 
}

void bfs(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)dis[i][j] = INF;
	dq.push_back(mpr(x1,y1));
	dis[x1][y1] = 0;
	while(!dq.empty()){
		pii u = dq.front(); dq.pop_front();
		for(int i=0;i<4;i++){
			int curx = u.first + dr[i].first, cury = u.second + dr[i].second;
			if(!in(curx,cury))continue;
			int v = 1;
			if(s[u.first][u.second] == s[curx][cury])v = 0;
			if(dis[u.first][u.second] + v < dis[curx][cury]){
				dis[curx][cury] = dis[u.first][u.second] + v;
				if(v == 0)dq.push_front(mpr(curx,cury));
				else dq.push_back(mpr(curx,cury));
			}
		}
	}
	printf("%d\n",dis[x2][y2]);
}

signed main(){
	while(scanf("%d%d",&n,&m), n+m){
		for(int i=1;i<=n;i++)
			scanf("%s", s[i] + 1);
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		++ x1, ++ y1, ++ x2, ++ y2;
		bfs();
	}

	return 0;
}


