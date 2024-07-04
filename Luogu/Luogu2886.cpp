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

int k,m,s,t,cnt;
int u[1005],v[1005],w[1005];
map<int,int>lsh, trans;
struct mat{
	int a[105][105];
	mat(){memset(a,0x3f,sizeof a);}
}dis;
mat operator * (mat a, mat b){
	mat c;
	for(int k=1;k<=cnt;k++)
		for(int i=1;i<=cnt;i++)
			for(int j=1;j<=cnt;j++)
				c.a[i][j] = min(c.a[i][j], a.a[i][k] + b.a[k][j]);
	return c;
}

mat pw(mat a,int y){
	-- y;
	mat bs = a, res = a;
	while(y){
		if(y & 1)res = res * bs;
		bs = bs*bs;
		y >>= 1;
	}
	return res;
}

signed main(){
	scanf("%d%d%d%d",&k,&m,&s,&t);
	lsh[s] = lsh[t] = 1;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&w[i],&u[i],&v[i]);
		lsh[u[i]] = lsh[v[i]] = 1;
	}
	for(auto it : lsh)trans[it.first] = ++cnt;
	s = trans[s], t = trans[t];
	for(int i=1;i<=m;i++){
		u[i] = trans[u[i]], v[i] = trans[v[i]];
		dis.a[u[i]][v[i]] = dis.a[v[i]][u[i]] = w[i];
	}
//	printf("%d %d\n",s,t);
//	for(int i=1;i<=m;i++)printf("%d %d %d\n",u[i],v[i],w[i]);
	dis = pw(dis, k);
	printf("%d\n",dis.a[s][t]);

	return 0;
}

