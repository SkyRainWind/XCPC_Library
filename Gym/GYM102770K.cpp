// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=23333;

int n,a[maxn],b[maxn];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++){
		if(b[i] > a[i]*3)return printf("%d\n",i),void();
	}
	puts("-1");
}

signed main(){
	int te;scanf("%d",&te);
	while(te--){
		solve();
	}

	return 0;
}

