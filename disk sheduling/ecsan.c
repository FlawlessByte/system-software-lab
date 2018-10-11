#include<stdio.h>
int diff(int,int);
int main(){

	int m=0,arr[100],headpos,avgs=0,seektime=0,queue[200],n,i,j,temp,range,start,pre,aft;
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
			pre=i;
			aft=i+1;
			break;
		}
	}
//will find the smaller direction

	if(diff(queue[i],headpos)<diff(queue[i+1],headpos))
	{
		//will go in left dir.
		for(j=pre;j>=0;j--)
		{
			seektime+=diff(headpos,queue[j]);
				//	printf("seektime\n:%d",seektime);
			headpos=queue[j];
			if(queue[j]!=0)
				arr[m++]=queue[j];
		}
		seektime+=diff(headpos,0);
	//	printf("first for loop seektime:%d",seektime);
		headpos=range;
		for(j=n-1;j>=aft;j--)
		{
			seektime+=diff(headpos,queue[j]);
	//		printf("j:%d",j);
			headpos=queue[j];
			if(queue[j]!=0)
				arr[m++]=queue[j];
		}
		//printf("second  for loop seektime:%d",seektime);
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
		for(j=aft;j<n;j++)
		{
			seektime+=diff(headpos,queue[j]);
			headpos=queue[j];
			arr[m++]=queue[j];
		}
		seektime+=diff(range,queue[j-1]);
		headpos=0;
		for(j=0;j<=pre;j++)
		{
			seektime+=diff(headpos,queue[j]);
			headpos=queue[j];
			arr[m++]=queue[j];
		}
		printf("\nthe total seektime in right direction:%d\n",seektime);
		avgs=seektime/n;
		printf("the average seektime :%d",avgs);
		printf("\nthe direction of movement of headposition:\n");
		for(i=0;i<m;i++)
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
