// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=233;
int n,m,K[maxn],p[maxn];
map<int,int>ts;
int pw(int x,int y){
	if(!y)return 1;
	if(y==1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return mid*mid*x;
	return mid*mid;
}
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&K[i],&p[i]);
	}
	
	if(n==1){
		int r=0;
		for(int i=1;i<=m;i++)
			if(K[1]*pw(i,p[1])==0)++r;
		cout<<r;return 0;
	}
	
	if(n==2){
		int r=0;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				if(K[1]*pw(i,p[1])+K[2]*pw(j,p[2])==0)++r;
		cout<<r;return 0;
	}
	if(n>=3)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				for(int k=1;k<=m;k++){
					int tt = K[1]*pw(i,p[1])+K[2]*pw(j,p[2])+K[3]*pw(k,p[3]); 
					if(!ts.count(tt))ts[tt]=1;
					else ++ts[tt];
//					printf("%d %d %d %d\n",i,j,k,tt);
				}
	if(n==3){cout<<ts[0];return 0;}
	if(n==4){
		int r=0;
		for(int i=1;i<=m;i++){
			int tt=-K[4]*pw(i,p[4]); 
			if(ts.count(tt))r+=ts[tt];
		}
		cout<<r;return 0;
	}
	
	if(n==5){
		int r=0;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++){
				int tt=K[4]*pw(i,p[4])+K[5]*pw(j,p[5]);
				if(ts.count(-tt))r+=ts[-tt];
			}
		cout<<r;return 0;
	}
	
	int ans=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=m;k++){
				int tt = K[4]*pw(i,p[4])+K[5]*pw(j,p[5])+K[6]*pw(k,p[6]); 
				if(ts.count(-tt))
					ans+=ts[-tt]; 
			}
	cout<<ans;

	return 0;
}
