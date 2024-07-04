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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5 + 5;

char s[maxn];

void solve(){
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	
	int ok = s[1] == '1';for(int i=2;i<=n;i++)ok &= ((s[i] == '0') || (s[i] == '1' && i == n));
	if(ok){
		for(int i=1;i<=n-2;i++)printf("9");
		puts("");
		return ;
	}
	
	int st = 0, finst;
	pair<int,int> res;
	for(int i=1;i<=n;i++){
		for(int j = (i == 1 ? 1 : 0); j <= s[i] - '0' - 1; j++){
			int curst = st ^ (1 << j);
			int pc = __builtin_popcount(curst);
			if(pc > n-i || (n-i-pc)%2 == 1)continue;
			res = mpr(i, j);	// 1~i-1 normal i=j i+1~n ..
			finst = curst;
		}
		st ^= (1 << (s[i] - '0'));
	}
	for(int i=1;i<=res.first-1;i++)printf("%c",s[i]);
	printf("%d",res.second);
	int lim = n - res.first - __builtin_popcount(finst);
	for(int i=1;i<=lim;i++)putchar('9');
	for(int i=9;i>=0;i--)
		if(finst & (1<<i))printf("%d",i);
	puts("");
	// n - res.first - __builtin_popcount(finst)
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

