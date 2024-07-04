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

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=1e6+5;

int n,k,a[maxn];

namespace s2{
	int qu[maxn],qu2[maxn];
	void solve(){
		int hd=1, tl=0;
		for(int i=1;i<=n;i++){
			while(hd <= tl && qu[tl] <= a[i])-- tl;
			qu[++ tl] = a[i];
			qu2[tl] = i;
			if(i < k)continue;
			while(hd <= tl && i - qu2[hd] >= k)++ hd;
			printf("%d ",qu[hd]);
		}
	}
};

namespace s1{
	int qu[maxn],qu2[maxn];
	void solve(){
		int hd=1, tl=0;
		for(int i=1;i<=n;i++){
			while(hd <= tl && qu[tl] >= a[i])-- tl;
			qu[++ tl] = a[i];
			qu2[tl] = i;
			if(i < k)continue;
			while(hd <= tl && i - qu2[hd] >= k)++ hd;
			printf("%d ",qu[hd]);
		}
	}
};

signed main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	s1::solve();puts("");
	s2::solve();

	return 0;
}


