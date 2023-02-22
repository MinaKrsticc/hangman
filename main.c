#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define _CONIO_H_
#define BUFFER_SIZE 29
#define CHANCE 7

void insertsLetter(char *word, char letter, bool *mistakeFlag, int hitCounterLetter, char *wordGuessed)
{
    int lenWord = strlen(word);
    for (int k = 0; k <= lenWord - 1; k++)
    { 
        if (word[k] == letter)
        {
            wordGuessed[k] = word[k];
            printf(" %c ", letter);
            *mistakeFlag = false;
            hitCounterLetter++;
        }
        else if (wordGuessed[k] == '_')
        {
            printf(" __");
        }
        else
        {
            printf("%c", wordGuessed[k]);
        }
    }
    
//     // for (int k = 0; k <= lenWord - 1; k++)
//     // {
//     //     if (word[k] == letter)
//     //     {
//     //         printf(" %c", letter);
//     //         mistakesFlag = false;
//     //     }
//     //     else
//     //     {
//     //         printf(" __");
//     //     }
//     // }
}

void printBody(char *body, int mistakes)
{
    printf("\t Mistakes :%d \n", mistakes);
    switch (mistakes)
    {
    case 6:
        body[6] = '\\';
        break;
    case 5:
        body[5] = '/';
        break;
    case 4:
        body[4] = '\\';
        break;
    case 3:
        body[3] = '|';
        break;
    case 2:
        body[2] = '/';
        break;
    case 1:
        body[1] = ')', body[0] = '(';
        break;
    default:
        break;
    }
    printf("\t _________\n"
           "\t|         |\n"
           "\t|        %c %c\n"
           "\t|        %c%c%c\n"
           "\t|        %c %c\n"
           "\t|             \n"
           "\t|             ",
           body[0], body[1], body[2], body[3], body[4], body[5], body[6]);
}

void printDashes(char *word)
{
    int lenWord = strlen(word);
    for (int i = 0; i < lenWord; i++)
    {
        if (word[i] == ' ')
        {
            printf("  ");
        }
        else
        {
            printf(" __");
        }
    }
    printf("\n");
}

void getWord(char *words, char ch, int len)
{
    printf(" \n\t - Enter the word you want the opponent to guess : \n");

    while ((ch = getchar()) != '\n')
    {
        words[len] = ch;

        len++;
        if (words[len] == ' ')
        {
            printf(" ");
        }
        else
        {
            printf("%c", '*');
        }
    }
    words[len] = '\0';
}

int main(int argc, char *argv[])
{
    char body[CHANCE] = {' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char wordGuessed[BUFFER_SIZE];
    bool mistakeFlag = true;
    int mistakes = 0;
    char letter;
    char word[BUFFER_SIZE];
    int hitCounterLetter = 0;
    int lenWord = 0;
    char ch;
    char letterArray[CHANCE];
    int i = 0;

    printf("\n\t Be aware you can be hanged!");
    printf("\n\n\t Rules : ");
    printf("\n\t - Maximum 6 mistakes are allowed.");
    printf("\n\t - All alphabet are in lower case.");
    printf("\n\t - If you enjoy continue, otherwise close it. \n");

    if (argc == 1)
    {
        getWord(word, ch, lenWord);
        system("clear");

        lenWord = strlen(word);
        
        memset(wordGuessed, '_', lenWord);

        // for (int i = 0; i <= lenWord; i++)
        // {
        //     printf("%c", word[i]);
        // }

        printf(" \n");
        printDashes(word);
        while (mistakes < 7)
        {
            if (hitCounterLetter == lenWord)
            {
                printf(" Congratulations, you WON  \n");
                break;
            }

            printf("Enter letter would you like: \n");
            scanf("  %c", &letter);
            printf(" \n");
            letterArray[i] = letter;
            i++;
            for (int j = 0; j < i; j++)
            {
                printf(" %c", letterArray[j]);
            }
            printf(" \n");

            insertsLetter(word, letter, &mistakeFlag, hitCounterLetter, wordGuessed);

            // for (int k = 0; k <= lenWord - 1; k++)
            // {
            //     if (word[k] == letter)
            //     {
            //         wordGuessed[k] = word[k];
            //         printf(" %c ", letter);
            //         mistakeFlag = false;
            //         hitCounterLetter++;
            //     }
            //     else if (wordGuessed[k] == '_')
            //     {
            //         printf(" __");
            //     }
            //     else
            //     {
            //         printf("%c", wordGuessed[k]);
            //     }
            // }

            if (mistakeFlag == true)
            {
                mistakes++;
            }
            mistakeFlag = true;
            printBody(body, mistakes);
            printf(" \n");
        }

        if (mistakes > 7 || mistakes == 7)
        {
            printf("GAME OVER \n");
        }
    }
    else
    {
        printf("Somting is wrong \n");
    }
}