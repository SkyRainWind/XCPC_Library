// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e6+5;

int notpm[maxn], pm[maxn], pcnt = 0, curv[maxn], lea[maxn];

void xxs(){
	notpm[1] = 1;
	for(int i=2;i<=maxn-5;i++){
		if(!notpm[i])pm[++pcnt]=i, curv[i] = pcnt, lea[i] = pcnt;
		for(int j=1;j<=pcnt&&1ll*pm[j]*i<=maxn-5;j++){
			notpm[i*pm[j]] = 1;
			lea[i*pm[j]] = j;
			if(i%pm[j] == 0)break;
		}
	}
}

int n,a[maxn], lst[maxn], rightmost[80005], cs;
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
void solve(){
	int ans = -1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int gd = a[1];
	for(int i=2;i<=n;i++)gd=gcd(gd, a[i]);
	memset(rightmost, 0x3f, sizeof rightmost);
	lst[n+1] = n + 1;
	for(int i=n;i>=1;i--){
		lst[i] = lst[i+1];
		int tmp = a[i];
		vector<int>curpm;
		while(tmp != 1){
			curpm.push_back(lea[tmp]);
			int cc = pm[lea[tmp]];
			while(tmp%cc == 0)tmp /= cc;
		}
		for(int u : curpm){
			lst[i] = min(lst[i], rightmost[u]);
			rightmost[u] = i;
		}
		ans = max(ans, lst[i] - i + 1 - 1); 
	}
	printf("Case %d: %d ",++cs,gd == 1 ? n : -1);
	if(ans == 1)puts("-1");
	else printf("%d\n",ans);
}

signed main(){
	xxs();
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

