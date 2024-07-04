// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, eps = 1e-9;

signed main(){
	int a,b;scanf("%d%d",&a,&b);
	double sq = sqrt(3.0);
	if(a>b)swap(a,b);
	if(b-2.0/sq*a > -eps)printf("%.12f\n",2/sq*a);
	else{
		double ta = 2.0*b/a-sq;
		double co = sqrt(1. / (1 + ta * ta));
		printf("%.12f\n",a / co);
	}

	return 0;
}

