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

int n,m,a[505][505];

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)scanf("%1d",&a[i][j]);
	for(int i=1;i<=n-1;i++)a[i][1]=2;
	for(int i=1;i<=m;i++)a[1][i]=2;
	for(int i=1;i<=m;i++)a[n][i]=3;
	for(int i=2;i<=n;i++)a[i][m]=3;
	
	for(int i=2;i<=n-1;i+=2){
		if(i==n-1){
			for(int j=2;j<=m-1;j++)if(a[i][j]==0)a[i][j]=2;
		}else{
			for(int j=2;j<=m-1;j++)if(a[i][j]==0)a[i][j]=3;
			for(int j=2;j<=m-1;j++)if(a[i+1][j]==0)a[i+1][j]=2;
		}
	}
	for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=m;j++)printf("%d",(a[i][j]==1||a[i][j]==2));
	for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=m;j++)printf("%d",(a[i][j]==1||a[i][j]==3));

	return 0;
}

