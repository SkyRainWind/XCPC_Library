// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=25005;

int n,a[maxn],f[maxn];

void solve(){
	memset(f,0,sizeof f);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	f[0] = 1;
	int ans = n;
	for(int i=1;i<=n;i++){
		if(f[a[i]])-- ans;
		for(int j=1;j<=25000;j++)
			if(j >= a[i]){
				f[j] |= f[j-a[i]];
			}
	}

	printf("%d\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

