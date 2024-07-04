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

struct node{int h,d,x;}sz[maxn];
int b1[maxn],b2[maxn],n;

int bit[maxn];
int lb(int x){return x&(-x);}
void upd(int x,int v){
	for(int i=x;i<=n;i+=lb(i))bit[i]=min(bit[i],v);
}
int query(int x){
	int re=2e9;
	for(int i=x;i;i-=lb(i))re=min(re,bit[i]);
	return re;
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)bit[i]=2e9;
	for(int i=1;i<=n;i++){
		vector<int>a(3);
		for(int j=0;j<3;j++)scanf("%d",&a[j]);
		sort(a.begin(),a.end());
		sz[i].h=a[0];
		sz[i].d=a[1];
		sz[i].x=a[2];
		b1[i]=a[1],b2[i]=a[2];
	}
	sort(b1+1,b1+n+1);sort(b2+1,b2+n+1);
	int n1=unique(b1+1,b1+n+1) - (b1+1);
	int n2=unique(b2+1,b2+n+1) - (b2+1);
	for(int i=1;i<=n;i++)
		sz[i].d = lower_bound(b1+1,b1+n1+1,sz[i].d) - b1;
	for(int i=1;i<=n;i++)
		sz[i].x = lower_bound(b2+1,b2+n2+1,sz[i].x) - b2;
	
	sort(sz+1,sz+n+1,[&](node a,node b){return a.h==b.h?a.d<b.d:a.h<b.h;});
	
	int lst=1;
	for(int i=1;i<=n;i++){
		while(lst<i && sz[lst].h<sz[i].h){
			upd(sz[lst].d,sz[lst].x);
			++lst;
		}
		if(sz[i].d>1&&query(sz[i].d-1)<sz[i].x)
			return puts("Yes"),0;
	}
	puts("No");

	return 0;
}

