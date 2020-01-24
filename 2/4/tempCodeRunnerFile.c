node* pCrawl = graph->adjlist[v]; 
        printf("\n Adjacency list of vertex %d\n head ", v+1); 
        while (pCrawl) 
        { 
            printf("-> %d", pCrawl->data+1); 
            pCrawl = pCrawl->next; 
        } 
        printf("\n"); 