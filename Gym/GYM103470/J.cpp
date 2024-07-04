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

unordered_map<ll,int>mp;
vector<int>vc;

int dfs(int a,int b){
	if(a==1)return 0;
	if(b-a==1)return a-1;
	if(mp.count((ll)1e9*a+b))return mp[(ll)1e9*a+b];
	int res = a-1;
	for(auto it : vc)if((b-a)%it == 0){
		if(a>=it){
			int r1=dfs(a/it, b/it);
			res = min(res, a%it+1+r1);
		}
		
		int r2 = dfs(a/it+1,b/it+1);
		res = min(res, it-a%it+1+r2);
	}
	return mp[(ll)1e9*a+b] = res;
}

void solve(){
	int a,b;scanf("%d%d",&a,&b);
	if(a>b)swap(a,b);
	int delt = b-a;
	if(delt == 0)delt = a;
	int dd = delt;
	vc.clear();
	for(int i=2;i*i<=delt;i++){
		if(dd%i==0){
			while(dd%i==0)dd/=i;
			vc.pb(i);
		}
	}
	if(dd>1)vc.pb(dd);
	int res = dfs(a,b);
	printf("%d\n",res);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

