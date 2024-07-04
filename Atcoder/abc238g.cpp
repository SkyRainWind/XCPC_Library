// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5, maxm=1e6+5;

int n,q,a[maxn],blo;
struct que{int l,r,id;}qu[maxn];
int notpm[maxm], pm[maxm], pcnt=0, least[maxm];
int cubdiv[maxm], noncub=0, ans[maxn];
vector<pii>divs[maxn];

void xxs(){
	notpm[1] = 1;
	for(int i=2;i<=maxm-5;i++){
		if(!notpm[i]){
			pm[++pcnt]=i;
			least[i] = pcnt;
		}
		for(int j=1;j<=pcnt && i*pm[j]<=maxm-5;j++){
			notpm[i*pm[j]] = 1;
			least[i*pm[j]] = j;
			if(i%pm[j] == 0)break;
		}
	}
}

void add(int x){
	for(auto it : divs[x]){
		int bef = cubdiv[it.first] == 0;
		(cubdiv[it.first] += it.second) %= 3;
		int aft = cubdiv[it.first] == 0;
		if(bef+aft==1){
			if(bef == 1)-- noncub;
			else ++ noncub;
		}
	}
}

void del(int x){
	for(auto it : divs[x]){
		int bef = cubdiv[it.first] == 0;
		(cubdiv[it.first] -= it.second) %= 3;
		(cubdiv[it.first] += 3) %= 3;
		int aft = cubdiv[it.first] == 0;
		if(bef+aft==1){
			if(bef == 1)-- noncub;
			else ++ noncub;
		}
	}
}

signed main(){
	xxs();
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	blo = sqrt(1.0 * n);
	for(int i=1;i<=q;i++){
		int x,y;scanf("%d%d",&x,&y);
		qu[i] = {x,y,i};
	}
	sort(qu+1,qu+q+1,[&](que a,que b){
		if(a.l/blo == b.l/blo){
			if((a.l/blo)&1)return a.r<b.r;
			else return a.r>b.r;
		}else return a.l<b.l;
	});
	
	for(int i=1;i<=n;i++){
		int b = a[i];
		while(b != 1){
			int le = least[b], cnt = 0;
			while(least[b] == le){
				b /= pm[le];
				++ cnt;
			}
			divs[i].pb(mpr(le, cnt));
		}
	}
	
	int l=1,r=0;
	for(int i=1;i<=q;i++){
		int ql = qu[i].l, qr = qu[i].r;
		while(l<ql)del(l++);
		while(l>ql)add(--l);
		while(r<qr)add(++r);
		while(r>qr)del(r--);
		
		if(noncub==0)ans[qu[i].id] = 1;
	}
	for(int i=1;i<=q;i++)puts(ans[i] ? "Yes" : "No");

	return 0;
}

