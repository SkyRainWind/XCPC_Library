// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=1e6+5;
int n;
int xx[maxn],yy[maxn];
int para(int x1,int y1,int x2,int y2){
	return 1ll*x1*y2==1ll*x2*y1;
}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}

void solve(){
	int fg=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		xx[i]=x2-x1,yy[i]=y2-y1;
		if(i >= 2 && fg)fg &= para(xx[i-1],yy[i-1],xx[i],yy[i]);
	}
	if(n==1||fg)return (void)puts("0");
	if(n==2)return (void)puts("1");
	set<pii>S;
	for(int i=1;i<=n;i++){
		int gd=gcd(xx[i],yy[i]);
		xx[i] /= gd, yy[i] /= gd;
		if(xx[i] < 0)xx[i]*=-1,yy[i]*=-1;
		S.insert(mpr(xx[i], yy[i]));
		if(S.size() >= 3)return (void)puts("3");
	}
	puts("2");
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

