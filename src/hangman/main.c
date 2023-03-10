#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define BUFFER_SIZE 29
#define CHANCE 7

void insertsLetter(char *word, char letter, bool *mistakeFlag, char *wordGuessed)
{
    int lenWord = strlen(word);
    for (int k = 0; k <= lenWord - 1; k++)
    {
        if (word[k] == ' ')
        {
            printf("  ");
        }
        else if (word[k] == letter)
        {
            wordGuessed[k] = word[k];
            printf(" %c", letter);
            *mistakeFlag = false;
        }
        else
        {
            printf(" %c", wordGuessed[k]);
        }
    }
    printf("\n");
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
        if (words[len] == ' ')
        {
            printf(" %c", ' ');
        }
        else
        {
            printf(" %c", '*');
        }
        len++;
    }
    printf("\n");
    words[len] = '\0';
}

int countBlank(char *words)
{
    int hitCounterLetter = 0;
    int lenWord = strlen(words);
    for (int k = 0; k <= lenWord - 1; k++)
    {
        if (words[k] == ' ')
        {
            hitCounterLetter++;
        }
    }
    return hitCounterLetter;
}

int countCorectLetters(char *words, char letter)
{
    int hitCounterLetter = 0;
    int lenWord = strlen(words);
    for (int k = 0; k <= lenWord - 1; k++)
    {
        if (words[k] == letter)
        {
            hitCounterLetter++;
        }
    }
    return hitCounterLetter;
}

void printLetterArray(char *letterArray, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf(" %c", letterArray[i]);
    }
    printf(" \n");
}

int main(int argc, char *argv[])
{
    char body[CHANCE] = {' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char wordGuessed[BUFFER_SIZE]; //slova koja su pogodjena
    bool mistakeFlag = true;
    int mistakes = 0;
    char letter;
    char word[BUFFER_SIZE]; //rec koja je zadata
    int hitCounterLetter = 0;
    int lenWord = 0;
    char ch;
    char letterArray[BUFFER_SIZE]; //sva slova koja se nagadjaju
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

        printf(" \n");
        printDashes(word);
        hitCounterLetter = countBlank(word);
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
            printLetterArray(letterArray, i);

            insertsLetter(word, letter, &mistakeFlag, wordGuessed);

            hitCounterLetter = hitCounterLetter + countCorectLetters(word, letter);

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