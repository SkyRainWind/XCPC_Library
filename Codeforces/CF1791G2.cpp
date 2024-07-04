// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n,c,a[maxn];
ll sum[maxn];
pii b[maxn];

void solve(){
	scanf("%d%d",&n,&c);
	int mn=1e9, id;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}

	for(int i=1;i<=n;i++){
		b[i] = {min(a[i] + i, a[i] + (n+1) - i),a[i] + i};
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)sum[i] = sum[i-1] + b[i].first;
	
	int ra=0;
	for(int i=1;i<=n;i++){
		if(b[i].second <= c){
			int l=1,r=n,ans=0;
			while(l<=r){
				int mid=l+r>>1;
				ll val = sum[mid];
				
				if(mid >= i)val -= b[i].first;
				if(val + b[i].second <= c){
					ans = mid;
					l = mid+1;
				}else r = mid-1;
			}
			if(i > ans)++ ans;
			ra = max(ra, ans);
		}
	}
	printf("%d\n",ra);
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

