#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node{
	int data;
	struct Node* next;
};
struct Node* head = NULL;
struct Node* tail = NULL;
struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
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
		tail = newNode; 
	}
}
void display(){
	struct Node* trav = head;
	while(trav!= NULL){
	printf("%d -> ",trav->data);
	trav = trav->next;
	}
	printf("NULL");
}
void deleteNode(){
	int val;
	printf("Enter the node that you want to delete:");
	scanf("%d",&val);
	struct Node* trav = head;
	struct Node* prev = NULL;
	while(trav != NULL && trav->data!=val){
		prev = trav;
		trav = trav->next;
	}
	if(trav == NULL){
		printf("\nThe Node is not valid");
	}
	else if(trav == head){
		head = trav->next;
		free(trav);
	}
	else if(trav==tail){
		tail = prev;
		tail->next = NULL;
		free(trav);
	}
	else{
		prev->next = trav->next;
	}
	
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
		if(trav == NULL){
			printf("Node not found");
		}	
		if(trav == tail){
			tail = newNode;
			trav->next = tail;
			tail->next = NULL;
		}
		else{
			newNode->next = trav->next;
			trav->next = newNode;			
		}	
}
void deleteAllInstances(){
	int val;
	printf("Enter the node that you want to delete:");
	scanf("%d",&val);
	struct Node* trav = head;
	struct Node* prev = NULL;
	while(trav != NULL){
		if(trav->data == val){
			if(trav == head){
				head = trav->next;
				free(trav);
				trav =head;
			}
			else if(trav == tail){
				tail = prev;
				tail->next = NULL;
				free(trav);
				trav = tail;
			}
			else if {// if there is any other node other than tail and head
				prev->next = trav->next;
				free(trav);
				trav = prev->next;
			}
		}
		else{
			prev= trav;
			trav = trav->next;
		}
	}
}
int findmin(){
	if(head == NULL){
		printf("The List is empty");
		return -1;
	}
	int min = head->data;
	struct Node* temp = head;
	while(temp != NULL){
		if(temp->data < min){
			min = temp->data;
		}
		temp = temp->next;
	}
	return min;
}
int findmax(){
	if(head == NULL){
		printf("The List is empty");
		return -1;
	}
	int max = head->data;
	struct Node* temp = head;
	while(temp != NULL){
		if(temp->data > max){
			max = temp->data;
		}
		temp = temp->next;
	}
	return max;
}
void reverseLL(){
	struct Node* current = head;
	struct Node* prev = NULL;
	struct Node* next = NULL;
	while(current != NULL){
		next = current->next;  
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}
float findaverage(){
	int count = 0;
	float sum = 0;
	struct Node* trav = head;
	while(trav != NULL){
		sum = sum + trav->data;
		count++;
		trav = trav->next;
	}
	float average = sum/count;
	return average;
}
float findvariance(int mean){
	double variance = 0;
	int count = 0;
	struct Node* temp = head;
	while(temp != NULL){
		variance = variance + pow((temp->data - mean),2);
		count ++;
		temp = temp->next;
		return variance/count;
	}
}
float findSD(float variance){
	return sqrt(variance);
}
int main(){
	appendNode(1);
	appendNode(2);
	appendNode(3);
	appendNode(4);
	appendNode(5);
	appendNode(6);
	appendNode(7);
	appendNode(8);
	deleteNode();
	insert();
	display();
	reverseLL();
	display();
}



