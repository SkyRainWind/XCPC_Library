// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;
int p[23],r=0;
int pm(int x){
	if(x==1)return 0;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)return 0;
	return 1;
}
map<set<int>,int>mp;
void dfs(int x,int lst,set<int>S){
	if(x==10){
		if(lst)S.insert(lst);
		if(!lst || pm(lst))mp[S]++;
		return ;
	}
	int nw = lst*10+p[x];
	dfs(x+1,nw,S);
	if(pm(nw)){S.insert(nw);dfs(x+1,0,S);}
}
signed main(){
	for(int i=1;i<=9;i++)p[i]=i;
	do{
		set<int>S;
		dfs(1,0,S);
	}while(next_permutation(p+1,p+10));
	cout<<mp.size();

	return 0;
}

