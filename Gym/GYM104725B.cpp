// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int cnt=0;
pii lst;
ll go(int x,int y){
	printf("%d %d\n",x-lst.first,y-lst.second);
	assert(++cnt<=30);
	lst = mpr(x,y);
	fflush(stdout);
	ll ret;scanf("%lld",&ret);
	if(!ret)exit(0);
	return ret;
}

signed main(){
	lst=mpr(0,0);
	int l,r;ll tl,tr,t;
	scanf("%lld",&t);
	if(t==0)exit(0);
	ll t1 = go(-1000,0),t2 = go(1000,0);
	if(t1<t2)l=-1000,r=0,tl=t1,tr=t;else l=0,r=1000,tl=t,tr=t2;
	
	while(l < r-1){
		int mid=l+r+1>>1;
		ll tmp = go(mid,0);
		if(tl > tr)l=mid,tl=tmp;
		else r=mid,tr=tmp;
	}
	int x;
	ll tmp=min(tl,tr);
	if(tl < tr)x=l;else x=r;
//	int x=3;
	
	t1 = go(x,-1000), t2 = go(x,1000);
	if(t1<t2)l=-1000,r=0,tl=t1,tr=tmp;else l=0,r=1000,tl=tmp,tr=t2;
	while(l < r-1){
		int mid=l+r+1>>1;
		ll tmp = go(x,mid);
		if(tl > tr)l=mid,tl=tmp;
		else r=mid,tr=tmp;
	}
	if(tl<tr)go(x,l);else go(x,r);

	return 0;
}

