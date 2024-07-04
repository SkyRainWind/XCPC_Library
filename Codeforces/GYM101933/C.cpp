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

const int inf = 1e9;

int dirt,a[1005];

signed main(){
	int n,res=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){int t;scanf("%d",&t);a[t]=1;}
	int cc=0,dd=0;
	for(int i=1;i<=365;i++){
		dirt += cc;
		if(a[i])++ cc;
		if(dirt + cc >= 20){
			dirt = 0;
			++ res;
			cc = 0;
		}
	}
	if(dirt || cc)++ res;
	printf("%d\n",res);

	return 0;
}


