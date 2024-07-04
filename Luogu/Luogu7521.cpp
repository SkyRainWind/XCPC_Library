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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2e5+5;

int n;
int a[maxn],b[maxn];

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans = 0;
	for(int i=n;i>=1;){
		if(ans > a[i])break;
		int cnt=0;
		for(int j=1;j<=n;j++)if(i!=j)b[++ cnt] = a[j]%a[i];
		
		sort(b+1,b+cnt+1);
		int res=0;
		if(b[cnt-1] + b[cnt]-a[i] >= 0)res = (b[cnt-1] + b[cnt] - a[i])%a[i];
		for(int j=1;j<=cnt;j++){
			int id = upper_bound(b+1,b+cnt+1,a[i]-1 - b[j]) - b - 1;
			if(id!=0){
				if(id == j)--id;
				if(id !=0)res = max(res, (b[id]+b[j])%a[i]);
			}
		}
		ans = max(ans,res);
		--i;
		while(a[i-1] == a[i])-- i;
	}
	printf("%d\n",ans);

	return 0;
}


