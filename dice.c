#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "types.h" 
#include "players.h" 

int rolldice() {
   // srand((unsigned int)time(NULL)); // To get the current time for generate random numbers 
    
    int die1 = (rand() % 6) + 1; 
    int die2 = (rand() % 6) + 1; 

    return die1 + die2; // Return the sum of the two dice
}


// void tie_breaker(){
//     printf("\nChecking for ties...\n");

//     if (players[0].first_roll == players[1].first_roll && players[0].first_roll > players[2].first_roll && players[0].first_roll > players[3].first_roll) {
//         printf("Player 1 and Player 2 are tied. Rolling again...\n");
//         players[0].first_roll = rolldice();
//         players[1].first_roll = rolldice();
//         printf("%s rolls %d.\n", players[0].player_name , players[0].first_roll);
//         printf("%s rolls %d.\n", players[1].player_name , players[1].first_roll);
//     } else if (players[0].first_roll == players[2].first_roll && players[0].first_roll > players[1].first_roll && players[0].first_roll > players[3].first_roll) {
//         printf("Player 1 and Player 3 are tied. Rolling again...\n");
//         players[0].first_roll = rolldice();
//         players[2].first_roll = rolldice();
//         printf("%s rolls %d.\n", players[0].player_name , players[0].first_roll);
//         printf("%s rolls %d.\n", players[2].player_name , players[2].first_roll);
//     } else if (players[0].first_roll == players[3].first_roll && players[0].first_roll > players[1].first_roll && players[0].first_roll > players[2].first_roll) {
//         printf("Player 1 and Player 4 are tied. Rolling again...\n");
//         players[0].first_roll = rolldice();
//         players[3].first_roll = rolldice();
//         printf("%s rolls %d.\n", players[0].player_name , players[0].first_roll);
//         printf("%s rolls %d.\n", players[3].player_name , players[3].first_roll);
//     } else if (players[1].first_roll == players[2].first_roll && players[1].first_roll > players[0].first_roll && players[1].first_roll > players[3].first_roll) {
//         printf("Player 2 and Player 3 are tied. Rolling again...\n");
//         players[1].first_roll = rolldice();
//         players[2].first_roll = rolldice();
//         printf("%s rolls %d.\n", players[1].player_name , players[1].first_roll);
//         printf("%s rolls %d.\n", players[2].player_name , players[2].first_roll);
//     } else if (players[1].first_roll == players[3].first_roll && players[1].first_roll > players[0].first_roll && players[1].first_roll > players[2].first_roll) {
//         printf("Player 2 and Player 4 are tied. Rolling again...\n");
//         players[1].first_roll = rolldice();
//         players[3].first_roll = rolldice();
//         printf("%s rolls %d.\n", players[1].player_name , players[1].first_roll);
//         printf("%s rolls %d.\n", players[3].player_name , players[3].first_roll);
//     } else if (players[2].first_roll == players[3].first_roll && players[2].first_roll > players[0].first_roll && players[2].first_roll > players[1].first_roll) {
//         printf("Player 3 and Player 4 are tied. Rolling again...\n");
//         players[2].first_roll = rolldice();
//         players[3].first_roll = rolldice();
//         printf("%s rolls %d.\n", players[2].player_name , players[2].first_roll);
//         printf("%s rolls %d.\n", players[3].player_name , players[3].first_roll);
//     }
//}


void dice() {  // declare the dice function with array to store the sum of dice rolls.

for (int i = 0; i<4; i++)    
{
    players[i].first_roll = rolldice(); // assign the value of sum to players.
    
    printf("%s rolls %d.\n", players[i].player_name , players[i].first_roll);
}

}

void tie_breaker() { //compare one by one players to find tie and roll again dice for determine the order

     if (players[0].first_roll == players[1].first_roll) {
         printf("\nTie detected between %s and %s. Rolling again...\n", players[0].player_name, players[1].player_name);
        players[0].first_roll = rolldice();
        players[1].first_roll = rolldice();
        printf("%s rolls %d.\n", players[0].player_name , players[0].first_roll);
        printf("%s rolls %d.\n", players[1].player_name , players[1].first_roll);
    } else if (players[0].first_roll == players[2].first_roll) {
        printf("\nTie detected between %s and %s. Rolling again...\n", players[0].player_name, players[2].player_name);
        players[0].first_roll = rolldice();     
        players[2].first_roll = rolldice();
        printf("%s rolls %d.\n", players[0].player_name , players[0].first_roll);
        printf("%s rolls %d.\n", players[2].player_name , players[2].first_roll);
    } else if (players[0].first_roll == players[3].first_roll) {
        printf("\nTie detected between %s and %s. Rolling again...\n", players[0].player_name, players[3].player_name);
        players[0].first_roll = rolldice(); 
        players[3].first_roll = rolldice();
        printf("%s rolls %d.\n", players[0].player_name , players[0].first_roll);
        printf("%s rolls %d.\n", players[3].player_name , players[3].first_roll);
    } else if (players[1].first_roll == players[2].first_roll) {
        printf("\nTie detected between %s and %s. Rolling again...\n", players[1].player_name, players[2].player_name);
        players[1].first_roll = rolldice();
        players[2].first_roll = rolldice();     
        printf("%s rolls %d.\n", players[1].player_name , players[1].first_roll);
        printf("%s rolls %d.\n", players[2].player_name , players[2].first_roll);
    } else if (players[1].first_roll == players[3].first_roll) {
        printf("\nTie detected between %s and %s. Rolling again...\n", players[1].player_name, players[3].player_name);
        players[1].first_roll = rolldice();
        players[3].first_roll = rolldice();
        printf("%s rolls %d.\n", players[1].player_name , players[1].first_roll);
        printf("%s rolls %d.\n", players[3].player_name , players[3].first_roll);
    } else if (players[2].first_roll == players[3].first_roll) {
        printf("\nTie detected between %s and %s. Rolling again...\n", players[2].player_name, players[3].player_name);
        players[2].first_roll = rolldice();
        players[3].first_roll = rolldice();
        printf("%s rolls %d.\n", players[2].player_name , players[2].first_roll);
        printf("%s rolls %d.\n", players[3].player_name , players[3].first_roll);

     
        }
}

   
