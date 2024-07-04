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

int n,a[5005];
vector<int>to[5005];
int cnt[5005][5005],sum[5005];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)to[i].clear();
	for(int i=1;i<=n;i++){
		to[i].pb(i);
		for(int j=i;j<=n;j++)
			if(a[j]<a[i])to[i].pb(j);
	}
	for(int i=1;i<=n;i++){
		cnt[i][i] = 0;
		for(int j=i-1;j>=1;j--){
			cnt[j][i] = cnt[j+1][i];
			if(a[j]<a[i])cnt[j][i]++;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)sum[j]=0;
		int cur=0;
		for(int j=i;j<=n;j++){
			if(j-i-cnt[i][j]<to[j].size())sum[to[j][j-i - cnt[i][j]]]++;
			if(j-i-cnt[i][j]+1<to[j].size())sum[to[j][j-i-cnt[i][j]+1]]--;
			cur += sum[j];
			if(cur == 0)++ ans;
		}
	}
	printf("%d\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

