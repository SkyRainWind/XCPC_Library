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

int n,mod;
int a[maxn];

int pw(int x,int y){
	if(!y)return 1;
	if(y==1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

void ck(int x,int &ans){
	map<int,int>dp;
	if(x == 1){
		for(int i=1;i<=n;i++)dp[a[i]] ++, ans = max(ans, dp[a[i]]);
		return ;
	}
	int inv = pw(x, mod-2);
	for(int i=1;i<=n;i++){
		if(!dp.count(a[i]))dp[a[i]] = 1;
		int now = 1ll * a[i] * inv % mod;
		if(dp.count(now))dp[a[i]] = max(dp[a[i]], dp[now] + 1);
		ans = max(ans, dp[a[i]]);
	}
}

void solve(){
	scanf("%d%d",&n,&mod);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n == 2){
		puts("2");
		return ;
	}
	
	map<int,int>mp;
	vector<int>cdt;
	if(n>66){
		for(int i=1;i<=n-2;i++){
			int rnd = i;
			int inv = pw(a[rnd], mod-2);
			mp[1ll * a[rnd+1] * inv%mod] ++;
			mp[1ll * a[rnd+2] * inv%mod] ++;
		}
		for(auto it : mp){
			if(it.second >= n/10)cdt.pb(it.first);
		}
	}else{
		for(int i=1;i<=n-1;i++)
			for(int j=i+1;j<=n;j++){
				int rnd = i;
				int inv = pw(a[rnd], mod-2);
				mp[1ll * a[j] * inv%mod] ++;
				if(j < n)mp[1ll * a[j+1] * inv%mod] ++;
			}
		for(auto it : mp){
			if(it.second >= 1)cdt.pb(it.first);
		}
	}
	if(cdt.size() == 0)
		return puts("-1"), void();
		
	int ans = 0;
	for(int i : cdt)ck(i, ans);
	if(2*ans >= n)printf("%d\n",ans);
	else puts("-1");
}

signed main(){
	srand(time(0));
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

