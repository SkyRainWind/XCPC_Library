// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 4000000,maxn=105;

int n;
char ed[maxn];
int v[maxn];
int dp[maxn][maxn],f[maxn][maxn];
set<int>dd[maxn][maxn];
set<int>ansl;

void ck(int &a,int b,int c){a=max(a,b+c);}
void ckmn(int &a,int b,int c){a=min(a,b+c);}
/*
6
t -1 t -3 t 4 t 1 x -4 x 4 
*/

signed main(){
//	freopen("Luogu4342.in","r",stdin);
//	freopen("Luogu4342-1.out","w",stdout);
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)scanf("%c %d",&ed[i],&v[i]),getchar();
	for(int i=1;i<=n;i++)ed[i+n] = ed[i], v[i+n] = v[i], dp[i][i]=dp[i+n][i+n]=f[i][i]=f[i+n][i+n]=v[i];
	ed[2*n+1]=ed[1]; 
	
	int ans=0;
	for(int p=100;p<=100;p++){
		for(int i=1;i<=2*n;i++)for(int j=i+1;j<=2*n;j++)dp[i][j]=-inf,f[i][j]=inf;
		for(int l=2;l<=n;l++)
			for(int i=1;i+l-1<=2*n;i++){
				int j=i+l-1;
				for(int k=i;k+1<=j;k++){
					if(ed[k+1] == 't'&&(k+1-1)%n+1!=p){
						if(dp[i][k]!=-inf&&dp[k+1][j]!=-inf)
							ck(dp[i][j],dp[i][k]+dp[k+1][j],0);
						if(f[i][k]!=inf&&f[k+1][j]!=inf)
							ckmn(f[i][j],f[i][k]+f[k+1][j],0);
					}
					else if(ed[k+1]=='x'&&(k+1-1)%n+1!=p){
						if(dp[i][k]!=-inf&&dp[k+1][j]!=-inf)
							ck(dp[i][j],dp[i][k]*dp[k+1][j],0);
						if(f[i][k]!=inf&&f[k+1][j]!=inf)
							ck(dp[i][j],f[i][k]*f[k+1][j],0);
//						if(f[i][k]!=inf&&dp[k+1][j]!=-inf)
//							ck(dp[i][j],f[i][k]*dp[k+1][j],0);
//						if(dp[i][k]!=-inf&&f[k+1][j]!=inf)
//							ck(dp[i][j],dp[i][k]*f[k+1][j],0);
							
						if(dp[i][k]!=-inf&&dp[k+1][j]!=-inf)
							ckmn(f[i][j],dp[i][k]*dp[k+1][j],0);
						if(f[i][k]!=inf&&f[k+1][j]!=inf)
							ckmn(f[i][j],f[i][k]*f[k+1][j],0);
						if(f[i][k]!=inf&&dp[k+1][j]!=-inf)
							ckmn(f[i][j],f[i][k]*dp[k+1][j],0);
						if(dp[i][k]!=-inf&&f[k+1][j]!=inf)
							ckmn(f[i][j],dp[i][k]*f[k+1][j],0);
					}
				}
			}
	}
	
	ans=-1e9;for(int i=1;i<=n;i++)ans=max(ans,dp[i][i+n-1]);
	printf("%d\n",ans);	
	for(int i=1;i<=n;i++)if(dp[i][i+n-1]==ans)printf("%d ",i);puts("");

	return 0;
}

