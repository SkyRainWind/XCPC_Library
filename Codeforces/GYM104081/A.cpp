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

int n,k,a[maxn];
signed main(){
	int mx=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),mx=max(mx,a[i]);
	for(int i=1;i<=n;){
		if(a[i] == mx){
			printf("%d\n",i);
			return 0;
		}
		int j=i+1;
		while(j<=n&&a[i] >= a[j])++ j;
		-- j;
		int win = j-(i+1)+1;
		int t = 0;
		if(i > 1)++t;
		if(win+t >= k){
			printf("%d\n",i);
			return 0;
		}
		i = j+1;
	}

	return 0;
}

