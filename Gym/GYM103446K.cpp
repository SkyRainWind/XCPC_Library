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

int a[666],n,b[666],c[666],d[666],k;

void ck(){
	memcpy(c,d,sizeof c);
	memcpy(a,d,sizeof a);
	int gg=0;
	for(int k=1;k<=2*n;k++){
		for(int i=1;i<=n;i++)b[i]=0;
		for(int i=1;i<=n;i++)
			if(a[i]==1){
				if(a[i-1]==1||(i>=3&&a[i-2]==1)){
					;
				}else{
					if(i>1)b[i-1]=1;
				}
				if(a[i+1]==1||a[i+2]==1);
				else b[i+1]=1;
			}
		
		int f=0;
		for(int i=1;i<=n;i++)f|=b[i];
		if(!f)return ;
		for(int i=1;i<=n;i++)f &= (b[i]==c[i]);
		if(f)gg=1;
		for(int i=1;i<=n;i++)a[i] = b[i];
//		cerr<<"?? " <<a[i] << ' '<<d[i]<<' ';
//		cerr<<'\n';
	}
//	printf("??? %d\n",gg);
	if(gg){
		k=1;
		int r=0;
		for(int i=1;i<=n;i++)if(c[i]!=c[n-i+1])
		return ;
		for(int i=1;i<=n;i++){
			printf("%d ",c[i]);
		}puts("");
	}
}

void dfs(int x){
	if(x==n+1){
		ck();
		return ;
	}
	d[x]=0;
	dfs(x+1);
	d[x]=1;
	dfs(x+1);
}

signed main(){
//	freopen("103446K.txt","w",stdout);
	for(n=6;;n++)
	
	{
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		memset(d,0,sizeof d);
		printf("n=%d\n",n);
		k=0;
		dfs(1);
		if(!k)puts("GG");
	}

	return 0;
}

