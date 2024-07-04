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
const double pi = 3.14159265358;

signed main(){
	int te;scanf("%d",&te);
	while(te --){
		int a,b;scanf("%d%d",&a,&b);
		printf("%.4f\n",pi*a*a + 4.0*a*b);
	}

	return 0;
}

