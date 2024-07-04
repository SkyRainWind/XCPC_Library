// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

signed main(){
	int n,m;scanf("%d%d",&n,&m);
	while(n--){
		int x,y;cin>>x>>y;
		if(x+y==7||x==y||x==m||y==m||x==7-m||y==7-m)return puts("NO"),0;
	}
	puts("YES");

	return 0;
}

