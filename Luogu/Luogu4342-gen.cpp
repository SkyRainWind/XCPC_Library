// by Balloons
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9;

signed main(){
	freopen("Luogu4342.in","w",stdout);
	srand(time(0));
	int n=6;printf("%d\n",n);
	for(int i=1;i<=n;i++){
		int te=rand()%2;if(te==0)printf("t ");else printf("x ");
		int tp=rand()%5+1;if(rand()%2)tp *= -1;printf("%d ",tp);
	}
	puts("");

	return 0;
}


