// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int g(int x){
	if(x==0||x==4||x==6||x==9)return 1;
	if(x==8)return 2;
	return 0;
}

int f(int x){
	if(x == 0)return 1;
	int ans=0;
	while(x){ans+=g(x%10);x/=10;}
	return ans;
}

void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	while(m){
		n=f(n);
		--m;
		if(n == 0)break;
	}
	if(n == 0){
		puts(m%2 ? "1" : "0");
	}else printf("%d\n",n);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

