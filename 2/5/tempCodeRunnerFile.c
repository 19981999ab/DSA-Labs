node* pCrawl = graph->adjlist[i]; 
        
        while (pCrawl) 
        { 
            printf("-> %d", pCrawl->data+1); 
            pCrawl = pCrawl->next; 
        } 
        printf("\n"); 