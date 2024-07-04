// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e6+5;
const int bs = 131, mod = 998244353;

char s[maxn];
int hs[maxn], pw[maxn];
int n;

int geth(int l,int r){
	return (hs[r] - 1ll*hs[l-1]*pw[r-l+1]%mod + mod)%mod; 
}

signed main(){
	pw[0] = 1;
	for(int i=1;i<=maxn-5;i++)
		pw[i] = 1ll * pw[i-1] * bs % mod;
		
	scanf("%s", s+1);
	n = strlen(s+1);
	hs[0] = 0;
	for(int i=1;i<=n;i++)
		hs[i] = (1ll*hs[i-1]*bs%mod + s[i] - 'A')%mod;
	for(int len=1;len<=n;len++){
		vector<int>vc;
		set<int>S;
		int gg = 0, fr;
		for(int i=1;i+len-1<=n;){
			vc.pb(geth(i,i+len-1));
			int t1=S.size();
			S.insert(geth(i,i+len-1));
			if(t1 == 1 && S.size() == 2)fr = i;
			i += len;
			if(i+len-1>n){
				int h1 = geth(i,n);
				int h2 = geth(1,n-i+1);
				if(h1 != h2)gg = 1;
			}
		}
		if(gg || S.size() != 2)continue;
		int t0 = vc[0], t1 = -1, l, r;
		for(int i=1;i<vc.size();i++){
			if(vc[i] != t0){
				if(t1 == -1)l = i;
				t1 = vc[i];
				r = i;
			}
		}
		for(int i=0;i<vc.size();i++){
			if(l <= i && i <= r){
				if(vc[i] != t1)gg = 1;
			}else{
				if(vc[i] != t0)gg = 1;
			}
		}
		if(!gg){
			for(int i=1;i<=len;i++)printf("%c",s[i]);
			printf(" ");
			for(int i=fr;i<=fr+len-1;i++)printf("%c",s[i]);
			puts("");
			return 0;
		}
	}

	return 0;
}

