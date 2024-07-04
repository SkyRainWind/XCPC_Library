// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define int ll
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int n,a,b,c;
int sub;
ll ave;
ll rmin;

void ck(int to,int x,pii &y){
	int k=n-x-to;
	if(k < 0)to += k;
	if(to < 0)to = 0;
	if(to<0||x+to>n)return ;
	ll lft =3ll*(a-c)*x+3ll*(b-c)*to+3ll*c*n-ave;
	lft = abs(lft);
	if(lft < rmin)y = mpr(x,to), rmin=lft;
}

void go(int x){
	printf("%lld\n",x);
	fflush(stdout);
	int a,b;
	scanf("%lld%lld",&a,&b);
	if(a+b==-2)exit(0);
}

void solve(){
	scanf("%lld",&n);
	scanf("%lld%lld%lld",&a,&b,&c);
	a*=3,b*=3,c*=3;
	ave = 1ll*n * (a+b+c);
	rmin = 1e18;
	pii move;
	if(a==b&&b==c){move=mpr(n,0);goto nxt;}
	if(b==c)swap(a,c);
	move=mpr(n,0);
	rmin = abs(3ll*(a-c)*n+3ll*c*n-ave);
	for(int x=0;x<=n;x++){
		sub = ave/3-c*n-(a-c)*x;
		int to = sub/(b-c);
		ck(to,x,move),ck(to-1,x,move),ck(to+1,x,move);
	}
	nxt:;
	int x=move.first,y=move.second;
	for(int i=1;i<=x;i++)go(a/3);
	for(int i=1;i<=y;i++)go(b/3);
	for(int i=1;i<=n-x-y;i++)go(c/3);
}

signed main(){
	int te;scanf("%lld",&te);
	while(te--)solve();

	return 0;
}

