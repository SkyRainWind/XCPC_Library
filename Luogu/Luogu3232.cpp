// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn =505;

int n,m;
vector<int>g[maxn];
int deg[maxn];

struct gauss{
	const double eps = 1e-7;
	double ans[maxn];
	double a[maxn][maxn];
	// a[1][1]*x1+a[1][2]*x2+..+a[1][n]*xn=a[1][n+1]
	
	int main(){
		for(int i=1;i<=n;i++){
			int r=i;
			for(int j=i+1;j<=n;j++)if(fabs(a[r][i])<fabs(a[j][i]))r=j;
			if(fabs(a[r][i])<eps){
				return 0;
			}
			
			if(r!=i)swap(a[r],a[i]);
			double div=a[i][i];
			
			for(int j=i;j<=n+1;j++)a[i][j]/=div;
			for(int j=i+1;j<=n;j++){
				div=a[j][i];
				for(int k=i;k<=n+1;k++)a[j][k]-=a[i][k]*div;
			}
		}	
		
		ans[n]=a[n][n+1];
		for(int i=n-1;i>=1;i--){
			ans[i]=a[i][n+1];
			for(int j=i+1;j<=n;j++)ans[i]-=(a[i][j]*ans[j]);
		}
		return 1;
	}
};
pii ed[200005];
double tms[200005];

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y), g[y].push_back(x);
		++ deg[x], ++ deg[y];
		ed[i] = mpr(x, y);
	}
	
	gauss gs;
	gs.a[1][n+1] = 1.0;
	for(int i=1;i<=n-1;i++){
		gs.a[i][i] = 1.0;
		for(int j : g[i]){
			gs.a[i][j] = -1.0 / deg[j];
		}
	}
	gs.a[n][n] = 1.0;
	
	gs.main();
	
	for(int i=1;i<=m;i++){
		int u = ed[i].first, v = ed[i].second;
		tms[i] = gs.ans[u] / deg[u] + gs.ans[v] / deg[v];
	}
	sort(tms+1,tms+m+1);
	double res = 0.0;
	for(int i=1;i<=m;i++)
		res += tms[i] * (m-i+1);
	printf("%.3f\n",res);

	return 0;
}

