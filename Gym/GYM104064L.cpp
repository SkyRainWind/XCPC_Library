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
	int n,p,k;scanf("%d%d%d",&n,&p,&k);
	double t = pow((p-1) * 1.0 / n, k) * p;
	for(int i=p;i<=n;i++){
		double qw = pow(i * 1.0 / n, k) - pow((i-1) * 1.0 / n, k);
		t += qw * (i+1) / 2;
	}
	printf("%.10f\n",t);

	return 0;
}

