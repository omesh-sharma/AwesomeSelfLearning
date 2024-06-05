//====================================================

//            C Program STARTS

//====================================================



#include <stdlib.h>
#include <stdio.h>


struct Node {
    int data;
    struct Node* next;
};


// If you push only using this , then it will print the linklist in the reverse order.
void pushAtBegining(struct Node** headref, int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = data;
    new_node->next = (*headref);
    (*headref) = new_node;
}


void pushAtTheEnd(struct Node** headref, int data)
{

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = data;
    temp->next = NULL;

    if (*headref == NULL)
    {
        *(headref) = temp;
        return;
    }

    struct Node* curr = (*headref);
    while(curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = temp;

}

void printList(struct Node* head)
{
    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("%d\n", temp->data);

        temp = temp->next;
    }
}

//https://miro.medium.com/v2/resize:fit:1400/0*ZB971cjFJfkzQbJs
void reverseRecursive(struct Node** headref)
{
    // struct Node* curr, prev, next = NULL;
    // curr = (*headref);       
    struct Node* prev = NULL;
    struct Node* curr = *headref;
    struct Node* next = NULL;

    while(curr != NULL)
    {   
        // Let say 1->2->3->4->5

        // 2
        next = curr->next;

        // 1
        curr->next = prev;

        // 1
        prev = curr;

        // 2
        curr = next;
    }

    (*headref) = prev;
}

int main()
{
    struct Node* head = NULL;

    pushAtBegining(&head, 1);
    pushAtTheEnd(&head, 2);
    pushAtTheEnd(&head, 3);
    pushAtTheEnd(&head, 4);
    pushAtTheEnd(&head, 5);

    // pushAtBegining(&head, 20);
    // pushAtBegining(&head, 4);
    // pushAtBegining(&head, 15);
    // pushAtBegining(&head, 85);

    printList(head);

    reverseRecursive(&head);

    printList(head);



    return 0;
}





//====================================================

//            C Program ENDS

//====================================================