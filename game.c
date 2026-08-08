#include <stdio.h>
#include "game.h"
#include "types.h"
#include "players.h"



int start() {

// Example usage of the squares array
     for (int i = 0; i < 40; i++) {
        printf("\nSquare ID: %d, Name: %s, Type: %d\n", squares[i].square_id, squares[i].square_name, squares[i].square_type);
     }
     // Example usage of the players array
     for (int i = 0; i < 4; i++) {
        printf(" \nPlayer %d: %s\n Balance: %d\n", players[i].player_id, players[i].player_name, players[i].balance);
    }
return 0;
}








