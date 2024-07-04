// by SkyRainWind
#include <cstdio>
#include <vector>
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

int r[15],c[15];

void solve(){
	int n,m;scanf("%d%d",&n,&m);
	memset(r,0,sizeof r);memset(c,0,sizeof c);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		r[x] = c[y] = 1;
	}
	int fg = 0;
	for(int i=1;i<=n;i++)
		fg |= r[i] == 0,
		fg |= c[i] == 0;
	if(fg)puts("YES");
	else puts("NO");
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

