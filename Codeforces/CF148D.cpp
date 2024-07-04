// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

double f[1005][1005];
int w,b;

double frac(int x,int y){return 1.0 * x / y;}

double dfs(int x,int y){
	if(x < 0 || y < 0)return 0.0;
	if(x == 0)return 0.0;
	if(y == 0)return 1.0;
	if(x+y == 2)return 0.5;
	int i=x,j=y;
	if(f[i][j])return f[i][j];
	return f[i][j] = frac(i,i+j) + frac(j,i+j) * (frac(j-1,i+j-1)*(frac(j-2,i+j-2)*dfs(i,j-3)+frac(i,i+j-2)*dfs(i-1,j-2)));
}

signed main(){
	scanf("%d%d",&w,&b);
	double res = dfs(w, b);
	printf("%.10f\n",res);

	return 0;
}

