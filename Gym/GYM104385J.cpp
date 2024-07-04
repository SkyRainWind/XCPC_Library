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
int n,b[200005];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	int qu;scanf("%d",&qu);
	int sq=sqrt(n);
	while(qu--){
		int op,x,y;scanf("%d%d",&op,&x);
		if(op==0){
			scanf("%d",&y);b[x]=min(b[x],y);
		}else{
			ll ans = 1e18;
			for(int i=max(1,x-sq);i<=min(n,x+sq);i++){
				ans=min(ans,1ll*(x-i)*(x-i)+b[i]);
			}
			cout<<ans<<'\n';
		}
	}

	return 0;
}

