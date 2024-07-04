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

int solve(){
	int n;
	scanf("%d",&n);
	if(n&1^1)puts("No");
	else{
		puts("Yes");
		if(n==1)return puts("1 2"),0;
		int cnt = 1;
		for(int i=1;i<=n;i++){
			printf("%d %d\n",cnt,2*n-i+1);
			cnt += 2;
			if(cnt > n)cnt = 2;
		}
	}
	return 0;
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

