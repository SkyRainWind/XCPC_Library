// by SkyRainWind
#include <bits/stdc++.h>
#include <atcoder/all> 
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

signed main(){
	int n;
	scanf("%d",&n);
	vector<int>a(n),b(n),c(n),d(n<<1),e,f(n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++)scanf("%d",&b[i]);
	
	for(int k=0;k<5;k++){
		for(int i=0;i<n;i++)d[i+n] = d[i]=(b[i]>>k)&1^1,c[n-1-i]=(a[i]>>k)&1^1;
		e=atcoder::convolution(c,d);
		for(int i=0;i<n;i++)f[i]+=(n-e[i+n-1])<<k;
	}
	printf("%d\n",*max_element(f.begin(),f.end()));

	return 0;
}

