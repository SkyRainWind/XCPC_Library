// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int mp[105][105];
int b[222],cnt=0,a[222],ans,n,m;

int check(int x){
	for(int i=1;i<=cnt;i++)
		if(mp[x][b[i]])return 0;
	return 1;
}

void dfs(int x){
	if(ans<cnt)ans=cnt,memcpy(a, b, sizeof b);
	for(int i=x+1;i<=n;i++)if(check(i)){
		b[++cnt]=i;
		dfs(i);
		--cnt;
	}
}

void solve(){
	memset(mp,0,sizeof mp);
	cnt=0;memset(a,0,sizeof a);memset(b,0,sizeof b);
	ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		mp[x][y] = mp[y][x] = 1;
	}
	dfs(0);
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++)printf("%d%c",a[i]," \n"[i == ans]);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

