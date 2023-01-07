#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    int size;
    int top;
    char * str;
};

int isEmpty(struct stack *st){
    if (st->top == -1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int precedence(char ch){
    if(ch == '*' || ch == '/')return 3;
    if(ch == '+' || ch == '-')return 2;
    return 0;    
}

int operator(char ch){
    if (ch == '*' || ch == '/' || ch == '-' || ch == '+')
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *st,char val){
    st->top++;
    st->str[st->top] = val;
}

char pop(struct stack *st){
    char val = st->str[st->top];
    st->top--;
    return val;
}

char stackTop(struct stack *st){
    return st->str[st->top];
}

char * infix_to_post(char * infix){
    struct stack * st = (struct stack* )malloc(sizeof(struct stack));
    st->top = -1;
    st->size = 50;
    st->str = (char *)malloc(st->size * sizeof(char));
    char * postfix = (char *)malloc(strlen(infix)+1 * sizeof(char));
    int i=0,j=0;
    while (infix[i] != '\0')
    {
        if (!operator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if (precedence(infix[i]) > precedence(stackTop(st)))
            {
                push(st,infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(st);
                push(st,infix[i]);
                i++;
                j++;
            }
        }        
    }
    while (!isEmpty(st))
    {
        postfix[j] = pop(st);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main(int argc, char const *argv[])
{
    char * exp = "a+3+b*s-334+d";
    printf("The postfix is : %s",infix_to_post(exp));
    return 0;
}
