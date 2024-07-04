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

int cnt=0;
int st[15];

void dfs(int cur,int lim=1,int is0=1){
	if(cur==cnt+1)return 1;
	int &ddp = dp[cur][lim][is0];
	if(~ddp)return ddp;
	
	int up=lim?st[cur]:9;
	for(int i=0;i<=up;i++){
		dp[cur][lim][is0][i] = dfs(cur+1,lim&&i==up,is0&&i==0);
	}
}

void getans(int x){
	cnt=0;
	while(x){st[++ cnt]=x%10;x/=10;}
	reverse(st+1,st+cnt+1);
	dfs(1);
}

signed main(){
	int l,r;scanf("%d%d",&l,&r);
	getans(r);

	return 0;
}


