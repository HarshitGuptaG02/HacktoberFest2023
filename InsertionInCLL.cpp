#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

int size = 0;
void insert(Node** head, int data){
    
    Node* newNode = new Node();
    newNode->data = data;
    
    // if its the first node being entered
    if(*head == NULL){
        *head = newNode;
        (*head)->next = *head;
        size++;
        return;
    }
    
    // if Circular Linked List had >=1 node
    Node* curr = *head;
    
    // traverse till last node in Circular Linked List
    while(curr->next != *head){
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->next = *head;
    *head = newNode;
    
    size++;
}
void insertMiddle(Node** head, int data){
    
    Node* newNode = new Node();
    newNode->data = data;
    
    // if the LL was empty
    if(*head == NULL){
        // use insert function to insert
        insert(head, data);
        return;
    }
    
    // otherwise
    Node* temp = *head;
    
    // find correct insertion position for middle
    int mid = (size % 2 == 0) ? (size/2) : (size+1)/2;
    
    // Unique case when there is only one node in CLL
    // we will be inserting at the last, 
    // inserting 2nd node at the last
    // Example size = 1 will result in mid = 1 so entering after 1st node
    // where size itself is 1 so entering last node
    if(mid == size){
        newNode->next = *head;
        (*head)->next = newNode;
        size++;
        return;
    }
    // traverse to current mid position
    while(--mid){
        temp = temp->next;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    size++;
}

void display(Node* head){
    // if there are no node in LL
    if(head == NULL)
        return;
    cout << "Linked List: ";
    Node* temp = head;
    
    //need to take care of circular structure of LL
    do{
        cout <<temp->data << " "; 
        temp = temp->next;
        
    }while(temp!=head);
    cout << "\n" << endl;
}

int main()
{
    Node* head = NULL;

    insert(&head,20);
    insert(&head,4);

    display(head); 

    insertMiddle(&head, 8);
    display(head); 

    insertMiddle(&head, 16);
    display(head); 
    
    insertMiddle(&head, 12);
    display(head); 

    return 0; 
}
