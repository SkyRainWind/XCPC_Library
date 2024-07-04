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
ll C;
int h[maxn];
ll dp[maxn];
ll qu[maxn], hd, tl;

double gy(int x){return 1.0*dp[x]+1.0*h[x]*h[x];}
double gx(int x){return 1.0*h[x];}
double slope(int x,int y){
	return (1.0 * (gy(y) - gy(x)) / (gx(y) - gx(x)));
}

signed main(){
	cin.tie(0);
	cin>>n>>C;
	for(int i=1;i<=n;i++)cin>>h[i];
	
	qu[1] = 1;hd = tl = 1;
	dp[1] = 0;
	for(int i=2;i<=n;i++){
		while(hd < tl && slope(qu[hd], qu[hd+1]) <= 2*h[i])++ hd;
		int j = qu[hd];
		dp[i] = dp[j] + 1ll * (h[i]-h[j]) * (h[i]-h[j]) + C; 
		while(hd < tl && slope(qu[tl-1], qu[tl]) >= slope(qu[tl], i))-- tl;
		qu[++ tl] = i;
	}
	cout<<dp[n];

	return 0;
}

