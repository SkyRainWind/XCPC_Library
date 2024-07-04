// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e4+5;

int n,k;
int x[maxn], y[maxn];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 mrand(random_device{}()); 
int rnd(int x) { return uniform_int_distribution<int>(1, x)(rng);}

pii slope;

pii go(pii slope){	
	if(slope.first == 0){
		slope.second = 1;
		return slope;
	}
	if(slope.second == 0){
		slope.first = 1;
		return slope;
	}
//	printf("%d %d\n",slope.first,slope.second);
	if(slope.first < 0)slope.first*=-1, slope.second*=-1;
	int gd = __gcd(abs(slope.first), abs(slope.second));
	slope.first /= gd; slope.second /= gd;
	return slope;
}

int bel[maxn];
vector<int>S[maxn];
vector<int>s;

void goo(int i1,int i2){
	s.clear();
	
	slope = mpr(x[i1] - x[i2], y[i1] - y[i2]);
	slope = go(slope);
	
	s.pb(i1);
	bel[i1] = bel[i2] = s.size();
	int gg = 1, f = 1;
	for(int i=1;i<=n;i++)if(i!=i1&&i!=i2){
		gg = -1;
		for(auto it : s){
			pii now = mpr(x[i] - x[it], y[i] - y[it]);
			now = go(now);
			if(now == slope){gg=bel[it];break;}
		}
		if(gg==-1)s.pb(i), bel[i] = s.size();
		else bel[i] = gg;
		if(s.size() > k){f = 0;break;}
	}
	if(f){
		if(s.size()!=k)return ;
		for(int i=1;i<=s.size();i++)S[i].clear();
		for(int i=1;i<=n;i++)S[bel[i]].pb(i);
		int gg = 0;
		for(int i=1;i<=s.size();i++)if(S[i].size() < 2)gg=1;
		if(gg)return ;
		for(int i=1;i<=s.size();i++){
			printf("%d ",S[i].size());
			sort(S[i].begin(),S[i].end());
			for(auto it : S[i])printf("%d ",it);
			puts("");
		}
		exit(0); 
	}
}

signed main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
	int cs = 1000000;
	if(n <= 500){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)if(i!=j)goo(i,j);
//		assert(0);
	}
	while(cs --){
		s.clear();
		int i1 = rnd(n), i2 = rnd(n);
		while(i1 == i2)i2 = rnd(n);
		
		slope = mpr(x[i1] - x[i2], y[i1] - y[i2]);
		slope = go(slope);
		
		s.pb(i1);
		bel[i1] = bel[i2] = s.size();
		int gg = 1, f = 1;
		for(int i=1;i<=n;i++)if(i!=i1&&i!=i2){
			gg = -1;
			for(auto it : s){
				pii now = mpr(x[i] - x[it], y[i] - y[it]);
				now = go(now);
				if(now == slope){gg=bel[it];break;}
			}
			if(gg==-1)s.pb(i), bel[i] = s.size();
			else bel[i] = gg;
			if(s.size() > k){f = 0;break;}
		}
		if(f){
			if(s.size()!=k)continue;
			for(int i=1;i<=s.size();i++)S[i].clear();
			for(int i=1;i<=n;i++)S[bel[i]].pb(i);
			int gg = 0;
			for(int i=1;i<=s.size();i++)if(S[i].size() < 2)gg=1;
			if(gg)continue;
			for(int i=1;i<=s.size();i++){
				printf("%d ",S[i].size());
				sort(S[i].begin(),S[i].end());
				for(auto it : S[i])printf("%d ",it);
				puts("");
			}
			return 0;
		}
	}

	return 0;
}


