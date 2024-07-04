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

int n,k;
int a[200055];
signed main(){
	scanf("%d%d",&n,&k);
	ll sum=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), sum+=a[i];
	if(sum < k)puts("0");
	else cout << sum - (k+1)/2 << '\n';

	return 0;
}

