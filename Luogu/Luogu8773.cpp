// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = (1<<20) + 5;

int n,q,x;
int a[maxn];
int lst[maxn], st[maxn][22];

int query(int l,int r){
	int len = (int)(log(1.0 *(r-l+1)) / log(2.0));
	return max(st[l][len], st[r-(1<<len)+1][len]);
}

signed main(){
	scanf("%d%d%d",&n,&q,&x);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int tar = a[i] ^ x;
		st[i][0] = lst[tar];
		lst[a[i]] = i;
	}
	
	for(int j=1;j<=20;j++)
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[i][j] = max(st[i][j-1], st[i+(1<<j-1)][j-1]);
		}
	while(q --){
		int l,r;scanf("%d%d",&l,&r);
		int qu = query(l, r);
		puts(qu >= l ? "yes" : "no");
	}

	return 0;
}

