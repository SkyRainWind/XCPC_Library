// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5e5 + 5;

char s[maxn];
int bit[maxn], n;
vector<int>id[maxn];

int lb(int x){
	return x & -x;
}
int query(int x){
	int ans = 0;
	for(int i=x;i;i-=lb(i))
		ans += bit[i];
	return ans;
}

void update(int x,int del){
	for(int i=x;i<=n;i+=lb(i))
		bit[i] += del;
}

void solve(){
	scanf("%s",s + 1);
	n = strlen(s + 1);
	s[n+1] = '#';
	vector<int>R(n+1);
	int l=0,r=0;
	for(int i=1;i<=n;i++){
		if(i <= r)R[i] = min(r-i, R[l+r-i]);
		else R[i] = 0;

		while(s[i+R[i]+1] == s[i-R[i]-1])
			++ R[i];
		if(i + R[i] >= r)
			r = i+R[i],l=i-R[i];
	}

	for(int i=1;i<=n;i++)++ R[i];
		// for(int i=1;i<=n;i++)printf("%d ",R[i]);

	ll ans = 0;
	for(int i=n;i>=1;i--){
		for(auto it : id[i])
			update(it, -1);
		id[i].clear();
		ans += query(i+R[i]-1);
		// printf("%d %d %d\n",ans,query(i+R[i]-1),R[i]);
		id[i - R[i]].pb(i);
		update(i, 1);
	}
	for(int i=1;i<=n;i++)bit[i] = 0;
	cout << ans << '\n';
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}
