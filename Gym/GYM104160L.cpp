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

struct node{
	int hp,atk,cnt,alive;
};
vector<node>a,b;
vector<node>prea[9],sufa[9],preb[9],sufb[9];

#define vn vector<node>
#define pdd pair<double,double>

void add(pdd&a,pdd b){
	a.first+=b.first;a.second+=b.second;
}
pdd operator *(double t,pdd a){return mpr(t*a.first,t*a.second);}

pair<double,double> dfs(vector<node>a,vector<node>b,int cur){
	if(a.size()==0)return mpr(0.0,b.size()==0?0.0:1.0);
	if(b.size()==0)return mpr(1.0,0.0);
	
	pdd r;
	
	auto get = [](vn a,vn b,double bs,int i,int op,int now) -> pdd{
		pdd r=mpr(0.0,0.0);
		vn c,d;
		for(int j=0;j<b.size();j++){
			c.clear(), d.clear();
			for(int k=0;k<i;k++)c.pb(a[k]);
			for(int k=0;k<j;k++)d.pb(b[k]);
			
			if(a[i].hp - b[j].atk > 0)c.pb(node{a[i].hp-b[j].atk,a[i].atk,a[i].cnt+1,1});
			if(b[j].hp - a[i].atk > 0)d.pb(node{b[j].hp-a[i].atk,b[j].atk,b[j].cnt,1});
			
			for(int k=i+1;k<a.size();k++)c.pb(a[k]);
			for(int k=j+1;k<b.size();k++)d.pb(b[k]);
			
			if(op)add(r,bs * dfs(c,d,now));
			else add(r,bs * dfs(d,c,now));
		}
		return r;
	};
	
	if(cur==0){
		vector<node>c,d;
		int mn=1e9,id;
		
		for(int i=0;i<a.size();i++)
			if(a[i].cnt<mn)mn=a[i].cnt,id=i;
		
		r = get(a,b,1.0,id,1,cur^1);
		r = (1.0/b.size()) * r;
	}else{
		vector<node>c,d;
		int mn=1e9,id;
		
		for(int i=0;i<b.size();i++)
			if(b[i].cnt<mn)mn=b[i].cnt,id=i;
		
		r = get(b,a,1.0,id,0,cur^1);
		r = (1.0/a.size())*r;
	}
	
//	for(int i=0;i<a.size();i++)printf("%d %d %d  ",a[i].hp,a[i].atk,a[i].cnt);puts("");
//	for(int i=0;i<b.size();i++)printf("%d %d %d  ",b[i].hp,b[i].atk,b[i].cnt);puts("");
//	printf("%f\n\n",r);
	
	return r;
}

signed main(){
	int n,m;
	scanf("%d%d",&n,&m);
	a.resize(n), b.resize(m);
	for(int i=0;i<n;i++)scanf("%d",&a[i].atk),a[i].hp=a[i].atk,a[i].cnt=0,a[i].alive=1;
	for(int i=0;i<m;i++)scanf("%d",&b[i].atk),b[i].hp=b[i].atk,b[i].cnt=0,b[i].alive=1;
	
	pdd r1=dfs(a,b,0), r2=dfs(a,b,1);
	double ans=0.0,ans2=0.0;
	if(a.size()==b.size())ans=(r1.first+r2.first)/2.0;
	else if(a.size()>b.size())ans=r1.first;
	else ans=r2.first;

	if(a.size()==b.size())ans2=(r1.second+r2.second)/2.0;
	else if(a.size()>b.size())ans2=r1.second;
	else ans2=r2.second;
	
	printf("%.9f\n%.9f\n",ans,ans2);
	printf("%.9f\n",1-ans-ans2);

	return 0;
}

