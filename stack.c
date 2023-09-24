#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct node
{
  int value;
  struct node* prev;
}
node;

int peek(node** head);
int pop(node** head, int *length);
int push(node **head, int value, int *length);
int print_stack(node** head);

int main(void) 
{    
  node *head = NULL;
  int length = 0;

  for (int i = 1; i <= 10; i++)
  {
    push(&head, i, &length);
  }

  print_stack(&head);
  printf("Length is %i\n", length);


  for (int i = 0; i < 12; i++)
  {
    int value = pop(&head, &length);

    if (value == -1) 
    {
      return 1;
    }
    printf("Value %i was popped. \n", value);
  }

  print_stack(&head);
  printf("Length is %i\n", length);

  return 0;
}

int print_stack(node** head)
{
  node* ptr = *head;
  while (ptr != NULL)
  {
    printf("%i ", ptr->value);
    ptr = ptr->prev;
  }

  printf("\n");
  return 0;
}

int pop(node **head, int *length)
{
  if (*length == 0)
  {
    printf("List is empty! \n");
    return -1;
  }

  node *h = (*head);
  (*head) = h->prev;
  (*length)--;

  return h->value;
}

int push(node** head, int value, int *length)
{
  (*length)++;
  
  node* n = malloc(sizeof(node));
  if (n == NULL)
  {
    return 1;
  }

  n->value = value;
  n->prev = *head;

  if (*head == NULL)
  {
    *head = n;
  }
  else 
  {
    n->prev = *head;
    *head = n;
  }

  return 0;   
}
