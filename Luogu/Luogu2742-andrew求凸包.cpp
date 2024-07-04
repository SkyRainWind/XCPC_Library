// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2e5+5;

int n;
struct point{
	int x,y;
}p[maxn];
int stk[maxn];

point operator - (point a,point b){return point{a.x - b.x, a.y - b.y};}
point operator + (point a,point b){return point{a.x + b.x, a.y + b.y};}

ll cross(point a,point b){return 1ll * a.x * b.y - 1ll * a.y * b.x;}

void solve(){ // andrew
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
		char ch[5];
		scanf("%s",ch+1);
	}
	sort(p+1,p+n+1,[&](point a,point b){
		return a.x == b.x ? a.y < b.y : a.x < b.x;
	});
	int tp=0;
	stk[++ tp] = 1;
	for(int i=2;i<=n;i++){
		while(tp > 1 && cross(p[stk[tp]] - p[stk[tp-1]], p[i] - p[stk[tp]]) < 0)
			-- tp;
		stk[++ tp] = i;
	}
	vector<int>ans;
	for(int i=1;i<=tp;i++)ans.pb(stk[i]);
	
	tp = 0;
	stk[++ tp] = 1;
	for(int i=2;i<=n;i++){
		while(tp > 1 && cross(p[stk[tp]] - p[stk[tp-1]], p[i] - p[stk[tp]]) > 0)
			-- tp;
		stk[++ tp] = i;
	}
	for(int i=tp-1;i>=2;i--)ans.pb(stk[i]);
	printf("%d\n",ans.size());
	for(int it : ans)printf("%d %d\n",p[it].x,p[it].y);
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

