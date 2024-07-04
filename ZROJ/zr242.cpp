// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int n,m;
char s[3005][3005];
char ss[100005][15];
int a[3005];

signed main(){
	scanf("%d%d",&n,&m);
	if(n <= 3000)for(int i=1;i<=n;i++)scanf("%s", s[i] +1);
	if(n > 3000)for(int i=1;i<=n;i++)scanf("%s", ss[i] +1);
	int ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)if(n <= 3000 ? s[i][j] == '0' : ss[i][j] == '0')++ a[j];else a[j] = 0;
		vector<int>vi;
		for(int j=1;j<=m;j++)vi.push_back(a[j]);
		sort(vi.begin(), vi.end());
		for(int j=0;j<vi.size();j++){
			ans = max(ans, ((int)vi.size() - j) * vi[j]);
		}
	}
	printf("%d\n",ans);

	return 0;
}


