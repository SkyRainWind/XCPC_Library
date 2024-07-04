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

LL a,b;
int st[15];
LL dp[15][2][10][15][3][2];	// dp[i][j][lst][k][l] 到第 i 位，与上界关系，末尾数，末尾相同的数的个数，没有/有8/4 
LL res=0;

LL dfs(int cur,int lim=1,int lst=0,int cs=0,int fg=0,int ck=0){
	if(cur == 12)return ck;
	LL &ddp = dp[cur][lim][lst][cs][fg][ck];
	if(~ddp){
		return ddp;
	}
	
	int up = lim?st[cur]:9;
	int down = cur==1?1:0;
	LL ret=0;
	for(int i=down;i<=up;i++){
		if(i == lst){
			if(i!=8&&i!=4)ret += dfs(cur+1,lim&&i==up,lst,cs+1,fg,ck || (cs+1==3));
			if(i==8)if(fg==0||fg==1)ret += dfs(cur+1,lim&&i==up,lst,cs+1,1,ck || (cs+1==3));
			if(i==4)if(fg==0||fg==2)ret += dfs(cur+1,lim&&i==up,lst,cs+1,2,ck || (cs+1==3));
		}else{
			if(i!=8&&i!=4)ret += dfs(cur+1,lim&&i==up,i,1,fg,ck);
			if(i==8)if(fg==0||fg==1)ret += dfs(cur+1,lim&&i==up,i,1,1,ck);
			if(i==4)if(fg==0||fg==2)ret += dfs(cur+1,lim&&i==up,i,1,2,ck);
		}
	}
	return ddp = ret;
}

LL getans(LL x){
	if(x == 9999999999)return 0;
	memset(dp,-1,sizeof dp);
	for(int i=1;i<=11;i++){
		st[i] = x%10;x /= 10;
	}
	reverse(st+1,st+12);
	res=dfs(1);
	return res;
}

signed main(){
//	printf("%lld\n",getans(12121285550));
	scanf("%lld %lld",&a,&b);
	printf("%lld\n",getans(b)-getans(a-1));

	return 0;
}


