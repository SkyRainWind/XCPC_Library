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

mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}
int rnd(int l,int r){return rnd(r-l+1) + l;} 

ll a[15],ansp,ansq,ansr;

int ck(vector<ll>d[3]){
//	a|b b|c c|a
//	a&b b&c c&a
	ll p,q,r;
//	for(int i=0;i<3;i++,puts(""))
//		for(ll u : d[i])printf("%lld ",u);
//		puts("");
	p=q=r=0;
	for(int i=60;i>=0;i--){
		vector<int>conf(3,-1);
		for(int j=0;j<3;j++){
			if(((d[j][0] >> i)&1) == 0)conf[j] = conf[(j+1)%3] = 0;
			if(((d[j][1] >> i)&1) == 1)conf[j] = conf[(j+1)%3] = 1;
		}
		for(int j=0;j<3;j++)
			if(conf[j] == -1)conf[j] = conf[(j+1)%3] ^ 1;
		if(conf[0]==1)p |= 1ll<<i;
		if(conf[1]==1)q |= 1ll<<i;
		if(conf[2]==1)r |= 1ll<<i;
	}
	if((p|q)==d[0][0]&&(p&q)==d[0][1]&&(q|r)==d[1][0]&&(q&r)==d[1][1]&&(r|p)==d[2][0]&&(r&p)==d[2][1]){
		ansp=p,ansq=q,ansr=r;
		return 1;
	}
	return 0;
}

void solve(){
	map<ll,int>is;
	for(int i=1;i<=9;i++)scanf("%lld",&a[i]),is[a[i]]++;
	while(1){
		int a02,b01,b02;
		ll a2,b1=-1,b2=-1;
		a02=rnd(2,9);
		a2 = a[a02];
		do{b01=rnd(2,9);}while(b01 == a02);
		do{b02=rnd(2,9);}while(b02 == a02 || b02 == b01);
		b1=a[b01],b2=a[b02];
		
		map<ll,int>is2;
		is2 = is;
		-- is2[b1], -- is2[a[1]], -- is2[a2], -- is2[b2];
		if(-- is2[b1^b2] < 0){
			continue;
		}
		if(-- is2[a[1]^a2] < 0){
			continue;
		}
		vector<ll>c[3],d[3];
		c[0].pb(a[1]),c[0].pb(a2),c[0].pb(a[1]^a2);
		c[1].pb(b1),c[1].pb(b2),c[1].pb(b1^b2);
		for(auto &u : is2)while(u.second){
			c[2].pb(u.first);
			-- u.second;
		}
		
		for(int i=0;i<3;i++)sort(c[i].begin(),c[i].end(),greater<ll>());
		for(int i=0;i<=1;i++){
			d[0]=c[0];
			if(i==1)swap(d[0][1],d[0][2]);
			for(int j=0;j<=1;j++){
				d[1]=c[1];
				if(j==1)swap(d[1][1],d[1][2]);
				for(int k=0;k<=1;k++){
					d[2]=c[2];
					if(k==1)swap(d[2][1],d[2][2]);
					
					int t=ck(d);
					if(t==1){
						printf("%lld %lld %lld\n",ansp,ansq,ansr);
						return ;
					}
				}
			}
		}
	}
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

