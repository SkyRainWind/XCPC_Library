// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e5+5;

int n;
int a[maxn];
map<int,int>mp,trans;

struct fen{
	int a[maxn];
	int N = -1;
	void init(int up){
		N = up;
	}
	
	int lb(int x){return x & (-x);}
	void add(int x,int del){	// init N!!!
		assert(N != -1);
		for(int i=x;i<=N;i+=lb(i)){
			a[i] += del;
		}
	}
	
	int query(int x){
		int res = 0;
		for(int i=x;i;i-=lb(i))res += a[i];
		return res;
	}
	int query(int l,int r){
		return query(r) - query(l-1);
	}
}rev,sev,nrev,nsev;
int gr[maxn], le[maxn];

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), mp[a[i]] = 1;
	int cnt = 0;
	for(auto it : mp)trans[it.first] = ++ cnt;
	for(int i=1;i<=n;i++)a[i] = trans[a[i]];
	
	rev.init(cnt); sev.init(cnt);
	nrev.init(cnt); nsev.init(cnt);
	rev.add(cnt - a[1] + 1, 1);sev.add(a[1], 1);
	ll revcnt=0, sevcnt=0, ans = 0;
	ll del1 = 0;
	for(int i=2;i<=n;i++){
		int tr = rev.query(cnt - a[i] + 1 - 1), sr = sev.query(a[i] - 1); 
		revcnt += tr;sevcnt += sr;
		ans += 1ll * tr * sevcnt;
		ans += 1ll * sr * revcnt;
		rev.add(cnt - a[i] + 1, 1);sev.add(a[i], 1);
		del1 += 2ll*tr*sr;	// #2 
		gr[i] = tr, le[i] = sr;
	}
	
	nrev.add(cnt - a[n] + 1, 1); nsev.add(a[n], 1);
	ll del2 = 0;
	for(int i=n-1;i>=1;i--){
		int tr = nrev.query(cnt - a[i] + 1 - 1), sr = nsev.query(a[i] - 1);
		del2 += 1ll*gr[i]*tr + 1ll*le[i]*sr + 1ll*tr*sr;  // #3  #4  #1
		nrev.add(cnt - a[i] + 1, 1); nsev.add(a[i], 1);
	}
	cout<<ans - del1 - del2;

	return 0;
}

