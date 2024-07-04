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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2005, maxm = 10005;

int n,m,k;
int a[maxn], con[maxn][maxn];
pii ed[maxm];
vector<int>g[maxn];

signed main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		con[x][y] = con[y][x] = 1;
		ed[i] = mpr(x, y);
		g[x].push_back(y), g[y].push_back(x);
	}
	if(k == 0){
		for(int i=1;i<=m;i++){
			pii u = ed[i];
			if(u.first ==1 || u.second == 1)continue;
			int tmp = a[u.first] + a[u.second];
			int mx0=0,imx0, smx0=0, ismx0;
			int tmp2=0, setmp2=0,tmp3 =0;
			for(int v : g[u.first]){
				if(con[v][1] == 1){
					if(mx0 < a[v]){
						smx0
					}
				}tmp2 = max(tmp2, a[v]);
			}
			for(int v : g[u.second]){
				if(con)
			}
		}
		
		return 0;
	}

	return 0;
}

