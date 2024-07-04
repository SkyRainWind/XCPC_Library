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

struct point{
	int x,y;
}p[55];
int a,b;

int cross(point a,point b){
	return a.x * b.y - a.y * b.x;
}

point operator - (point a,point b){
	return point{a.x - b.x, a.y - b.y};
}

signed main(){
	for(int i=1;i<=3;i++)
		scanf("(%d,%d)\n",&p[i].x,&p[i].y);
	scanf("(%d,%d)",&p[0].x,&p[0].y);
	
	int lf=0, ri=0;
	for(int i=1;i<=3;i++){
		point p1 = p[0] - p[i], p2 = p[0] - p[i%3 + 1];
		int t = cross(p1, p2);
		if(t < 0)++ lf;
		if(t > 0)++ ri;
	}
	if(lf == 3 || ri == 3)puts("1");
	else if(ri > 0 && lf > 0)puts("2");
	else if(lf+ri == 1)puts("4");
	else puts("3");

	return 0;
}

