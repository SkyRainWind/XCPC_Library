// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,mod=1e9+7;

int f(int x){
	int r=1;
	while(x){r=1ll*r*(x%10)%mod;x/=10;}
	return r;
}

void solve(){
	int l,r;scanf("%d%d",&l,&r);
	if(r-l+1 >= 10)puts("0");
	else{
		int ans=1;
		for(int i=l;i<=r;i++)
			ans=1ll*ans*f(i)%mod;
		printf("%d\n",ans);
	}
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

