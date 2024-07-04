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

signed main(){
	int n;
	long double t = 0;
	scanf("%d",&n);
	if(n == 1)return printf("1.000000"),0;
	
	t=1;
	for(int i=1;i<=n-1;i++)
		t += (long double)1.0 / i;
	printf("%.7Lf\n",t); 

	return 0;
}

