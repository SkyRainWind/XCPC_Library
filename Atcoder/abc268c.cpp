// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n,a[maxn],cnt[maxn];

signed main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		int now = (a[i]-i+n)%n;
		++ cnt[now%n];
		++ cnt[(now+1)%n];
		++ cnt[(now+n-1)%n];
	}
	int ans = 0;
	for(int i=0;i<n;i++)
		ans = max(ans, cnt[i]);
	cout << ans << '\n';

	return 0;
}

