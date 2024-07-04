// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2005;

int n,k;
int a[maxn][maxn];
pii line[maxn], col[maxn];
int sumx[maxn][maxn],sumy[maxn][maxn];
int vx[maxn][maxn],vy[maxn][maxn], bx[maxn], by[maxn];

signed main(){
	int ans = 0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		char s[2005];
		scanf("%s",s +1);
		for(int j=1;j<=n;j++){
			if(s[j] == 'B')a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			sumx[i][j] = sumx[i][j-1] + a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			sumy[i][j] = sumy[i-1][j] + a[i][j];
	for(int i=1;i<=n;i++)bx[i] = sumx[i][n] == 0, by[i] = sumy[n][i] == 0;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(j+k-1<=n)vx[i][j] = (sumx[i][j+k-1] - sumx[i][j-1] == sumx[i][n]) - bx[i];
			if(i+k-1<=n)vy[i][j] = (sumy[i+k-1][j] - sumy[i-1][j] == sumy[n][j]) - by[j];
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			vx[i][j] += vx[i-1][j],
			vy[i][j] += vy[i][j-1];
	ans = 0;
	for(int i=1;i<=n-k+1;i++){
		for(int j=1;j<=n-k+1;j++){
			ans = max(ans, vx[i+k-1][j] - vx[i-1][j] + vy[i][j+k-1] - vy[i][j-1]);
		}
	}
	for(int i=1;i<=n;i++)ans += bx[i] + by[i];
	cout<<ans;
	
	return 0;
}

