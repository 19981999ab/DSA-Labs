void push(node** head, int new_data) 
{ 
	node* new_node = (node*)malloc(sizeof(node)); 
	new_node->data = new_data; 
	new_node->next = (*head); 
	(*head) = new_node; 
}