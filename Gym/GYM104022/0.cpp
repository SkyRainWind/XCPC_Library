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

set<pii>px,py,pz;

signed main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		pz.insert(mpr(x,y));
		px.insert(mpr(y,z));
		py.insert(mpr(x,z));
	}
	int mn = max({px.size(),py.size(),pz.size()});
	if(px.size()==mn)puts("X");
	else if(py.size()==mn)puts("Y");
	else puts("Z");

	return 0;
}

