typedef struct listnode{
    char data;
    struct listnode *next;
} ListNode;

typedef struct stack {
    ListNode *top;
}Stack;

void init_stack(Stack *s);
int stack_full(Stack *s);
int stack_empty(Stack *s);
void push_stack(Stack *s, char c);
char pop_stack(Stack *s);