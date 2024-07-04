// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 4e5+5;

int n,m,a[maxn],b[maxn],x[maxn],y[maxn],z[maxn];
int no[maxn], ok[maxn];
struct node{
	int to,x,y,z;
};
vector<node>vc[maxn];

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)no[i] = 0, ok[i] = 0;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d%d",&a[i],&b[i],&x[i],&y[i],&z[i]);
		vc[a[i]].pb(node{b[i],x[i],y[i],z[i]});
		vc[b[i]].pb(node{a[i],y[i],x[i],z[i]});
	}
	int dx = -1, sdx = -1, did = 0;
	multiset<int>S;
	for(int i=1;i<=m;i++){
		int t1 = x[i], t2 = y[i], zz = z[i], mx = 0;
		
		if(t1 > t2)swap(t1, t2);
		int delt = t2 - t1;
		zz -= delt;
		if(zz < 0)mx = t2;
		else mx = t2 + (zz+1) / 2;
		if(dx <= mx)sdx = dx, dx = mx, did = i;
		else if(sdx < mx)sdx = mx;
		S.insert(mx);
	}
//	for(auto it : S)printf("--- %d\n",it);
//	printf("? %d %d %d\n",sdx,dx,did);
	for(int i=1;i<=n;i++){
		int now = 0;
		for(auto it : vc[i]){
			int t1 = it.x, t2 = it.y, zz = it.z, mx = 0;
			
			if(t1 > t2)swap(t1, t2);
			int delt = t2 - t1;
			zz -= delt;
			if(zz < 0)mx = t2;
			else mx = t2 + (zz+1) / 2;
			now = max(now, it.x+it.z);
			S.insert(it.y);
			S.erase(S.find(mx));
		}
		
		multiset<int>::iterator it = S.end(); -- it;
		if(now > *it)ok[i] = 1;
		
		for(auto it : vc[i]){
			int t1 = it.x, t2 = it.y, zz = it.z, mx = 0;
			
			if(t1 > t2)swap(t1, t2);
			int delt = t2 - t1;
			zz -= delt;
			if(zz < 0)mx = t2;
			else mx = t2 + (zz+1) / 2;
			S.erase(S.find(it.y));
			S.insert(mx);
		}
	}
	for(int i=0;i<=n;i++)vc[i].clear();
	vector<int>ans;
	for(int i=1;i<=n;i++)if(ok[i])ans.pb(i);
	printf("%d\n",ans.size());
//	if(ans.size() == 0){
//		return ;
//	}
	for(auto it : ans)printf("%d ",it);
	puts("");
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}


