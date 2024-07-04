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

const int inf = 1e9, INF = 0x3f3f3f3f;

int n,m;
int buc[222];

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int t;scanf("%d",&t);
		int cc = 0;
		while(t){
			t >>= 1;
			++ cc;
		}
		buc[cc-1] ++;
	}
	while(m--){
		int cur;scanf("%d",&cur);
		int res = 0, cnt=0;
		for(int i=30;i>=0;i--){
			if(cur&(1<<i))++ res;
			if(res > buc[i]){
				cnt += buc[i];
				res -= buc[i];
			}else{
				cnt += res;
				res = 0;
			}
			res <<= 1; 
		}
		if(res)puts("-1");
		else printf("%d\n",cnt);
	}

	return 0;
}

