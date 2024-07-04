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

const int inf = 1e9;
int n,tar[19];
int dp[19][19][2][2];

int dfs(int cur,int islead0=1,int islim=1,int lstdg=0){
	if(cur == n+1)return 1;
	int &ddp = dp[cur][lstdg][islead0][islim];
	if(~ddp)return ddp;
	
	int ret=0;
	int up = islim == 1?tar[cur]:9;
	
	for(int i=0;i<=up;i++){
		if((islead0) || (!islead0 && abs(lstdg - i)>=2))ret += dfs(cur+1,islead0 && (i==0),islim && (i==up),i);
	}
	return ddp = ret;
}

int sum(int x){
	n=0; 
	memset(dp,-1,sizeof dp); 
	int t=x;while(t){tar[++n]=t%10;t/=10;}
	reverse(tar+1,tar+n+1);
	return dfs(1);
}

signed main(){
	int l,r;scanf("%d%d",&l,&r);
	printf("%d\n",sum(r) - sum(l-1));

	return 0;
}


