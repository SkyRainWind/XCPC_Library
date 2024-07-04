// by SkyRainWind
#include <cstdio>
#include <vector>
#include <set>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=50005;

int n,m;
vector<pii>g[maxn];
int dp[maxn], mx[maxn];

void dfs(int x,int lim,int fat = -1){
	if(~fat && g[x].size() == 1)return ;
	vector<int> mp;
	for(pii now : g[x]){
		int u = now.first, w = now.second;
		if(u == fat)continue;
		dfs(u, lim, x);
		mx[u] += w;
		if(mx[u] >= lim)++ dp[x];	// 自成一派 
		else mp.push_back(mx[u]);
		dp[x] += dp[u];
	}
	sort(mp.begin(),mp.end());
	int mpc = mp.size();
	int curid = -2, curmx = -inf;
	int le = 0, ri = mpc-1, rans;
	
	// 单独考虑全配对情况 
	int l=0;
	int r=mpc-1;
	int curres = 0;
	while(l < r){
		if(mp[l] + mp[r] >= lim)++l, -- r,++ curres;
		else ++ l;
	}
	if(curres > curmx)curmx = curres, curid = -1;
	else if(curres == curmx)curid = -1;
	
	// 二分上传哪条边 
	while(le <= ri){
		int mid = le + ri >> 1;
		int l = mid == 0 ? 1 : 0;
		int r = mid == mpc-1 ? mpc-2 : mpc-1;
		int curres = 0;
		while(l < r){
			if(l == mid){
				++l;continue;
			}
			if(r == mid){
				-- r;continue;
			}
			if(mp[l] + mp[r] >= lim)++l, -- r,++ curres;
			else ++ l;
		}
		if(curres > curmx)curmx = curres, curid = mid, le=mid+1;
		else if(curres == curmx)curid = mid, le=mid+1;
		else ri = mid-1;
	}
	
	if(curid == -2){	// 没有配对，直接取最大 
		mx[x] = mp[mp.size() - 1];
		return ;
	}
	if(curid == -1){	// 全配对 
		mx[x] = 0;
		dp[x] += curmx;
		return ;
	}
	mx[x] = mp[curid];	// 部分配对 
	dp[x] += curmx;
}

int check(int lim){
	for(int i=1;i<=n;i++)dp[i] = mx[i] = 0;
	dfs(1, lim);
	if(dp[1] >= m)return 1;
	return 0;
}

signed main(){
//	freopen("P5021_5.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		g[x].push_back(mpr(y,z)), g[y].push_back(mpr(x, z));
	}
	int l = 1, r = 1e9, ans;
	while(l <= r){
		int mid=l+r>>1;
		if(check(mid))l = mid+1, ans = mid;
		else r = mid-1;
	}
	printf("%d\n",ans);

	return 0;
}
