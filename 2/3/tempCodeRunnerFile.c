else if(s[2]=='m')
        {
            int status;
            node *final=NULL;
            scanf("%d",&data);
            status=remove_node(&head,data,&final);
            head=final;
            if(status)
                traverse(&head);
            else
                printf("ELEMENT NOT FOUND\n");
        }