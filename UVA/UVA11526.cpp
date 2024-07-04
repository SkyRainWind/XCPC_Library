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

signed main(){
	int te;scanf("%d",&te);
	while(te --){
		LL n;scanf("%lld",&n);
		if(n<=0){puts("0");continue;}
		LL res=0;
		for(LL l=1;l<=n;){
			LL r = n/(n/l);
			res += 1ll*(r-l+1) * (n/l);
			l = r+1;
		}
		printf("%lld\n",res);
	}

	return 0;
}


