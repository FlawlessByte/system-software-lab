#include<stdio.h>
int diff(int,int);
int main()
{
	int start,queue[200],i,j,seektime=0,headpos,avgs=0,temp,range,n,arr[100],m=0;
	printf("enter the head position:");
	scanf("%d",&headpos);
	printf("enter the size of queue:");
	scanf("%d",&n);
	printf("enter the range:");
	scanf("%d",&range);
	printf("enter the queue elements:");
	for(i=0;i<200;i++)
	{
		queue[i]=0;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&queue[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(queue[i]>=queue[j])
			{
				temp=queue[i];
				queue[i]=queue[j];
				queue[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(queue[i]<headpos && queue[i+1]>=headpos)
		{
			break;
		}
	}
	//printf("the element is in between %d and %d\n",queue[i],queue[i+1]);
	//will find the smaller direction

	if(diff(queue[i],headpos)<diff(queue[i+1],headpos))
	{
		start=i;
	
		for(j=i;j>=0;j--)
		{
			seektime+=diff(headpos,queue[j]);
//				printf("seektime:%d",seektime);
			headpos=queue[j];
			arr[m++]=queue[j];
		}
		seektime+=diff(queue[j+1],0);
		headpos=0;
		seektime+=diff(headpos,queue[i+1]);
		headpos=queue[i+1];
		//printf("the test seektime:%d",seektime);
		for(j=i+1;j<n;j++)
		{
			seektime+=diff(headpos,queue[j]);
				printf("seektime:%d",seektime);			
			headpos=queue[j];
			arr[m++]=queue[j];
		}
		//seektime+=diff(range,queue[j-1]);
		printf("\nthe total seektime in left direction:%d\n",seektime);
		avgs=seektime/n;
		printf("the average seektime :%d",avgs);
		printf("\nthe direction of movement of headposition:\n");
		for(i=0;i<m;i++)
		{
			printf("%d-->",arr[i]);
		}
	}
	else
	{
		start=i+1;
		for(j=start;j<n;j++)
		{
			seektime+=diff(headpos,queue[j]);
			headpos=queue[j];
			arr[m++]=queue[j];
		}
		seektime+=diff(queue[j-1],range);
		headpos=range;
			seektime+=diff(range,queue[i]);
		headpos=queue[i];
		for(j=i;j>=0;j--)
		{
			seektime+=diff(headpos,queue[j]);
			headpos=queue[j];
			arr[m++]=queue[j];
		}
		printf("\nthe total seektime in right direction:%d\n",seektime);
		avgs=seektime/n;
		printf("the average seektime:%d",avgs);
		printf("\nthe direction of movement of headposition:\n");
		for(i=0;i<n;i++)
		{
			printf("%d-->",arr[i]);
		}
	}
}
int diff(int a,int b)
{
	if(a<b)
		return(b-a);
	else
		return(a-b);
}
