#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// XOR鏈結串列節點結構
typedef struct XorNode
{
    char data;
    struct XorNode *LRPtr;
} XorNode, *XorPointer;

// XOR指標雙向鏈結串列結構
typedef struct XorLinkedList
{
    XorPointer left, right;
} XorLinkedList;

// XOR操作
XorPointer xor (XorPointer a, XorPointer b) {
    return (XorPointer)((unsigned long)(a) ^ (unsigned long)(b));
}

// 建立 XOR 雙向鏈結串列，輸入連續 char
void createXorLinkedList(XorLinkedList *list) {
    char ch;
    XorPointer lastNode = NULL;
    int isFirstNode = 1;

    // 連續輸入 char 加入 傳入的 XOR Linked List
    while ((ch = getchar()) != '\n') {
        XorPointer newNode = (XorPointer) malloc(sizeof(XorNode));
        newNode -> data = ch;
        newNode -> LRPtr = NULL;

        // 若新增的 newNode 不是 XOR Linked List 的第一個 Node， lastNode 就會有值
        if (lastNode) {
            newNode -> LRPtr = xor(lastNode, NULL);
            lastNode -> LRPtr = xor(xor(lastNode -> LRPtr, NULL), newNode);  // lastNode 必定為 XOR Linked List 的 tail
        }
        lastNode = newNode;
        if (isFirstNode) {
            isFirstNode = 0;
            list -> left = newNode;
        }
    }
    list -> right = lastNode;
}

// 在第i個節點之前插入一個節點
void XorLinkedListInsert(XorLinkedList *list, int pos, char data) {
    XorPointer node = list -> left, tmp = NULL;
    XorPointer last = NULL;
    XorPointer newNode = NULL;
    int i = 1;
    while (i < pos && node != NULL) {
        tmp = node;
        node = xor(last, node -> LRPtr);
        last = tmp;
        i++;
    }
    newNode = (XorPointer) malloc(sizeof(XorNode));
    newNode -> data = data;
    newNode -> LRPtr = xor(last, node);
    if (node != NULL) {
        node -> LRPtr = xor(newNode, xor(last, node -> LRPtr));
    }
    if (last != NULL) {
        last -> LRPtr = xor(xor(last -> LRPtr, node), newNode);
    }
    if (pos == 1) {
        list -> left = newNode;
    }
}

// 刪除第i個節點
void XorLinkedListDelete(XorLinkedList *list, int pos) {
    XorPointer node = list -> left, last = NULL, next = NULL, tmp = NULL;
    int i = 1;
    while (i < pos && node != NULL) {
        i++;
        tmp = node;
        node = xor(last, node -> LRPtr);
        last = tmp;
    }
    next = xor(last, node -> LRPtr);
    if (last != NULL) {
        last -> LRPtr = xor(xor(last -> LRPtr, node), next);
    }
    if (next != NULL) {
        next -> LRPtr = xor(last, xor(node, next -> LRPtr));
    } else {
        list -> right = last; //删除了最后一个结点
    }
    if (pos == 1) {
        list -> left = next;
    }
    free(node);
}

// 按任意方向依次輸出各節點值， a或b可以是list.right or list.left, 但另一個一定要搭配NULL
void print(XorPointer a, XorPointer b) {
    XorPointer nullFirst = a == NULL ? a : b;
    XorPointer nonNullFirst = a != NULL ? a : b;
    XorPointer tmp = NULL;
    do {
        printf("%c ", nonNullFirst -> data);
        tmp = nonNullFirst;
        nonNullFirst = xor(nullFirst, nonNullFirst -> LRPtr);
        nullFirst = tmp;
    } while (nonNullFirst != NULL);
}


int main()
{
    XorLinkedList list;  // 建立一個空的 XOR Linked List
    createXorLinkedList(&list);
    print(list.right, NULL);
}