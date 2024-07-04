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

void solve(){
	int n,m;scanf("%d%d",&n,&m);
	printf("%d ",m);
	int delt = n-m+1;
	printf("%d\n",m/delt + (m%delt!=0));
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

