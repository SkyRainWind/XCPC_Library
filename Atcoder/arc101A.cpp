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

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5;
int n,k,a[maxn],sum[maxn];
signed main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), sum[i] = sum[i-1] + abs(a[i]);	
	int st;for(int i=1;i<=n;i++)if(a[i] >= 0){st = i;break;}
	int ans =1e9;
	for(int i=1;i+k-1 <= n;i++){
		int nxt = i+k-1;
		if(a[i] <= 0){
			if(a[nxt] <= 0)ans = min(ans, abs(a[i]));
			else ans = min(ans, min(2 * (-a[i]) + a[nxt], 2*a[nxt] - a[i]));
		}else{
			ans = min(ans, a[nxt]);
		}
	}
	printf("%d\n",ans);

	return 0;
}


