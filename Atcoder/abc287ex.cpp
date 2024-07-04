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
bitset<2005>acc[2005];
int s[10005], t[10005], ans[10005];
signed main(){
	memset(ans,-1,sizeof ans);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		acc[x][y] = 1;
	}
	int Q;
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++){
		scanf("%d%d",&s[i],&t[i]);
	}
	for(int k=1;k<=n;k++){
		acc[k][k] = 1;
		for(int i=1;i<=n;i++){
			if(acc[i][k])acc[i] |= acc[k];
		}
		for(int i=1;i<=Q;i++){
			int u=s[i], v=t[i];
			if(u<=k && v<=k && acc[u][v] && ans[i]==-1){
				ans[i] = k;
			}
		}
	}
	for(int i=1;i<=Q;i++)printf("%d\n",ans[i]);
	
	return 0;
}

