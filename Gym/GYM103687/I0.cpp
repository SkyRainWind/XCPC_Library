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

char s[2222];
int n;
int sg[223][233];

int mex(int s1,int s2){
	for(int i=0;i<=5;i++)if(s1!=i&&s2!=i)return i;
}

signed main(){
	scanf("%s",s+1);
	int n =strlen(s+1);
//	scanf("%d",&n);
	for(int i=1;i<=n;i++)sg[i][i] = 0;
	for(int l=2;l<=n;l++)
		for(int i=1;i+l-1<=n;i++){
			int j=i+l-1;
			sg[i][j] = mex(sg[i+1][j], sg[i][j-1]);
		}
	for(int i=1;i<=n;i++,puts(""))
		for(int j=i+1;j<=n;j++)printf("%d %d %d\n",i,j,sg[i][j]);

	return 0;
}

