// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e6+5;

int n,pa,pb;
char s[maxn];

void solve(){
	scanf("%d",&n);
	scanf("%s",s);
	scanf("%d%d",&pa,&pb);
	for(int i=1,x,y;i<=pb;i++)scanf("%d%d",&x,&y);
	int delt = (pb - (pa-1)) % n;
	if(s[delt] == '1')puts("2");
	else puts("1");
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

