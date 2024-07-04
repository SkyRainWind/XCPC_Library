// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e6+5;

int n,p3[15],a[maxn];
signed main(){
	scanf("%d",&n);
	p3[0] = 1;
	for(int i=1;i<=n;i++)p3[i] = 3*p3[i-1];
	for(int i=0;i<p3[n];i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<p3[n];j++)if((j/p3[i])%3 == 0){
			int v0=j, v1=j+p3[i], v2=j+2*p3[i];
			int w0=a[v0], w1 = a[v1], w2 = a[v2];
			a[v2]=w1-w0; a[v0]=w1-w2; a[v1]=w1-a[v2]-a[v0];
		}
	}
	for(int i=0;i<p3[n];i++)printf("%d ",a[i]);

	return 0;
}

