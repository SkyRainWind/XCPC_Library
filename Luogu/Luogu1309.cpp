// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5;

int n,r,q,win[maxn],lose[maxn];
struct node{
	int s,w,id;
} a[maxn],b[maxn];
int cmp(node a,node b){
	return a.s != b.s ? a.s > b.s : a.id < b.id;
}

signed main(){
//	freopen("1309.in","r",stdin);
	scanf("%d%d%d",&n,&r,&q);
	for(int i=1;i<=2*n;i++)scanf("%d",&a[i].s), a[i].id = i;
	for(int i=1;i<=2*n;i++)scanf("%d",&a[i].w);
	sort(a+1,a+2*n+1,cmp);
	while(r --){
		for(int i=1;i<=2*n;i+=2){
			if(a[i].w > a[i+1].w)++ a[i].s, win[i/2+1]=i, lose[i/2+1]=i+1;
			else ++ a[i+1].s, win[i/2+1]=i+1, lose[i/2+1]=i;
		}
		int p1=1, p2=1;
		for(int i=1;i<=2*n;i++){
			if(p1 == n+1){b[i] = a[lose[p2++]];continue;}
			if(p2 == n+1){b[i] = a[win[p1++]];continue;}
			if(a[win[p1]].s == a[lose[p2]].s){
				if(a[win[p1]].id < a[lose[p2]].id)b[i] = a[win[p1++]];
				else b[i] = a[lose[p2++]];
				continue;
			}
			if(a[win[p1]].s > a[lose[p2]].s)b[i] = a[win[p1++]];
			else b[i] = a[lose[p2++]];
		}
		for(int i=1;i<=2*n;i++)a[i] = b[i];
	} 
	printf("%d\n",a[q].id);

	return 0;
}


