// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;

const int inf = 1e9, INF = 0x3f3f3f3f, m = 1e6;

ull f[m + 5];

pair<ull,ull> solve(ull n){
	if(n <= m)return mpr(f[n], f[n-1]);
	if(n == 1)return mpr(1,1);
	else if(n == 0)return mpr(1,0);
	if(n%2 == 0){
		pair<ull,ull> s1 = solve(n/2);
		return mpr(2ull * s1.first * s1.second, 1ull * s1.second * s1.second);
	}else{
		pair<ull,ull> s1 = solve(n/2);
		return mpr(1ull * s1.first * s1.first, 2ull * s1.first * s1.second);
	}
}

void solve(){
	ull n;scanf("%llu",&n);
	printf("%llu\n",solve(n).first);
}

signed main(){
	f[0] = 1;
	for(int i=1;i<=m;i++)
		if(i&1)f[i] = 1ull * f[i/2] * f[i/2];
		else f[i] = 2ull * f[i/2-1] * f[i/2];
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

