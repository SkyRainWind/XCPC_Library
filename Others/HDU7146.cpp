// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5e5+5;
const long double eps = 1e-12;

pii a[maxn], b[maxn];
int id[maxn];

vector<int>deal(int id,pii c){
    if(id == 1)return {0,1,-c.second};
    if(id == 2)return {1,-1,c.second-c.first};
    if(id == 3)return {1,0,-c.first};
    if(id == 4)return {1,1,-c.second-c.first};
}

int eq(long double x,long double y){
    return fabs(x-y) < eps;
}

void solve(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i].first,&a[i].second), id[i] = i;
    int fgg = 0;
    for(int i=1;i<n;i++)if(a[i].first != a[i+1].first){fgg=1;break;}
    if(!fgg)return (void)puts("YES");
    fgg=0;
    for(int i=1;i<n;i++)if(a[i].second != a[i+1].second){fgg=1;break;}
    if(!fgg)return (void)puts("YES");
    fgg=0;
    for(int i=1;i<n;i++)if(a[i].first-a[i+1].first != a[i].second-a[i+1].second){fgg=1;break;}
    if(!fgg)return (void)puts("YES");
    fgg=0;
    for(int i=1;i<n;i++)if(a[i].first-a[i+1].first != -a[i].second+a[i+1].second){fgg=1;break;}
    if(!fgg)return (void)puts("YES");
    
    int lp = 0;
    while(++lp <= 1){
        for(int i=1;i<=n;i++)b[i] = a[id[i]];
        int t = 1, ta = -1;
		for(int i=2;i<=n;i++){
		        ll dx = a[i].first - a[1].first;
		        ll dy = a[i].second- a[1].second;
		        if(dy==0||dx==0||abs(dx)==abs(dy))
		            ;
		            else ta = i;
			
		}
                
        for(int i=1;i<=4;i++)
            for(int j=1;j<=4;j++)if(i!=j){
                // x+y+c=0 / x-y+c=0 / x+c=0 / y+c=0
                vector<int>t1 = deal(i,b[t]);
                vector<int>t2 = deal(j,b[ta]);
                
                ll det = 1ll*t1[0]*t2[1] - 1ll*t1[1]*t2[0];
                if(det == 0)continue;
                ll d1 = 1ll*(-t1[2])*t2[1] - 1ll*t1[1]*(-t2[2]);
                ll d2 = 1ll*t1[0]*(-t2[2]) - 1ll*(-t1[2])*t2[0];
                
                long double cx = 1.0 * d1 / det;
                long double cy = 1.0 * d2 / det;
//                printf("qw %Lf %Lf\n",cx,cy);
                
                int fg = 1;
                for(int k=1;k<=n;k++){
                    long double dx = a[k].first - cx;
                    long double dy = a[k].second - cy;
//                    printf("qqq %f %f\n",dx,dy);
                    if(fabs(dy) < eps || fabs(dx) < eps || eq(fabs(dx),fabs(dy)))
                        ;
                    else{
                        fg = 0;
                        break;
                    }
                }
                if(fg){
                    puts("YES");
                    return ;
                }
            }
        
        random_shuffle(id+1,id+n+1);
    }
    puts("NO");
}

signed main(){
    int te;scanf("%d",&te);
    while(te --)solve();

    return 0;
}

