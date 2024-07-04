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
	int n,t;scanf("%d%d",&n,&t);
	for(int i=n/2;i>=1;i--)printf("%d %d\n",i+1,i);
	for(int i=n/2+1;i<=n;i++)printf("%d %d\n",n/2,i);

	return 0;
}

