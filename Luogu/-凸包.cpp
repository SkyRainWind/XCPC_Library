int is(point a,point b){return a.x==b.x?a.y<b.y:a.x<b.x;}

for(int i=1;i<=n;i++)cin>>p[i].x>>p[i].y;
sort(p+1,p+n+1,[&](point a,point b){return a.x==b.x?a.y<b.y:a.x<b.x;});

int cnt=0;
#define pd(A,B,C) (cross((C-B),(B-A))>0||(cross((C-B),(B-A))==0&&is(A,B)==is(B,C)))
int i;for(i=1;i<=n;all[++cnt]=i++) while(cnt>1&&pd(p[all[cnt-1]],p[all[cnt]],p[i])) --cnt;
for(i=n-1;i;all[++cnt]=i--) while(cnt>1&&pd(p[all[cnt-1]],p[all[cnt]],p[i])) --cnt;--cnt;
