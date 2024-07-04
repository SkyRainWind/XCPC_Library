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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+ 5;

int a[maxn];
int n,m,l[maxn], r[maxn];

signed main(){
	int ans = 0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char s[3];scanf("%s", s + 1);
			if(s[1] == 'F'){
				++ a[j];
			}else a[j] = 0;
		}
		for(int j=1;j<=m;j++)l[j] = r[j] = j;
		for(int j=1;j<=m;j++){
			while(a[j] && l[j] > 1 && a[j] <= a[l[j] - 1])l[j] = l[l[j] - 1];
			while(a[j] && r[j] < m && a[j] <= a[r[j] + 1])r[j] = r[r[j] + 1];
		}
		
		for(int j=1;j<=m;j++){
			int tmp = r[j] - l[j] + 1;
			tmp *= a[j];
			if(tmp > ans)ans = tmp;
		}
	}
	printf("%d\n",ans *3);

	return 0;
}


