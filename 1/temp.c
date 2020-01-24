#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int* func(int *arr,int n)
{
    static int arr_temp[4];
    int* dynamic_arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        // *(arr+i)+=1;
        // arr_temp[i]=i;
        dynamic_arr[i]=i*i;
    }
    return dynamic_arr;
}
int main(){
    int arr[] = {5,1,2,3};
    int *arr1;
    arr1=func(arr,8);
    printf("%d\n",arr[1]);
    printf("%d\n",arr1[7]);

}