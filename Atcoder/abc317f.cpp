// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 998244353;

ll n;
int a,b,c;
int num[77], cnt=0;
int dp[67][12][12][12][2][2][2][8];

int dfs(int x,int ma=0,int mb=0,int mc=0,int ua=1,int ub=1,int uc=1,int z=7){
//	printf("%d %d %d %d %d %d %d %d\n",x,ma,mb,mc,ua,ub,uc,z);
	if(x == cnt+1){
		if(z || ma || mb || mc)
			return dp[x][ma][mb][mc][ua][ub][uc][z] = 0;
		else
			return dp[x][ma][mb][mc][ua][ub][uc][z] = 1;
 	}
	int &ret = dp[x][ma][mb][mc][ua][ub][uc][z];
	if(~ret)return ret;
	ret = 0;
	(ret += dfs(x+1,ma*2%a,mb*2%b,mc*2%c,ua&&num[x]==0,ub&&num[x]==0,uc&&num[x]==0,z)) %= mod;
	if(!(ua==1&&num[x]==0) && !(uc==1&&num[x]==0))(ret += dfs(x+1,(ma*2+1)%a,mb*2%b,(mc*2+1)%c,ua&&num[x]==1,ub&&num[x]==0,uc&&num[x]==1,z&2)) %= mod;
	if(!(ua==1&&num[x]==0) && !(ub==1&&num[x]==0))(ret += dfs(x+1,(ma*2+1)%a,(mb*2+1)%b,mc*2%c,ua&&num[x]==1,ub&&num[x]==1,uc&&num[x]==0,z&1)) %= mod;
	if(!(ub==1&&num[x]==0) && !(uc==1&&num[x]==0))(ret += dfs(x+1,ma*2%a,(mb*2+1)%b,(mc*2+1)%c,ua&&num[x]==0,ub&&num[x]==1,uc&&num[x]==1,z&4)) %= mod;
	
	return ret;
}

signed main(){
	memset(dp,-1,sizeof dp);
	scanf("%lld%d%d%d",&n,&a,&b,&c);
	for(int i=0;i<=60;i++){
		int t = (n >> i) & 1;
		num[++ cnt] = t;
	}
	reverse(num+1,num+cnt+1);
	int res = dfs(1);
	printf("%d\n",res);

	return 0;
}

