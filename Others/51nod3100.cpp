#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;
int f[100005], n;
signed main(){
	f[0] = f[1] = f[2] = 1;
	int n;scanf("%d",&n);
	for(int i=4;i<=n;i++)
		f[i%3] += f[(i+2)%3], f[i%3] %= 100003;
	printf("%d\n",f[n%3]);

	return 0;
}

