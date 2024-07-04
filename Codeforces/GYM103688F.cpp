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

int g[11][11];
void gt(int x,int y){g[x][y]=g[y][x]=1;}

void solve(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a>b)swap(a,b);if(c>d)swap(c,d);
	if(a==c&&b==d){puts("0");return ;}
	printf("%d\n",min(g[a][c]+g[b][d],g[a][d]+g[b][c]));
}

signed main(){
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=7;i++)g[i][i]=0;
	gt(1,3);gt(2,1);gt(2,4);gt(3,4);
	gt(4,5);gt(4,6);gt(5,7);gt(6,7);
	for(int k=1;k<=7;k++)for(int i=1;i<=7;i++)for(int j=1;j<=7;j++)
		g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

