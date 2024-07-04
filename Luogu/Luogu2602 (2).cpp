// by Balloons
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2e5+5;

int cnt1[maxn], cnt2[maxn];
int p10[maxn], s10[maxn];
int len, num[maxn], suf[22];

void dfs(int *res, int cur,int islim=1,int islead0=1){
	if(cur == len+1)return ;
	int up = islim ? num[cur] : 9;
//	int dn = islead0 ? 1 : 0;
	for(int i=0;i<=up;i++){
		int nwlim = islim && i == up, nw0 = islead0 && i == 0;
		if(!nwlim && !nw0){
//			printf("!! %d %d %d %d %d\n",i,cur,islim,islead0,p10[len-cur]);
			res[i] += p10[len - cur];
			if(len > cur)for(int j=0;j<=9;j++)res[j] += p10[len - cur - 1] * (len - cur);
		}
		if(!nwlim && nw0){
			dfs(res, cur+1, nwlim, nw0);
		}
		if(nwlim && !nw0){
			dfs(res, cur+1, nwlim, nw0);
			res[i] += suf[cur + 1] + 1;
		}
	}
}

void solve(int *res,int lim){
	if(lim == 0)return ;
	len = 0;
	while(lim){num[++ len] = lim%10; lim /= 10;}
	reverse(num+1,num+len+1);
	memset(suf, 0, sizeof suf);
	for(int i=len;i>=1;i--)suf[i] = suf[i+1] + num[i]*p10[len-i];
	dfs(res,1); 
}

signed main(){
	p10[0] = s10[0] = 1;
	for(int i=1;i<=15;i++)p10[i] = 10ll*p10[i-1];
	for(int i=1;i<=15;i++)s10[i] = s10[i-1] + p10[i];
	int l, r;scanf("%lld%lld",&l,&r);
	solve(cnt1, l-1);
	solve(cnt2, r);
	
	for(int i=0;i<=9;i++)printf("%lld ",cnt2[i] - cnt1[i]); 

	return 0;
}


