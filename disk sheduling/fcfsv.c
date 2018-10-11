#include<stdio.h>
int diff(int,int);
int main(){

	int m=0,arr[100],headpos,avgs=0,seektime=0,queue[200],n,i;
	printf("enter the head position:");
	scanf("%d",&headpos);
	printf("enter the size of queue:");
	scanf("%d",&n);
	printf("enter the queue elements:");
	for(i=0;i<200;i++)
	{
		queue[i]=0;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&queue[i]);
	}
	for(i=0;i<n;i++)
	{
		seektime+=diff(headpos,queue[i]);
		headpos=queue[i];
		arr[m++]=queue[i];
	}
	avgs=seektime/n;
	printf("\nthe direction of head movement:\n");
	for(i=0;i<n;i++)
	{
		printf("%d-->",arr[i]);
	}
	printf("\nthe total seektime is :%d\n",seektime);
	printf("\nthe average seektime is :%d\n",avgs);
}
int diff(int a,int b)
{
	if(a<b)
		return(b-a);
	else
		return(a-b);
}
