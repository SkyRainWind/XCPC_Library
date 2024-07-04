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

char s[100005];
signed main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	int fg = 1;
	for(int i=2;i<=n;i++)
		if(s[i] != s[i-1])fg = 0;
	if(fg)printf("%d\n",n-1);
	else puts("0");

	return 0;
}

