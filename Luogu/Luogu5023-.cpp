// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=20005;

int n,m;
int a[105][105],b[105][105];
int g[105][105];

int check(int x,int y){
	a[x][y] = a[x+1][y] | (g[x][y] << (n-x));
	if(y == m)b[x][y] = 1;
	else b[x][y] = b[x][y+1] && (a[x][y+1] >> 1) == a[x+1][y];
	if(x < n && y > 1 && !b[x+1][y] && g[x][y] == g[x+1][y-1])return 0;
	return 1;
}
int ans=0;

void dfs(int x,int y){
	if(y == 0){
		if(x == 1)++ ans;
		else dfs(x-1, m);
		return ;
	}
	if(x == n || y == 1 || g[x+1][y-1] == 1){
		g[x][y] = 1;
		if(check(x,y))dfs(x,y-1);
	}
	g[x][y] = 0;
	if(check(x,y))dfs(x,y-1);
}

signed main(){
	freopen("5023.out","w",stdout);
	for(n=2;n<=9;n++)
	for(m=2;m<=9;m++){
		ans=0;
		memset(a,0,sizeof a),memset(b,0,sizeof b),memset(g,0,sizeof g); 
//	scanf("%d%d",&n,&m);
		dfs(n,m);
		printf("(%d,%d): %d\n",n,m,ans);
	}

	return 0;
}


