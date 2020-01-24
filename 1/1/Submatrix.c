#include<stdio.h>
#include <stdlib.h>

int main()
{
    int r_inp,c_inp;
    scanf("%d %d",&r_inp,&c_inp);

    int mat_inp[r_inp][c_inp];

    for(int i=0;i<r_inp;i++)
        for(int j=0;j<c_inp;j++)
        {
            scanf("%d",&mat_inp[i][j]);
        }
    for(int i=0;i<r_inp;i++)
    {
        for(int j=0;j<c_inp;j++)
        {
            printf("%d ",mat_inp[i][j]);
        }
        printf("\n");
    }
    int r_test,c_test;
    scanf("%d %d",&r_test,&c_test);

    if(r_test>r_inp || c_test>c_inp)
    {
        printf("Invalid Inputs");
        exit(0);
    }

    int mat_test[r_test][c_test];

    for(int i=0;i<r_test;i++)
        for(int j=0;j<c_test;j++)
        {
            scanf("%d",&mat_test[i][j]);
        }
    for(int i=0;i<r_test;i++)
    {
        for(int j=0;j<c_test;j++)
        {
            printf("%d ",mat_test[i][j]);
        }
        printf("\n");
    }
    int check=0;
    for(int i=0;i<r_inp-r_test+1;i++)
    {
        for(int j=0;j<c_inp-c_test+1;j++)
        {
            if(mat_inp[i][j]==mat_test[0][0])
            {
                check=0;
                for(int k=i;k<i+r_test;k++)
                {
                    for(int l=j;l<j+c_test;l++)
                    {
                        if(mat_inp[k][l]==mat_test[k-i][l-j])
                        {
                            check+=1;
                        }
                    }
                }
                if(check==r_test*c_test)
                {
                    printf("YES");
                    exit(0);
                }
            }
        }
    }
    printf("NO");
}