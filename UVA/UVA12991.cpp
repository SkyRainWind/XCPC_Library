// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e18,maxn=4005;

int n,t[maxn],p[maxn];	// t 球 p 水 
int preft[maxn][2],prefp[maxn][2];	// t[i]的前缀；前缀的前缀(1*a[1]+2*a[2]+..) p[i]的前缀 前缀的前缀 
int suft[maxn][2],sufp[maxn][2];	// 后缀 后缀的后缀 
int dp[maxn][maxn];	// dp[i][0/1] 到第 i 楼，最后一段是 水/球 

int cst(int l,int r,int type){	// type==0 -> p[i] type==1 -> t[i]
	if(l==r)return type==0?p[l]:t[l];
	int mid = l+r>>1;	
	if(l == 1 && r == n)return 1e18;
	if(r == n){
		if(type == 0)return sufp[l][1];
		else return suft[l][1];
	}
	if(l == 1){
		if(type == 0)return prefp[r][1];
		else return preft[r][1];
	}
	// [l..mid] (mid-l+1)*p[l]+(mid-l)*p[l+1]+..+p[mid]  [mid+1..r] (r-mid)*p[r]+...+p[mid+1]
	// 			sufp[l][1] - sufp[mid+1][1] - (mid-l+1) * sufp[mid+1][0];
	//			prefp[r][1] - prefp[mid][1] - (r-mid) * prefp[mid][0];
	if(type == 0){
		int t1 = sufp[l][1] - sufp[mid+1][1] - (mid-l+1) * sufp[mid+1][0];
		int t2 = prefp[r][1] - prefp[mid][1] - (r-mid) * prefp[mid][0];
		return t1 +t2;
	}
	if(type == 1){
		int t1 = suft[l][1] - suft[mid+1][1] - (mid-l+1) * suft[mid+1][0];
		int t2 = preft[r][1] - preft[mid][1] - (r-mid) * preft[mid][0];
		return t1 +t2;
	}
}

int tot=0;

void solve(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&t[i],&p[i]);
	for(int i=1;i<=n;i++)preft[i][0] = preft[i-1][0] + t[i],prefp[i][0] = prefp[i-1][0] + p[i];
	for(int i=1;i<=n;i++)preft[i][1] = preft[i-1][1] + preft[i][0], prefp[i][1] = prefp[i-1][1] + prefp[i][0]; 

	suft[n+1][0] = suft[n+1][1] = sufp[n+1][0] = sufp[n+1][1] = 0;	//!!!!!
	for(int i=n;i>=1;i--)suft[i][0] = suft[i+1][0] + t[i],sufp[i][0] = sufp[i+1][0] + p[i];
	for(int i=n;i>=1;i--)suft[i][1] = suft[i+1][1] + suft[i][0],sufp[i][1] = sufp[i+1][1] + sufp[i][0];
	
	for(int i=1;i<=n;i++)dp[i][0] = dp[i][1] = inf;
	
	dp[0][0] = dp[0][1] = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i-1;j++){
			dp[i][0] = min(dp[i][0],dp[j][1]+cst(j+1,i,1));
			dp[i][1] = min(dp[i][1],dp[j][0]+cst(j+1,i,0));
		}
	}
	int ans = min(dp[n][1], dp[n][0]);
	printf("Case #%lld: %lld\n",++tot,ans);
}

signed main(){
//	freopen("UVA12991.in","r",stdin);
//	freopen("UVA12991.out","w",stdout);
	int te;scanf("%lld",&te);
	while(te--)solve();

	return 0;
}


