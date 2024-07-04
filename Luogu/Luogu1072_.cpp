// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int a0,a1,b0,b1;
void solve(){
	int ans=0;
	scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
	for(int i=1;i*i<=b1;i++){
		if(b1%i==0){
			if(i%a1==0&&gcd(b1/b0,b1/i) == 1 && gcd(a0/a1,i/a1) == 1)++ans;
			int x = b1/i;
			if(x==i)continue;
			if(b1%x==0&&x%a1==0&&gcd(b1/b0,b1/x)==1&&gcd(a0/a1,x/a1)==1)++ans;
		}
	}
	cout<<ans<<'\n';
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

