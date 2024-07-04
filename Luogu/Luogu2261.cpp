// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

// k mod i = k - (k/i)*i

signed main(){
	int n,k;scanf("%d%d",&n,&k);
	LL ans = 1ll*k*n;
	for(int l = 1;l<=min(n,k);){
		int r = k/(k/l);
		if(r > min(n,k))r = min(n,k);
		ans -= 1ll*(k/l) * (l+r) * (r-l+1) / 2; 
		l = r+1;
	}
	printf("%lld\n",ans);

	return 0;
}


