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

const int inf = 1e9,maxn=2e5+5;

int n,m;
int a[maxn],dis[maxn];
int cmp(int p,int q){return p>q;}
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d",&a[i]),a[i+m]=a[i]+n;
	sort(a+1,a+2*m+1);
	int cnt=0;
	for(int i=2;i<=2*m;i++){
		dis[++ cnt] = a[i]-a[i-1]-1;
		if(a[i] > n)break;
	}
	sort(dis+1,dis+cnt+1,cmp);
	int bs=0, ans=0;
	for(int i=1;i<=cnt;i++){
		if(dis[i]-bs-1 <= 0){
			if(dis[i]-bs >=1)++ ans;
			break;
		}
		ans += dis[i]-bs-1;
		bs += 4;
	}
//	if(n==m)ans
	printf("%d\n",n-ans);
}

signed main(){
	int te;scanf("%d",&te);while(te--)solve();

	return 0;
}


