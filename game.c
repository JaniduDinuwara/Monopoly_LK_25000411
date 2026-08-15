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
int game_round = 0;   // called to calculate the game round
int players_pass_go = 0;  //calculate the players who passed GO

 for (int i=0; i<500; i++){
   // players[4].game_round = i;
    //printf("\nGame Round : %d\n",players[4].game_round);
     for(int j =0; j<4; j++){

   players[j].dice_roll = rolldice();

   int old_position = players[j].current_position;
   int number_of_moves = players[j].dice_roll;
   int new_position = old_position + number_of_moves;

   players[j].current_position = new_position % 40;

   printf("\n %s rolled %d\n", players[j].player_name, players[j].dice_roll);

   printf("%s moves from square %d to square %d\n", players[j].player_name, old_position, players[j].current_position);
   
   if(new_position >= 40){   //check player passed go
    players[j].balance += 2000;
    players_pass_go++;
    players[j].player_round++;
    //printf("%d rounds passed\n",players[j].player_round);
      printf("\n%s passed GO.\n Collected LKR 2,000.\n", players[j].player_name);
      printf("Current Balance : LKR %d\n",players[j].balance);
   }

   switch (players[j].player_type) {  //call the player function for continue player behavior
    case Aggressive_Investor:
        Player_Aggressive_Investor(j);
        break;
    case Conservative_Banker:
        Player_Conservative_Banker(j);
        break;
    case Risk_Taker:
        Player_Risk_Taker(j);
        break;
    case Opportunistic_Trader:
        Player_Opportunistic_Trader(j);
        break;
}


if(players_pass_go == 4){ //calculate the game round
    game_round++;
    players_pass_go = 0;
    //printf("\nGame Round : %d\n",game_round);
  }

 }
}
}
