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
    for (; head != NULL; head = head->next)
        printf("data = %d\n", head->data);
}

void freeLinkedList(ListNode *node)
{
    while (node != NULL)
    {
        ListNode *nextNode = node->next;
        free(node);
        node = nextNode;
    }
}

int main(void)
{
    int i;
    int array[5];
    ListNode *head;
    ListNode *previous = NULL;

    for (i = 0; i < 5; i++)
        scanf("%d", &(array[i]));
    
    // 逆著next方向加入數字，從linked list的尾端開始加入資料
    for (i = 0; i < 5; i++)
    {
        head = (ListNode *)malloc(sizeof(ListNode)); // head 指向一塊新要求的空間
        assert(head != NULL);
        head->data = array[i]; // 將data[i] assign給head node
        // 將當下這個node的next指向前一個node，由於最尾端沒有下個node所以一開始previous為NULL
        // head永遠指向最新的node
        head->next = previous; 
        previous = head;
    }
    // array = {1,2,3,4,5}
    // Node1: 1, next:NULL      head->1->NULL
    // Node2: 2, next:Node1     head->2->1->NULL
    // Node3: 3, next:Node2     head->3->2->1->NULL
    // Node4: 4, next:Node3     head->4->3->2->1->NULL
    // Node5: 5, next:Node4     head->5->4->3->2->1->NULL
    print_linked_list(head);
    return 0;
}