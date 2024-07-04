// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 60005;

map<pii,int>mp;
pii res[maxn];
int n,cnt=0;

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=13 && i+(1<<j)-1<=n;j++){
			mp[mpr(i, j)] = ++ cnt;
			res[cnt] = mpr(i, i+(1<<j)-1);
		}
	}
	printf("%d\n",cnt);fflush(stdout);
	for(int i=1;i<=cnt;i++)printf("%d %d\n",res[i].first,res[i].second),fflush(stdout);
	int qu;scanf("%d",&qu);
	while(qu--){
		int l,r;scanf("%d%d",&l,&r);
		int len = (int)(log(1.0 * (r-l+1)) / log(2.0));
		int l1 = l, l2 = r - (1<<len) + 1;
		printf("%d %d\n",mp[mpr(l1, len)], mp[mpr(l2, len)]);fflush(stdout);
	}

	return 0;
}

