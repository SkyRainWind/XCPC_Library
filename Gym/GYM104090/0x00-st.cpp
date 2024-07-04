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

int n,m;
int a[maxn], st[maxn][25];
// st[i][j] a[i] .. a[i+2^j-1]

int query(int l,int r){
	int len = r-l+1;
	int to = (int)(1.0 * log(r-l+1) / log(2.0));
	return max(st[l][to], st[r-(1<<to)+1][to]);
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), st[i][0] = a[i];
	for(int j=1;j<=20;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
	while(m --){
		int l,r;scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r));
	}

	return 0;
}

