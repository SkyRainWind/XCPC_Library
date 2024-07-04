// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

signed main(){
	int a[]={0,1,2,3,4,5,6,7,8,9,10};
	int b[22];
	while(1){
		random_shuffle(a+1,a+11);
		int k = 3;
		int n=10;
		for(int i=1;i<=n;i++){
			int cur = a[i];
			if(cur > k){
				int tmp = 0;
				for(int j=i-1;j>=1;j--){
					if(a[j] <= k){
						tmp = a[j];
						break;
					}
				}
				b[cur] = tmp;
			}else{
				int tmp = n+1;
				for(int j=i-1;j>=1;j--){
					if(a[j] > k){
						tmp = a[j];
						break;
					}
				}
				b[cur] = tmp;
			}
		}
		for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
		for(int i=1;i<=n;i++)printf("%d ",b[i]);puts("");
		getchar();
		getchar();
	}

	return 0;
}

