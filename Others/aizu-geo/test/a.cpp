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
int n,a[23333];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int cnt = 1;
	for(int i=1;i<=n;i++){
		if(a[i] == cnt)++ cnt;
		if(i == n)return printf("%d\n",cnt),void();
	}
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}
