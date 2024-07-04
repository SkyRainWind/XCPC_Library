// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9,maxn=705,mod=1e9+7;

char s[maxn];
int dp[maxn][maxn][3][3];
int ok[maxn][maxn],n,mtc[maxn];

void add(int &a,int b){(a+=b)%=mod;}

signed main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		int curs = 0;
		for(int j=i;j<=n;j++){
			if(s[j] == '(')++ curs;
			else -- curs;
			if(curs == 0)ok[i][j] = 1;
			if(curs < 0)break;
		}
	}
	memset(mtc,-1,sizeof mtc);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(ok[i][j] == 1){mtc[i] = j;break;}
		}
	}
	
	memset(dp,0,sizeof dp);
	for(int i=1;i+1<=n;i++)dp[i][i+1][0][1] = dp[i][i+1][0][2] = dp[i][i+1][1][0] = dp[i][i+1][2][0] = ok[i][i+1];
	for(int l=4;l<=n;l+=2){
		for(int i=1;i+l-1<=n;i++){
			int j=i+l-1;
			if(!ok[i][j])continue;
				
			if(ok[i+1][j-1]){
				add(dp[i][j][0][1],dp[i+1][j-1][0][0]);
				add(dp[i][j][0][1],dp[i+1][j-1][0][2]);
				add(dp[i][j][0][1],dp[i+1][j-1][1][0]);
				add(dp[i][j][0][1],dp[i+1][j-1][1][2]);
				add(dp[i][j][0][1],dp[i+1][j-1][2][0]);
				add(dp[i][j][0][1],dp[i+1][j-1][2][2]);
				
				add(dp[i][j][0][2],dp[i+1][j-1][0][0]);
				add(dp[i][j][0][2],dp[i+1][j-1][0][1]);
				add(dp[i][j][0][2],dp[i+1][j-1][1][0]);
				add(dp[i][j][0][2],dp[i+1][j-1][1][1]);
				add(dp[i][j][0][2],dp[i+1][j-1][2][0]);
				add(dp[i][j][0][2],dp[i+1][j-1][2][1]);
				
				add(dp[i][j][1][0],dp[i+1][j-1][0][0]);
				add(dp[i][j][1][0],dp[i+1][j-1][2][0]);
				add(dp[i][j][1][0],dp[i+1][j-1][0][1]);
				add(dp[i][j][1][0],dp[i+1][j-1][2][1]);
				add(dp[i][j][1][0],dp[i+1][j-1][0][2]);
				add(dp[i][j][1][0],dp[i+1][j-1][2][2]);
				
				add(dp[i][j][2][0],dp[i+1][j-1][0][0]);
				add(dp[i][j][2][0],dp[i+1][j-1][1][0]);
				add(dp[i][j][2][0],dp[i+1][j-1][0][1]);
				add(dp[i][j][2][0],dp[i+1][j-1][1][1]);
				add(dp[i][j][2][0],dp[i+1][j-1][0][2]);
				add(dp[i][j][2][0],dp[i+1][j-1][1][2]);
			}
			
			if(mtc[i]==-1 || mtc[i]+1 >= j)continue;
			for(int p=0;p<=2;p++)for(int q=0;q<=2;q++)
				for(int pq=0;pq<=2;pq++)for(int ps=0;ps<=2;ps++){
					if(pq!=0&&pq==ps)continue;
					add(dp[i][j][p][q],1ll*dp[i][mtc[i]][p][pq]*dp[mtc[i]+1][j][ps][q]%mod);
				}
		}
	}
	int ans=0;
	for(int i=0;i<=2;i++)for(int j=0;j<=2;j++)add(ans,dp[1][n][i][j]);
	printf("%d\n",ans);

	return 0;
}


