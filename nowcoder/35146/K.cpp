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

int n,m;
char s[105][105];

struct node{
	int x,y,dis,dir,times;
	node(int x,int y,int d,int dd,int times):x(x),y(y),dis(d),dir(dd),times(times){}
};

const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
int vis[105][105][4][105];

int in(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=n&&s[x][y] == '.';
}

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=0;k<4;k++)
				for(int l=0;l<=m;l++)
					vis[i][j][k][l] = 0;
	
	for(int i=1;i<=n;i++)
		scanf("%s",s[i] + 1);
	queue<node>Q;
	Q.push(node(1,1,0,0,0));
	while(!Q.empty()){
		node u = Q.front(); Q.pop();
		int dir = u.dir, times = u.times, dis = u.dis;
		if(vis[u.x][u.y][dir][times])continue;
		vis[u.x][u.y][dir][times] = 1;
		for(int k = 0;k<4;k++)if(k != dir || (k == dir && times+1 <= m)){
			int fx = u.x + dx[k], fy = u.y + dy[k];
			if(in(fx, fy)){
				if(fx == n && fy == n){
					printf("%d\n",u.dis + 1);
					return ;
				}
				if(k != dir)	
					Q.push(node(fx, fy, dis+1, k, 1));
				else
					Q.push(node(fx, fy, dis+1, k, times + 1));
			}
		}
	}
	puts("-1");
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

