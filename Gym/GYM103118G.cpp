// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

signed main(){
	int n,k,x,t=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		t+=x;
	}
	printf("%d.",t/n);
	int qw = t%n*10;
	while(k--){
		printf("%d",qw/n);
		qw=qw%n*10;
	}
	puts("");

	return 0;
}

