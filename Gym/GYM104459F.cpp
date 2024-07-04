// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e6+5;

int n,a[maxn];

void solve(){
	ll sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), sum += a[i];
	ll res = sum - sum/n*n;
//	printf("?? %d %d %d\n",sum,n,res);
	sum = sum/n;
	for(int i=1;i<=n;i++)if(a[i] <= sum)res -= a[i] - sum;
	printf("%lld\n",res);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

