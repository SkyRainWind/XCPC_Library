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

int n,x,a[maxn];
signed main(){
	scanf("%d%d",&n,&x);x<<=1;
	int ans = 0;
	for(int i=1;i<n;i++)scanf("%d",&a[i]);
	for(int i=1,j=0,sum=0;i<n;i++){
		while(j<n && sum<x)sum+=a[++j];
		ans = max(ans, j-i+1);
		sum -= a[i];
	}
	cout << ans << '\n';

	return 0;
}

