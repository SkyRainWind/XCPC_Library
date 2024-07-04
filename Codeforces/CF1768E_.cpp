// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=15;

int n,a[maxn],ans;

int c0(int *a){
	for(int i=2;i<=3*n;i++)
		if(a[i] < a[i-1])return 0;
	return 1;
}
int c1(){
	int b[maxn];
	memcpy(b,a,sizeof b);
	sort(b+1,b+2*n+1);
	if(c0(b))return 1;
	memcpy(b,a,sizeof b);
	sort(b+n+1,b+3*n+1);
	if(c0(b))return 1;
	return 0;
}
int c2(){
	int b[maxn];
	memcpy(b,a,sizeof b);
	sort(b+1,b+2*n+1);sort(b+n+1,b+3*n+1);
	if(c0(b))return 1;
	memcpy(b,a,sizeof b);
	sort(b+n+1,b+3*n+1);sort(b+1,b+2*n+1);
	if(c0(b))return 1;
	return 0;
}
int ck(){
	int t0=0,t1=0;
	for(int i=1;i<=2*n;i++)
		if(a[i]<=n)++t0;
		else if(a[i]>2*n) ++t1;
	if(t0<n)return 0;
	if(t1)return 1;
	return 0;
//	if(t0==2*n)return 1;
//	return 0;
}
int ck2(){
	int t0=0,t1=0;
	for(int i=1;i<=2*n;i++)
		if(a[i]<=2*n)++t0;
		else if(a[i]>2*n) ++t1;
//	if(t0<n)return 0;
//	if(t1)return 1;
//	return 0;
	if(t0==2*n)return 1;
	return 0;
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=3*n;i++)a[i]=i;
	int t0=0,t1=0,t2=0,t3=0,tt=0;
	do{
		if(c0(a))++t0;
		else if(c1())++ans,++t1;
		else if(c2()){
			ans+=2,++t2;
			if(ck() || ck2()){
//				for(int i=1;i<=3*n;i++)printf("%d ",a[i]);puts("");
			}else{
				++ tt;
//				for(int i=1;i<=3*n;i++)printf("%d ",a[i]);puts("");
			}
		}
		else{
			ans+=3,++t3;
//			
//				for(int i=1;i<=3*n;i++)printf("%d ",a[i]);puts("");
		}
	}while(next_permutation(a+1,a+3*n+1));
	cout<<ans<<'\n';
	printf("%d %d %d %d %d\n",t0,t1,t2,t3,tt);

	return 0;
}

