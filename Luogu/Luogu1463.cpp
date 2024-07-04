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

int pm[] = {2,3,5,7,11,13,17,19,23,29};
int a[23],n;
int mx;LL mxi;

void dfs(int x,int lst,LL cur,int ys){
	if(cur > 1ll * n)return ;
	if(ys > mx){
		mx = ys;
		mxi = cur;
	}else if(ys == mx)mxi = min(mxi, cur);
	
	if(x == 10)return ;
	int bs = pm[x];
	for(int j=1;j<=lst;j++){
		if(1ll * cur * bs > 1ll * n)return ;
		dfs(x+1, j, 1ll * cur * bs, ys * (j+1));
		bs *= pm[x];
	}
}

signed main(){
	scanf("%d",&n);
	for(int i=31;i>=1;i--){
		dfs(1, i, 1ll<<i, i+1);
	}
	printf("%lld\n",mxi);

	return 0;
}

