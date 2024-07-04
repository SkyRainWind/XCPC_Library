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

const int inf = 1e9,maxn=200005;

int t0,t1,t00,t01,n;
int t[maxn],c[maxn],p[maxn];
int dp[2][1445];

void ck(int &a,int b,int c){if(b != -1e9)a = max(a,b+c);}

signed main(){
	scanf("%d:%d %d:%d %d",&t0,&t1,&t00,&t01,&n);
	int dt = -(t0*60+t1)+(t00*60+t01);
	int nn = 0;
	for(int i=1;i<=n;i++){
		int tt,cc,pp,q=1;scanf("%d%d%d",&tt,&cc,&pp);
		if(pp == 0)pp = 1440;
		while(1){
			if(pp-q >= 0){pp -= q;t[++nn]=q*tt;c[nn]=q*cc;}
			else{t[++nn]=pp*tt;c[nn]=pp*cc;break;}
			q <<= 1;
		}
	}
	n = nn;
	for(int i=0;i<=1440;i++)dp[0][i]=dp[1][i]=-1e9;
	dp[0][0] = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=dt;j++)ck(dp[i&1][j],dp[i&1^1][j],0);//!!!
		for(int j=t[i];j<=dt;j++){
			ck(dp[i&1][j],dp[i&1^1][j-t[i]] , c[i]);
		}
	}
	int ans=0;
	for(int i=0;i<=dt;i++)ans=max(ans,dp[n&1][i]);
	printf("%d\n",ans);

	return 0;
}


