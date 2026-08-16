#include <stdio.h>
#include "types.h"
#include "players.h"

void take_loan(int j){
    
Squares *landed_square = &squares[players[j].current_position];

int maximum_loan = 0;
int total_mortgage_value = 0;
for(int i = 0; i<40; i++){
    if(squares[i].property_details.current_owner_no == players[j].player_id){
        total_mortgage_value += squares[i].property_details.mortgage_value;
        //printf("Total Mortagage Value is %d\n", total_mortgage_value);
    }
}
maximum_loan = total_mortgage_value *0.75;  //calculate players can maximum loan
// this is only for testing. loan amount decide according to the player behaviors.
int loan_amount =5000;
if(maximum_loan > loan_amount){
    players[j].loan_amount += 5000;
    players[j].balance += 5000;
    printf("\n%s takes loan of LKR %d\n", players[j].player_name,loan_amount);

}
}