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

int vis[1000005];

signed main(){
	int n,k;
	scanf("%d%d",&n,&k);
	vector<int>p;
	for(int i=1;i<=n;i++)if(!vis[i]){
		vis[i] = 1;
		for(int j=i;j<=n;j+=k)p.pb(j), vis[j]=1;
	}
	for(int i=0;i<p.size();i++)printf("%d%c",p[i]," \n"[i==p.size()-1]);

	return 0;
}

