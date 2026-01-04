#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *keyword[] = {"int", "printf", "scanf", "for", "if", "else", "continue", "break"};
int keywordCount = 8;

int isKeyword(char *str)
{
    for (int i = 0; i < keywordCount; i++)
        if (strcmp(str, keyword[i]) == 0)
            return 1;
    return 0;
}

int isOperator(char ch)
{
    return (ch == '-' || ch == '+' || ch == '!' || ch == '*' ||
            ch == '<' || ch == '>' || ch == '%' || ch == '/' || ch == '=');
}

int main()
{
    char str[2000];
    str[0] = '\0';

    printf("Provide the code (press EOF when finished):\n");

    // ====== MULTILINE INPUT ======
    char line[300];
    while (fgets(line, sizeof(line), stdin))
        strcat(str, line);
    // ==============================

    int i = 0;
    int tokenCount = 0;   // <-- token counter

    while (str[i] != '\0')
    {
        if (isspace(str[i])) { i++; continue; }

        if (str[i] == '/' && str[i + 1] == '/')
        { while (str[i] != '\0' && str[i] != '\n') i++; continue; }

        if (str[i] == '/' && str[i + 1] == '*')
        {
            i += 2;
            while (str[i] != '\0')
            {
                if (str[i] == '*' && str[i + 1] == '/') { i += 2; break; }
                i++;
            }
            continue;
        }

        if (isalpha(str[i]))
        {
            char temp[50]; int k = 0;
            while (isalnum(str[i])) temp[k++] = str[i++];
            temp[k] = '\0';

            if (isKeyword(temp))
                printf("<Keyword ,%s>", temp);
            else
                printf("<Id ,%s>", temp);

            tokenCount++;   // count token
        }
        else if (str[i] == '"')
        {
            i++;

            while (str[i] != '"' && str[i] != '\0')
                printf("<%c>", str[i++]);
            printf("\n");
            if (str[i] == '"') i++;

            tokenCount++;
        }
        else if (isdigit(str[i]))
        {
            char temp[50]; int k = 0;
            while (isdigit(str[i])) temp[k++] = str[i++];
            temp[k] = '\0';

            printf("<s>", temp);
            tokenCount++;
        }
        else if (isOperator(str[i]))
        {
            if ((str[i + 1] == '=') && (str[i] == '=' || str[i] == '<' || str[i] == '>' || str[i] == '!'))
            {
                printf("<%c%c>", str[i], str[i + 1]);
                i += 2;
            }
            else
            {
                printf("<%c>", str[i]);
                i++;
            }
            tokenCount++;
        }
        else if (str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}' ||
                 str[i] == '[' || str[i] == ']' || str[i] == ';' ||
                 str[i] == ':' || str[i] == ',')
        {
            printf("<%c>", str[i]);
            i++;
            tokenCount++;
        }
        else
        {
            printf("<%c>", str[i]);
            i++;
            tokenCount++;
        }
    }

    printf("\nTotal Tokens = %d\n", tokenCount);

    return 0;
}

