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

// 插入排序，將linked list順著next方向由小到大排列
ListNode *insert_linked_list(ListNode *head, int data)
{
    ListNode *current = (ListNode *)malloc(sizeof(ListNode));  // 建立一個新node
    ListNode *ptr;
    ListNode *last;
    assert(current != NULL);
    current->data = data;  // 將資料存進這個node
    if (head == NULL)
    {
        // 如果函式傳進來的head為NULL，表示linked list是空的，回傳current node
        current->next = NULL;
        return (current);
    }
    last = NULL;
    ptr = head;  // pointer從head開始
    while (ptr != NULL && ptr->data < data)  // 沿著當前的head順著next方，向往下找到第一個不小於要插入的current node的ptr與該node的last
    {
        last = ptr;
        ptr = ptr->next;
    }
    if (last == NULL)  // 如果while結束後找出來的last是NULL，代表要加入的資料是最小的，把current接到linked list的頭再回傳current
    {
        current->next = head;
        return (current);
    }
    else  // 否則將current node指向剛剛找到的第一個不小於current node的ptr，然後將前一個node指向自己
    { 
        current->next = last->next;
        last->next = current;
        return (head);
    }
}

int main(void)
{
    int i;
    int array[5];
    ListNode *head = NULL;

    for (i = 0; i < 5; i++)
        scanf("%d", &(array[i]));
    for (i = 0; i < 5; i++)
        head = insert_linked_list(head, array[i]);
    print_linked_list(head);
    return 0;
}