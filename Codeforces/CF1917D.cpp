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

int n,k,p[maxn],q[maxn];
int bit[maxn];

int lb(int x){return x & (-x);}

int query(int x){
	int res = 0;
	for(int i=x;i;i-=lb(i))res += bit[i];
	return res;
}

void add(int x,int uplim){
	for(int i=x;i<=uplim;i+=lb(i))bit[i] ++;
}

void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=k;i++)scanf("%d",&q[i]), ++ q[i];
	ll ans = 0;
	for(int i=1;i<=k;k++){
		ans += query(k-q[i]+1);
		add(q[i], k);
	}
	for(int i=0;i<=k;i++)bit[i] = 0;
	for(int i=1;i<=n;i++){
		
	}
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

