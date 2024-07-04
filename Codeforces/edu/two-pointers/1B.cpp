// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=1e5+5;

int n,m;
int a[maxn],b[maxn];

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	
	a[0] = -1e9-1;
	int p1 = 0;
	for(int i=1;i<=m;i++){
		if(p1 == n+1){printf("%d ",n);continue;}
		while(p1 <= n && a[p1]<b[i])p1++;
		printf("%d ",p1-1);
	}

	return 0;
}


