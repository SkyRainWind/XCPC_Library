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

const int inf = 1e9, INF = 0x3f3f3f3f;
int a[100005],b[100005];
signed main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	
	int p1=1,p2=1;
	for(int i=1;i<=n+m;i++){
		if(p1 == n+1)printf("%d ",b[p2++]);
		else if(p2 == m+1)printf("%d ",a[p1++]);
		else{
			if(a[p1] <= b[p2])printf("%d ",a[p1++]);
			else printf("%d ",b[p2++]);
		}
	}
	

	return 0;
}


