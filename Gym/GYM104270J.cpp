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

int a[200050];
int b[200050];

void solve(){
	int n,m,z=0,cnt=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i] == 0)++z; 
		else b[++cnt] = a[i];
	}
	if(z > m){
		puts("Impossible");
		return ;
	}
	if(n == m){
		puts("Richman");
		return ;
	}
	ll qwq = 0;
	int mn = 2e9;
	m -= z;
	for(int i=1;i<=m;i++)qwq += b[i];
	for(int i=m+1;i<=cnt;i++)mn = min(mn, b[i]-1);
	printf("%lld\n",qwq + mn);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

