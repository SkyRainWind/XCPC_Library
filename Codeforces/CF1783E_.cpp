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
int n,a[maxn],b[maxn],cf[maxn];
set<int>ban;
void cutdiv(int x){
	for(int i=1;i*i<=x;i++)
		if(x%i == 0)
			ban.insert(i), ban.insert(x/i);
}
void solve(){
	ban.clear();
	scanf("%d",&n);
	for(int i=0;i<=n+1;i++)cf[i] = 0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	
	for(int i=1;i<=n;i++)
		if(a[i] > b[i])
			++ cf[b[i]], -- cf[a[i]];
	
	for(int i=2;i<=n;i++)
		cf[i] += cf[i-1];
	vector<int>vi;
	for(int k=1;k<=n;k++){
		int gg = 0;
		for(int i=k;i<=n;i+=k)
			if(cf[i]){gg = 1;break;}
		if(!gg)vi.push_back(k);
	}
	printf("%d\n",vi.size());
	for(int u : vi)printf("%d ",u);puts("");
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve(); 

	return 0;
}

