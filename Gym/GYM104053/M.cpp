// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod=1e9+7;

ll n,m,k;
ll C[2005][2005];
int N[222],M[222];
int f[65][202][22];

signed main(){
	C[0][0] = 1;
	for(int i=1;i<=2000;i++){
		C[i][0] = 1;
		for(int j=1;j<=i;j++)C[i][j] = (C[i-1][j-1]+C[i-1][j])%mod;
	}
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=60;i++){
		if(n&1)N[i] = 1;
		if(m&1)M[i] = 1;
		n >>= 1, m >>= 1;
	}
	
	f[60][0][k] = 1;
	for(int i=60;i>=1;i--){
		for(int j=0;j<=200;j++){
			for(int u=0;u<=k;u++){
				for(int l=0;l<=k;l++){
					int num = ((j-l*(k-l))*2)+N[i-1];
					if(num>200||num<0)continue;
					if(!M[i])
						(f[i-1][num][u] += f[i][j][u]*1ll*C[k-u][l]%mod) %= mod;
					else
						for(int v=0;v<=l;v++)
							(f[i-1][num][v] += 1ll*f[i][j][u]*C[u][v]%mod*C[k-u][l-v]%mod) %= mod;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=k;i++)(ans += f[0][0][i]) %= mod;
	cout<<ans<<'\n';

	return 0;
}

