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
int msk[maxn];
int ban[maxn][27];
int dp[(1 << 26) + 5];

signed main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++){
		vector<int>buc(27,0);
		string s;
		cin >> s;
		for(int j=0;j<s.size();j++){
			++ buc[s[j] - 'a'];
		}
		for(int j=0;j<=25;j++)
			msk[i] |= ((buc[j]%2) << j);
		for(int j=0;j<=25;j++)
			if(buc[j] == 0)ban[i][j] = 1;
	}
	ll ans = 0;
	for(int j=0;j<=25;j++){
		for(int i=1;i<=n;i++)if(ban[i][j]){
			ans += dp[(1 << 26) - 1 - (1 << j) - msk[i]];
			dp[msk[i]] ++;
		}
		for(int i=1;i<=n;i++)if(ban[i][j])-- dp[msk[i]];
	}
	cout << ans << '\n';

	return 0;
}

