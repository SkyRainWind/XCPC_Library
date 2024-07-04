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

int bin_gcd(int a,int b){
    int az = __builtin_ctz(a);
    int bz = __builtin_ctz(b);
    int z = min(az, bz);
    b >>= bz;
    while (a) {
        a >>= az;
        int diff = a - b;
        az = __builtin_ctz(diff);
        b = min(a, b), a = abs(diff);
    }
    return b << z;
}

const int maxn=5005,mod=998244353;
int n,a[maxn],b[maxn],ans[maxn];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	
	for(int i=1;i<=n;i++){
		int cs = i, r=0;
		for(int j=1;j<=n;j++){
			(r += 1ll*cs*bin_gcd(a[i], b[j])%mod);
			if(r >= mod)r -= mod;
			cs = 1ll*cs*i%mod;
		}
		printf("%d\n",r);
	}

	return 0;
}

