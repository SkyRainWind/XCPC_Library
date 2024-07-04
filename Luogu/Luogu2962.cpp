// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

map<ll,int>dp;
int n,m;
ll st[233];

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)st[i]=1ll<<i;
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		-- x, -- y;
		st[x] |= (1ll<<y);
		st[y] |= (1ll<<x);
	}
	for(int i=0;i<=(1<<(n/2))-1;i++){
		ll s = 0;int cnt = 0;
		for(int j=0;j<=(n/2)-1;j++)
			if(i & (1<<j))
				s ^= st[j],
				++ cnt;
		if(!dp.count(s))dp[s] = cnt;
		else dp[s] = min(dp[s], cnt);
	}
	
	int res = 50;
	for(int i=0;i<=(1<<(n - n/2))-1; i++){
		ll s = 0;
		int cnt = 0;
		for(int j=0;j<=(n-n/2)-1;j++)
			if(i & (1 << j))
				s ^= st[n/2 + j], ++ cnt;
		s ^= ((1ll<<n)-1);
		if(dp.count(s))
			res = min(res, cnt + dp[s]);
	}
	cout << res;

	return 0;
}

