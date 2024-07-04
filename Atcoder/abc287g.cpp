// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 4e5+5;

int n,q,a[maxn],b[maxn],c[maxn],v[maxn];
struct node{
	int ty,x,y;
}qu[maxn];
map<int,int>mp;
int cmp(int a,int b){return a>b;}

struct fen{
	ll a[maxn];
	int N = -1;
	void init(int up){
		N = up;
	}
	
	int lb(int x){return x & (-x);}
	void add(int x,ll del){	// init N!!!
		assert(N != -1);
		for(int i=x;i<=N;i+=lb(i)){
			a[i] += del;
		}
	}
	
	ll query(int x){
		ll res = 0;
		for(int i=x;i;i-=lb(i))res += a[i];
		return res;
	}

	int kth(int k){
		ll sum=0;
		int x=0;
		for(int i=log2(N);i>=0;i--){
			x+=1<<i;
			if(x>=N || sum + a[x] >= k)x -= 1<<i;
			else sum += a[x];
		}
		return x+1;
	}
}fc, fw;

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]),c[i]=a[i];
	scanf("%d",&q);
	
	int cnt = n;
	for(int i=1;i<=q;i++){
		scanf("%d",&qu[i].ty);
		if(qu[i].ty == 1){
			scanf("%d%d",&qu[i].x,&qu[i].y);
			c[++cnt] = qu[i].y;
		}else if(qu[i].ty == 2){
			scanf("%d%d",&qu[i].x,&qu[i].y);
		}else scanf("%d",&qu[i].x);
	}
	
	sort(c+1,c+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		mp[c[i]] = i;
		v[i] = c[i];
	}
	for(int i=1;i<=n;i++)a[i] = mp[a[i]];
	
	fc.init(cnt);fw.init(cnt);
	for(int i=1;i<=n;i++){
		fc.add(a[i], b[i]);
		fw.add(a[i], 1ll*v[a[i]]*b[i]);
	}
	
	for(int i=1;i<=q;i++){
		if(qu[i].ty == 1){
			qu[i].y = mp[qu[i].y];
			int x = qu[i].x, y = qu[i].y;
			fc.add(a[x], -b[x]);
			fw.add(a[x], -1ll*v[a[x]]*b[x]);
			a[x] = y;
			fc.add(a[x], b[x]);
			fw.add(a[x], 1ll*v[a[x]]*b[x]);
		}else if(qu[i].ty == 2){
			int x = qu[i].x, y = qu[i].y;
			fc.add(a[x], -b[x]);
			fw.add(a[x], -1ll*v[a[x]]*b[x]);
			b[x] = y;
			fc.add(a[x], y);
			fw.add(a[x], 1ll*v[a[x]]*y);
		}else{
			int kt = fc.kth(qu[i].x);
			if(fc.query(kt) < qu[i].x && kt == cnt)puts("-1");
			else{
				ll res = fw.query(kt-1);
				qu[i].x -= fc.query(kt-1);
				res += 1ll*qu[i].x*v[kt];
				cout<<res<<'\n';
			}
		}
	}

	return 0;
}

