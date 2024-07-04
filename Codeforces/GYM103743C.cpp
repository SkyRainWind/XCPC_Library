// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e6+5;

int n,qu,p;
int a[maxn], b[maxn], cnt=0;

signed main(){
	scanf("%d%d%d",&n,&qu,&p);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	while(qu --){
		int x;scanf("%d",&x);
		if(x > p)
			puts("Noob");
		else{
			cnt = 0;
			for(int i=x;i<=n;i+=x)
				b[++ cnt] = a[i];
				// printf("! %d\n", a[i]);
			vector<ll>f(cnt+2, -1e18);
			int up = p / x;
			ll ans = -1e18;
			deque<int>dq;
			for(int i=1;i<=cnt;i++){
				while(!dq.empty() && i - dq.front() > up)
					dq.pop_front();
				ll ndp = (dq.empty() ? 0 : f[dq.front()]) + b[i];
				if(i <= up)ndp = max(ndp, 1ll * b[i]);
				// if(!dq.empty())printf("- %d %d\n",f[dq.back()],ndp);
				while(!dq.empty() && f[dq.back()] <= ndp)
					dq.pop_back();
				dq.push_back(i);
				f[i] = ndp;
				if(n + 1 - x*i <= p)
					ans = max(ans, f[i]);
				// printf("hh %d %d\n",f[i],dq.back());
			}
			// while(!dq.empty() && cnt + 1 - dq.front() > up)
				// dq.pop_front();
			printf("%lld\n",ans);
		}
	}

	return 0;
}

