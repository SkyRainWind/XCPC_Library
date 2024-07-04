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
	
	int p1=1;
	LL res=0;
	for(int i=1;i<=m;){
		int cnt = 0, c=0;
		while(p1 <= n && b[i] >= a[p1]){
			if(b[i] == a[p1])++ cnt;
			++ p1;
		}
		while(i<m && b[i] == b[i+1]){
			++ c;
			++ i;
		}
		++ i;
		res += 1ll*(c+1)*cnt;
	}
	printf("%I64d\n",res);

	return 0;
}


