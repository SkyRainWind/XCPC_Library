// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n,h[maxn],a[maxn];
struct segm{
	ll mxf;
	segm(){mxf=0;}
}se[maxn << 2];
ll dp[maxn];

void update(int x,ll to,int l,int r,int num){
	if(l == r){
		se[num].mxf = to;
		return ;
	}
	int mid=l+r>>1;
	if(x<=mid)update(x,to,l,mid,num<<1);
	else update(x,to,mid+1,r,num<<1|1);
	se[num].mxf = max(se[num << 1].mxf, se[num << 1 | 1].mxf);
}

ll query(int x,int y,int l,int r,int num){
	if(x <= l && r <= y)return se[num].mxf;
	int mid=l+r>>1;
	if(y<=mid)return query(x,y,l,mid,num<<1);
	else if(x>mid)return query(x,y,mid+1,r,num<<1|1);
	else return max(query(x,y,l,mid,num<<1), query(x,y,mid+1,r,num<<1|1));
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&h[i]);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	
	ll r=0;
	for(int i=1;i<=n;i++){
		ll qu = query(1, h[i], 1, n, 1);
		dp[i] = qu + a[i];
		r = max(r, dp[i]);
		update(h[i], dp[i], 1, n, 1);
	}
	cout << r;
	
	return 0;
}

