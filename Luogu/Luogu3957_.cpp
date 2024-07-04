#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5e5 + 5;

int n,d,k;
int x[maxn], s[maxn];
LL dp[maxn];

int check(int lim){
	int jmin = max(d-lim, 1), jmax = d + lim;
	deque<int>dq,bk;
	bk.pb(0);
	
	for(int i=1;i<=n;i++){
		while(!bk.empty() && x[i]-x[bk.front()] >= jmin){
			int u = bk.front();bk.pop_front();
			while(!dq.empty() && dp[dq.back()] < dp[u])
				dq.pop_back();
			dq.pb(u);
		}
		while(!dq.empty() && x[i]-x[dq.front()] > jmax)
			dq.pop_front();
		if(dq.empty())dp[i] = -1e18;
		else dp[i] = dp[dq.front()] + s[i];
		if(dp[i] >= k)return 1;
		bk.pb(i);
	}
	
	return 0;
}

signed main(){
	scanf("%d%d%d",&n,&d,&k);
	LL r1 = 0;
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&s[i]), r1 += s[i] >= 0 ? s[i] : 0;
	if(r1 < k){
		puts("-1");
		return 0;
	}
	int l=1, r=1e9, ans;
	while(l <= r){
		int mid = l+r>>1;
		if(check(mid))r = mid-1, ans = mid;
		else l = mid+1;
	}
	printf("%d\n",ans);

	return 0;
}
