// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <deque>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2005;

int n,m,r,c,lf,ri;
char s[maxn];
int g[maxn][maxn];
pii dr[] = {mpr(0,-1), mpr(0,1), mpr(1,0), mpr(-1,0)};
deque<pii>dq;
int dis[maxn][maxn];

int in(int x,int y){
	return x >= 1 && x <=n && y >= 1 && y <= m;
}

void bfs(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)dis[i][j] = INF;
	dq.push_back(mpr(r,c));
	dis[r][c] = 0;
	while(!dq.empty()){
		pii cur = dq.front();dq.pop_front();
		for(int i = 0;i<4;i++){
			int curx = cur.first + dr[i].first, cury = cur.second + dr[i].second;
			if(!in(curx,cury))continue;
			if(g[curx][cury] == 0)continue;
			int v = i == 0 ? 1 : 0;
			if(dis[cur.first][cur.second] + v < dis[curx][cury]){
				dis[curx][cury] = dis[cur.first][cur.second] + v;
				if(v)dq.push_front(mpr(curx, cury));
				else dq.push_back(mpr(curx, cury));
			}
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(!g[i][j])continue;
			int curlf = dis[i][j], curri = (j - c) + curlf;
			if(curlf <= lf && curri <= ri)++ ans;
		}
	printf("%d\n",ans);
}

signed main(){
	scanf("%d%d",&n,&m);
	scanf("%d%d",&r,&c);
	scanf("%d%d",&lf,&ri);
	for(int i=1;i<=n;i++){
		scanf("%s", s + 1);
		for(int j=1;j<=m;j++)
			if(s[j] == '.')
				g[i][j] = 1;
	}
	bfs();

	return 0;
}


