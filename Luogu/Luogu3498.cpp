// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;
const int p = 998244353, mod = 1e9+7;

int n,a[maxn];
ll hs1[maxn], hs2[maxn], bs[maxn];

ll geth2(int l,int r){return (hs2[r] - 1ll*hs2[l-1]*bs[r-l+1]%mod+mod)%mod;} 
ll geth1(int l,int r){return (hs1[r] - 1ll*hs1[l-1]*bs[r-l+1]%mod+mod)%mod;} 

signed main(){
//	freopen("3498.in","r",stdin);
	scanf("%d",&n);
	bs[0] = 1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), bs[i] = bs[i-1]*p%mod;
	for(int i=1;i<=n;i++)
		(hs1[i] = hs1[i-1]*p%mod + a[i])%=mod,
		(hs2[i] = hs2[i-1]*p%mod + a[n-i+1])%=mod;
		
	int ans1 = 0;
	vector<int>vans;
	
	for(int k=1;k<=n;k++){
//		if(ans1 > n/k)break;
		set<ll>S;
		int r=0;
		for(int i=1;i+k-1<=n;i+=k){
			int j = i+k-1;
//			cout<<i<<' '<<j<<' '<<geth1(i,j)<<' '<<geth2(n-j+1,n-i+1)<<'\n';
			if(!S.count(geth1(i,j)) || !S.count(geth2(n-j+1, n-i+1)))
				S.insert(geth1(i,j)), S.insert(geth2(n-j+1,n-i+1)), ++r;
		}
		if(ans1 < r){
			vans.clear();
			ans1 = r;
			vans.push_back(k);
		}else if(ans1 == r)vans.push_back(k);
	}
	printf("%d %d\n",ans1,vans.size());
	for(auto it : vans)printf("%d ",it);

	return 0;
}

