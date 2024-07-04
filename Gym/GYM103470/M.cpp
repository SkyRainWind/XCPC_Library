// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e6+5;

int n,a[maxn];

void solve(){
	int c1=0,c2=0;
	scanf("%d",&n);
	int mn = 1e9;
	ll sum = 0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i] > 0)++ c1;
		else ++ c2;
		mn = min(mn, abs(a[i]));
		sum += abs(a[i]);
	}
	if(n == 1){
		printf("%d\n",a[1]);
		return ;
	}
	if(c2==0 || c1==0){
		printf("%lld\n",sum - mn * 2);
		return ;
	}
	printf("%lld\n",sum);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

