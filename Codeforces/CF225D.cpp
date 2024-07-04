// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 17;
const int p = 998244353, p2 = 990804011;

int n,m;
char s[maxn][maxn];
struct state{
	char st[maxn][maxn];
	int cnt;
	
	ull gethash(){
		ull hs = 0;
		ull hs2 = 0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				hs = hs*p + st[i][j],
				hs2 = (hs2*p2 + st[i][j]);
		return hs*127+hs2;
	}
	
	state(){cnt=0;}
}hajime;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
unordered_map<ull,int>vis;
queue<state>Q;
int ans = -1, len = 0;

int ind(int x,int y){return (x-1)*n+y;}
int in(int x,int y){return x>=1 && x<=n && y>=1 && y<=m;} 
ull hsh(int *pp){
	ull now=0;
	for(int i=1;i<=len;i++)now=now*p+pp[i];
	return now;
}

void move(state now){
	int tmp[12];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(now.st[i][j] >= '1' && now.st[i][j] <= '9'){
				now.st[i][j] ++;
				if(now.st[i][j] < len + '1')tmp[now.st[i][j] - '0'] = ind(i, j);
			}
	int bx, by;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(now.st[i][j] == '2')
				bx = i, by = j;
			if(now.st[i][j] == len + '1')
				now.st[i][j] = '.';
		}
	
	now.cnt ++;
	for(int i=0;i<4;i++){
		int fx = bx + dx[i], fy = by + dy[i];
		if(!in(fx, fy))continue;
		if(now.st[fx][fy] == '@'){
			ans = now.cnt;
			return ;
		}else if(now.st[fx][fy] == '.'){
			tmp[1] = ind(fx, fy);
			now.st[fx][fy] = '1';
			ull nowhs = hsh(tmp);
			if(!vis.count(nowhs)){
				vis[nowhs] = 1;
//				vis.insert(nowhs);
				Q.push(now);
			}
			now.st[fx][fy] = '.';
		}
	}
}

signed main(){
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++)scanf("%s",hajime.st[i] + 1);
	
	int tmp[12];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(hajime.st[i][j] >= '1' && hajime.st[i][j] <= '9')
				len = max(len, hajime.st[i][j] - '0'),
				tmp[hajime.st[i][j] - '0'] = ind(i, j);
	hajime.cnt = 0;
	vis[hsh(tmp)] = 1;
//	vis.insert(hajime.gethash());
	Q.push(hajime);
	
	while(!Q.empty()){
		state now = Q.front(); Q.pop();
		
		move(now);
		if(~ans)break;
	}
	cout<<ans;

	return 0;
}
