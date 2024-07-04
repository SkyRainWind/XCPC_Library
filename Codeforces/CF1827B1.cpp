// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int ok[5005][5005],n;

void solve(){
	scanf("%d",&n);
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ok[i][i] = 1;
	}
	for(int l=2;l<=n;l++)
		for(int i=1;i+l-1<=n;i++){
			int j = i+l-1;
			ok[i][j] = ok[i][j-1] & (a[j-1] < a[j]);
			printf("%d %d %d\n",i,j,ok[i][j]);
		}
	int ans = 0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ans += (1-ok[i][j]) * (j-i);
	printf("%d\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}
