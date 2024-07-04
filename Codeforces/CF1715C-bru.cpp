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

int n,m;
int a[20005];
void ck(){
		int res=0;
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++){
				for(int k=i+1;k<=j;k++){
					if(a[k] != a[k-1])++ res;
				}
				++ res;
			}
		printf("%d\n",res); 
} 
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); 
	}
	ck();
	while(m--){
		int p,x;scanf("%d%d",&p,&x);
		a[p]=x;
		int res=0;
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++){
				for(int k=i+1;k<=j;k++){
					if(a[k] != a[k-1])++ res;
				}
				++ res;
			}
		printf("%d\n",res);
	}

	return 0;
}


