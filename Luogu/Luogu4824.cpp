// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, p=19260817, mod = 998244353, maxn = 1e6+5;

ll bs[maxn];
ll hs, hs1[maxn];
char s[maxn], t[maxn];

ll geth(int l,int r){return (hs1[r] - hs1[l-1]*bs[r-l+1]%mod + mod) % mod;}

signed main(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	bs[0]=1;
	int n = strlen(s + 1);
	for(int i=1;i<=n;i++)bs[i]=1ll*bs[i-1]*p%mod;
	int m=strlen(t+1);for(int i=1;i<=m;i++)hs=(hs*p%mod+t[i])%mod;
	
	int times = 0;
	int j = 0;
	string ans;ans.resize(n + 5);
	for(int i=1;i<=n;i++){
		++ j;
		hs1[j] = (hs1[j-1]*p%mod + s[i]) % mod;
		ans[j] = s[i];
		if(j>=m && geth(j-m+1, j) == hs){
			++ times;
			j -= m;
		}
	}
	int nn = n - times*m;
	for(int i=1;i<=nn;i++)cout<<ans[i];

	return 0;
}

