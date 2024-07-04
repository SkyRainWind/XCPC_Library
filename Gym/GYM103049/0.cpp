#include<bits/stdc++.h>
#define R register
#define LL long long
using namespace std;
inline int read(){
	int x=0,d=1; char y=getchar();
	for(;y<'0'||y>'9';y=getchar())if(y=='-')d=-1;
	for(;y>='0'&&y<='9';y=getchar())x=(x<<3)+(x<<1)+(y^'0');
	return x*d;
}
const int N=1e7+10;
int n,q,a[110];
LL dp[N];
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	n=read(); q=read(); int m=1e7;
	for(R int i=1;i<=m;i++)dp[i]=2e18; dp[0]=0;
	for(R int i=1;i<=n;i++)a[i]=dp[i]=read();
//	for(R int i=1;i<=n;i++)
		for(R int j=n+1;j<=m;j++)
			for(int i=1;i<=n;i++)dp[j]=min(dp[j],dp[j-i]+a[i]);
	for(R int i=1,k,x;i<=q;i++){
		k=read();
		if(k<=m)cout<<dp[k]<<'\n';
		else {
			LL ans=2e18;
			for(R int j=1;j<=n;j++){
				x=(k-m)/j+1;
				ans=min(ans,1ll*x*a[j]+dp[k-x*j]);
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
