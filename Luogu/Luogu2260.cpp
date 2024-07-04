// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 19940417;
const int inv6=3323403, inv2=9970209;

int n,m;
ll get1(int l,int r){
	return 1ll*(l+r)*(r-l+1)%mod*inv2%mod;
}
ll get2(int l,int r){	// l^2+..+r^2
	-- l;
	ll s1 = 1ll*r*(r+1)%mod*(2*r+1)%mod*inv6%mod;
	ll s2 = 1ll*l*(l+1)%mod*(2*l+1)%mod*inv6%mod;
	return (s1-s2+mod)%mod;
}

signed main(){
	scanf("%d%d",&n,&m);
	if(n>m)swap(n, m);
	ll r1=0,r2=0;
	// r1 ÎÞ [i!=j] ÏÞÖÆ; r2: \sum(n-[n/i]*i)(m-[m/i]*i) 
	ll r01=0,r02=0,r03=0,r04=0;
	// r01=\sum(n-[n/i]*i); r02=\sum(m-[m/i]*i)
	// r03=\sum([n/i]*i); r04=\sum([m/i]*i)
	
	for(int l=1,r;l<=m;){
		r=m/(m/l);
		ll t1=1ll*(r-l+1)*m%mod;
		(t1 += mod-1ll*(m/l)*get1(l,r)%mod) %= mod;
		(r01 += t1) %= mod; 
		l=r+1;
	}
	for(int l=1,r;l<=n;){
		r=m/(m/l);if(r>n)r=n;
		(r03+=1ll*get1(l,r)*(m/l)%mod)%=mod;l=r+1;
	}
	
	for(int l=1,r;l<=n;){
		r=n/(n/l);
		ll t1=1ll*(r-l+1)*n%mod;
		(t1 += mod-1ll*(n/l)*get1(l,r)%mod) %= mod;
		(r02 += t1) %= mod; 
		(r04 += 1ll*(n/l)*get1(l,r)%mod) %= mod;
		l=r+1;
	}
	r1 = 1ll*r01*r02%mod;
	
	r2 = 1ll*n*n%mod*m%mod;
	(r2 += mod-1ll*n%mod*r03%mod) %= mod;
	(r2 += mod-1ll*m%mod*r04%mod) %= mod;

	for(int l=1,r;l<=n;){
		r=min(n/(n/l), m/(m/l));
		if(r>n)r=n;
		(r2 += 1ll*(n/l)*(m/l)%mod*get2(l,r)%mod) %= mod;
		l=r+1;
	}
	ll ans = (r1-r2+mod)%mod;
	cout<<ans;

	return 0;
}

