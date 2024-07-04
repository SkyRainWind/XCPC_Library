// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e5+5;

int n,x[maxn],y[maxn],cx[maxn];
vector<int>tmp0,tmp1;
pii operator * (int a,pii b){return mpr(b.first*a,b.second*a);}
pii operator + (pii a,pii b){return mpr(a.first+b.first,a.second+b.second);}

int ck(pii c,int ty){
	LL len = 1ll*c.first*c.first + 1ll*c.second*c.second;
	if(ty == 0)return len <= (LL)1e12;
	return len <= 2250000000000ll;
}

pair<pii,pii> upd(pii t1, pii t2, pii t3,int id){
	// 1,1,1, -1,1,1, -1,1,-1, 1,1,-1
	vector<int>bs;bs.push_back(1);bs.push_back(-1);
//	vector<pii>bs;
//	bs.push_back(mpr(1,1));bs.push_back(mpr(1,-1));bs.push_back(mpr(-1,-1));bs.push_back(mpr(-1,1));
	for(int u : bs){
		if(ck(t2+u*t3,0)){
			tmp1.push_back(id);
			if(u == -1)cx[id] = -cx[id];
			
			return mpr(t1, t2+u*t3);
		}
	}
	for(int u : bs){
		if(ck(t1+u*t3,0)){
			tmp0.push_back(id);
			if(u == -1)cx[id] = -cx[id];
			
			return mpr(t1+u*t3, t2);
		}
	}
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]), cx[i] = 1;
	if(n == 1)return puts("1"), 0;
	if(n == 2){
		if(ck(mpr(x[1],y[1]) + mpr(x[2],y[2]),1))puts("1 1");
		else puts("1 -1");
		return 0;
	}
	pii cur;
	
	pii lst0 = mpr(x[1],y[1]), lst1 = mpr(x[2],y[2]);
	tmp0.push_back(1);tmp1.push_back(2);
	for(int i=3;i<=n;i++){
		if(tmp0.size() > tmp1.size())swap(tmp0, tmp1), swap(lst0, lst1);
		pair<pii,pii>now = upd(lst0,lst1,mpr(x[i],y[i]),i);	// set lst1 = 1
		lst0 = now.first, lst1 = now.second;
	}
	if(ck(lst0 + (-1) * lst1, 1))
		for(int u : tmp1)cx[u] = -1;
	for(int i=1;i<=n;i++)printf("%d ",cx[i]);

	return 0;
}

