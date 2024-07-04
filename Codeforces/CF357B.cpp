// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5005;

int n,m,a[maxn][maxn];
pii sum[maxn];	// <sum, id>
pii s[5002];

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		char s[5005];scanf("%s",s + 1);
		for(int j=1;j<=m;j++)a[i][j] = s[j] - '0';
	}
	int ans = 0;
	for(int j=1;j<=n;j++)
		if(a[j][m] == 1)sum[j] = mpr(1, j), ans = 1;
		else sum[j] = mpr(0, j);
	sort(sum+1,sum+n+1,[&](pii a,pii b){return a.first > b.first;});
	
	for(int i=m-1;i>=1;i--){
		int lst = n, fi = 0;
		for(int j=1;j<=n;j++){
			pii v = sum[j];
			if(a[v.second][i] == 0)s[lst --] = mpr(0, v.second);
			else s[++ fi] = mpr(v.first+1, v.second);
		}
		for(int i=1;i<=n;i++)
			ans = max(ans, s[i].first * i), 
			sum[i] = s[i];
	}
	printf("%d\n",ans);
	
	return 0;
}

