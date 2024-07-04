// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=4e6+5;

namespace fft{
	const double pi = acos(-1.0);
	struct complex{
		double x,y;
		complex(double x=0,double y=0):x(x),y(y){}
	}a[maxn],b[maxn];
	complex operator + (complex a,complex b){return complex(a.x+b.x,a.y+b.y);}
	complex operator - (complex a,complex b){return complex(a.x-b.x,a.y-b.y);}
	complex operator * (complex a,complex b){return complex(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
	
	int r[maxn],lim;
	
	void dft(complex *a,int op){
		for(int i=0;i<lim;i++)if(i<r[i])swap(a[i],a[r[i]]);
		for(int mid=1;mid<lim;mid<<=1){
			complex wn(cos(pi/mid), op*sin(pi/mid));
			for(int r=mid<<1,j=0;j<lim;j+=r){
				complex w(1,0);
				for(int k=0;k<mid;k++,w=w*wn){
					complex x=a[j+k],y=w*a[j+mid+k];
					a[j+k]=x+y;
					a[j+mid+k]=x-y;
				}
			}
		}
	}
	
	vector<int>fft(vector<int>f,vector<int>g){	// f[0] g[0] ´ú±íµÍÎ»  
		int n=f.size(),m=g.size();
		--n, --m;
		int len=0;
		lim=1;
		while(lim<=n+m)lim<<=1,++len;
		for(int i=0;i<=lim;i++)r[i]=(r[i>>1]>>1)|((i&1)<<(len-1));
		for(int i=0;i<=n;i++)a[i].x=f[i];
		for(int i=0;i<=m;i++)b[i].x=g[i];
		
		dft(a,1);dft(b,1);
		for(int i=0;i<=lim;i++)a[i]=a[i]*b[i];
		dft(a,-1);
		
		vector<int>res;
		for(int i=0;i<=n+m;i++)res.pb((int)(a[i].x/lim+0.5));
		return res;
	}
}

vector<int>f,g;
signed main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0,x;i<=n;i++)scanf("%d",&x),f.pb(x);
	for(int i=0,x;i<=m;i++)scanf("%d",&x),g.pb(x);
	
	vector<int>res = fft::fft(f,g);
	for(int i=0;i<res.size();i++)printf("%d ",res[i]);

	return 0;
}

