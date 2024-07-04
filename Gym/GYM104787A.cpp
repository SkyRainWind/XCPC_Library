// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

vector<pii>vc;
int n,k;

int isok(int x,int y){
	if(x==y || y==x+1)return 0;
	if((x==n&&y==1))return 0;
	return 1;
}

signed main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		vc.pb(mpr(i,i));
		if(i!=n)vc.pb(mpr(i,i+1));
	}
	vc.pb(mpr(n,1));
	int tmp = vc.size();
	int x=1,y=1;
	for(int i=tmp+1;i<=k;i++){
		while(!isok(x, y)){
			y++;
			if(y==n+1)x++, y=1;
		}
		vc.pb(mpr(x, y));
		y++;
		if(y==n+1)x++, y=1;
	}
	for(auto it : vc)printf("%d %d\n",it.first,it.second);

	return 0;
}

