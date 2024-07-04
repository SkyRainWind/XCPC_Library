// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5;

int n,a,b,c;
ll d[maxn];
ll dp[maxn][2][2][2];

void ck(ll &a,ll b){a = min(a, b);}

signed main(){
	memset(dp,0x3f,sizeof dp);
	ios::sync_with_stdio(false);
	cin>>n>>a>>b>>c;
	for(int i=1;i<=n;i++)cin>>d[i];
	dp[0][0][0][0] = 0;
	for(int i=1;i<=n;i++){
		for(int j1=0;j1<=1;j1++)for(int j2=0;j2<=1;j2++)for(int j3=0;j3<=1;j3++){
			ll bs = 1;
			if(j1)bs=bs*a/__gcd(bs,1ll*a);
			if(j2)bs=bs*b/__gcd(bs,1ll*b);
			if(j3)bs=bs*c/__gcd(bs,1ll*c);
			ll to = (d[i]-1) / bs * bs + bs;
			int t1=j1,t2=j2,t3=j3;
			if(to%a==0)t1=1;
			if(to%b==0)t2=1;
			if(to%c==0)t3=1;
			for(int k1=0;k1<=1;k1++)for(int k2=0;k2<=1;k2++)for(int k3=0;k3<=1;k3++)
				ck(dp[i][t1|k1][t2|k2][t3|k3], dp[i-1][k1][k2][k3] + to - d[i]);
		}
	}
	cout << dp[n][1][1][1] << '\n';

	return 0;
}

