#include<stdio.h>
#include<math.h>
main()
 {int n,a[20],i;
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		scanf("%x",&a[i]);
	}
	for(i=0;i<=n-1;i++)
	{
	    printf("%o\n",a[i]); 
	}
	
}
