// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=5e5+5;

int n,m,a[maxn],c[maxn];

int lb(int x){
	return x & (-x);
}
void add(int x,int to){
	for(int i=x;i<=n;i+=lb(i))c[i] += to;
}
int query(int x){
	int ans = 0;
	for(int i=x;i;i-=lb(i))ans += c[i];
	return ans;
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),add(i,a[i]);
	while(m --){
		int op,x,y;scanf("%d%d%d",&op,&x,&y);
		if(op == 1)add(x,y);
		else printf("%d\n",query(y) - (x==1?0:query(x-1)));
	}

	return 0;
}

