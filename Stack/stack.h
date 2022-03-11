typedef struct stack
{
    int top;  // 下一個可以使用的 element idx
    char elements[100];
} Stack;

void init_stack(Stack *s);
int stack_full(Stack *s);
int stack_empty(Stack *s);
void push_stack(Stack *s, char c);
char pop_stack(Stack *s);