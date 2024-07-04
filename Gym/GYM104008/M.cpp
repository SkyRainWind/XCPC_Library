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

int n,a[300005];

char s[600005];

int bit[600005];

int lb(int x){return x&(-x);}
void add(int x){
	for(int i=x;i<=n;i+=lb(i))bit[i]++; 
}
int query(int x){
	int res=0;
	for(int i=x;i;i-=lb(i))res+=bit[i];
	return res;
}

signed main(){
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%s",s+1);
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans += query(n-a[i]+1);
		add(n-a[i]+1);
	}
	printf("%lld\n",ans);
	int id = 1, forw = 1;
	for(int i=1;i<=m;i++){
		if(s[i] == 'R')ans = 1ll*n*(n-1)/2 - ans, forw = -forw, id+=forw;
		else{
			ans -= a[id]-1;
			ans += n-a[id];
			id += forw;
		}
		if(id < 1)id = n;
		if(id > n)id = 1;
		printf("%d",ans%10);
	}
	
	return 0;
}

