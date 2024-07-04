// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int n,m,p;
int mp[15][15][15][15];
int vis[15][15][(1<<10) + 5];
vector<int> key[15][15];
struct node{
	int x,y,step,st;
};
queue<node>Q;
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};

int in(int x,int y){return x >= 1 && x <= n && y >= 1 && y <= m;}

int bfs(){
	int S=0;
	for(int it : key[1][1])S |= (1 << it-1);
	Q.push(node{1,1,0,S});
	vis[1][1][S] = 1;
	
	while(!Q.empty()){
		node now = Q.front(); Q.pop();
		int x = now.x, y = now.y;
		for(int i=0;i<4;i++){
			int fx = now.x + dx[i], fy = now.y + dy[i];
			if(!in(fx, fy))continue;
			if(mp[x][y][fx][fy] == -1)continue;
			if(mp[x][y][fx][fy] && (now.st & (1 << mp[x][y][fx][fy]-1)) == 0)continue;
			if(fx == n && fy == m)return now.step + 1;
			int stt = now.st;
			for(int it : key[fx][fy])stt |= (1 << it-1);
			if(vis[fx][fy][stt])continue;
			vis[fx][fy][stt] = 1;
			Q.push(node{fx,fy,now.step + 1, stt});
		}
	}
	return -1;
}

signed main(){
	scanf("%d%d%d",&n,&m,&p);
	int mt;scanf("%d",&mt);
	while(mt --){
		int x1,y1,x2,y2,q;
		scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&q);
		if(q == 0)mp[x1][y1][x2][y2] = mp[x2][y2][x1][y1] = -1;
		else mp[x1][y1][x2][y2] = mp[x2][y2][x1][y1] = q;
	}
	scanf("%d",&mt);
	while(mt --){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		key[x][y].pb(z);
	}
	
	int ans = bfs();
	cout << ans << '\n';

	return 0;
}

