// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 3e5 + 5;

struct node{
	int i,j,w;
}ed[maxn];

int fa[maxn];
int find(int x){return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);}
int cmp(node a,node b){return a.w<b.w;}

signed main(){
	int n;
	scanf("%d",&n);
	int cnt = 0;
	for(int i=1;i<=n;i++){
		int w;scanf("%d",&w);
		ed[++ cnt] = node{i,n+1,w};
		fa[i] = i;
	}
	fa[n+1] = n+1;
	
	for(int i=1;i<=n;i++){
		int a[333];
		for(int j=1;j<=n;j++){
			scanf("%d",&a[j]);
			if(j > i)ed[++ cnt] = node{i,j,a[j]};
		}
	}
	
	LL ans = 0;
	sort(ed+1,ed+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int x = ed[i].i, y =ed[i].j;
		x = find(x), y = find(y);
		if(x != y){
			fa[x] = y;
			ans += ed[i].w;
		}
	}
	cout << ans << '\n';

	return 0;
}

