#include<stdio.h>

int check_prime();
void update_hash_array();

void main()
{
    long int num1,num2;
    long int hash_array[10];
    for(int i=0;i<10;i++)
        hash_array[i]=0;

    scanf("%d %d",&num1,&num2);
    int count=0;
    for(int i=num1;i<=num2;i++)
    {
        if(check_prime(i))
        {
            printf("%d ",i);
            update_hash_array(hash_array,i);
            count+=1;
        }
    }
    long int max=-1,max_index;
    for(long int i=0;i<10;i++)
    {
        printf("\n%d %d",i,hash_array[i]);
        if(hash_array[i]>max)
        {
            max_index=i;
            max=hash_array[i];
        }
    }
    printf("\n%d %d",max_index,max);
    printf("\n%d",count);
}

int check_prime(int n)
{
    if(n<=1) return 0;
    if(n<=3) return 1;
    if(n%2==0||n%3==0) return 0;
    for(int i=5;i*i<=n;i+=6)
    {
        if(n%i==0||n%(i+2)==0)
            return 0;
    }
    return 1;

}
void update_hash_array(int *arr,int num)
{
    for(;num!=0;num/=10)
    {
        *(arr+num%10)+=1;
    }
}