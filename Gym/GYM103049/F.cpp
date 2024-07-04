#include<bits/stdc++.h>
#define R register
#define LL long long
#define mkr make_pair
using namespace std;
inline int read(){
	int x=0,d=1; char y=getchar();
	for(;y<'0'||y>'9';y=getchar())if(y=='-')d=-1;
	for(;y>='0'&&y<='9';y=getchar())x=(x<<3)+(x<<1)+(y^'0');
	return x*d;
}
const int N=1e5+10;
struct node{int x,v;}e[N];
int n,ans;
set<int>st;
priority_queue< pair<double,pair<int,int> > >p;
void Insert(int i){
	if(i<1||i>n)return; int j=*st.lower_bound(i+1); if(j>n)return;
	if(e[i].v>e[j].v)p.push(mkr(-1.0*(e[j].x-e[i].x)/(e[i].v-e[j].v),mkr(i,j)));
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	n=ans=read();
	for(R int i=1;i<=n;i++)e[i].x=read(),e[i].v=read(),st.insert(i); st.insert(0); st.insert(n+1);
	for(R int i=1;i<n;i++)if(e[i].v>e[i+1].v)
		p.push(mkr(-1.0*(e[i+1].x-e[i].x)/(e[i].v-e[i+1].v),mkr(i,i+1)));
	while(!p.empty()){
		int u=p.top().second.first,v=p.top().second.second; p.pop();
		if(st.find(u)==st.end()||st.find(v)==st.end())continue;
		st.erase(u); st.erase(v); ans-=2; cerr<<u<<' '<<v<<'\n';
		auto it=st.lower_bound(u);
		--it; Insert(*it);
	}
	st.erase(0); st.erase(n+1);
	cout<<st.size()<<'\n';
	for(auto it=st.begin();it!=st.end();++it)cout<<*it<<' ';
	return 0;
}
