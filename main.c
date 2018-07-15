#include <stdio.h>
#include <stdlib.h>
#define width 4
#define playernamelength 100

char displaygamearray [width][width];

void init()
{
         // Array befüllen initialisierung
    for(int y=0; y<width; y++) { // Schleife fuer Zeilen, Y-Achse
        for(int x=0; x<width; x++) { // Schleife fuer Spalten, X-Achse
           displaygamearray[y][x] = ' ';
           }
        }
    // Beschriftung definieren
    displaygamearray[0][0] = ' ';
    displaygamearray[0][1] = '1';
    displaygamearray[0][2] = '2';
    displaygamearray[0][3] = '3';
    displaygamearray[1][0] = '1';
    displaygamearray[2][0] = '2';
    displaygamearray[3][0] = '3';
}

void printgamefield(char displaygamearray[width][width])
{
     for(int y=0; y<width; y++) { // Schleife fuer Zeilen, Y-Achse
        for(int x=0; x<width; x++) { // Schleife fuer Spalten, X-Achse
        printf(" ");
        printf("%c" ,displaygamearray[y][x]);

        }
    printf("\n");
    }

}

void checkwin(char displaygamearray[width][width], char gamesign, char playername [100])
{

    if (
        ((displaygamearray[1][1] == gamesign) && (displaygamearray[1][2] == gamesign) && (displaygamearray[1][3] == gamesign)) ||
        ((displaygamearray[2][1] == gamesign) && (displaygamearray[2][2] == gamesign) && (displaygamearray[2][3] == gamesign)) ||
        ((displaygamearray[3][1] == gamesign) && (displaygamearray[3][2] == gamesign) && (displaygamearray[3][3] == gamesign)) ||
        ((displaygamearray[1][1] == gamesign) && (displaygamearray[2][1] == gamesign) && (displaygamearray[3][1] == gamesign)) ||
        ((displaygamearray[1][2] == gamesign) && (displaygamearray[2][2] == gamesign) && (displaygamearray[3][2] == gamesign)) ||
        ((displaygamearray[1][3] == gamesign) && (displaygamearray[2][3] == gamesign) && (displaygamearray[3][3] == gamesign)) ||
        ((displaygamearray[1][1] == gamesign) && (displaygamearray[2][2] == gamesign) && (displaygamearray[3][3] == gamesign)) ||
        ((displaygamearray[1][3] == gamesign) && (displaygamearray[2][2] == gamesign) && (displaygamearray[3][1] == gamesign)) )
        {
            printf("Congratulations! Player %s has won!", playername);
            exit(1);
        }
}

void checkinput(char playername [playernamelength], char gamesign)
{
        int inputvalue1 = 0;
        int inputvalue2 = 0;

        printf("\nPlayer %s: Please input a number between 1 to 3 for horizontal coordinate: ", playername);
        scanf("%d", &inputvalue1);

        printf("Player %s: Please input a number between 1 to 3 for vertical coordinate: ", playername);
        scanf("%d", &inputvalue2);
        if (((inputvalue1 > 3) || (inputvalue1 < 1)) || ((inputvalue2 > 3) || (inputvalue2 < 1)))
        {
            printf("ERROR 1: Your Number is outside the possible input!\n");
        }
        else if (displaygamearray[inputvalue1][inputvalue2] == 'o' || displaygamearray[inputvalue1][inputvalue2] == 'x')
        {
            printf("ERROR 2: Position is already reserved!\n");
        }
        else
        {
            displaygamearray[inputvalue1][inputvalue2] = gamesign;
        }
}

void printstart(char playername1 [playernamelength], char playername2 [playernamelength], char o, char x)
{
    printf("############################################################################\n");
    printf("#################### WELCOME BY THE GAME - TIC TAC TOE #####################\n");
    printf("############################################################################\n");
    printf("Please input a name for Player 1: ");
    scanf("%s", playername1);
    printf("Hello %s you are Player 1. Your Symbol is '%c'.\n\n", playername1, o);
    printf("Please input a name for Player 2: ");
    scanf("%s", playername2);
    printf("Hello %s you are Player 2. Your Symbol is '%c'.\n\n", playername2, x);
    printf("------------------- The Game starts now ------------------------------------");
}

int main()
{
    char playername1 [playernamelength]; //VARIABLE FOR PLAYER 1
    char playername2 [playernamelength]; //VARIABLE FOR PLAYER 2

    char o = 'o';
    char x = 'x';
    int reservedfields = 0;

    init();

    printstart(playername1, playername2, o, x);


    while (reservedfields < 9)
    {
        checkinput(playername1, o);
        printgamefield(displaygamearray);
        checkwin(displaygamearray, o, playername1);
        reservedfields++;

        checkinput(playername2, x);
        printgamefield(displaygamearray);
        checkwin(displaygamearray, x, playername2);
        reservedfields++;

        if (reservedfields == 9)
        {
            printf("draw!");
            exit(1);
        }

    }

    return 0;
}
