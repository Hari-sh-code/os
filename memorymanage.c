#include<stdio.h>
#include<math.h>

#define size 8

main()
{
	int frame[size],pt[size];
	int n,i=0,r;
	
	for (i = 0;i<size;i++)
	{
		frame[i]=-1;
		pt[i]=-1;
	}
	
	printf("Enter the number of pages: ");
	scanf("%d",&n);
	
	i=0;
	while(1)
	{
		r = rand()%size;
		if(frame[r]==-1)
		{
			pt[i] = r;
			frame[r]=i;
			i++;
		}
		if(i==n)
			break;
	}
	printf("\nPhysical memory (Frame index -> Page number)");
	for(i=0;i<size;i++)
	{
		if(frame[i]==-1)
			printf("\n\t %d -> %d",i,frame[i]);
		
		else
			printf("\n\t %d -> Page %d",i,frame[i]);
	}
	printf("\nPage table (Page number -> Frame index)");
	for (i=0;i<n;i++)
		printf("\n\t %d -> %d",i,pt[i]);
}		
