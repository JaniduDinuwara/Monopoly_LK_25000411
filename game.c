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

// void sorting_players() {
//    struct Players *ptr[] = &players;

// for (int i=0; i<4; i++){
//    for (int j=0; j<4; j++){

//         if(ptr[j]->first_roll < ptr[j+1]->first_roll) {
//          do {
//             printf("Players")
//          }

//         }


//    }
// }
// }

void sorting_players() {

    // array of pointers to each player
    Players *ptr[4];
    for (int i = 0; i < 4; i++) {
        ptr[i] = &players[i];
    }

    // bubble sort descending by first_roll
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (ptr[j]->first_roll < ptr[j + 1]->first_roll) {
                Players *temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }

    // print final order
    printf("\nFinal order:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d. %s (%d)\n", i + 1, ptr[i]->player_name, ptr[i]->first_roll);
    }
}


