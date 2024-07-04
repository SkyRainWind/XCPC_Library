// by Balloons
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e9,maxn=1e5 + 5;

int n,m;

void solve(){
	scanf("%I64d%I64d",&n,&m);
	int mxx = -1e18,mnn = 1e18,p;
	for(int i=1;i<=n;i++){
		int mx=0;
		for(int j=1;j<=m;j++){
			int t;scanf("%I64d",&t);
			mx += t*j;
		}
		if(mxx < mx)p = i;
		mxx = max(mxx, mx);
		mnn = min(mnn, mx);
	}
	printf("%I64d %I64d\n",p,mxx - mnn);
}

signed main(){
	int te;scanf("%I64d",&te);
	while(te --)solve();

	return 0;
}


