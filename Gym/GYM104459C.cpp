// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e6+5;

int n,k;
char s[maxn];

void move(pair<ll,ll> &a,char t){
	if(t=='U')a.second++;
	else if(t=='D')a.second--;
	else if(t=='R')a.first++;
	else a.first--;
}

void solve(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	pair<ll,ll> now = mpr(0,0);
	ll ans=0;
	for(int i=1;i<=n;i++)move(now,s[i]), ans=max(ans,abs(now.first)+abs(now.second));
	pair<ll,ll>fin = mpr(now.first*1ll*(k-1),now.second*1ll*(k-1));
	now = mpr(0,0);
//	printf("?? %lld %lld\n",fin.first,fin.second);
	ans = max(ans,abs(fin.first) + abs(fin.second));
	for(int i=1;i<=n;i++){
		move(fin,s[i]);
		ans = max(ans, abs(fin.first) + abs(fin.second));
	}
	printf("%lld\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

