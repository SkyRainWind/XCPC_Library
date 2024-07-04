// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=305;

int n,l[maxn],c[maxn];
map<int,int>dp[2];

int gcd(int a,int b){if(a==0)return b;return !b?a:gcd(b,a%b);}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&l[i]); 
	}
	for(int i=1;i<=n;i++)scanf("%d",&c[i]); 
	
	int ans=inf;
	dp[0][0] = 0;
	for(int i=1;i<=n;i++){
		dp[i&1] = dp[i&1^1];
		for(pair<int,int> dpp : dp[i&1^1]){
			int tmp = gcd(dpp.first,l[i]);
			if(dp[i&1].count(tmp))dp[i&1][tmp] = min(dp[i&1][tmp], dpp.second+c[i]);
			else dp[i&1][tmp] = dpp.second+c[i];
		}
	}
	printf("%d\n",dp[n&1].count(1)==0 ? -1 : dp[n&1][1]);

	return 0;
}


