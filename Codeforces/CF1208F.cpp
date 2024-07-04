// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e6+5;

int n,a[maxn], ans,b[maxn];

void getans(int x){
	if(b[0] < 2)return ;
	int y = 0;
	for(int i=20;i>=0;i--){
		if(((x >> i) & 1) == 0){
			if(b[y ^ (1<<i)] >= 2){
				y ^= (1<<i);
			}
		}
	}
	ans = max(ans, x | y);
}

void add(int x,int k){
	if(b[x] >= 2)return;
	++ b[x];
	while(k <= 20){
		if(x & (1<<k)){
			add(x ^ (1<<k), k+1);
		}
		++ k;
	}
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=n;i>=1;i--){
		getans(a[i]);
		add(a[i], 0);
	}
	printf("%d\n",ans);

	return 0;
}

