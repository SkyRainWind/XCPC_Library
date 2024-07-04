// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 4e5 * 30 + 5;

int b[maxn],n,ri[maxn], le[maxn];
struct trie{
	int cnt=0, a[maxn][2];
	void insert(int x){
		int fm=0;
		for(int i=30;i>=0;i--){
			int now = (x >> i) & 1;
			if(!a[fm][now]){
				a[fm][now] = ++ cnt;
				fm = cnt;
			}else fm = a[fm][now];
		}
	}
	
	int query(int x){
		int fm = 0;
		int res = 0;
		for(int i=30;i>=0;i--){
			int now = (x >> i) & 1;
			if(a[fm][now ^ 1]){
				fm = a[fm][now ^ 1], res |= (1 << i);
			}
			else fm = a[fm][now];
		}
		return res;
	}
}tr, tr2;

signed main(){
	memset(tr.a,0,sizeof tr.a);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	int xo = 0;
	for(int i=1;i<=n;i++){
		xo ^= b[i];
		tr.insert(xo);
		ri[i] = max(ri[i-1], tr.query(xo));
		ri[i] = max(ri[i], xo);
	}
	
	xo = 0;
	for(int i=n;i>=1;i--){
		xo ^= b[i];
		tr2.insert(xo);
		le[i] = max(le[i+1], tr2.query(xo));
		le[i] = max(le[i], xo);
	}
	int ans=0;
	for(int i=1;i<n;i++)ans = max(ans, ri[i] + le[i+1]);
	cout<<ans;

	return 0;
}

