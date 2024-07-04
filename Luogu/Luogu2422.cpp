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
int n,a[200005],l[200005],r[200005];
ll ans, sum[200005];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int tmp = i-1;
		while(a[tmp] >= a[i])tmp = l[tmp];
		l[i] = tmp;
	}
	for(int i=n;i>=1;i--){
		int tmp = i+1;
		while(a[tmp] >= a[i])tmp = r[tmp];
		r[i] = tmp;
	}
	for(int i=1;i<=n;i++)sum[i] = sum[i-1] + a[i];
	for(int i=1;i<=n;i++){
		ans = max(ans, 1ll*(sum[r[i]-1]-sum[l[i]])*a[i]);
	}
	cout<<ans;

	return 0;
}

