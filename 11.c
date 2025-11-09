#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *keyword[] = {"int", "printf", "scanf", "for", "if", "else", "continue", "break"};
int keywordCount = 8;

int isKeyword(char *str)
{
    for (int i = 0; i < keywordCount; i++)
    {
        if (strcmp(str, keyword[i]) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch)
{
    return (ch == '-' || ch == '+' || ch == '!' || ch == '*' || ch == '<' || ch == '>' || ch == '%' || ch == '/' || ch == '=');
}

int main()
{
    char str[500];
    printf("Provide the code: ");
    fgets(str, sizeof(str), stdin);

    int i = 0;
    while (str[i] != '\0')
    {
        if (isspace(str[i]))
        {
            i++;
            continue;
        }

        // skip single-line comments
        if (str[i] == '/' && str[i + 1] == '/')
        {
            while (str[i] != '\0' && str[i] != '\n')
                i++;
            continue;
        }

        // skip multi-line comments
        if (str[i] == '/' && str[i + 1] == '*')
        {
            i += 2;
            while (str[i] != '\0')
            {
                if (str[i] == '*' && str[i + 1] == '/')
                {
                    i += 2;
                    break;
                }
                i++;
            }
            continue;
        }

        // Keywords / identifiers
        if (isalpha(str[i]))
        {
            char temp[50];
            int k = 0;
            while (isalnum(str[i]))
            {
                temp[k++] = str[i++];
            }
            temp[k] = '\0';

            if (isKeyword(temp))
                printf("Keyword ----> %s\n", temp);
            else
                printf("Identifier ----> %s\n", temp);
        }

        // String constants
        else if (str[i] == '"')
        {
            i++;
            printf("Constant ---> ");
            while (str[i] != '"' && str[i] != '\0')
            {
                printf("%c", str[i]);
                i++;
            }
            printf("\n");
            if (str[i] == '"')
                i++;
        }

        // Numbers
        else if (isdigit(str[i]))
        {
            char temp[50];
            int k = 0;
            while (isdigit(str[i]))
                temp[k++] = str[i++];
            temp[k] = '\0';
            printf("Number ----> %s\n", temp);
        }

        // Operators
        else if (isOperator(str[i]))
        {
            if ((str[i + 1] == '=') && (str[i] == '=' || str[i] == '<' || str[i] == '>' || str[i] == '!'))
            {
                printf("Operator ----> %c%c\n", str[i], str[i + 1]);
                i += 2;
            }
            else
            {
                printf("Operator ----> %c\n", str[i]);
                i++;
            }
        }

        // Parentheses and punctuations
        else if (str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}' ||
                 str[i] == '[' || str[i] == ']' || str[i] == ';' || str[i] == ':' || str[i] == ',')
        {
            printf("Parenthesis ----> %c\n", str[i]);
            i++;
        }

        else
        {
            printf("Symbol ---> %c\n", str[i]);
            i++;
        }
    }

    return 0;
}
