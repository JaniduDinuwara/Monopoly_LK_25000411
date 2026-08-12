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
   //  Players *ptr[4];
   //  for (int i = 0; i < 4; i++) {
   //      ptr[i] = &players[i];
   // }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (players[j].first_roll < players[j + 1].first_roll) {
                Players temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }

    
    printf("\nFinal order:\n");// print final order
    for (int i = 0; i < 4; i++) {
        printf("%d. %s (%d)\n", i + 1, players[i].player_name, players[i].first_roll);
    }
}

void start_playing() {
 for (int i=0; i<500; i++){
    players[4].game_round = i;
    //printf("\nGame Round : %d\n",players[4].game_round);
     for(int j =0; j<4; j++){
   players[j].dice_roll = rolldice();
   printf("\nRolls %s : %d\n",players[j].player_name,players[j].dice_roll);
players[j].current_position = (players[j].current_position + players[j].dice_roll)%40;

if(players[j].current_position + players[j].dice_roll >=40){
    players[j].balance += 2000;
     printf("\n%s passed GO! Collected LKR 2,000.\n", players[j].player_name);
}
printf("Current Balance : %d\n",players[j].balance);
printf("Current Position : %d\n", players[j].current_position);

}
 }
}