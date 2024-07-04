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

int k;
int cnt, up[20];
LL dp[21][(1<<10) + 5][2][2][10];	// dp[i][S][0/1][0/1] 考虑到第 i 位，LIS数组为 S，是否有前导零/是否和上界相等, LIS为k 

int popc(LL x){
	int cnt = 0;
	while(x){	// 一个小 trick 
		x &= (x-1);
		++ cnt;
	}
	return cnt;
}

int calc(int S,int x){
	if(S & (1<<x))return S; 
	int gg = -1;
	for(int i=x+1;i<=9;i++){
		if(S & (1<<i)){gg = i;break;}
	}
	if(gg == -1)return S | (1<<x);
	return S ^ (1<<gg) | (1<<x); 
}

LL dfs(int cur,int S,int is0,int isup){
	if(cur == cnt + 1)return !is0 && popc(S) == k ? 1 : 0;
	int lim = isup ? up[cur] : 9;
	if(!is0 && !isup && ~dp[cur][S][is0][isup][k])return dp[cur][S][is0][isup][k]; 
	LL ret = 0;
	for(int i=0;i<=lim;i++){
		int T = calc(S, i); 
		if(popc(T) > k)break;
		if(i == 0 && is0)T = 0;
		ret += dfs(cur+1, T, is0 && i==0, isup && i == lim);
	}
	return dp[cur][S][is0][isup][k] = ret;
}

LL solve(LL x){
//	memset(dp, -1, sizeof dp);
	if(x == 0)return 0;
	cnt = 0;
	for(int i=1;i<=19;i++)up[++cnt]=x%10, x/=10;
	reverse(up+1, up+cnt+1);
	return dfs(1, 0, 1, 1);
}

int tsc = 0;
void solve(){
	LL l, r;scanf("%lld%lld%d",&l,&r,&k);
	LL re = solve(r) - solve(l-1);
	printf("Case #%d: %lld\n",++tsc,re);
}

signed main(){
	freopen("HDU4352.in","r",stdin);
	freopen("HDU4352_1.out","w",stdout);
	memset(dp, -1, sizeof dp); 
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}


