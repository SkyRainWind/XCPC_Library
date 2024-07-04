// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

signed main(){
	int n,ans=0;
	scanf("%d",&n);
	int r[100];memset(r,0,sizeof r);
	for(int i=1;i<=n;i++)	
		for(int j=i;j<=n;j++){
			ans+=__builtin_popcount(i-1);
			ans+=__builtin_popcount(j);
			++r[i-1];++r[j];
		}
//	for(int i=0;i<=n;i++)printf("%d\n",r[i]);
	cout<<ans<<'\n';

	return 0;
}

