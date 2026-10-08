int count=0;

        if (n<0)
        {
            n = n*(-1);
            while (n>0)
            {
                int a=n%10;
                n = n-a;
                n = n/10;
                count++;

            };
        }
        else if (n==0)
        {
            count = 0;
        }
        else
        {
            while (n>0)
            {
                int a=n%10;
                n = n-a;
                n = n/10;
                count++;

            };
        }
        cout<<"number of digit :"<<count;