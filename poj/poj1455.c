main(n,t){
for(scanf("%d%d",&t,&n);t;(--t)&&scanf("%d",&n))printf("%d\n",(n>>1)*((n-1)>>1));
}
