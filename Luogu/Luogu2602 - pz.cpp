// by Balloons
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;
int rr[11];
signed main(){
	int l,r;scanf("%d%d",&l,&r);
	for(int i=l;i<=r;i++){
		int t = i;
		while(t){if(t%10==1)printf("i=%d\n",i);rr[t%10]++; t/=10;}
	}
	for(int i=0;i<=9;i++)printf("%d ",rr[i]);;puts("");

	return 0;
}


