// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
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
	int te;scanf("%d",&te);
	while(te --){
		int n,m;scanf("%d%d",&n,&m);
//		if(n>m)swap(n,m);
		if(n == 1 || m == 1){
			puts("1 1");continue;
		}
		if(max(n, m) >= 4){
			puts("1 1");continue;
		}
		puts("2 2");continue;
	}

	return 0;
}


