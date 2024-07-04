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

const int inf = 1e9,maxn=505;

int n,p,mod;
int prm[]={2,3,5,7,11,13,17,19};
struct node{
	int num, S;
	int mxp;
	node(){mxp=0;} 
}a[maxn];
int cmp(node a,node b){return a.mxp < b.mxp;}
int dp[2][(1<<8)+5][(1<<8)+5];
int f[2][(1<<8) +5][(1<<8) + 5];
int g[2][(1<<8) +5][(1<<8) + 5];

inline void add(int &x,int y){
	x += y;
	if(x>=mod)x -= mod;
}

signed main(){
//	freopen("2150-2.out","w",stdout);
	scanf("%d%d",&n,&p);mod=p;
	for(int i=2;i<=n;i++){
		int cur = i;
		a[i-1].num = i;
		for(int j=0;j<8;j++){
			while(cur%prm[j] == 0){
				cur /= prm[j];
				a[i-1].S |= (1<<j);
			}
		}
		a[i-1].mxp = cur;
	}
	sort(a+1,a+n,cmp);
	int t=n-1;
	for(int i=1;i<=n-1;i++)if(a[i].mxp!=1){t=i-1;break;} 
	dp[0][0][0] = 1;
	for(int i=1;i<=t;i++){
		memset(dp[i&1],0,sizeof dp[i&1]);
		int curi = a[i].S;
		for(int S1=0;S1<=(1<<8)-1;S1++){
			for(int S2=0;S2<=(1<<8)-1;S2++)if((S1&S2) == 0){
				if((S2&curi) == 0)add(dp[i&1][S1|curi][S2],dp[i&1^1][S1][S2]);
				if((S1&curi) == 0)add(dp[i&1][S1][S2|curi],dp[i&1^1][S1][S2]);
				add(dp[i&1][S1][S2],dp[i&1^1][S1][S2]);
			}
		}
	}
	int lst_dp = t;
	
	for(int i=t+1;i<=n-1;i++){
		if(a[i].mxp != a[i-1].mxp){
			memcpy(f[i&1^1],dp[lst_dp&1], sizeof f[i&1^1]);
			memcpy(g[i&1^1],dp[lst_dp&1], sizeof g[i&1^1]);
		}
		memset(f[i&1],0,sizeof f[i&1]), memset(g[i&1],0,sizeof g[i&1]);	
	
		for(int S1=0;S1<=(1<<8)-1;S1++){
			for(int S2=0;S2<=(1<<8)-1;S2++)if((S1&S2)==0){
				if((S1&a[i].S) == 0)add(g[i&1][S1][S2|a[i].S],g[i&1^1][S1][S2]);
				if((S2&a[i].S) == 0)add(f[i&1][S1|a[i].S][S2],f[i&1^1][S1][S2]);
				add(f[i&1][S1][S2],f[i&1^1][S1][S2]);
				add(g[i&1][S1][S2],g[i&1^1][S1][S2]);
			}
		}
		if(a[i].mxp != a[i+1].mxp || i == n-1){
			for(int S1=0;S1<=(1<<8)-1;S1++)
				for(int S2=0;S2<=(1<<8)-1;S2++)if((S1&S2) == 0)
					dp[lst_dp&1][S1][S2]=((f[i&1][S1][S2] + g[i&1][S1][S2])%mod - dp[lst_dp&1][S1][S2] + mod)%mod;//!!!! 
		}
	}
	int ans=0;
	for(int S1=0;S1<=(1<<8)-1;S1++)for(int S2=0;S2<=(1<<8)-1;S2++)if((S1&S2)==0)
		add(ans,dp[lst_dp&1][S1][S2]);
	printf("%d\n",ans);

	return 0;
}


