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
const double eps = 1e-9;

ll ans,s1=0,s2=0;
int n,a[2003];
void sa(){
	double T = 2000;
	int m = n/2, rm = n-n/2, nm = m + n%2;
	s1=0,s2=0;
	for(int i=1;i<=m;i++)s1+=a[i];
	for(int i=m+1;i<=n;i++)s2+=a[i];
	while(T > 1e-9){
		int x = rand()%m + 1, y = m + 1 + rand()%nm;
		ll dis = abs(s1-a[x]*2+a[y]*2-s2);
		double delt = dis - ans;
		if(delt < 0){
			ans = dis;
			s1 = s1-a[x]+a[y];
			s2 = s2+a[x]-a[y];
			swap(a[x], a[y]);
		}else if(exp(delt / T) < rand()%32768){
			s1 = s1 - a[x]+a[y];
			s2 = s2 + a[x]-a[y];
			swap(a[x],a[y]);
		}
		T *= 0.998;
//		cerr << dis << ' ' << ans << ' ' << x << ' ' << y << '\n';
//		for(int i=1;i<=n;i++)cerr<<a[i]<<'\n';
	}
}

void solve(){
	ans = 1e18;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n==1)return (void)printf("%d\n",a[1]);
	int tt=20;while(tt--)sa();
	cout<<ans<<'\n';
}

signed main(){
	srand(time(0));
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

