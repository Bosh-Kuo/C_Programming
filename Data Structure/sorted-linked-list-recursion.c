#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct listnode
{
    int data;
    struct listnode *next;
};

typedef struct listnode ListNode;

void print_linked_list(ListNode *head)
{
    if (head == NULL)
    { // 如果head為NULL表示head在linked list的最尾端，沒有存資料，因此印出換行
        printf("\n");
        return;
    }
    // 如果head不是在最尾端，就印出當前node的資料並且遞迴將next ptr做為參數傳入
    printf("data = %d\n", head->data);
    print_linked_list(head->next);
}

ListNode *insert_linked_list(ListNode *head, int data) // head代表linked list從哪裡開始找
{
    ListNode *current = (ListNode *)malloc(sizeof(ListNode));
    assert(current != NULL);
    current->data = data;
    if (head == NULL || data < head->data) // 如果什麼資料都還沒有，或是current node比head還要小，則current必須成為linked list的新起點並回傳起點node
    {
        current->next = head;
        return (current);
    }
    head->next = insert_linked_list(head->next, data); // 否則將目前head的next node作為新起點再call一次function，並將目前的head在接上新的linked list
    return (head);
}

ListNode *delete_linked_list(ListNode *head, int data)  // head代表linked list從哪裡開始找
{
    ListNode *temp;
    if (head == NULL)  // 如果什麼資料都還沒有，就回傳原本的head，也就是NULL回去
        return NULL;
    if (data == head->data)  // 如果當前的head的資料就是要刪除的資料，先把next存起來，釋放head指向的空間，然後回傳next
    {
        temp = head->next;
        free(head);
        return (temp);
    }
    head->next = delete_linked_list(head->next, data);  // 如果當前的head不是要刪掉的node，就遞迴call function將next作為新的head傳進function，並將原本的next接上新的Linked list
    return (head);
}

void freeLinkedList(ListNode *node)
{
    if (node == NULL)
        return;
    freeLinkedList(node);
    free(node);
}

int main(void)
{
    int i;
    int insert_keys[5];
    int delete_keys[3];
    for (i = 0; i < 5; i++)
        scanf("%d", &(insert_keys[i]));
    for (i = 0; i < 3; i++)
        scanf("%d", &(delete_keys[i]));
    ListNode *head = NULL;
    for (i = 0; i < 5; i++)
        head = insert_linked_list(head, insert_keys[i]);
    print_linked_list(head);
    for (i = 0; i < 3; i++)
        head = delete_linked_list(head, delete_keys[i]);
    print_linked_list(head);
    return 0;
}