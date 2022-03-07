#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define N 100

// 使用者可以要求某一塊由start開始，長度為size的的記憶體

typedef struct freeBlock
{
    int start;
    int length;
    struct freeBlock *next;
} FreeBlock;

// 建立FreeBlock節點
FreeBlock *getFreeBlock(int start, int length, FreeBlock *next)
{
    FreeBlock *block = (FreeBlock *)malloc(sizeof(FreeBlock));
    block->start = start;
    block->length = length;
    block->next = next;
    return block;
}

void initMemory(FreeBlock **head, int length) // 藉由傳指標變數的位址在function中直接賦予或變更該指標變數儲存的內容
{
    assert(length > 0);
    // 將head指到一個只有一個freeBlock的linked list起點
    *head = getFreeBlock(0, length, NULL);
}

// start為要求記憶體的起點，length為要求記憶體長度
void allocateMemory(FreeBlock **head, int start, int length)
{
    FreeBlock *current = *head;
    FreeBlock *before = NULL;
    assert(current != NULL);

    // 找出包含start的freeBlock
    while (!((start >= current->start) && (start < current->start + current->length)))
    {
        before = current;
        current = current->next;
        assert(current != NULL);
    }
    printf("current node記憶體位址: %p\n", current);

    int beginSame = (start == current->start);
    int endSame = (start + length == current->start + current->length);
    
    // start跟current有相同的起點跟終點
    if (beginSame && endSame)  
    {
        // 若current為linked list的第一個node
        if (before == NULL)
        {
            assert(current == *head);
            *head = current->next;
        }
        else
            before->next = current->next;
        free(current);
    }
    // start跟current有相同的起點
    else if (beginSame)
    {
        current->start += length;
        current->length -= length;
    }
    // start跟current有相同的終點
    else if (endSame)
    {
        current->length -= length;
    }
    // 在current node後面串一個freeBlock node
    else
    {
        FreeBlock *after = getFreeBlock(start + length, (current->start + current->length) - (start + length), current->next);
        current->next = after;
        current->length = start - current->start;
    }
}

// 將還可以使用的FreeBlock印出來
void printMemory(FreeBlock *head)
{
    FreeBlock *ptr = head;
    printf("==========\n");
    while (ptr != NULL)
    {
        printf("start %d, length %d\n", ptr->start, ptr->length);
        ptr = ptr->next;
    }
}

int main()
{
    FreeBlock *head = NULL;
    int memorySize;
    // 輸入記憶體大小
    scanf("%d", &memorySize);
    initMemory(&head, memorySize);
    printMemory(head);
    int n;
    // 輸入要幾塊記憶體block
    scanf("%d", &n);
    int start[N], size[N];
    for (int i = 0; i < n; i++)
    {
        // 輸入要的起始位置與長度
        scanf("%d%d", &(start[i]), &(size[i]));
    }
    for (int i = 0; i < n; i++)
    {
        allocateMemory(&head, start[i], size[i]);
        printMemory(head);
    }

    return 0;
}