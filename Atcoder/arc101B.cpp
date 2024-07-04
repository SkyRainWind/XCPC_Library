// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn =2e5+10, bs = 1e5+1;

int n,a[maxn],bit[maxn],sum[maxn];
int lb(int x){return x & (-x);}
int query(int x){
	int r = 0;
	for(int i = x;i;i-=lb(i))r += bit[i];
	return r;
}

void upd(int x){
	for(int i=x;i<=maxn - 5;i+=lb(i))++ bit[i];
}

int check(int k){
	LL r = 0;
	for(int i=0;i<=maxn - 5;i++)bit[i] = 0;
	for(int i=1;i<=n;i++)sum[i] = a[i] >= k ? -1 : 1;
	for(int i=2;i<=n;i++)sum[i] += sum[i-1];
	for(int i=1;i<=n;i++)r += sum[i] > 0 ? 1 : 0; 
	
	for(int i=1;i<=n;i++)
		r += query(sum[i] - 1 + bs), upd(sum[i] + bs);
	
	return r <= 1ll * n * (n+1) / 4;
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int l=1, r=1e9, ans;
	while(l <= r){
		int mid = l+r>>1;
		if(check(mid))l = mid+1, ans = mid;
		else r = mid-1;
	}
	printf("%d\n",ans);

	return 0;
}

