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
int n,a[200005];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int m = lower_bound(a+1,a+n+1,0) - a-1;
	vector<int>b;
	for(int i=1;i<=m;i++){
		if(i<=3 || m-i+1 <= 3)b.pb(a[i]);
	}
	for(int i=m+1;i<=n;i++){
		if(i-m <= 3 || n-i+1 <= 3)b.pb(a[i]);
	}
	double a1 = 1e18, a2 = -1e18;
	for(int i=0;i<b.size();i++)
		for(int j=i+1;j<b.size();j++)
			for(int k=j+1;k<b.size();k++)
				a1 = min(a1, 1.0*(b[i]+b[j]+b[k])/b[i]/b[j]/b[k]),
				a2 = max(a2, 1.0*(b[i]+b[j]+b[k])/b[i]/b[j]/b[k]);
	printf("%.14f\n%.14f\n",a1,a2);

	return 0;
}

