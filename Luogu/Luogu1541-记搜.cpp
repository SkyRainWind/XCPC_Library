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

const int inf = 1e9,maxn=355;

int n,m;
int a[maxn],b[maxn],cnt[11];
int dp[41][41][41][41]; 

inline int gt(int i,int j,int k,int u){return i+2*j+3*k+4*u+1;}
void ck(int &a,int b){a=max(a,b);}

int dfs(int cur,int i,int j,int k,int u){
	if(i+j+k+u==0){return dp[0][0][0][0] = a[1];}
	if(dp[i][j][k][u]>0)return dp[i][j][k][u];
	
	int &ddp = dp[i][j][k][u];
	if(i)ck(ddp,dfs(cur+1,i-1,j,k,u)+a[cur+1]);
	if(j)ck(ddp,dfs(cur+2,i,j-1,k,u)+a[cur+2]);
	if(k)ck(ddp,dfs(cur+3,i,j,k-1,u)+a[cur+3]);
	if(u)ck(ddp,dfs(cur+4,i,j,k,u-1)+a[cur+4]);
	
	return ddp;
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]),++ cnt[b[i]];
	for(int i=0;i<=cnt[1];i++)for(int j=0;j<=cnt[2];j++)
		for(int k=0;k<=cnt[3];k++)for(int u=0;u<=cnt[4];u++)dp[i][j][k][u]=-1e9;
	printf("%d\n",dfs(1,cnt[1],cnt[2],cnt[3],cnt[4])); 

	return 0;
}


