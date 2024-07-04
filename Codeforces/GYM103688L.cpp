// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e6+5, p = 131;

char s[maxn], t[maxn];
ull hs1[maxn];
ull hs2[maxn];
ull pp[maxn];
ull ht;
int n,l1,l2;

ull get1(int l,int r){
	return hs1[r] - hs1[l-1] * pp[r-l+1];
}
ull get2(int l,int r){
	return hs2[r] - hs2[l-1] * pp[r-l+1];
}

void solve(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	n = strlen(s+1);
	ht = 0;
	for(int i=1;i<=n;i++)ht = ht*p+t[i]-'a';
	scanf("%d%d",&l1,&l2);
	if(l1 > l2)swap(l1, l2);
	pp[0] = 1;
	for(int i=1;i<=n;i++){
		hs1[i] = hs1[i-1]*p+s[i] - 'a';
		hs2[i] = hs2[i-1]*p+s[n-i+1]-'a';
		pp[i] = pp[i-1]*p;
	}
	for(int i=1;i<=n;i++){
		hs1[i+n] = hs1[i+n-1]*p+s[i] - 'a';
		hs2[i+n] = hs2[i+n-1]*p+s[n-i+1]-'a';
		pp[i+n] = pp[i+n-1]*p;
	}
//	cout << get1(2,1+n) << ' ' << get1(n+1,2*n) << '\n';
	vector<int>vis(2*n+2, 0);
	int gd = l2 - l1, fg = 0;
	for(int i=1+n;;){
		if(vis[i])break;
		vis[i] = 1;
		if(get1(i, i+n-1) == ht){
			fg = 1;
			break;
		}
		i -= gd;if(i <= 0)i += n;
	}
	vis.assign(2*n+2, 0);
	for(int i=n-l1+1;;){
		if(vis[i])break;
		vis[i] = 1;
		if(get2(i,i+n-1) == ht){
			fg = 1;
//			printf("? %d %d\n",i,i+n-1);
			break;
		}
		i += gd;if(i+n-1 > 2*n)i -= n;
	}
	if(fg)return (void)puts("yes");
	puts("no");
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

