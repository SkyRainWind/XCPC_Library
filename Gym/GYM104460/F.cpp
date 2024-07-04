// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,mod=1e9+7;

int f(int x){
	int r=1;
	while(x){r=1ll*r*(x%10)%mod;x/=10;}
	return r;
}

void solve(){
	int x,y,z;scanf("%d%d%d",&x,&y,&z);
	if(x+y < z){puts("-1");return ;}
	if(x+y==z){printf("%d\n",(x+y+1) <= 2000000000 ? (x+y+1) : -1);return ;}
	int tmp = x+y-z;
	printf("%d\n",(x<tmp&&z<tmp) ? tmp : -1);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

