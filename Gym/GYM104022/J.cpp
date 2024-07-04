// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1005*1005;

int m;
struct node{int n,s,e,w;}a[maxn]; 
int b[1005][1005];

signed main(){
	scanf("%d",&m);
	for(int i=1;i<=m*m;i++)
		scanf("%d%d%d%d",&a[i].n,&a[i].s,&a[i].w,&a[i].e);
	for(int i=1;i<=m*m;i++){
		if(a[i].n == -1&&a[i].w == -1)b[1][1] = i;
		if(a[i].n == -1&&a[i].e == -1)b[1][m] = i;
		if(a[i].s == -1&&a[i].w == -1)b[m][1] = i;
		if(a[i].s == -1&&a[i].e == -1)b[m][m] = i;
	}
	for(int i=1;i<=m;i++){
		if(i%2 == 1){
			for(int j=1;j<=m-1;j++){
				int t = b[i][j];
				int qw = a[t].e;
				b[i][j+1] = qw;
			}
			if(i<m)b[i+1][m] = a[b[i][m]].s;
		}else{
			for(int j=m;j>=2;j--){
				int t=b[i][j];
				int qw = a[t].w;
				b[i][j-1] = qw;
			}
			if(i<m)b[i+1][1] = a[b[i][1]].s;
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)printf("%d%c",b[i][j], " \n"[j==m]);

	return 0;
}

