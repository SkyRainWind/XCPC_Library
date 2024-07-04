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

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5,mod=10007;

int n;
char s[maxn];

int pw(int x){
	if(!x)return 1;if(x==1)return 2;
	int mid = pw(x>>1);
	if(x&1)return 2ll*mid*mid%mod;
	return 1ll*mid*mid%mod;
}
int nxt[maxn];
int stk[maxn], tp=0;

pair<int,int> dfs(int l,int r){
	int curfig = 0, curans = 1, ans=1, totfig=0;
	for(int i=l;i<=r;){
		if(s[i] == '('){
			pair<int,int> res = dfs(i+1, nxt[i]-1);
			curfig += res.first;
			totfig += res.first;
			curans = 1ll*curans * ((pw(res.first) - res.second%mod + mod)%mod) % mod;
			i = nxt[i]+1;
			continue;
		}
		if(s[i] == '*'){
			if((i > l && s[i-1] != ')') || (i == l)){
				++ curfig;
				++ totfig;
			}
		}
		if(s[i] == '+'){
			if((i>l && (s[i-1] != ')')) || (i == l))++ curfig,++ totfig;
			ans = 1ll*ans*((pw(curfig) - curans+mod) % mod)%mod;
			curfig = 0;
			curans = 1;
		}
		i ++;
	}
	if(s[r] != ')')++ curfig, ++ totfig;
	ans = 1ll*ans*((pw(curfig) - curans+mod)%mod)%mod;
	return mpr(totfig, ans);
}

signed main(){
	scanf("%d",&n);
	scanf("%s",s + 1);
	for(int i=1;i<=n;i++){
		if(s[i] == '(')stk[++ tp] = i;
		if(s[i] == ')'){
			int cur = stk[tp --];
			nxt[cur] =i;
		}
	}
	pair<int,int>res = dfs(1,n);
	printf("%d\n",res.second);

	return 0;
}


