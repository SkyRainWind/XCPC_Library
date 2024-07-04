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

int n,a[maxn];
ll sum[maxn];
int s[maxn];

namespace ls {
	const int maxnum = 2e5 + 5;
	ll C[maxnum], L[maxnum], A[maxnum];
	//把 长度为n的a数组的内容离散化到 f 中
	void ls(int *f, ll *a, int n) {
		for (int i = 0; i < n; i++)A[i] = a[i + 1];
		memcpy(C, A, sizeof(A));
		sort(C, C + n);
		int l = unique(C, C + n) - C;
		for (int i = 0; i < n; ++i)
			L[i] = lower_bound(C, C + l, A[i]) - C + 1;
		for (int i = 0; i < n; i++)f[i + 1] = L[i];
	}
}

struct segm{
	int mx;
}se[maxn << 2];

void build(int x,int y,int num){
	se[num].mx = -1e9;
	if(x==y)return ;
	int mid=x+y>>1;build(x,mid,num<<1);build(mid+1,y,num<<1|1);
}

void upd(int x,int to,int l,int r,int num){
	if(l==r){
		se[num].mx = to;
		return ;
	}
	int mid=l+r>>1;
	if(x<=mid)upd(x,to,l,mid,num<<1);
	else upd(x,to,mid+1,r,num<<1|1);
	se[num].mx = max(se[num<<1].mx, se[num<<1|1].mx);
}

int query(int x,int y,int l,int r,int num){
	if(x<=l&&r<=y)return se[num].mx;
	int mid=l+r>>1;
	if(y<=mid)return query(x,y,l,mid,num<<1);
	else if(x>mid)return query(x,y,mid+1,r,num<<1|1);
	else return max(query(x,y,l,mid,num<<1), query(x,y,mid+1,r,num<<1|1));
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), sum[i] = sum[i-1] + a[i];
	ls::ls(s, sum, n);
	ll mn = 1e18;
	int idx = n+1;
	for(int i=1;i<=n;i++){
		if(sum[i]>=0 && sum[i]<mn){
			mn = sum[i];
			idx = s[i];
		}
	}
	
	build(1,n,1);
	
	int ans = 0, r = 0;
	if(a[1]>=0)upd(s[1],0,1,n,1), ans = 1;
	else upd(s[1],-1,1,n,1), r = -1;
	
	for(int i=2;i<=n;i++){
		int mdp = query(1, s[i], 1, n, 1);
		ans = max(ans, mdp + i);
		int nr = r-1;
		nr = max(nr, mdp);
		upd(s[i],nr,1,n,1);
		
		if(s[i] >= idx){
			ans = max(ans, i);
			upd(s[i], 0, 1, n, 1);
			nr = 0;
		}
		r = nr;
	}
	cout << ans << '\n';

	return 0;
}

