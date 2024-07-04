// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;
typedef long double db;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5e5+5;

int n,m;
struct se{
	int l,r;
};
ll la, lb;
int sa[maxn], sb[maxn];
db ans=0;
vector<int>v,ls; 

void solve(int n,int m){
	db suma=0,prea=0;
	for(int i=0;i+1<ls.size();i++){
		ll delt = ls[i+1] - ls[i];
		db pa, pb;
		if(sa[i]==0)pa = 0;else pa = (la==0?1.0 / n:1.0 * delt / la);
		if(sb[i]==0)pb = 0;else pb = (lb==0?1.0 / m:1.0 * delt / lb);
		ans += 1.0 / 6 * pa * pb * delt;
		ans += pb*suma;
		ans += pb*delt/2*prea;
		suma += delt*prea+delt*pa/2;
		prea += pa;
	}
}

signed main(){
	scanf("%d%d",&n,&m);
	vector<se>a(n+2), b(m+2);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].l,&a[i].r),v.pb(a[i].l),v.pb(a[i].r),la+=a[i].r-a[i].l;
	for(int i=1;i<=m;i++)scanf("%d%d",&b[i].l,&b[i].r),v.pb(b[i].l),v.pb(b[i].r),lb+=b[i].r-b[i].l;
	
	sort(v.begin(), v.end());
	for(int i=0;i<v.size();i++){
		while(ls.size() >= 2 && ls[ls.size() - 2] == v[i])ls.pop_back();
		ls.pb(v[i]);
	}
	for(int i=1;i<=n;i++)
		a[i].l = lower_bound(ls.begin(), ls.end(), a[i].l) - ls.begin(),
		a[i].r = lower_bound(ls.begin(), ls.end(), a[i].r+1) - ls.begin() - 1;
	for(int i=1;i<=m;i++)
		b[i].l = lower_bound(ls.begin(), ls.end(), b[i].l) - ls.begin(),
		b[i].r = lower_bound(ls.begin(), ls.end(), b[i].r+1) - ls.begin() - 1;
	
	for(int i=1;i<=n;i++)sa[a[i].l] += 1, sa[a[i].r] -= 1;
	for(int i=1;i<=m;i++)sb[b[i].l] += 1, sb[b[i].r] -= 1;
	for(int i=1;i<ls.size();i++)sa[i]+=sa[i-1];
	for(int i=1;i<ls.size();i++)sb[i]+=sb[i-1];
	
	solve(n,m);
	swap(la, lb);swap(sa, sb);
	solve(m,n);
	printf("%.10Lf\n",ans);

	return 0;
}

