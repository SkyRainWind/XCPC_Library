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

const int inf = 1e9,maxn=15;

int n,m;
char s[maxn];
int type[maxn];	// 0 主猪 1 忠猪 2 反猪 
char card[maxn][2005];
int pos[maxn];	// card[i][1..pos[i]] 表示第 i 个猪的手牌， 
char pile[2005];	// 牌堆 
int pilepoint;
int hp[maxn];
int isdead[maxn];
int isarmed[maxn];	// 是否有装备牌 
int islf[maxn];	// 是否被认为是类反猪 
int iden[maxn];	// -1 跳反 1 跳忠 
int gameover;

void getnew(int x){
	++ pilepoint;
	if(pilepoint == n+1)--pilepoint;
	card[x][++ pos[x]] = pile[pilepoint];
}

void checkdead(int vert){
	if(hp[vert] > 0)return ;
	int mxhp = hp[vert];
	for(int i=1;i<=pos[vert];i++){
		if(card[vert][i] == 'P'){
			++ mxhp;
			if(mxhp == 1){
				for(int j=1;j<=i;j++)
					if(card[vert][j] == 'P')card[vert][j] = '#';
				return ;
			}
		}
	}
	isdead[vert] = 1;
}

void funeral(int x){for(int i=1;i<=pos[x];i++)card[x][i] = '#';}// 手牌弃置 

void checkwin(){	// 是否获胜 
	int fg = 1;
	for(int i=1;i<=n;i++)
		if(type[i] == 2 && isdead[i] == 0){fg=0;break;}
	if(fg)gameover = 2;	// 主猪获胜 
}

void judge(int x,int susp){	// x was killed by susp
	if(type[x] == 0){	// 反猪获胜 
		gameover = 1;
		return ;
	}
	if(type[x] == 1 && type[susp] == 0){	// 主猪所有牌弃置 
		for(int j=1;j<=pos[susp];j++){
			card[susp][j] = '#'; 
		}
		return ;
	}
	if(type[x] == 2){
		getnew(susp);getnew(susp);getnew(susp);
	}
}

int getdist(int x,int dis){
	int curdis = 0;
	for(int i=(x+1)%n+1;i!=x;i=(i==n?1:i+1)){
		if(!isdead[i]){
			++ curdis;
			if(curdis == dis)return i;
		}
	}
	return -1;
}

void solve(){
	int cur = 1;
	for(;;cur = cur%n + 1)if(!isdead[cur]){
		getnew(cur);getnew(cur);
		
		for(int tp=1;tp<=pos[cur];tp++){
			if(card[cur][tp] == 'P' && hp[cur] < 4){
				++ hp[cur];
				card[cur][tp]='#';
			}
			if(card[cur][tp] == 'N'){
				card[cur][tp] = '#';
				for(int j=(cur+1)%n+1;j!=cur;j=(j==n?1:j+1))if(!isdead[j]){
					int isresist=0;
					for(int k=1;k<=pos[j];k++){
						if(card[j][k] == 'K'){card[j][k]='#';isresist = 1;break;}
					}
					if(isresist == 0){
						-- hp[j];
						if(type[j] == 0)islf[cur] = 1; 
						checkdead(j);
						if(isdead[j]){
							funeral(j);
							checkwin();
							judge(j,cur);
							if(gameover)return ;
						}
					}
				}
			}
			if(card[cur][tp] == 'W'){
				card[cur][tp] = '#';
				for(int j=(cur+1)%n+1;j!=cur;j=(j==n?1:j+1))if(!isdead[j]){
					int isresist=0;
					for(int k=1;k<=pos[j];k++){
						if(card[j][k] == 'D'){card[j][k]='#';isresist = 1;break;}
					}
					if(isresist == 0){
						-- hp[j];
						if(type[j] == 0)islf[cur] = 1;
						checkdead(j);
						if(isdead[j]){
							funeral(j);
							checkwin();
							judge(j,cur);
							if(gameover)return ;
						}
					}
				}
			}
			if(card[cur][tp] == 'Z'){
				card[cur][tp] = '#';
				isarmed[cur] = 1;
			}
			if(card[cur][tp] == 'D'){
				
			}
		}
	}
}

signed main(){
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		if(s[1] == 'M')type[i] = 0;
		if(s[1] == 'Z')type[i] = 1;
		if(s[1] == 'F')type[i] = 2;
		
		for(int j=1;j<=4;j++){
			char p;cin>>p;
			card[i][j] = p;
		}
		pos[i] = 4;
		hp[i] = 4;
	}
	for(int i=1;i<=m;i++)cin >> pile[i];
	
	solve();
	if(gameover == 1)puts("FP");
	else puts("MP");
	for(int i=1;i<=n;i++){
		if(isdead[i] == 1)puts("DEAD");
		else{
			for(int j=1;j<=pos[i];j++)printf("%c ",card[i][j]);
			puts("");
		}
	}

	return 0;
}


