#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void insert_end(int val){
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));

    temp->data = val;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    return;
}

void delete_end(){
    struct node *ptr = head;
    struct node *p;

    if (head->next == NULL)
    {
        head = NULL;
        free(ptr);
        return;
    }
    while(ptr->next != NULL){
        p = ptr;
        ptr = ptr->next;
    }
    p->next = NULL;
    free(ptr);
    return;
}

void insert_first(int val){
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));
    temp->data=val;
    temp->next=head;
    head=temp;
}

void delete_first(){
    struct node *ptr = head;
    head = ptr->next;
    free(ptr);
}

void insert_mid(int num,int pos){
    struct node *ptr = head;
    struct node *p;

    struct node *temp = malloc(sizeof(struct node));
    temp->data = num;
    temp->next = NULL;

    while (ptr->data != pos)
    {
        p = ptr;
        ptr = ptr->next;
    }
    p->next=temp;
    temp->next=ptr;
}

void delete_mid(int pos){
    struct node *ptr=head;
    struct node *p;

    while (ptr->data!=pos)
    {
        p=ptr;
        ptr=ptr->next;
    }

    p->next = ptr->next;
    free(ptr);
}

void display(){
    struct node *ptr = head;

    if (head == NULL)
    {
        printf("Already empty");
    }else
    {
        while (ptr!= NULL)
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n\n");
}

int main() {
    int choice, val, pos;

    while (1) {
        printf("Linked List Operations:\n");
        printf("1. Insert at the end\n");
        printf("2. Delete from the end\n");
        printf("3. Insert at the beginning\n");
        printf("4. Delete from the beginning\n");
        printf("5. Insert at a specific position\n");
        printf("6. Delete from a specific position\n");
        printf("7. Display list\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at the end: ");
                scanf("%d", &val);
                insert_end(val);
                break;

            case 2:
                delete_end();
                break;

            case 3:
                printf("Enter value to insert at the beginning: ");
                scanf("%d", &val);
                insert_first(val);
                break;

            case 4:
                delete_first();
                break;

            case 5:
                printf("Enter value to insert and position to insert at: ");
                scanf("%d %d", &val, &pos);
                insert_mid(val, pos);
                break;      

            case 6:
                printf("Enter position to delete from: ");
                scanf("%d", &pos);
                delete_mid(pos);
                break;

            case 7:
                printf("Linked List: ");
                display();
                break;

            case 8:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
