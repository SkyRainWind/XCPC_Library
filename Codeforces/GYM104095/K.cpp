// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, p = 131, maxn = 5e5+5, mod = 998244353;

char s[maxn];
int hs[maxn], rhs[maxn], pp[maxn],m; 

int geths(int l,int r){
	return (hs[r] - 1ll*hs[l-1]*pp[r-l+1]%mod + mod)%mod;
}

int getrhs(int l,int r){
	return (rhs[l] - 1ll*rhs[r+1]*pp[r-l+1]%mod + mod)%mod;
}

int check(string t){
	hs[0] = 0;
	for(int i=1;i<=m;i++)hs[i] = (1ll*hs[i-1]*p%mod + t[i] - 'a') % mod;
	
	rhs[m+1] = 0;
	for(int i=m;i>=1;i--)rhs[i] = (1ll*rhs[i+1]*p%mod + t[i] - 'a') % mod;
	
	for(int i=1;i<m;i++){
		int t1 = (getrhs(1,i) + 1ll*pp[i]*geths(i+1,m)%mod) % mod;
		int t2 = (getrhs(i+1,m) + 1ll*pp[m-i]*geths(1,i)%mod) % mod;
//		cout << t1 << ' ' << t2 << '\n';
		if(t1 == t2)return 1;
	}
	return 0;
}

void solve(){
	scanf("%s",s + 1);
	int nn = strlen(s + 1);
	int pos = -1;
	for(int i=1;i<=nn/2;i++){
		if(s[i] != s[nn - i + 1]){
			pos = i;
			break;
		}
	}
	if(pos == -1)return (void)puts("Yes");
	string tt = "";
	for(int i=pos;i<=nn-pos+1;i++)tt += s[i];
	string t = "0" + tt;
	m = t.size()-1;
//	cout << t << '\n';

	if(check(t))return (void)puts("Yes");
	reverse(tt.begin(),tt.end());
	t = "0" + tt;
//	cout << t << '\n';
	if(check(t))return (void)puts("Yes");
	puts("No");
}

signed main(){
	pp[0] = 1;
	for(int i=1;i<=maxn-5;i++)pp[i] = 1ll*pp[i-1]*p%mod;
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

