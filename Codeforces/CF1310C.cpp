// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1005;

int n,m;
ll k;
char s[maxn];
pii sub[maxn * maxn];
int lcp[maxn][maxn];
int cnt = 0;
ll dp[maxn][maxn], suf[maxn][maxn];

int check(int p){
	memset(dp, 0, sizeof dp);
	memset(suf, 0, sizeof suf);
	
	// dp[i][j] s[i..n] 划分成了 j 段并且每一段都 >= s[sub[p]] 的方案数
	// dp[i][j] <- dp[t+1][j-1] (s[i][t] >= s[sub[p]])
	
	suf[n+1][0] = 1;
	int sl = sub[p].first,sr = sub[p].second;
	for(int i=n;i>=1;i--){
		int t = min(sr-sl+1, lcp[sl][i]);
		if(t == sr-sl+1 || s[i+t] > s[sl+t]){
			for(int j=1;j<=m;j++)
				dp[i][j] = suf[i+t+1][j-1];
		}
		for(int j=0;j<=m;j++)
			suf[i][j] = suf[i+1][j] + dp[i][j],
			suf[i][j] = min(suf[i][j], k);
	}
	return dp[1][m] >= k;
}

signed main(){
	scanf("%d%d%lld",&n,&m,&k);
	scanf("%s",s + 1);
	for(int i=n;i>=1;i--)
		for(int j=n;j>=1;j--){
			if(s[i] == s[j])lcp[i][j] = 1 + lcp[i+1][j+1];
			else lcp[i][j] = 0;
		}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			sub[++ cnt] = mpr(i, j);
	sort(sub+1,sub+cnt+1,[&](pii a,pii b){
		int len = lcp[a.first][b.first];
		if(len >= a.second-a.first+1 || len >= b.second-b.first+1)
			return a.second-a.first <= b.second-b.first;
		return s[a.first+len] <= s[b.first+len];
	});
	int l=1,r=cnt,ans=0;
	while(l <= r){
		int mid = l+r>>1;
		if(check(mid))l = mid+1, ans = mid;
		else r = mid-1;
	}
	++ ans;
	for(int i=sub[ans].first;i<=sub[ans].second;i++)
		putchar(s[i]);
	puts("");

	return 0;
}

