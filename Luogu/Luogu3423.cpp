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

int n,b[maxn],c[maxn],lim;
int dp[maxn],g[maxn];

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]); 
	for(int i=1;i<=n;i++)scanf("%d",&c[i]); 
	scanf("%d",&lim);
	
	for(int i=1;i<=n;i++){
		memset(g,0,sizeof g);
		for(int j=0;j<b[i];j++){
			deque<int>dq;
			for(int k=j;k<=lim;k+=b[i]){
				// g[k] <- g[k-t*b[i]]+t 
				while(!dq.empty() && )
			}
		}
	}

	return 0;
}

