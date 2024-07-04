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

int n,m;
char s[1005][1005];

#define ck(x,y,t) if((!(x>=1&&x<=n&&y>=1&&y<=m))||(x>=1&&x<=n&&y>=1&&y<=m&&s[x][y]!=t))return 0

string t[6]={
	"######",
	"##..##",
	"#....#",
	"#....#",
	"##..##",
	"######"
};

int ish(int x,int y){
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
			ck(x+i,y+j,t[i][j]);
	return 1;
}

signed main(){
	scanf("%d%d",&n,&m);
	int c=0,t=0;
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++)if(s[i][j] == '#')++c;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(ish(i,j))++t;
	// 146x+100y=c
	// 2x+y=t -> 200x+100y=100t
	// 54x = 100t-c
//	printf("? %d %d\n",c,t);
	int x=(100*t-c)/54, y=t-2*x;
	printf("%d %d\n",x,y);

	return 0;
}

