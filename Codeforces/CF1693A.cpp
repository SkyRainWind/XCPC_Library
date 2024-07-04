// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5;

int n;
ll a[maxn],sum[maxn];
int solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	int up=-1;
	for(int i=n;i>=1;i--)if(a[i]){up=i;break;}
	if(up==-1)return 1;
	for(int i=1;i<=up;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<up;i++)if(sum[i]<=0)return 0;
	if(sum[up])return 0;
	return 1;
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)puts(solve() ? "Yes" : "No");

	return 0;
}

