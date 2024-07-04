// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 3e6+5;

int afls[maxn];
vector<int>ns;
namespace ls {
	const int maxnum = 3e6 + 5;
	int C[maxnum], L[maxnum], A[maxnum];
	//把 长度为n的a数组的内容离散化到 f 中
	void ls(int *f, int *a, int n) {
		for (int i = 0; i < n; i++)A[i] = a[i + 1];
		memcpy(C, A, sizeof(A));
		sort(C, C + n);
		int l = unique(C, C + n) - C;
		for (int i = 0; i < n; ++i)
			L[i] = lower_bound(C, C + l, A[i]) - C + 1;
		for (int i = 0; i < n; i++)f[i + 1] = L[i];
	}
	
	void ls(){
		int n = ns.size();
		for (int i = 0; i < n; i++)A[i] = ns[i];
		memcpy(C, A, sizeof(A));
		sort(C, C + n);
		int l = unique(C, C + n) - C;
		for (int i = 0; i < n; ++i)
			L[i] = lower_bound(C, C + l, A[i]) - C + 1;
		for (int i = 0; i < n; i++)afls[i + 1] = L[i];
	}
}

struct fen{
	int a[maxn];
	int N = -1;
	void init(int up){
		N = up;
		for(int i=0;i<=N;i++)a[i] = 0;
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
}fw;

int a[maxn], n,q;
const int maxm = 3e6+5;
struct node{int l,r,h,ans;}qu[maxm];
struct newnode{int to,h,ans,id;}part[maxm*2];
vector<int>vc[maxn];

int cmp(newnode a,newnode b){return a.to < b.to;}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ns.pb(a[i]);
	}
	ls::ls();
	
	for(int i=1;i<=n;i++)a[i] = afls[i];
	 
	for(int k=1;k<=n-1;k++){
		for(int i=1;;i++){
			int L=k*(i-1)+2, R=k*i+1;
			if(L>n)break;
			R = min(R, n);
			
			++q;
			qu[q]=node{L,R,a[i]-1,0};
			vc[k].push_back(q);
		}
	}
	fw.init(q+q);
//	if(n>5){cout<<q<<'\n';return ;}
	
	for(int i=1;i<=q;i++){
		part[i*2-1] = newnode{qu[i].l-1, qu[i].h, 0, -i};
		part[i*2] = newnode{qu[i].r, qu[i].h, 0, i};
	}
	
	sort(part+1,part+2*q+1,cmp);
	
	int curs = 1;
	for(int i=1;i<=n;i++){
		fw.add(a[i], 1);
		while(part[curs].to == 0)++curs;
		while(curs <= 2*q && part[curs].to == i){
			part[curs].ans += fw.query(part[curs].h);
			++ curs;
		}
	}
	
	for(int i=1;i<=2*q;i++){
		int now = part[i].id, f = 1;
		if(now < 0)now = -now, f = -f;
		
		qu[now].ans += f * part[i].ans;
	}
	for(int i=1;i<=n-1;i++){
		ll ans=0;
		for(auto it : vc[i]){
			ans += qu[it].ans;
		}
		printf("%d ",ans);
	}
	puts("");
}

signed main(){
	solve();

	return 0;
}

