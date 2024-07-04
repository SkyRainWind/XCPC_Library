// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=1e6+5;

int h,n,m;
struct node{int x,y,t;}a[maxn];

void solve(){
	scanf("%d",&h);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y),a[i].t=0;
	scanf("%d",&m);
	for(int i=n+1;i<=n+m;i++)scanf("%d%d",&a[i].x,&a[i].y),a[i].t=1;
	sort(a+1,a+n+m+1,[&](node a,node b){
		return a.x == b.x ? a.y > b.y : a.x > b.x;
	});
	map<int,int>mp;
	for(int i=1;i<=n+m;i++){
		int x=a[i].x,y=a[i].y;
		int i2=(2*h+(x-y)%(2*h))%(2*h),i1=(x+y)%(2*h);
		if(a[i].t == 1)mp[i1]++, mp[i2]++;
		else{
			int tmx = max(mp[i1], mp[i2]);
			mp[i1] = mp[i2] = tmx;
		}
	}
	printf("%d\n",mp[0]);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

