// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+ 5;

int n;
char a[maxn] ,b[maxn];
int c[maxn];

void solve(){
	scanf("%d",&n);
	scanf("%s", a+1);
	scanf("%s", b+1);
	int fg = 0, tmp =0;
	for(int i=1;i<=n;i++){
		if(i<n && a[i] == '1' && a[i+1] == '1')fg = 1;
		if(a[i] == '1')c[i] = 1 - (b[i] - '0'), ++ tmp;
		else c[i] = b[i] - '0';
	}
	int is0=1, is1 = 1;
	for(int i=1;i<=n;i++)
		is1 &= c[i] == 1,
		is0 &= c[i] == 0;
	if(!is0 && !is1){
		puts("NO");
		return ;
	}
	if(!fg){
		if(is1 && (tmp%2==0)){
			puts("NO");
			return ;
		}
		if(is0 && (tmp&1)){
			puts("NO");
			return ;
		}
	}
	puts("YES");
	if((is1 && (tmp%2) == 0) || (is0 && (tmp&1))){
		vector<pii>res;
		int tpp = 0;
		for(int i=1;i<=n;i++){
			if(i<n && a[i] == '1' && a[i+1] == '1' && !tpp){
				res.push_back(mpr(i, i+1));
				++i;
				tpp = 1;
				continue;
			}
			if(a[i] == '1')res.push_back(mpr(i,i));
		}
		printf("%d\n",res.size());
		for(pii u : res)printf("%d %d\n",u.first, u.second);
		return ;
	}
	vector<pii>res;
	for(int i=1;i<=n;i++){
		if(a[i] == '1')res.push_back(mpr(i,i));
	}
	printf("%d\n",res.size());
	for(pii u : res)printf("%d %d\n",u.first, u.second);
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

