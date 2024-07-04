// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod=1e9+7;

ll n;
int bit[65],cnt;
int f[65][2][2], g[65][2][2], dp[65][2], dpp[65][2];

pii dfs0(int x,int isup){
	if(x == cnt+1)return mpr(0, 1);
	int &dd = dp[x][isup];
	if(~dd)return mpr(dd, dpp[x][isup]);
	
	dd = 0;
	int &ng = dpp[x][isup];ng = 0;
	for(int i=0;i<=(isup ? bit[x] : 1);i++){
		pii now = dfs0(x+1, isup && i == bit[x]);
		(dd += now.first) %= mod;
		if(i == 1)(dd += now.second) %= mod;
		(ng += now.second) %= mod;
	}
	return mpr(dd, ng);
}

pii dfs(int x,int iseq,int isup){
	if(x == cnt+1){
		if(!iseq)return mpr(0,1);
		else return mpr(0,0);
	}
	int &dd = f[x][iseq][isup];
	if(~dd)return mpr(dd, g[x][iseq][isup]);
	
	int up = 1;if(isup)up = bit[x];
	int &ng = g[x][iseq][isup];
	dd = ng = 0;
	for(int r=0;r<=up;r++)
		for(int l=0;l<=(iseq?r:1);l++){
			pii now = dfs(x+1, iseq && l==r, isup && r == up);
			(dd += now.first) %= mod;
			if(l==1&&r==1&&iseq)(dd += now.second) %= mod;
			(ng += now.second) %= mod;
		}
	return mpr(dd, ng);
}

void solve(){
	memset(f,-1,sizeof f);
	memset(g,-1,sizeof g);
	memset(dp,-1,sizeof dp);
	memset(dpp,-1, sizeof dpp);
	cin >> n;
	ll t = n;
	cnt = 0;
	while(t){
		bit[++ cnt] = t&1;
		t >>= 1;
	}
	reverse(bit+1,bit+cnt+1);
	pii res0 = dfs0(1, 1);
	pii res = dfs(1, 1, 1);
	cout << (1ll*res0.first*(n%mod)%mod - 2ll*res.first%mod + mod) % mod << '\n';
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

