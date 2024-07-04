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
char s[55][55],t[555];
int a[55][55],sx,sy;
pii di[10];

int in(int x,int y){
	return x>=1 && x<=n && y>=1 && y<=m;
}

signed main(){
	di[0] = mpr(-1, 0), di[1] = mpr(-1, 1), di[2] = mpr(0, 1), di[3] = mpr(1, 1);
	di[4] = mpr(1, 0), di[5] = mpr(1, -1), di[6] = mpr(0, -1), di[7] = mpr(-1, -1);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(s[i][j] == '#')a[i][j] = 0;
			else if(s[i][j] == '.')a[i][j] = 1;
			else a[i][j] = 1, sx=i, sy=j;
		}
	int len;scanf("%d",&len);
	scanf("%s",t+1);
	pii dir = di[0];
	int v=0, idx = 0, x=sx, y=sy;
	for(int i=1;i<=len;i++){
		if(t[i] == 'U'){
			++ v;
		}else if(t[i] == 'D')v = max(v-1, 0);
		else if(t[i] == 'R')idx = (idx+1) % 8;
		else idx = (idx-1+8)%8;
		
		dir = di[idx];
		int tv = v;
		int gx=-1, gy=-1;
		while(tv --){
			int fx = x+dir.first, fy = y+dir.second, ok=1;
			if(abs(dir.first) + abs(dir.second) == 2){
				int px = x, py = y + dir.second;
				int qx = x + dir.first, qy = y;
				if(a[px][py] == 0 && a[qx][qy] == 0)ok = 0;
			}
			if(in(fx, fy) && (a[fx][fy] == 1 && ok)){
				x = fx, y = fy;
			}else{
				gx = x, gy = y;
				v = 0;
				break;
			}
		}
//		printf("? %d %d %d %d %d %d\n",x,y,idx,dir.first,dir.second,v);
		if(~gx){
			printf("Crash! %d %d\n",gx,gy);
			x = gx, y = gy;
		}else{
			printf("%d %d\n",x,y);
		}
	}

	return 0;
}

