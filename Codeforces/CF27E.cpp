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
int hs[1005];
signed main(){
	freopen("27E.out","w",stdout);
	for(int i=1;i<=2000;i++){
		int res=0;
		for(int j=1;j<=i;j++){
			if(i%j == 0)++ res;
		}
		if(hs[res] == 0)hs[res] = i;
	}
	for(int i=1;i<=50;i++)if(hs[i])printf("tb[%d]=%d,",i,hs[i]);puts("");

	return 0;
}


