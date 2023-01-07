#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *str;
};

void push(struct stack *st, char val)
{
    st->top++;
    st->str[st->top] = val;
}

char pop(struct stack *st)
{
    char val = st->str[st->top];
    st->top--;
    return val;
}

int isEmpty(struct stack *st)
{
    if (st->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int match(char a, char b){
    if (a == ']' && b == ']')
    {
        return 1;
    }
    if (a == '}' && b == '}')
    {
        return 1;
    }
    if (a == ')' && b == ')')
    {
        return 1;
    }
    return 0;
}

int multiple_bracket_check(char *exp)
{
    struct stack *st;
    st->size = 100;
    st->top = -1;
    st->str = (char *)malloc(st->size * sizeof(char));
    char pop_result;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if ((exp[i] == '[') || (exp[i] == '{') || (exp[i] == '('))
        {
            push(st, exp[i]);
        }
        else if ((exp[i] == ']') || (exp[i] == '}') || (exp[i] == ')'))
        {
            if (isEmpty(st))
            {
                printf("Stack Underflow....\n");
                return 0;
            }
            else
            {
                pop_result = pop(st);
                char stack_top = st->str[st->top];
                if (match(stack_top, pop_result))
                {
                    return 1;
                }
            }
        }
    }
    if (isEmpty(st))
    {
        return 1;
    }
    else{
        return 0;
    }
    
}

int main(int argc, char const *argv[])
{
    char *exp = "[{a+b}]";
    if (multiple_bracket_check(exp))
    {
        printf("The expression is balanced...\n");
    }
    else
    {
        printf("The expression is not balanced....\n");
    }

    return 0;
}
