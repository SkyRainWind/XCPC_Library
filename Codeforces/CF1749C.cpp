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

void solve(){
	int n;scanf("%d",&n);
	int a[105];
	int bin[105],ain[105];memset(bin,0,sizeof bin);memset(ain,0,sizeof ain);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),++bin[a[i]],++ain[a[i]];
	for(int i=2;i<=100;i++)ain[i]+=ain[i-1];
	int bbin[105],aain[105];
	memcpy(bbin,bin,sizeof bbin);memcpy(aain,ain,sizeof aain);
	int qz = 0;
	for(int k=100;k>=1;k--){
		memcpy(bin,bbin,sizeof bin);memcpy(ain,aain,sizeof ain);
		int gg=0;qz=0;
		for(int i=k;i>=1;i--){
			if(ain[i] - qz <= 0){
				gg=1;break;
			}
			if(bin[i] == 0)
				for(int j=i;j>=1;j--)
					if(bin[j]){--bin[j];--ain[j];break;}
					else -- ain[j];
			++ qz;
		}
		if(!gg){printf("%d\n",k);return ;}
	}
	puts("0");
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}


