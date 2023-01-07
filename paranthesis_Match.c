#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    char *exp;
};
  
void push(struct stack *ptr, char val)
{
        ptr->top += 1;
        ptr->exp[ptr->top] = val;
}

void pop(struct stack *ptr)
{
        ptr->top -= 1;
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int paranthesis_match(char exp [])
{
    struct stack *st;
    st->size = 100;
    st->top = -1;
    st->exp = (char *)malloc(st->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(st, exp[i]);
        }
        if (exp[i] == ')')
        {
            if (isEmpty(st))
            {
                return 0;
            }
                pop(st);
        }
    }
    if (isEmpty(st))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    char str[100];
    gets(str);
    // char *exp = str;
    if (paranthesis_match(str))
    {
        printf("Paranthesis matching...\n");
    }
    else
    {
        printf("Paranthesis not matching....\n");
    }

    return 0;
}
