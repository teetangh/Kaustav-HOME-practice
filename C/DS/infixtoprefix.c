#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char s[10];
    int top;
} STACK;

void push(STACK *s1, char ele)
{
    s1->top++;
    s1->s[s1->top] = ele;
}
char pop(STACK *s1)
{
    return s1->s[s1->top--];
}

int pre(char symb)
{
    switch (symb)
    {
    case '#':
        return 0;
    case ')':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    case '$':
    case '^':
        return 4;
        break;
    }
}

void main()
{
    char infix[20], prefix[20], symb, ele;
    int i = 0, p = 0;

    STACK s1;
    s1.top = -1;
    push(&s1, '#');

    printf("Enter the infix \n");
    gets(infix);
    strrev(infix);

    while ((symb = infix[i++]) != '\0')
    {
        switch (symb)
        {
        case ')':
            push(&s1, ')');
            break;
        case '(':
            while (s1.s[s1.top] != ')')
                prefix[p++] = pop(&s1);
            ele = pop(&s1);
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            while (pre(s1.s[s1.top] > pre(symb)))
                prefix[p++] = pop(&s1);
            push(&s1, symb);
        case '$':
            if ((s1.s[s1.top] == '$' && symb == '$'))
                push(&s1, '$');
            break;
        // case '$':
        //     if ((s1.s[s1.top] == '$'))
        //         prefix[p++] = pop(&s1);
        //     push(&s1, '$');
        //     break;
        default:
            prefix[p++] = symb;
        }
    }

    while (s1.s[s1.top] != '#')
        prefix[p++] = pop(&s1);

    strrev(infix);
    strrev(prefix);

    printf("INFIX %s \n\n  PREFIX %s \n", infix, prefix);
}