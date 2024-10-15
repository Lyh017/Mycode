#include<stdio.h>
 
 //冒泡排序
 void bubbleSort(int a[],int sz)
 {
	for(int i=0;i<sz-1;i++)
	{
		for(int j=0;j<sz-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int tmp=a[j+1];
				a[j+1]=a[j];
				a[j]=tmp;
			}
		}
	}
 }

 //插入排序
 void insertSort(int a[],int sz)
 {
	for(int i=0;i<sz-1;i++)
	{
		int end=i;
		int tmp=a[end+1];
		while(end>=0)
		{
			if(a[end]>tmp)
			{
				a[end+1]=a[end];
				end--;
			}
			else{
				break;
			}
		}
		a[end+1]=tmp;
	}
 }

void quickSort(int a[],int left,int right)
{
	if(left>=right)
	{
		return;
	}
	int begin=left;
	int end=right;
	int pivot=begin;
	int key=a[begin];
	while(begin<end)
	{
		while(begin<end && a[end]>=key)
		{
			end--;
		}
		a[pivot]=a[end];
		pivot=end;

		while(begin<end && a[begin]<=key)
		{
			begin++;
		}
		a[pivot]=a[begin];
		pivot=begin;
	}
	pivot=begin;
	a[pivot]=key;

	quickSort(a,left,pivot-1);
	quickSort(a,pivot+1,right);
}

void move(int a,char n,char m)
{
	printf("把第%d个盘子从 %c->%c\n",a,n,m);
}

void Hanoi(int n,char pos1,char pos2,char pos3)
{
	if(n==1)
	{
		move(n,pos1,pos3);
	}
	else
	{
		
		Hanoi(n-1,pos1,pos3,pos2);
		move(n,pos1,pos3);
		Hanoi(n-1,pos2,pos1,pos3);
	}

}

 int main()
 {
	int a[]={4,7,8,5,3,1,2,9,0,6};
	int sz=sizeof(a)/sizeof(a[0]);
	//bubbleSort(a,sz);
	//insertSort(a,sz);
	quickSort(a,0,sz-1);
	for(int i=0;i<sz;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

	Hanoi(3,'A','B','C');
 }