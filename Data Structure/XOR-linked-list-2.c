#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define XOR(a, b) (list *)((intptr_t)(a) ^ (intptr_t)(b))

typedef struct _list
{
    int val;
    struct _list *link;
} list;

list *insertHead(list *head, int data)
{
    list *newNode = malloc(sizeof(list));
    newNode->val = data;

    // 空的 XOR Linked List
    if (head == NULL)
    {
        newNode->link = NULL;
    }
    else
    {
        /* Update original link of head node */
        head->link = XOR(XOR(NULL,head->link), newNode);
        newNode->link = XOR(head, NULL);
    }
    head = newNode;
    return head;
}

list *deleteHead(list *head)
{
    if (!(head))
        return head;

    list *neigher = XOR((head)->link, NULL);
    /* Update the link of new head */
    if (neigher)
        neigher->link = XOR(XOR((head), neigher->link), NULL);
    free(head);
    head = neigher;
    return head;
}

void printXorList(list *head)
{
    if (!head)
        return;

    list *prev = NULL;
    while (head)
    {
        list *tmp = head;
        printf("%d ", head->val);
        head = XOR(prev, head->link);
        prev = tmp;
    }
    printf("\n");
}

int main()
{
    list *head = NULL;
    head = insertHead(head, 1);
    printXorList(head);
    head = insertHead(head, 2);
    printXorList(head);
    head = insertHead(head, 3);
    printXorList(head);
    head = deleteHead(head);
    printXorList(head);
    return 0;

}