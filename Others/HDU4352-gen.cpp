// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

signed main(){
	srand(time(0));
	freopen("HDU4352.in","w",stdout);
	int t=10000;printf("%d\n",t);
	while(t--){
		LL r = 19260817ll * (rand()%251 + rand()%30000 + 233);
		LL l = 1ll * rand() * rand() + rand() + 998;
		printf("%lld %lld %d\n",l,r,rand()%10);
	}
	cerr << "Yoshino\n";
	fclose(stdout);

	return 0;
}


