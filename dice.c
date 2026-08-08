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
void dice(int sum[4]) {  // declare the dice function with array to store the sum of dice rolls.


for (int i = 0; i<4; i++) 
 { sum[i] = rolldice();
    players[i].first_roll = sum[i]; // assign the value of sum to players.
    printf("%s rolls %d.\n", players[i].player_name , players[i].first_roll);
}

}




