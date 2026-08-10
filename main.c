#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "players.h"
#include "game.h"
#include <time.h>




void main() {
   // Squares* board = getBoard();

   // Squares box0 = board[1];
   // printf("Square ID: %d, Name: %s, Type: %d\n", box0.square_id, box0.square_name, box0.square_type);

    printf("\n\n-----MONOPOLY-LK Simulation-----\n\n");
    printf("Player %d : %s\n", players[0].player_id, players[0].player_name);
    printf("Player %d : %s\n", players[1].player_id, players[1].player_name);
    printf("Player %d : %s\n", players[2].player_id, players[2].player_name);
    printf("Player %d : %s\n", players[3].player_id, players[3].player_name);

    printf("\nEach player begins with LKR 30,000.\n\n");


     // Example usage of the squares array
    /* for (int i = 0; i < 40; i++) {
        printf("Square ID: %d, Name: %s, Type: %d\n", squares[i].square_id, squares[i].square_name, squares[i].square_type);
     }
     // Example usage of the players array
     for (int i = 0; i < 4; i++) {
        printf(" Player %d: %s\n Balance: %.2f\n", players[i].player_id, players[i].player_name, players[i].balance);
    }
*/

 srand(time(NULL));


dice();
tie_breaker(); // call the tie breaker function to check if any players are tied.
sorting_players(); //call the sorting players function 

// int start_game = start();
     
}