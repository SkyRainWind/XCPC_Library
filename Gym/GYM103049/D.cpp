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

void pr(int x,int y){
	printf("%d %d\n",x,y);
	fflush(stdout);
}

int in(ll x,ll y){
	if(x >=0&&y>=0&&x<=(ll)1e6&&y<=(ll)1e6)return 1;
	return 0;
}

int sx=5e5, sy=5e5;
signed main(){
	int n;scanf("%d",&n);
	vector<int>S = {-1, 1};
	vector<pii>T = {mpr(0,1),mpr(0,-1),mpr(1,0),mpr(-1,0)};
	while(n --){
			pr(0,0);
			ll t0,t1;scanf("%lld",&t0);
			if(t0==0)continue;
			vector<pii>re;re.clear();
			for(int i=0;i<=(int)1e6&&1ll*i*i<=t0;i++){
				ll oth = t0 - 1ll*i*i;
				ll sqo = (ll)sqrt(1.0 * oth);
				while(sqo*sqo < oth)++sqo;
				while(sqo*sqo > oth)--sqo;
				if(sqo*sqo==oth&&sqo*sqo+1ll*i*i==t0&&sqo<=(int)1e6){
					re.pb(mpr(i,sqo));
				}
			}
			if(re.size() <= 60){
				for(auto it : re){
					pr(it.first,it.second);
					ll qw;scanf("%lld",&qw);
					if(qw == 0)goto nxt;
				}
			}
			pr(0,1);
			scanf("%lld",&t1);
			if(t1==0)continue;
			pr(2,0);
			ll t2;
			scanf("%lld",&t2); 
			pr(1,0);
			ll t3,t4;scanf("%lld",&t3);
			pr(0,2);
			scanf("%lld",&t4);
			
			for(auto it : re){
				if(1ll*it.first*it.first + 1ll*(it.second-1)*(it.second-1) == t1 && 
				1ll*it.first*it.first + 1ll*(it.second-2)*(it.second-2) == t4){
					pr(it.first,it.second);
					ll qw;scanf("%lld",&qw);
					if(qw == 0)goto nxt;
				}
			}
			
			for(auto it : re){
				if(1ll*(it.first-1)*(it.first-1) + 1ll*(it.second)*(it.second) == t3 && 
				1ll*(it.first-2)*(it.first-2) + 1ll*(it.second)*(it.second) == t2){
					pr(it.first,it.second);
					ll qw;scanf("%lld",&qw);
					if(qw == 0)goto nxt;
				}
			}
		nxt:;
		}

	return 0;
}

