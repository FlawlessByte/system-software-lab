#include<stdio.h>
int diff(int,int);
int main(){

	int m=0,arr[100],headpos,avgs=0,seektime=0,queue[200],n,i,j,temp,range,start;
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
			//printf("the element is in between %d and %d\n",queue[i],queue[i+1]);
			start=i+1;
			break;
		}
	}
	
	for(i=start;i<n;i++)
	{

		seektime+=diff(headpos,queue[i]);
		headpos=queue[i];
		arr[m++]=queue[i];
	}
	seektime+=diff(queue[i-1],range);
	//seektime+=diff(range,0);
	headpos=0;
	for(i=0;i<start;i++)
	{
		seektime+=diff(headpos,queue[i]);
		headpos=queue[i];
		arr[m++]=queue[i];
	}
	printf("the total seektime is :%d",seektime);
	avgs = seektime/n;
	printf("\n Average Seek time : \t%d\n",avgs);
	printf("\n---the movement of diskhead---\n");
	for(i=0;i<m;i++)
		printf("%d-->",arr[i]);
}
int diff(int a,int b)
{
	if(a<b)
		return(b-a);
	else
		return(a-b);
}
