// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9,maxn=1e5+5,maxm=1e8+5;

int n,d;
struct node{int w,l,h;}a[maxn];
int cmp(node a,node b){return a.w>b.w;}
int f[maxm];

signed main(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].l,&a[i].w,&a[i].h);
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++){
		int ww = a[i].w, ll = a[i].l, hh = a[i].h;
		if(f[ww] + ll > d)++ ans;
		for(int i=1;i<=ww-1 && i+ww<=maxm-5;i++)f[i] = max(f[i], f[i+ww] + hh);
	}
	printf("%d\n",ans);

	return 0;
}


