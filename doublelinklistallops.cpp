#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};
struct Node* head = NULL;
struct Node* tail = NULL;

struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->next = NULL;
	newNode->data = data;
	newNode->prev = NULL;
	return newNode;
}
void appendNode(int data){
	struct Node* newNode = createNode(data);
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}
	else{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}
void deleteNode(){
	int val;
	printf("Enter the node that you want to delete:");
	scanf("%d",&val);
	struct Node* trav = head;
	while(trav != NULL && trav->data!=val){
		trav = trav->next;
	}
	if(trav == head){
		head = trav->next;
		free(trav);
	}	
	else{
		trav->prev->next = trav->next; 
	}
	if(trav == tail){
		tail = trav->prev;
		tail->next = NULL;
	}
	else{
		trav->next->prev = trav->prev;
	}
	free(trav);
}
void insert(){
	int val, key;
	printf("Enter the Node you want to Insert: ");
	scanf("%d",&val);
	printf("Enter the Node after which you want to insert: ");
	scanf("%d",&key);
	struct Node* trav = head;
	while(trav->data != key && trav != NULL){
		trav = trav->next;
	}
		struct Node* newNode = createNode(val);
		newNode->next = trav->next;
		newNode->prev = trav;
		if(trav->next!=NULL){
			trav->next->prev = newNode;
		}	
		
		trav->next = newNode;
		if(trav == tail){
			tail = newNode;
			tail->next = NULL; 
		}
}
void reverseLL(){
	struct Node* current = head; // for traversal
	struct Node* temp; // for swaping the nodes
	while(current!=NULL){
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	if(temp != NULL ){
		head = temp->prev;
	}
	printf("List Reversed!\n");
}
void sortLL(){
	int swapped;
	struct Node* ptr1;
	struct Node* lptr = NULL;
	
	do{
		swapped = 0;
		ptr1 = head; // for each time the pass gets completed and it again reaches the head
		
		while(ptr1->next != lptr){
			if(ptr1->data > ptr1->next->data){
				int temp = ptr1->data;
				ptr1->data = ptr1->next->data;
				ptr1->next->data = temp;
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		// first pass has been completed and the last node is sorted
		lptr = ptr1;			
	}while(swapped); 
	printf("List Sorted!\n");
}
void deleteAllInstances(){
	int data;
	printf("Enter the node you want to delete: ");
	scanf("%d", &data);
	struct Node* trav = head;
	
	while(trav != NULL){
		if(trav->data == data){
			if(trav == head){
				head = trav->next;
				if(head == NULL){
					tail = NULL;
				}
				else{
					head->prev = NULL;
				}
				free(trav);
				trav = head;
			}
			else if(trav == tail){
				tail = tail->prev;
				if(tail == NULL){
					head = NULL;
				}
				else{
					tail->next = NULL;
				}
				free(trav);
				trav = tail;
			}
			else{
				trav->prev->next = trav->next;
				trav->next->prev = trav->prev;
				struct Node* temp = trav->next;
				free(trav);
				trav = temp;
			}		
		}
		else{
			trav = trav->next;
		}
	}
	printf("All instances of %d have been deleted.\n",data);
}
void display(){
	struct Node* trav = head;
	while(trav!=NULL){
		printf("%d <-> ",trav->data);
		trav = trav->next;
	}
	printf("NULL");
}

int main(){
	appendNode(1);
	appendNode(2);
	appendNode(5);
	appendNode(2);
	appendNode(6);
	appendNode(2);
	appendNode(8);

	deleteAllInstances();
	display();
}
