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

int n,m,k;

int lf(pii x,pii y){
	if(x.first==y.first&&x.second==y.second-1)return 1;
	return 0;
}
int ri(pii x,pii y){
	if(x.first==y.first&&x.second==y.second+1)return 1;
	return 0;
}
int up(pii x,pii y){
	if(x.first==y.first-1&&x.second==y.second)return 1;
	return 0;
}
int dn(pii x,pii y){
	if(x.first==y.first+1&&x.second==y.second)return 1;
	return 0;
}

int gethash(vector<pii>v){
	int a[7][7];
	memset(a,0,sizeof a);
	for(pii u : v)a[u.first][u.second]=1;
	int hs = 0, mod = 998244353;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)hs = (hs*38ll+a[i][j])%mod;
	return hs;
}

void solve(){
	scanf("%d%d%d",&n,&m,&k);
	vector<pii>v;
	for(int i=1;i<=k;i++){
		int x,y;scanf("%d%d",&x,&y);
		v.pb(mpr(x,y));
	}
	queue<vector<pii>>Q;
	set<int>S;
	int ans = 1e9;
	Q.push(v);
	while(!Q.empty()){
		vector<pii> u = Q.front();Q.pop();
		ans = min(ans, (int)u.size());
		for(int i=0;i<u.size();i++)
			for(int j=0;j<u.size();j++)if(i!=j){
//				if(i==4&&j==1)printf("?? %d %d\n",lf(u[i],u[j])); 
				if(lf(u[i],u[j])){
					int f=0;
					for(int k=0;k<u.size();k++)if(u[k].first==u[i].first && u[k].second==u[j].second+1)f=1;
					if(!f&&u[i].second+2<=m){
						vector<pii>v;
						v.pb(mpr(u[i].first,u[i].second+2));
						for(int k=0;k<u.size();k++)if(i!=k&&j!=k){
							v.pb(u[k]);
						}
						if(v.size() >= ans)continue;
						int hs=gethash(v);
						if(!S.count(hs))S.insert(hs), Q.push(v);
					}
				}
				if(ri(u[i],u[j])){
					int f=0;
					for(int k=0;k<u.size();k++)if(u[k].first==u[i].first && u[k].second==u[j].second-1)f=1;
					if(!f&&u[i].second-2>=1){
						vector<pii>v;
						v.pb(mpr(u[i].first,u[i].second-2));
						for(int k=0;k<u.size();k++)if(i!=k&&j!=k){
							v.pb(u[k]);
						}
						if(v.size() >= ans)continue;
						int hs=gethash(v);
						if(!S.count(hs))S.insert(hs), Q.push(v);
					}
				}
				if(up(u[i],u[j])){
					int f=0;
					for(int k=0;k<u.size();k++)if(u[k].first==u[j].first+1 && u[k].second==u[j].second)f=1;
					if(!f&&u[i].first+2<=n){
						vector<pii>v;
						v.pb(mpr(u[i].first+2,u[i].second));
						for(int k=0;k<u.size();k++)if(i!=k&&j!=k){
							v.pb(u[k]);
						}
						if(v.size() >= ans)continue;
						int hs=gethash(v);
						if(!S.count(hs))S.insert(hs), Q.push(v);
					}
				}
				if(dn(u[i],u[j])){
					int f=0;
					for(int k=0;k<u.size();k++)if(u[k].first==u[j].first-1 && u[k].second==u[j].second)f=1;
					if(!f&&u[i].first-2>=1){
						vector<pii>v;
						v.pb(mpr(u[i].first-2,u[i].second));
						for(int k=0;k<u.size();k++)if(i!=k&&j!=k){
							v.pb(u[k]);
						}
						if(v.size() >= ans)continue;
						int hs=gethash(v);
						if(!S.count(hs))S.insert(hs), Q.push(v);
					}
				}
			}
	}
	printf("%d\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

