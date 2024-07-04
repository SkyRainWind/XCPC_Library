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
int a[11][11],sum[66][66];

void ck(){
	int c0=0,c1=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=i;k<=n;k++)
				for(int l=j;l<=m;l++){
					int t=sum[k][l] - sum[i-1][l] - sum[k][j-1] + sum[i-1][j-1];
					if(t==(k-i+1)*(l-j+1) || t==0)++c0;
					else ++c1;
				}
	if(c0==c1){
		for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=m;j++)printf("%d ",a[i][j]);
		printf(":: %d %d\n",c0,c1);
		puts("-------------");
	}
}

void dfs(int x,int y){
	if(x==n+1){ck();return ;}
	a[x][y]=0;
	if(y==m)dfs(x+1,1);else dfs(x,y+1);
	a[x][y]=1;
	if(y==m)dfs(x+1,1);else dfs(x,y+1);
}

signed main(){
//	freopen("104160F.txt","w",stdout);
	scanf("%d%d",&n,&m);
	dfs(1,1);

	return 0;
}

