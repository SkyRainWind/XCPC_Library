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
	int te,n;scanf("%d",&te);
	while(te--){
		scanf("%d",&n);
		int a[105];
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		if(a[1] == 1)puts("YES");
		else puts("NO");
	}

	return 0;
}

