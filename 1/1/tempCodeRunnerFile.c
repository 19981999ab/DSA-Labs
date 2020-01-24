int check=0;
    for(int i=0;i<r_inp-r_test+1;i++)
    {
        for(int j=0;j<c_inp-c_test+1;j++)
        {
            if(mat_inp[i][j]==mat_test[0])
            {
                check=0;
                for(int k=i;k<i+r_test;k++)
                {
                    for(int l=j;l<j+c_test;l++)
                    {
                        if(mat_inp[k][l]==mat_test[l])
                        {
                            check+=1;
                        }
                    }
                }
                printf("/n %d   %d", mat_inp[i][j],check);
                if(check==r_test*c_test)
                {
                    printf("YES");
                    exit(0);
                }
            }
        }
    }
    printf("NO"