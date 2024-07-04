// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;

const int inf = 1e9, INF = 0x3f3f3f3f;
const int p = 127, maxn = 5e5+5, mod = 998244353;

ll hs1[maxn], hs2[maxn];
ll bs[maxn];

char s[maxn];
ll geth2(int l,int r){return (hs2[r] - 1ll*hs2[l-1]*bs[r-l+1]%mod+mod)%mod;} 
ll geth1(int l,int r){return (hs1[r] - 1ll*hs1[l-1]*bs[r-l+1]%mod+mod)%mod;} 
int n;
int check(int i,int mid){
	// [l,r]
	int l=i-mid+1,r=i+mid;
	ll h1 = geth1(n-i+1, n-l+1);
	ll h2 = geth2(i+1,r);
	return h1 == h2;
}

signed main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	
	for(int i=1;i<=n;i++)hs1[i] = hs1[i-1]*p%mod+(s[n-i+1] - '0');
	for(int i=1;i<=n;i++)hs2[i] = hs2[i-1]*p%mod+((s[i] - '0') ^ 1);
	bs[0] = 1;for(int i=1;i<=n;i++)bs[i]=bs[i-1]*p%mod;
	
	ll res=0;
	for(int i=1;i<=n-1;i++){	// [i,i+1]
		int l=1,r=min(i,n-i),ans=0;
		while(l<=r){
			int mid=l+r>>1;
			if(check(i,mid))ans = mid, l=mid+1;
			else r = mid-1;
		}
		res += ans;
	}
	cout<<res; 

	return 0;
}

