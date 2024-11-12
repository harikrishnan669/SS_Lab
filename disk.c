#include<stdio.h>
#include<stdlib.h>

int arr[25],n,max,intial,small;

void sort(int arr[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void fcfs()
{
    int seek,i;
    seek=abs(arr[0]-intial);
    for(i=0;i<n-1;i++)
    {
        seek+=abs(arr[i+1]-arr[i]);
    }
    printf("\ntotal seek time in fcfs scheduling is: %d",seek);
}

void scanr()
{
    sort(arr,n);
    int small=arr[0];
    int seek=abs(max-intial)+abs(max-small);
    printf("\ntotal seek time in scan right direction scheduling is: %d",seek);
}
void scanl()
{
    sort(arr,n);
    int large=arr[n-1];
    int seek=intial+large;
    printf("\ntotal seek time in scan left direction scheduling is: %d",seek);
}
void cscanr()
{
    sort(arr,n);
    int preceeding=arr[0],i;
    for(i=0;i<n;i++)
    {
        if(arr[i]>intial)
        {
            break;
        }
        preceeding=arr[i];
    }
    int seek=abs(intial-max)+max+preceeding;
    printf("\ntotal seek time in cscan right direction scheduling is: %d",seek);
}
void cscanl()
{
    sort(arr,n);
    int preceeding=arr[0],i;
    for(i=0;i<n;i++)
    {   
        preceeding=arr[i];
        if(arr[i]>intial)
        {
            break;
        }

    }
    int seek=abs(intial-max)+max+preceeding;
    printf("\ntotal seek time in cscan right direction scheduling is: %d",seek);
}



int main()
{
    printf("Enter the no of request: ");
    scanf("%d",&n);
    printf("Enter the requests ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the max size of disc: ");
    scanf("%d",&max);
    printf("Enter the initial positon of disk head");
    scanf("%d",&intial);
    fcfs();
    scanr();
    scanl();
    cscanr();
    cscanl();
}