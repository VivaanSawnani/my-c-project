#include<stdio.h>
int main()
{
    char ch;
    printf("Enter an alphabet:");
    scanf("%c",&ch);
    switch(ch)
    {
        case 'A':
        case 'a':
                printf("%c is a vowel",ch);
                break;
        case 'E':
        case 'e':
                printf("%c is a vowel",ch);
                break;
        case 'I':
        case 'i':
                printf("%c is a vowel",ch);
                break;
        case 'O':
        case 'o':
                printf("%c is a vowel",ch);
                break;
        case 'U':
        case 'u':
                printf("%c is a vowel",ch);
                break;
        default:printf("%c is a consonant",ch);
    }
    return 0;
}
