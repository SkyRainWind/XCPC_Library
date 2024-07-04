// by SkyRainWind
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

int n;
int a[(1<< 18) + 5];
int mx[(1<< 18) + 5][2];

void ck(int x,int y){
	int pp[] = {mx[x][0], mx[x][1], mx[y][0], mx[y][1]};
	sort(pp,pp+4);
	mx[x][0] = pp[3], mx[x][1] = pp[2];
}

signed main(){
	scanf("%d",&n);
	for(int i=0;i<=(1<<n) - 1;i++)scanf("%d",&a[i]), mx[i][0] = a[i], mx[i][1] = 0;
	for(int k = 0;k<=n-1;k++)
		for(int S = 0;S<=(1<<n)-1;S++)
			if((S & (1<<k)) == 0){
				ck(S ^ (1<<k), S);
			}
	int res = 0;
	for(int i=1;i<=(1<<n) - 1;i++){
		res = max(res, mx[i][0] + mx[i][1]);
		printf("%d\n",res);
	}

	return 0;
}


