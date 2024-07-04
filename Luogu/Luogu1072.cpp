// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5;

int notpm[maxn],pm[maxn],pcnt=0;

map<int,int>divs[7];
void decomp(int tmp,int id){
	for(int i=1;i<=pcnt;i++){
		if(tmp < pm[i])break;
		if(tmp%pm[i] == 0){
			int cnt = 0;
			while(tmp%pm[i] == 0)tmp /= pm[i], ++cnt;
			divs[id][pm[i]] = cnt;
		}
	}
	if(tmp != 1)divs[id][tmp] = 1;
}

int a0,a1,b0,b1;
void solve(){
	for(int i=1;i<=6;i++)divs[i].clear();
	scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
	
	int tmp = a1;
	decomp(a1, 1);
	decomp(b0, 2);
	decomp(a0, 3);
	decomp(b1, 4);
	
	for(auto it : divs[1]){
		if(divs[3].count(it.first))divs[5][it.first] = it.second;
		else divs[5][it.first] = 0;
	}
	
	// least gcd most lcm
	map<int,int>least, most;
	least = divs[5];	// least[i] = j 原数必须是 i^j，否则随便选 
	
	for(auto it : divs[4]){
		if(!divs[2].count(it.first))divs[6][it.first] = -it.second;
		else{
			if(divs[2][it.first] < divs[4][it.first])divs[6][it.first] = -it.second;
			else divs[6][it.first] = it.second;
		}
	}
	most = divs[6];
	
	int ggg=0;
	for(auto it : least)if(it.second)++ggg;
	int ans = 1, gg=0;
	for(auto it : most){
		if(it.second<0){
			int now = -it.second;
			if(least.count(it.first) && least[it.first] != now){
				ans = 0;
				break;
			}else{
				if(least[it.first] != 0)gg++;
				continue;
			}
		}
		if(least.count(it.first)){
			++gg;
			if(least[it.first] > most[it.first]);
			else{ans=0;break;}
		}else ans *= 1ll*(it.second+1);
	}
	if(ans && gg==ggg)
		cout<<ans<<'\n';
	else puts("0");
}

signed main(){
	notpm[1] = 1;
	for(int i=1;i<=100000;i++){
		if(!notpm[i]){
			pm[++pcnt]=i;
		}
		for(int j=1;j<=pcnt&&i*pm[j]<=100000;j++){
			notpm[i*pm[j]]=1;
			if(i%pm[j]==0)break;
		}
	}

	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

