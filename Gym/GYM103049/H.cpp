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

int n,a[maxn],b[maxn],cnt;

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1,[&](int a,int b){return a>b;});
	cnt=n;
	vector<int>vb;
	for(int i=1;i<=n;i++){
		if(i>n-i+1)break;
		vb.pb(a[i]);
		if(i == n-i+1)break;
		vb.pb(a[n-i+1]);
	}
	reverse(vb.begin(), vb.end());
	for(int it : vb)printf("%d ",it);puts("");

	return 0;
}

