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
double a[maxn],b[maxn];

signed main(){
	double t=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lf",&a[i]),t+=a[i];
	t /= (n+1);
	printf("%.7f ",t*2);for(int i=2;i<=n;i++)printf("%.7f ",t);

	return 0;
}

