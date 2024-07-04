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

double sum[]={0,19.9978964,1.6931472,1.4054651,1.2876821,1.2231436,1.1823216,1.1541507,1.1335314,1.1177830,1.1053605};

signed main(){
	int n;scanf("%d",&n);
	if(n <= 100000000){
		double t=1;
		for(int i=1;i<=min(100000000, n-1);i++)
			t += 1.0 / i;
		printf("%.7f\n",t);
		return 0;
	}
	double t=0;
	int tt = n/100000000;
	for(int i=1;i<=tt;i++)t+=sum[i];
	t-=tt-1;

	for(int i=tt*100000000;i<=min((tt+1)*100000000, n-1);i++)
		t += (double)1.0 / i;
	printf("%.7f\n",t);

	return 0;
}

