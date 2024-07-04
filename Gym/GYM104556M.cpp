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
	int n;scanf("%d",&n);
	vector<int>a(n+2);
	map<int,int>mp;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int m=0;
		for(int j=0;j<=30;j++)
			if(a[i] & (1<<j))m = j;
		mp[m]++;
	}
	int ans=0;
	for(auto it : mp)ans=max(ans,it.second);
	printf("%d\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

