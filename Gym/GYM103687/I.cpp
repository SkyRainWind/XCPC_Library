// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e6+5, mod = 998244353;

int n,qu;
char s[maxn];
int hs[maxn], pw[maxn], rhs[maxn];

int geth(int l,int r){
	return (hs[r] - 1ll*hs[l-1]*pw[r-l+1]%mod + mod)%mod;
}

int getrh(int l,int r){
	return (rhs[l] - 1ll*rhs[r+1]*pw[r-l+1]%mod + mod)%mod;
}

int pali(int l,int r){
	if((r-l+1)%2==0){
		int lf = l+(r-l+1)/2-1, rf = lf+1;
		if(geth(l,lf) == getrh(rf,r))return 1;
		return 0;
	}
	int mid = l+(r-l+1)/2;
	if(geth(l,mid) == getrh(mid,r))return 1;
	return 0;
}

signed main(){
	scanf("%d%d",&n,&qu);
	scanf("%s",s+1);
	pw[0] = 1;
	for(int i=1;i<=n;i++)hs[i] = (131ll*hs[i-1]%mod+s[i]-'a')%mod;
	for(int i=n;i>=1;i--)rhs[i] = (131ll*rhs[i+1]%mod+s[i]-'a')%mod;
	for(int i=1;i<=n;i++)pw[i] = 131ll*pw[i-1]%mod;
	
	while(qu --){
		int l,r;scanf("%d%d",&l,&r);
		if(pali(l,r))puts("Budada");
		else{
			if((r-l+1)%2==0)puts("Budada");
			else puts("Putata");
		}
	}

	return 0;
}

