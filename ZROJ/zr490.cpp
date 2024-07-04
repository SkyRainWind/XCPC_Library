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

const int inf = 1e9, INF = 0x3f3f3f3f;
LL k,l,r;
int ck(LL p){
	int r = 0;
	while(p){r += (p%10)*(p%10);p /= 10;}
	return r;
}

int query(LL x){
	if(x == 0)return 0;
	int r = 0;
	for(int i=1;i<=1458;i++){
		LL tmp = 1ll*i*k;
		if(tmp > x)break;
		if(i == ck(tmp))++ r;
	}
	return r;
}

void solve(){
	scanf("%lld%lld%lld",&k,&l,&r);
	printf("%d\n",query(r) - query(l-1));
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}


