// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

void solve(){
	ll x, y;
	cin >> x >> y;
	if(x == y){cout<<x<<'\n';return ;}
	int pre = 0, gg = 0;
	for(int i=63;i>=0;i--){
		if(x & (1ll << i)){
			if((y & (1ll << i)) == 0)pre = pre?pre:i;
			else if(pre){gg = 1;break;}
		}else{
			if(y & (1ll << i))return (void)puts("-1");
		}
	}
	if(gg){puts("-1");return ;}
	if((x & (1ll << pre)) && (x & (1ll << (pre+1)))){puts("-1");return ;}
	
	ll ans = 0;
	for(int i=pre+1;i<=63;i++)
		if(x & (1ll << i))ans += 1ll << i;
	ans += 1ll << (pre + 1);
	cout<<ans<<'\n';
}

int n,k;
int p[maxn],vis[maxn];
void solve2(){
	int cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		while(k--)scanf("%d",&p[++cnt]),vis[p[cnt]]++;
		p[++cnt]=-1;
	}
	int fg=0, ok=0;
	for(int i=1;i<=cnt;i++)
		if(p[i]==-1){
			if(!fg){ok=1;break;}
			fg=0;
		}else if(vis[p[i]]<2)fg=1;
	for(int i=1;i<=cnt;i++)if(p[i]!=-1)vis[p[i]]=0;
	puts(ok ? "Yes" : "No");
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve2();

	return 0;
}

