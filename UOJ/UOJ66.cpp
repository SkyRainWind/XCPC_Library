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

void solve(){
	int n;scanf("%d",&n);
	int res=0;
	for(int i=1;i<=n;i*=2){
		if(n&i)res += i-1;
	}
	printf("%d\n",res);
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}


