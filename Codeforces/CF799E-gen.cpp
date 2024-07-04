// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <iostream>
#include <ctime>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

signed main(){
	freopen("CF799E.in","w",stdout);
	int a[2203];
	srand(time(0));
	int n = 1000, m=rand()%n+1, k = rand()%m+1;
	printf("%d %d %d\n",n,m,k);
	for(int i=1;i<=n;i++)printf("%d ",rand()%20 + 1);puts("");
	int t = rand()%n+1;
	for(int i=1;i<=n;i++)a[i]=i;
	printf("%d\n",t);
	random_shuffle(a+1,a+n+1);
	for(int i=1;i<=t;i++)printf("%d ",a[i]);puts("");
	t = rand()%n+1;
	random_shuffle(a+1,a+n+1);
	printf("%d\n",t);
	for(int i=1;i<=t;i++)printf("%d ",a[i]);puts("");

	return 0;
}

