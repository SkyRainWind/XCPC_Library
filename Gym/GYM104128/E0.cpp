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

int exgcd(int a,int b,int &x,int &y){
	if(!b){
		x=1,y=0;
		return a;
	}
	int ret = exgcd(b,a%b,x,y);
	int t=x;x=y;y=t-a/b*y;
	return ret;
}

signed main(){
//	for(int n=2;n<=20;n++)for(int m=2;m<=n;m++){
//		printf("%d,%d:",n,m);
	int te;scanf("%d",&te);
	while(te--){
		int n,m;scanf("%d%d",&n,&m);
		if(n==1&&m==1){puts("Yes");continue;}
		if(m==1){puts("No");continue;}
		if(n==m){puts("Yes");continue;} 
		if(m%2==0){puts("Yes");continue;} 
		int k=m;
		int up=n/k,r=n%k,t=k-n%k;
//		int c = r+k*up;
//		if(n%2==1)--c;
//		if(c%2){puts("No");continue;}
//		debug();
		int x,y;
//		c /= 2;
//		int od=(n+1)/2-(k+1)/2*(n/k),ev=(n/2)-k/2*(n/k);
//		if(od>=0&&od<=(k+1)/2&&ev>=0&&ev<=(k)/2)puts("Yes");
//		else puts("No");
		int ret=exgcd(up+1,up,x,y);
		x *= n/2, y *= n/2;
//		int mn = (x%up+up)%up;
//		int del = (x-mn) / up;
//		x=mn;
//		y = y+(up+1)*del;
//		x*=(n/2)/ret, y*=(n/2)/ret;
//		if(n==5&&m==3)printf("%d*%d + %d*%d = n/2\n",x,up+1,y,up);
//		if(y>=0&&y<=t&&x>=0&&x<=r)puts("Yes");
		
		int mna = max((int)ceil(-1.0*x/up), (int)ceil(1.0*(y-k+r)/(up+1)));
  		int mxa = min((int)floor(1.0*(r-x)/up), (int)floor(1.0*(y)/(up+1)));
//		printf("%d %d %d %d\n",mna,mxa,x,y);
		if(mna <= mxa)puts("Yes");
		else puts("No");
		
//		int k=m;
//		if(n%2 == 1){
//			int r=n%k, t=k-n%k;
//			int up = n/k;
//			if(up == 1){puts("Yes");continue;} 
//			if(r%2==0){puts("No");continue;}
//			if(r%2==1){
//				-- t;
//				if(t%2==0||(up==2&&(t+1)>=2&&(t+1)%2==0)){puts("Yes");continue;}
//				else{puts("No");continue;}
//			}
//		}else{
//			int r=n%k, t=k-n%k;
//			int up = n/k;
//			if(up == 1){puts("Yes");continue;}
//			if(r%2==1){puts("No");continue;}
//			if(r%2==0){
//				if(t%2==0){puts("Yes");continue;}
//				else{puts("No");continue;}
//			}
//		}
	}

	return 0;
}

