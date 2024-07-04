// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2333;

int n,m,t;
struct node{string s;int t,m;}a[maxn];
int dp[(1<<22)+5];
int tim[(1<<22)+5];
int lowbit(int x){return x & (-x);}

void dfs(int S){
	if(S == 0)return ;
	for(int i=n;i>=1;i--)
		if(S & (1<<i-1))
			if(dp[S ^ (1<<i-1)] + max(a[i].m - tim[S], 0) == dp[S]){
				dfs(S ^ (1<<i-1));
				cout << a[i].s << '\n';
				break;
			}
}
signed main(){
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n;i++)cin>>a[i].s>>a[i].t>>a[i].m;
	for(int i=1;i<=n;i++)tim[(1 << i-1)] = a[i].t;
	
	for(int S=1;S<=(1<<n)-1;S++){
		tim[S] = tim[S ^ lowbit(S)] + tim[lowbit(S)];
		if(tim[S] > t)return puts("No Answer"), 0;
		for(int i=1;i<=n;i++)
			if((S & (1<<i-1)))
				dp[S] = max(dp[S], dp[S ^ (1<<i-1)] + max(a[i].m - tim[S], 0));
	}
	if(dp[(1<<n)-1] < m)return puts("No Answer"), 0;
	printf("%d\n",dp[(1<<n)-1]);
	dfs((1<<n)-1);

	return 0;
}

