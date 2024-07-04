#include<bits/stdc++.h>
using namespace std;
const long long mo=998244353;
const long long MAX_N=1e5+5,MAX_M=25;
inline int read(){
	long long x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x;
}//读入优化
long long kkksc03(long long x,long long y){
	long long s=1;
	while (y!=0){
		if (y%2==1) s=s*x%mo;
		x=x*x%mo;
		y/=2;
	}
	return s;
}//快速幂
struct kira{
	long long x;
	kira(long long x=0):x(x){};
	kira operator=(const long long &xx){
		x=xx;
		return *this;
	}
	kira operator+(const kira &b){
		return (kira)((x+b.x)%mo);
	}
	kira operator-(const kira &b){
		return (kira)((x-b.x+mo)%mo);
	}
	kira operator*(const kira &b){
		return (kira)((x*b.x)%mo);
	}
	kira operator/(const kira &b){
		return (kira)(x*kkksc03(b.x,mo-2)%mo);
	}
	kira operator^(const kira &b){
		return (kira)(kkksc03(x,b.x));
	}
	kira operator+=(const kira &b){
		return (kira)((x+b.x)%mo);
	}
	kira operator-=(const kira &b){
		return (kira)((x-b.x+mo)%mo);
	}
	kira operator*=(const kira &b){
		return (kira)((x*b.x)%mo);
	}
	kira operator/=(const kira &b){
		return (kira)(x*kkksc03(b.x,mo-2)%mo);
	}
	kira operator^=(const kira &b){
		return (kira)(kkksc03(x,b.x));
	}
	kira operator+(const long long  &b){
		return (kira)((x+b)%mo);
	}
	kira operator-(const long long &b){
		return (kira)((x-b+mo)%mo);
	}
	kira operator*(const long long &b){
		return (kira)((x*b)%mo);
	}
	kira operator/(const long long &b){
		return (kira)(x*kkksc03(b,mo-2)%mo);
	}
	kira operator^(const long long &b){
		return (kira)(kkksc03(x,b));
	}
	kira operator+=(const long long &b){
		return (kira)((x+b)%mo);
	}
	kira operator-=(const long long &b){
		return (kira)((x-b+mo)%mo);
	}
	kira operator*=(const long long &b){
		return (kira)((x*b)%mo);
	}
	kira operator/=(const long long &b){
		return (kira)(x*kkksc03(b,mo-2)%mo);
	}
	kira operator^=(const long long &b){
		return (kira)(kkksc03(x,b));
	}
	bool operator==(const long long b){
		return x==b;
	}
};//超级变态的运算符重载
long long n,m,i,k;
kira a[MAX_N],p[MAX_N],u,g[MAX_N][MAX_M][2],dp[MAX_N][MAX_M][2],gundam;
int main(){
	freopen("Luogu7509.in","r",stdin);
	n=read();m=read();
	for (i=1;i<=n;i++)  a[i]=read();
	for (i=1;i<=n;i++)	p[i]=read();//手打读入
	g[0][0][0]=1;//初始化
	u=1;//因为某些灵异事件（类型不相等事件），必须要这么定一个。
	for (i=1;i<=n;i++)
		for (k=0;k<=m;k++)
			if (k==0)
				g[i][k][0]=g[i-1][k][0]*(mo+1-p[i].x);
			else{
				if (k+k-1>i) continue;
				else if (k+k-1==i){
					g[i][k][1]=g[i-1][k-1][0]*p[i];
					dp[i][k][1]=dp[i-1][k-1][0]+a[i];
				}
				else{
					g[i][k][1]=g[i-1][k-1][0]*p[i]+g[i-1][k][1]*p[i];
					gundam=u/(g[i-1][k-1][0]+g[i-1][k][1]);
					dp[i][k][1]=a[i]+dp[i-1][k-1][0]*g[i-1][k-1][0]*gundam+dp[i-1][k][1]*g[i-1][k][1]*gundam;
					g[i][k][0]=(g[i-1][k][1]+g[i-1][k][0])*(mo+1-p[i].x);
					gundam=u/(g[i-1][k][0]+g[i-1][k][1]);
					dp[i][k][0]=dp[i-1][k][0]*g[i-1][k][0]*gundam+dp[i-1][k][1]*g[i-1][k][1]*gundam;//都懂的
				}
			}
			
for(int i=1;i<=n;i++,puts(""))
	for(int j=1;j<=k;j++)printf("%d %d  ",dp[i][j][0].x,dp[i][j][1].x);
		printf("%lld %lld\n",g[4][2][1].x,g[4][2][0].x);
	printf("%lld\n",(dp[n][m][0]*g[n][m][0]+dp[n][m][1]*g[n][m][1]).x);
	return 0; 
}
