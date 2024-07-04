// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

#define LL __int128
//typedef long double LL;
const long double eps = 1e-12;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 100005;

int n,m;
LL gcd(LL a,LL b){return __gcd(a,b);}
//LL gcd(LL a,LL b){return b < eps?a:gcd(b,a-round(a/b)*b);}
typedef struct frac{
	int id;
	LL a,b;
	frac(){}
	frac(int id,LL a,LL b):id(id),a(a),b(b){}
}fr;
//typedef frac fr;
fr yf(fr &c){
	LL gd = gcd(c.a, c.b);
	c.a /= gd; c.b /= gd;
	return c;
}
fr operator + (fr a, fr b){
	fr c;c.a = a.a * b.b + b.a * a.b;c.b = a.b * b.b;c.id = a.id;
	yf(c);
	return c;
}
int vis[maxn], de[maxn];
vector<int>ed, g[maxn];
fr ans[maxn];

void print(LL a){
	if(a>9) print(a/10);
	putchar('0'+a%10);
}

signed main(){
//	freopen("water10.in","r",stdin);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ans[i] = frac(i, 0.0, 1.0);
		int t;cin>>t;
		if(t==0)ed.push_back(i);
		while(t--){
			int u;cin>>u;
			g[i].push_back(u);
			++ de[u];
		}
	}
	queue<int>Q;
	for(int i=1;i<=m;i++)Q.push(i), ans[i] = frac(i,1.0,1.0), vis[i] = 1;
//	printf("%.0Lf\n",gcd(6,12));
	while(!Q.empty()){
		int ff = Q.front();Q.pop();
//		printf("?? %d %d %d\n",ff,ans[ff].a,ans[ff].b);

		fr cur = ans[ff];
		if(g[ff].size()){
			LL tmp = gcd(g[ff].size(), cur.a);
			cur.a /= tmp;
			cur.b = cur.b * (g[ff].size() / tmp);
//			cur.b = cur.b * 1ll * g[ff].size();
			yf(cur);
		}
		for(int u : g[ff]){
			ans[u] = ans[u] + cur;
			yf(ans[u]); 
			if(--de[u] == 0)Q.push(u);
		}
	}
	for(int i : ed)
		print(ans[i].a), putchar(' '), print(ans[i].b), puts("");
//		cout << ans[i].a << " " << ans[i].b << '\n';
//	printf("%.0Lf %.0Lf %.0Lf\n",ans[i].a,ans[i].b,gcd(ans[i].a,ans[i].b));

	return 0;
}

