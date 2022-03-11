#include <stdio.h>
#include "stack.h"
void init_stack(Stack *s)
{
  s->top = 0;
}
int stack_full(Stack *s)
{
  return(s->top >= 100);
}
int stack_empty(Stack *s)
{
  return(s->top <= 0);
}
void push_stack(Stack *s, char i)
{
  if (stack_full(s)) {
    printf("stack is full\n");
    return;
  }
  s->elements[s->top] = i;
  s->top++;
}
char pop_stack(Stack *s)
{
  if (stack_empty(s)) {
    printf("stack is empty\n");
    return(-1);
  }
  s->top--;
  return(s->elements[s->top]);
}