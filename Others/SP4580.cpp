// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;
int n,a[23333];
map<ll,int>ts;
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++){
				ll tmp = 1ll*a[i]*a[j]+a[k];
				if(!ts.count(tmp))ts[tmp]=1;
				else ++ts[tmp];
			}
	ll ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++){
				ll tmp = 1ll*a[i]*a[j]+1ll*a[i]*a[k];
				if(ts.count(tmp))ans+=ts[tmp];
			}			
	cout<<ans; 

	return 0;
}

