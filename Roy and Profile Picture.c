main()
{
	int l,i,n,h[1000],w[1000];
	scanf("%d",&l);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d\t%d",&w[i],&h[i]);
	}
	for(i=0;i<n;i++)
	{
		if(w[i] < l || h[i] < l)
		{
			printf("UPLOAD ANOTHER\n");
		}
		else
		{
			if(w[i] == h[i])
			{
				printf("ACCEPTED\n");
			}
			else
			{
				printf("CROP IT\n");
			}
		}
	}
}
