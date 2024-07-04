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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2e5+5;

int n;
pair<int,int> a[maxn];

int gt(int x){int t=0;while(x){++t;x/=10;}return t;}

int cmp(pair<int,int> a,pair<int,int> b){
	return a.first == b.first ? a.second > b.second : a.first > b.first;
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].second), a[i].first = gt(a[i].second);
	sort(a+1,a+n+1,cmp);
	if(a[1].first == a[3].first)
		for(int i=1;i<=3;i++){
			printf("%d",a[i].second); 
		}
	else{
		int t1 = a[1].second, t2 = a[2].second, t3 = a[3].second;
		LL p1 = t1*(LL)pow(10,gt(t3)+gt(t2)) + t2*(LL)pow(10,gt(t3))+t3;
		LL p2 = t1*(LL)pow(10,gt(t2)+gt(t3)) + t3*(LL)pow(10,gt(t2))+t2;
		LL p3 = t2*(LL)pow(10,gt(t3)+gt(t1)) + t1*(LL)pow(10,gt(t3))+t3;
		LL p4 = t2*(LL)pow(10,gt(t1)+gt(t3)) + t3*(LL)pow(10,gt(t1))+t1;
		LL p5 = t3*(LL)pow(10,gt(t2)+gt(t1)) + t1*(LL)pow(10,gt(t2))+t2;
		LL p6 = t3*(LL)pow(10,gt(t1)+gt(t2)) + t2*(LL)pow(10,gt(t1))+t1;
		printf("%lld\n",max(max(max(p1,p2),max(p3,p4)),max(p5,p6)));
	}

	return 0;
}


