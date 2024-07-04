// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;
//#define int ll

const int inf = 1e9, INF = 0x3f3f3f3f, mod = 1e9+7;

int k,B,d;
ll l,r;
ll dp[68][68][2][2],a[233],len;

int pw(int x,int y){
	if(!y)return 1;
	if(y == 1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

int dfs(int x,int num,int upnum, int isup,int is0){
	ll &dd = dp[x][num][isup][is0];
	if(~dd)return dd;

	if(num > upnum)return dd = 0;
//	if(len-x+1 < upnum - num)return dd = 0;
	if(len+1 == x)return num == upnum ? dd = 1 : dd=0;

	dd = 0;
	if(isup){
		if(is0){
			if(d == 0){
				if(a[x] == 0)dd = dfs(x+1,num,upnum,1,1);
				else{
					dd += dfs(x+1,num,upnum,0,1);
					dd%=mod;
					dd += 1ll*(a[x]-1)*dfs(x+1,num,upnum,0,0)%mod;
					dd%=mod;
					dd += dfs(x+1,num,upnum,1,0);
				}
			}else{
				if(a[x] < d){
					dd += dfs(x+1,num,upnum,0,1);
					dd += 1ll*(a[x]-1)*dfs(x+1,num,upnum,0,0)%mod;
					dd += dfs(x+1,num,upnum,1,0);
				}
				if(a[x] == d){
					dd += dfs(x+1,num,upnum,0,1);
					dd += 1ll*(a[x]-1)*dfs(x+1,num,upnum,0,0)%mod;
					dd += dfs(x+1,num+1,upnum,1,0);
				}
				if(a[x] > d){
					dd += dfs(x+1,num,upnum,0,1);
					dd += dfs(x+1,num+1,upnum,0,0);
					dd += 1ll*(a[x]-2)*dfs(x+1,num,upnum,0,0)%mod;
					dd += dfs(x+1,num,upnum,1,0);
				}
			}
		}else{
			if(d == 0){
				if(a[x] == 0)dd = dfs(x+1,num+1,upnum,1,0);
				else{
					dd += dfs(x+1,num+1,upnum,0,0);
					dd += 1ll*(a[x]-1)*dfs(x+1,num,upnum,0,0)%mod;
					dd %= mod;
					dd += dfs(x+1,num,upnum,1,0);
				}
			}else{
				if(a[x] < d){
					dd += 1ll*(a[x])*dfs(x+1,num,upnum,0,0)%mod;
					dd %= mod;
					dd += dfs(x+1,num,upnum,1,0);
				}
				if(a[x] == d){
					dd += 1ll*(a[x])*dfs(x+1,num,upnum,0,0)%mod;
					dd %= mod; 
					dd += dfs(x+1,num+1,upnum,1,0);
				}
				if(a[x] > d){
					dd += 1ll*(a[x]-1)*dfs(x+1,num,upnum,0,0)%mod;
					dd += dfs(x+1,num+1,upnum,0,0);
					dd %= mod;
					dd += dfs(x+1,num,upnum,1,0);
				}
			}
		}
	}else{
		if(is0){
			if(d == 0){
				dd += dfs(x+1,num,upnum,0,1);
				dd %= mod;
				dd += 1ll * (B-1) * dfs(x+1,num,upnum,0,0)%mod;
			}else{
				dd += dfs(x+1,num,upnum,0,1);
				dd += 1ll * (B-2) * dfs(x+1,num,upnum,0,0)%mod;
				dd %= mod;
				dd += dfs(x+1,num+1,upnum,0,0);
				dd %= mod;
			}
		}else{
			dd += 1ll*(B-1)*dfs(x+1,num,upnum,0,0)%mod;
			dd += dfs(x+1,num+1,upnum,0,0);
			dd %= mod;
		}
	}
	dd %= mod;
	return dd;
}

int solve(ll num){
	len = 0;
	while(num){
		a[++ len] = num%B;
		num /= B;
	}
	reverse(a+1,a+len+1);

	int ans = 0;
	for(int i=1;i<=len;i++){
//		memset(dp,-1,sizeof dp);
		for(int j=0;j<=len+1;j++)
			for(int k=0;k<=len+1;k++)
				dp[j][k][0][0]=dp[j][k][0][1]=dp[j][k][1][0]=dp[j][k][1][1]=-1;
		int cur = dfs(1,0,i,1,1);
//		printf("hh %lld\n",cur);
		(ans += 1ll*cur*pw(i,k)%mod) %= mod;
	}
	return ans;
}

signed main(){
	int te;scanf("%d",&te);
	// printf("qw %d\n",solve(5));
	while(te --){
		scanf("%d%d%d%lld%lld",&k,&B,&d,&l,&r);
		// printf("! %d\n",solve(5));
		int r1 = solve(r);
//		int r2=0;
		int r2 = solve(l-1);
		printf("%d\n",((r1-r2)%mod+mod)%mod);
	}

	return 0;
}
