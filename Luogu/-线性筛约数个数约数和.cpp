int n,pr[N],vis[N],d[N],sigma[N],cnt;
void make(int n)
{
    d[1] = sigma[1] = 1;
    for(int i = 2;i<=n;i++)
    {
        if(!vis[i])pr[++cnt] = i,d[i] = 2,sigma[i] = i+1;
        for(int j = 1;i*pr[j]<=n&j<=cnt;j++)
        {
            vis[i*pr[j]] = 1;
            d[i*pr[j]] = d[i]<<1;
            sigma[i*pr[j]] = sigma[i]*(pr[j]+1);
            if(i%pr[j]==0)
            {
                d[i*pr[j]]-=d[i/pr[j]];
                sigma[i*pr[j]]-=pr[j]*sigma[i/pr[j]];
                break;
            }
        }
    }
}
