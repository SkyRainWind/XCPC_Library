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

const int inf = 1e9,maxn=1005;

int t,n;
int v[maxn],p[maxn],q[maxn],de[maxn];
int nn,c[maxn],w[maxn];
int mp[maxn][4];
int dp[65][33005];
// 只对主件讨论，附件跳过，转移分只取主件；取1/2个附件 

void ck(int &a,int b,int c){if(b != -1e9)a=max(a,b+c);} 

signed main(){
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&v[i],&p[i],&q[i]);
		w[i] = v[i]*p[i];
		c[i] = v[i];
		if(q[i]){
			++ de[q[i]];
			mp[q[i]][de[q[i]]] = i;
		}
	}
	
	for(int i=0;i<=n;i++)for(int j=0;j<=t;j++)dp[i][j] = -1e9;
	dp[0][0] = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=t;j++)dp[i][j] = dp[i-1][j];
		if(q[i]){
			continue;
		}
		if(de[i] == 0){
			for(int j=c[i];j<=t;j++){
				ck(dp[i][j], dp[i-1][j-c[i]], w[i]);
			}
		}
		if(de[i] == 1){
			for(int j=c[i];j<=t;j++){
				ck(dp[i][j], dp[i-1][j-c[i]], w[i]);
				if(j-c[i]-c[mp[i][1]] >= 0)ck(dp[i][j], dp[i-1][j-c[i]-c[mp[i][1]]], w[i]+w[mp[i][1]]);
			}
		}
		if(de[i] == 2){
			for(int j=c[i];j<=t;j++){
				ck(dp[i][j], dp[i-1][j-c[i]], w[i]);
				if(j-c[i]-c[mp[i][1]] >= 0)ck(dp[i][j], dp[i-1][j-c[i]-c[mp[i][1]]], w[i]+w[mp[i][1]]);
				if(j-c[i]-c[mp[i][2]] >= 0)ck(dp[i][j], dp[i-1][j-c[i]-c[mp[i][2]]], w[i]+w[mp[i][2]]);
				if(j-c[i]-c[mp[i][1]]-c[mp[i][2]] >= 0)ck(dp[i][j], dp[i-1][j-c[i]-c[mp[i][1]]-c[mp[i][2]]], w[i]+w[mp[i][1]]+w[mp[i][2]]);
			}
		}
	}
	int ans = -1e9;
	for(int i=0;i<=t;i++)ans=max(ans,dp[n][i]);
	printf("%d\n",ans);

	return 0;
}


