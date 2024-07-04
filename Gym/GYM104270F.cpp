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

int n,m;
int b[1005][1005];

void solve(){
	scanf("%d%d",&n,&m);
	int lb = n&(-n);
	int qw = lb-1;
	if(m>qw){puts("Impossible");return ;}
	for(int i=0;i<=n-1;i++){
		for(int j=0;j<=qw;j++)
			b[i+1][j+1] = (i^j) + 1;
	}
	for(int j=2;j<=m+1;j++)
		for(int i=1;i<=n;i++)printf("%d%c",b[i][j]," \n"[i==n]);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

