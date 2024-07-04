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
const int bs = 131, bs2=233, mod = 998244353, mod2 = 1e9+7;

int n,q;
char s[maxn];
int odd[maxn], even[maxn];
int h1[maxn], h2[maxn], pw[maxn];
int h11[maxn],h22[maxn], pw2[maxn];

pii geth1(int l,int r){
	int t1=(h1[r] - 1ll*h1[l-1]*pw[r-l+1]%mod + mod)%mod;
	int t2=(h11[r] - 1ll*h11[l-1]*pw2[r-l+1]%mod2 + mod2)%mod2;
	return mpr(t1,t2);
}

pii geth2(int l,int r){
	int t1=(h2[l] - 1ll*h2[r+1]*pw[r-l+1]%mod + mod)%mod;
	int t2=(h22[l] - 1ll*h22[r+1]*pw2[r-l+1]%mod2 + mod2)%mod2;
	return mpr(t1,t2);
}

void solve(){
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	h1[0] = h2[n+1] = 0;
	h11[0] = h22[n+1] = 0;
	for(int i=1;i<=n;i++)h1[i] = (1ll*h1[i-1]*bs%mod + s[i] - 'a')%mod;
	for(int i=1;i<=n;i++)h11[i] = (1ll*h11[i-1]*bs2%mod2 + s[i] - 'a')%mod2;
	for(int i=n;i>=1;i--)h2[i] = (1ll*h2[i+1]*bs%mod + s[i] - 'a')%mod; 
	for(int i=n;i>=1;i--)h22[i] = (1ll*h22[i+1]*bs2%mod2 + s[i] - 'a')%mod2; 
	even[1] = 1;
	odd[1] = odd[2] = 1;
	for(int i=3;i<=n;i++){
		if(s[i] == s[i-2])odd[i] = odd[i-2];
		else odd[i] = i;
	}
	for(int i=2;i<=n;i++)
		if(s[i] == s[i-1])even[i] = even[i-1];
		else even[i] = i;
		
	while(q --){
		int l,r;scanf("%d%d",&l,&r);
		int len = r-l+1;
		ll ans = 0;
		
		if(geth1(l,r) != geth2(l, r))
			ans += len;
		
		-- len;
			
		if(even[r] > l){
			ans += 1ll * (1+len/2) * (len/2);
		}
		
		int le = len+1;
		if((le%2==0 && (odd[r] > l+1 || odd[r-1] > l)) || (le%2==1 && (odd[r] > l || odd[r-1] > l+1))){
			ans += 1ll * (1+len) * len / 2 - 1ll * (1+len/2) * (len/2);
		}else ans ++;
		
		printf("%lld\n",ans-1);
	}
}

signed main(){
	pw[0] = pw2[0] = 1;
	for(int i=1;i<=maxn - 5;i++)pw[i] = 1ll*pw[i-1]*bs%mod;
	for(int i=1;i<=maxn - 5;i++)pw2[i] = 1ll*pw2[i-1]*bs2%mod2;
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}
/*
3
141 1
hackedbysanguinechameleonrollinghashisbadaaabaaababcaaaaaabaaabaaaaaabaaaaaaabbbaaaaaaaaaaaaaaaaabaaaaaaaaaababbaabbabaabaaababaabaaaaaaaabaa
42 141
141 1
hackedbysanguinechameleonrollinghashisbadababaaabbaabaabaaaaaabbabacaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaababaaaaabaaabaaaaabbabaaaaaaaaacbaabab
42 141
141 1
hackedbysanguinechameleonrollinghashisbadbaabaaaaaaaabaabaabbbbaaaabacaabaaaaaaaabaaaaaaaaaaaaaaaaaaaaabaaabbaabaaababaaaaaaaaaaaaabacaaaaaaa
42 141
*/
