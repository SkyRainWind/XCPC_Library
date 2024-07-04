// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e6 + 5;

int n,k,p;
vector<int> p1[55],p2[55];
int st[maxn][23];

int query(int l,int r){
	int len = r-l+1;
	len = (int) (log(1.0 * len) / log(2.0));
	return min(st[l][len], st[r-(1<<len) + 1][len]);
}

signed main(){
	scanf("%d%d%d",&n,&k,&p);
	for(int i=1;i<=n;i++){
		int ai,bi;scanf("%d%d",&ai,&bi);
		++ ai;
		st[i][0] = bi;
		p1[ai].push_back(bi);
		p2[ai].push_back(i);
	}
	for(int j=1;j<=21;j++)
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[i][j] = min(st[i][j-1], st[i+(1<<j-1)][j-1]);
		}
	
	LL res = 0;
	for(int i=1;i<=k;i++){
		int p1s = p1[i].size();
		for(int le=0;le<p1s-1;le++){
			int l=le,r = p1s -1, ans = -1;
//			printf("?? %d %d %d %d\n",i,l,r,p1s - 1);
	//		int l = p1[i][0], r = *p1[i].end(), ans = -1;
			while(l <= r){
				int mid = l+r >> 1;
	//			int cur = 
				if(query(p2[i][le], p2[i][mid]) <= p)r = mid-1, ans = mid;
				else l = mid+1;
			}
//			printf("aft %d\n",ans);
			if(ans == le){
				res += 1ll * ((int)p1s - ans) - 1;
			}else if(~ans){
				res += 1ll * ((int)p1s - ans);
//				printf("!! %d %d\n",i,((int)p1s - ans) * (le+1)); 
			}
//			printf("?? %d %d %d %d %d %d\n",i,le,p1s-1,res,ans,query(p2[2][3],p2[2][5]));
		}
	}
	printf("%lld\n",res);

	return 0;
}


