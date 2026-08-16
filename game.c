#include <stdio.h>
#include "game.h"
#include "types.h"
#include "players.h"



int start() {

// Example usage of the squares array
     for (int i = 0; i < 40; i++) {
        printf("\nSquare iD: %d, Name: %s, Type: %d\n", squares[i].square_id, squares[i].square_name, squares[i].square_type);
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
   printf("\n>>> Turn %d \n",i+1); // output is unclear. so i was using this
   // players[4].game_round = i;
    //printf("\nGame Round : %d\n",players[4].game_round);
     for(int j =0; j<4; j++){

   players[j].dice_roll = rolldice();

   int old_position = players[j].current_position;
   int number_of_moves = players[j].dice_roll;
   int new_position = old_position + number_of_moves;
if(players[j].in_the_jail == 0){
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
}else{ players[j].jail_time++;
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
 dynamic_property_market(game_round);
 
    //printf("\nGame Round : %d\n",game_round);
  }
monopoly();

 }

}
}

// when player going to jail, how player can released from jail.
void come_from_jail(int j , int die1, int die2) { 
    Squares *landed_square = &squares[players[j].current_position];
if(landed_square->square_id == 30){
    players[j].in_the_jail = 1;
    players[j].current_position = 10;

    if(players[j].balance >= 300){
        players[j].balance -= 300;
        players[j].in_the_jail = 0;
        players[j].net_worth -= 300;
        printf("\n%s pay the fine of LKR 300.\n", players[j].player_name);
        printf("\n%s Released from jail.\n", players[j].player_name);
    }else if(die1 ==die2){
        players[j].in_the_jail = 0;
        printf("\n%s Released from jail.\n", players[j].player_name);
    }else if(players[j].jail_time ==3){
        players[j].in_the_jail = 0;
        printf("\n%s Released from jail.\n", players[j].player_name);
    }
}else if(landed_square->square_id == 20 || landed_square->square_id == 10){
    // square 20 is free place. it is safety place for the players.
    // square 10 is only visit jail.
}
}


void monopoly() {
    for(int i = 0; i < 4; i++){
    if(squares[1].property_details.current_owner_no == players[i].player_id 
        && squares[3].property_details.current_owner_no == players[i].player_id){
            
        property_colour[0].monopoly_owner = players[i].player_id;
            printf("\n%s is the owner of the monopoly %d\n", players[i].player_name, property_colour[0].property_group);

    } if(squares[6].property_details.current_owner_no == players[i].player_id 
         && squares[8].property_details.current_owner_no== players[i].player_id
            && squares[9].property_details.current_owner_no == players[i].player_id){
                
                property_colour[1].monopoly_owner = players[i].player_id;
                printf("\n%s is the owner of the monopoly %d\n", players[i].player_name, property_colour[1].property_group);

    }if(squares[11].property_details.current_owner_no == players[i].player_id
         && squares[13].property_details.current_owner_no == players[i].player_id
            && squares[14].property_details.current_owner_no == players[i].player_id){
                
                property_colour[2].monopoly_owner = players[i].player_id;
                printf("\n%s is the owner of the monopoly %d\n", players[i].player_name, property_colour[2].property_group);

    }if(squares[16].property_details.current_owner_no == players[i].player_id
         && squares[18].property_details.current_owner_no == players[i].player_id
            && squares[19].property_details.current_owner_no == players[i].player_id){
                
                property_colour[3].monopoly_owner = players[i].player_id;
                printf("\n%s is the owner of the monopoly %d\n", players[i].player_name, property_colour[3].property_group);

    } if(squares[21].property_details.current_owner_no == players[i].player_id
         && squares[23].property_details.current_owner_no == players[i].player_id
            && squares[24].property_details.current_owner_no == players[i].player_id){
                
                property_colour[4].monopoly_owner = players[i].player_id;
                printf("\n%s is the owner of the monopoly %d\n", players[i].player_name, property_colour[4].property_group);

    }if(squares[26].property_details.current_owner_no == players[i].player_id
         && squares[27].property_details.current_owner_no == players[i].player_id
            && squares[29].property_details.current_owner_no == players[i].player_id){
                
                property_colour[5].monopoly_owner = players[i].player_id;
                printf("\n%s is the owner of the monopoly %d\n", players[i].player_name, property_colour[5].property_group);

    } if(squares[31].property_details.current_owner_no == players[i].player_id
         && squares[32].property_details.current_owner_no == players[i].player_id
            && squares[34].property_details.current_owner_no == players[i].player_id){
                
                property_colour[6].monopoly_owner = players[i].player_id;
                printf("\n%s is the owner of the monopoly %d\n", players[i].player_name, property_colour[6].property_group);

    } if(squares[37].property_details.current_owner_no == players[i].player_id
         && squares[39].property_details.current_owner_no == players[i].player_id){

                property_colour[7].monopoly_owner = players[i].player_id;
                printf("\n%s is the owner of the monopoly %d\n", players[i].player_name, property_colour[7].property_group);

    }
         }

}

