// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n;
struct node{
	int l,r,y;
}a[maxn];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].y);
	sort(a+1,a+n+1,[&](node a,node b){
		return a.y > b.y;
	});
	int sx,sy;scanf("%d%d",&sx,&sy);
	int g = 0;
	for(int i=1;i<=n;i++){
		if(sy < a[i].y)g=i;
	}
	for(int i=g+1;i<=n;i++){
		if(sx > a[i].l && sx < a[i].r)sx = a[i].r, sy = a[i].y;
	}
	printf("%d\n",sx);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}


