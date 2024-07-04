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

void solve(){
	int n;
	scanf("%d",&n);
	vector<int>a(n+1),cnt(n,0);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		-- a[i];
		++ cnt[a[i]];
	}
	if(*max_element(cnt.begin(), cnt.end())*2 > n+1){
		puts("-1");
		return ;
	}
	cnt.assign(n, 0);
	int ans = 0;
	for(int i=0;i<n-1;i++)if(a[i] == a[i+1]){
		++ cnt[a[i]];
		++ cnt[a[i+1]];
		++ ans;
	}
	++ cnt[a[0]];
	++ cnt[a[n-1]];
	ans = max(ans, *max_element(cnt.begin(), cnt.end()) - 2);
	cout << ans << '\n'; 
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

