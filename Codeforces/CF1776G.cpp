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

int n;
char s[2000005];
int cf[2000005];
int pre[2000005];

signed main(){
	scanf("%d",&n);
	scanf("%s",s+1);
//	int cc = 0, fg = 0;
	for(int i=1;i<=2*n-1;i++)
		pre[i] = pre[i-1] + (s[i] == 'W');
	int ans = 0;
	for(int i=n;i>=1;i--)
		ans = max(ans, pre[i+n-1] - pre[i-1]);
	printf("%d\n",ans);

	return 0;
}

