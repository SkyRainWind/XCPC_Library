// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 105;

int n;
int a[maxn],b[maxn];
bitset<101*101*101>dp[2];

signed main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++){
		dp[i&1].reset();
		for(int j=a[i];j<=b[i];j++){
			dp[i&1] |= (dp[i&1^1]<<(j*j));
		}
		if(i==1)for(int j=a[i];j<=b[i];j++)dp[i&1][j*j]=1;
	}
	cout<<dp[n&1].count();

	return 0;
}

