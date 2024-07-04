// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;
#define int ll

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5;

int n;
struct point{
	int x,y;
}p[maxn];

point operator - (point a,point b){return point{a.x - b.x, a.y - b.y};}
point operator + (point a,point b){return point{a.x + b.x, a.y + b.y};}

int cross(point a,point b){return a.x * b.y - a.y * b.x;}
// 右手定则拇指向上，叉积为正，否则为负 

vector<point>up,dn;
int stk[maxn],all[maxn],cnt=0;

int dis(int x,int y){
	int delx = p[x].x - p[y].x, dely = p[x].y - p[y].y;
	return delx*delx + dely*dely;
}

int sqr(int x,int y,int q){
	return abs(cross(p[y]-p[x], p[q]-p[y]));
}

int is(point a,point b){return a.x==b.x?a.y<b.y:a.x<b.x;}

signed main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i].x>>p[i].y;
	sort(p+1,p+n+1,[&](point a,point b){return a.x==b.x?a.y<b.y:a.x<b.x;});
	
	int cnt=0;
	#define pd(A,B,C) (cross((C-B),(B-A))>0||(cross((C-B),(B-A))==0&&is(A,B)==is(B,C)))//平行也需要弹去
	int i;for(i=1;i<=n;all[++cnt]=i++) while(cnt>1&&pd(p[all[cnt-1]],p[all[cnt]],p[i])) --cnt;
	for(i=n-1;i;all[++cnt]=i--) while(cnt>1&&pd(p[all[cnt-1]],p[all[cnt]],p[i])) --cnt;--cnt;
	
	int j = 3; 
	int ans = dis(1,n);
	for(int i=1;i<=cnt;i++){
		while(sqr(all[i],all[i+1],all[j]) < sqr(all[i],all[i+1],all[j%cnt+1]))j=j%cnt+1;
		ans=max(ans,max(dis(all[i],all[j]), dis(all[i+1],all[j])));
		ans=max(ans,max(dis(all[i],all[j%cnt+1]), dis(all[i+1],all[j%cnt+1])));
	}
	cout<<ans;

	return 0;
}

