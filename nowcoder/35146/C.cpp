// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;

const int inf = 1e9, INF = 0x3f3f3f3f;

unordered_map<ull,int>rem;
int n,q,a[5005][5005];

ull to(int x,int y){
	return x+y*998244353ull;
}

int pre(int n,int q){
//	printf("%d %d\n",n,q);
	if(q == 0)return 0;
	if(n == 1)return 1;
	if(a[n][q])return a[n][q];
	
	int mid = (n+1)/2, qmid = (q+1)/2;
	return a[n][q] = 1 + pre(mid, qmid) + pre(n - mid, q - qmid);
}

int solve(int n,int q){
	if(q == 0)return 0;
	if(n == 1)return 1;
	if(n<=5000 && q<=5000)return a[n][q];
	if(rem.count(to(n,q)))return rem[to(n,q)];
	
	int mid = (n+1)/2, qmid = (q+1)/2;
	return rem[to(n,q)] = 1 + solve(mid, qmid) + solve(n - mid, q - qmid);
}

int qread(){
    int w=1,c,ret;
    while((c = getchar()) >  '9' || c <  '0') w = (c == '-' ? -1 : 1); ret = c - '0';
    while((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + c - '0';
    return ret * w;
}

void solve(){
	rem.clear();
	n=qread(),q=qread();
	if(q >= n)printf("%d\n",solve(n, n));
	else printf("%d\n",solve(n,q));
}

signed main(){
	for(int i=1;i<=5000;i++)
		for(int j=1;j<=5000;j++)
			a[i][j] = pre(i, j);
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

