// This is not a serious project, it is just a practice exercise to help dealing with strings.
// This parser is very cheap so don't depend on it, it only parses correctly when the code line is very simple with only a container tag and its contents currently.
#include <stdio.h>
#include <string.h>

void parser(char * code)
{
    // removing the container tags:
    int index = 0;
    int in = 0; // variable to track whether we are in a tag or not.
    for (int i = 0; i < strlen(code); i++)
    {
        if (code[i] == '<')
        {
            in = 1;
            continue;
        }

        else if (code[i] == '>')
        {
            in = 0;
            continue;
        }

        if (in == 0)
        {
            code[index] = code[i];
            index++;
        }
    }
    
    code[index] = '\0';

    // Removing the trailing spaces from the beginning:
    while (code[0] == ' ')
    {
        for (int i = 0; i < strlen(code); i++)
        {
            code[i] = code[i+1];
        }
        
    }
    
    // Removing the trailing spaces from the end:
    

}

int main(int argc, char const *argv[])
{
    char html_code[] = "<h1>   This is a heading   </h1>";
    printf("The original code is: ~~%s~~.\n", html_code);
    parser(html_code);
    printf("The parsed code is: ~~%s~~.", html_code);
    return 0;
}
