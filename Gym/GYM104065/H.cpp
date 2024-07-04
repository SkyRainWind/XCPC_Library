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

signed main(){
	int k;
	scanf("%d",&k);
	printf("%d\n",k*2-1);
	for(int i=1;i<=k*2-1;i++)printf("%d %d\n",i,300-i);

	return 0;
}

