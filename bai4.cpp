#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node {
	char data[100];
	struct Node* next;
} Node;
Node* createNode(char* value){
	Node* newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->data,value);
	newNode->next=NULL;
	return newNode;
}
void appendNode(Node** head,char* value){
	Node* newNode = createNode(value);
	if(*head == NULL){
		*head = newNode;
	} else {
		Node* temp = *head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
}
int searchNode(Node* head,char* key){
	int index = 0;
	Node* temp = head;
	while(temp != NULL){
		if(strcmp(temp->data, key) == 0){
			return index;
		}
		temp = temp->next;
		index++;
	}
	return -1;
}
void freeList(Node* head){
	Node* temp;
	while ( head != NULL){
		temp = head;
		head = head->next;
		free(temp);
	}
}
int main(){
	Node* head = NULL;
	int n;
	char value[100];
	char key[100];
	printf("nhap so phan tu ( 0 <= n <= 1000):");
	scanf("%d",&n);
	if(n < 0 || n > 1000){
		printf("so phan tu khong hop le:");
		return 1;
	}
	for ( int i = 0; i< n; i++){
		printf("nhap phan tu %d:",i + 1);
		scanf("%s",&value);
		appendNode(&head,value);
	}
	printf("nhap gia tri can tim:");
	scanf("%s",key);
	int result = searchNode(head,key);
	if( result != -1){
		printf("phan tu %s duoc tim thay tai vi tri %d.\n",key,result);
	}else {
		printf("phan tu %s khong ton tai trong danh sach.",key);
	}
	freeList(head);
	return 0;
}

