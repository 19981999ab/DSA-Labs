 for(int i=1;i<10;i++)
    {
        int temp=hash[i];
        while(temp!=0)
        {
            if(hash[0]!=0)
            {
                smallest=i;
                while(hash[0]!=0)
                {
                    smallest*=10;
                    hash[0]--;
                }
            }
            else
            {
                smallest=smallest*10+i;
            }
            temp--;
        }
    }