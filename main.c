#include <stdio.h>
#include <stdlib.h>
#define width 4
#define PLAYER_NAME_LENGTH 100

char game_field_array [width][width]; //GAME-FIELD-ARRAY

void init_game_field() //INITIALIZATION OF GAME-FIELD-ARRAY
{
    for(int y=0; y<width; y++) { //LOOP FOR ROWS
        for(int x=0; x<width; x++) { //LOOP FOR COLUMNS
            game_field_array[y][x] = ' '; //FILL IN ARRAY WITH SPACES FOR INITIALIZATION
        }
    }

    game_field_array[0][0] = ' '; //ADD EMPTY FIELD
    game_field_array[0][1] = '1'; //ADD MARKING FOR HORIZONTAL (=COLUMN) AXIS
    game_field_array[0][2] = '2'; //ADD MARKING FOR HORIZONTAL (=COLUMN) AXIS
    game_field_array[0][3] = '3'; //ADD MARKING FOR HORIZONTAL (=COLUMN) AXIS
    game_field_array[1][0] = '1'; //ADD MARKING FOR VERTICAL (=ROW) AXIS
    game_field_array[2][0] = '2'; //ADD MARKING FOR VERTICAL (=ROW) AXIS
    game_field_array[3][0] = '3'; //ADD MARKING FOR VERTICAL (=ROW) AXIS
}

void print_game_field(char game_field_array[width][width])  //PRINTING GAME-FIELD
{
    for(int y=0; y<width; y++) { //LOOP FOR ROWS
        for(int x=0; x<width; x++) { //LOOP FOR COLUMNS
            printf(" "); //PRINT SPACE
            printf("%c" ,game_field_array[y][x]); //PRINT GAME-FIELD
        }
        printf("\n"); //PRINT EMPTY LINE
    }
}

void check_win(char game_field_array[width][width], char game_sign, char player_name [PLAYER_NAME_LENGTH]) //CHECK IF A PLAYER HAS WON THE GAME
{
    if ( //ALL POSSIBLE COMBINATIONS OF THE GAME
        ((game_field_array[1][1] == game_sign) && (game_field_array[1][2] == game_sign) && (game_field_array[1][3] == game_sign)) ||
        ((game_field_array[2][1] == game_sign) && (game_field_array[2][2] == game_sign) && (game_field_array[2][3] == game_sign)) ||
        ((game_field_array[3][1] == game_sign) && (game_field_array[3][2] == game_sign) && (game_field_array[3][3] == game_sign)) ||
        ((game_field_array[1][1] == game_sign) && (game_field_array[2][1] == game_sign) && (game_field_array[3][1] == game_sign)) ||
        ((game_field_array[1][2] == game_sign) && (game_field_array[2][2] == game_sign) && (game_field_array[3][2] == game_sign)) ||
        ((game_field_array[1][3] == game_sign) && (game_field_array[2][3] == game_sign) && (game_field_array[3][3] == game_sign)) ||
        ((game_field_array[1][1] == game_sign) && (game_field_array[2][2] == game_sign) && (game_field_array[3][3] == game_sign)) ||
        ((game_field_array[1][3] == game_sign) && (game_field_array[2][2] == game_sign) && (game_field_array[3][1] == game_sign)) )
        {
            printf("Congratulations! Player %s has won!", player_name); //PRINT NAME OF PLAYER WHICH HAS WON
            exit(1); //EXIT THE GAME
        }
}

void check_input(char *player_name, char game_sign) //CHECK INPUT OF THE PLAYER
{
        int horizontal_coordinate = 0; //VARIABLE FOR HORIZONTAL COORDINATE
        int vertical_coordinate = 0; //VARIABLE FOR VERTICAL COORDINATE

        printf("\nPlayer %s: Please input a number between 1 to 3 for horizontal coordinate: ", player_name); //PRINT PLAYER FOR NEXT COORDINATE AND HIS HORIZONTAL COORDINATE
        scanf("%d", &horizontal_coordinate); //READ IN THE HORIZONTAL COORDINATE

        printf("Player %s: Please input a number between 1 to 3 for vertical coordinate: ", player_name); //PRINT PLAYER FOR NEXT COORDINATE AND HIS VERTICAL COORDINATE
        scanf("%d", &vertical_coordinate);//READ IN THE VERTICAL COORDINATE

        if (((horizontal_coordinate > 3) || (horizontal_coordinate < 1)) || ((vertical_coordinate > 3) || (vertical_coordinate < 1))) //CHECK IF INPUT OF COORDINATE IS INSIDE OF THE GAME-FIELD
        {
            printf("ERROR 1: Your Number is outside the possible input!\n"); //PRINT ERROR IF INPUT IS OUTSIDE OF THE POSSIBLE INPUTS
        }
        else if (game_field_array[horizontal_coordinate][vertical_coordinate] == 'o' || game_field_array[horizontal_coordinate][vertical_coordinate] == 'x')
        {
            printf("ERROR 2: Position is already reserved!\n"); //PRINT ERROR IF POSITION IS ALREADY RESERVED
        }
        else
        {
            game_field_array[horizontal_coordinate][vertical_coordinate] = game_sign; //IF POSITION IS FREE; PLACE THE GAME-SIGN TO RESERVED THE FIELD
        }
}

void print_start(char *player_name1, char *player_name2, char o, char x) //PRINT START INFORMATION BEFORE THE GAME CAN START
{
    printf("############################################################################\n");
    printf("#################### WELCOME BY THE GAME - TIC TAC TOE #####################\n");
    printf("############################################################################\n");
    printf("Please input a name for Player 1: ");
    scanf("%s", player_name1); //READ IN THE NAME FOR PLAYER 1
    printf("Hello %s you are Player 1. Your Symbol is '%c'.\n\n", player_name1, o); //PRINT NAME OF PLAYER 1 AGAIN AND GIVE HIM THE GAME-SIGN "O"
    printf("Please input a name for Player 2: ");
    scanf("%s", player_name2); //READ IN THE NAME FOR PLAYER 2
    printf("Hello %s you are Player 2. Your Symbol is '%c'.\n\n", player_name2, x); //PRINT NAME OF PLAYER 1 AGAIN AND GIVE HIM THE GAME-SIGN "X"
    printf("------------------- The Game starts now ------------------------------------");
}

print_moves(int maximum_game_fields, int counter_game_fields) //PRINT REMAINING MOVES
{
    int moves = 0; //VARIABLE FOR MOVES

    moves = maximum_game_fields - counter_game_fields; //CALCULATE REMAINING MOVES
    printf("\nRemaining moves: %i", moves); //PRINT MOVES
}

int main()
{
    char player_name1 [PLAYER_NAME_LENGTH]; //VARIABLE FOR PLAYER 1
    char player_name2 [PLAYER_NAME_LENGTH]; //VARIABLE FOR PLAYER 2
    char o = 'o'; //GAME SIGN FOR PLAYER 1
    char x = 'x'; //GAME SIGN FOR PLAYER 2
    int counter_game_fields = 0; //COUNTER FOR REMAINING GAME FIELDS -> MAXIMUM 9 POSSIBLE GAME FIELDS
    int maximum_game_fields = 9;

    init_game_field(); //INITIALIZATION OF GAME-FIELD-ARRAY

    print_start(player_name1, player_name2, o, x); //PRINT START INFORMATION BEFORE THE GAME CAN START

    while (counter_game_fields < maximum_game_fields) //LOOP FOR PLAYING THE GAME
    {
        print_moves(maximum_game_fields, counter_game_fields); //PRINT REMAINING MOVES
        check_input(player_name1, o); //CHECK INPUT OF THE PLAYER 1
        print_game_field(game_field_array); //PRINTING GAME-FIELD AFTER INPUT OF PLAYER 1
        check_win(game_field_array, o, player_name1); //CHECK IF A PLAYER 1 HAS WON THE GAME
        counter_game_fields++; //INCREASE COUNTER FOR REMAINING GAME FIELDS

        print_moves(maximum_game_fields, counter_game_fields); //PRINT REMAINING MOVES
        check_input(player_name2, x); //CHECK INPUT OF THE PLAYER 2
        print_game_field(game_field_array); //PRINTING GAME-FIELD AFTER INPUT OF PLAYER 2
        check_win(game_field_array, x, player_name2); //CHECK IF A PLAYER 2 HAS WON THE GAME
        counter_game_fields++; //INCREASE COUNTER FOR REMAINING GAME FIELDS

        if (counter_game_fields == maximum_game_fields) //IF NOBODY WON THE GAME BECAUSE IT IS A DRAW
        {
            printf("The game ends draw!"); //PRINT OUT IT IS A DRAW
            exit(1); //AND EXIT THE GAME
        }
    }

    return 0;
}
