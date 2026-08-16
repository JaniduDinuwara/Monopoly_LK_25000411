#include <stdio.h>
#include "players.h"
#include "game.h"
#include "types.h"
#include "finance.h"


Players players[4] =
 {
//Aggresive Investor
    {.player_id = 0, 
     .player_name = "Aggressive_Investor", 
     .balance = 30000, 
     .current_position = 0,
     .first_roll = 0,
     .dice_roll=0,
     .player_round=0,
     .player_type= Aggressive_Investor,
     .total_property=0,
     .total_railways=0,
     .total_utilities=0,
     .net_worth=30000,
    .in_the_jail= 0,
   .jail_time=0,
   .loan_amount=0,
   .loan_interest=0,
   .total_hotels=0,
 },
     //.game_round=0},

//Conservative Banker
    {.player_id = 1, 
     .player_name = "Conservative_Banker", 
     .balance = 30000, 
     .current_position = 0, 
     .first_roll = 0,
     .dice_roll=0,
     .player_round=0,
     .player_type= Conservative_Banker,
     .total_property=0,
     .total_railways=0,
     .total_utilities=0,
     .net_worth=30000,
    .in_the_jail=0,
    .jail_time=0,
    .loan_amount=0,
    .loan_interest=0,
    .total_hotels=0,
  },
     //.game_round=0},

//Risk Taker
    {.player_id = 2, 
     .player_name = "Risk_Taker", 
     .balance = 30000, 
     .current_position = 0, 
     .first_roll = 0,
     .dice_roll=0,
     .player_round=0,
     .player_type= Risk_Taker,
     .total_property=0,
     .total_railways=0,
     .total_utilities=0,
     .net_worth=30000,
    .in_the_jail=0,
   .jail_time=0,
   .loan_amount=0,
   .loan_interest=0,
   .total_hotels=0,
    },
     //.game_round=0},
  
//Opportunistic Trader
    {.player_id = 3, 
     .player_name = "Opportunistic_Trader", 
     .balance = 30000, 
     .current_position = 0, 
     .first_roll = 0,
     .dice_roll=0,
     .player_round=0,
     .player_type= Opportunistic_Trader,
     .total_property=0,
     .total_railways=0,
     .total_utilities=0,
     .net_worth=30000,
    .in_the_jail=0,
    .jail_time=0,
    .loan_amount=0,
    .loan_interest=0,
    .total_hotels=0,
     }
     //.game_round=0}
};
 // declare the fuction for each player type separately
void Player_Aggressive_Investor(int j) {
    
Squares *landed_square = &squares[players[j].current_position];

if(landed_square->square_type == Property){
    if(landed_square->property_details.current_owner_no == -1){
        int price = landed_square->property_details.purchase_price;
        int future_rent = landed_square->property_details.rent_price;
        int remaining_balance = players[j].balance - price;
        if (remaining_balance >= future_rent){
            landed_square->property_details.current_owner_no = players[j].player_id;
            players[j].balance = remaining_balance;
            players[j].total_property++;
            players[j].net_worth = remaining_balance + price;

            printf("\n%s purchased %s for LKR %d\n", players[j].player_name, landed_square->square_name, landed_square->property_details.purchase_price);
            printf("Remaining Balance : LKR %d\n",players[j].balance);
        } else{ auction(j);} // go to the auction

        }else if(landed_square->property_details.current_owner_no == players[j].player_id){

            if(players[j].player_id == property_colour[0].monopoly_owner && landed_square->property_details.mortgage_status == 0){
                if (landed_square->property_details.number_of_buildings < 4) {
                  if (players[j].balance >= landed_square->property_details.house_construction_cost){
                      landed_square->property_details.number_of_buildings++;
                      players[j].balance -= landed_square->property_details.house_construction_cost;
                      players[j].net_worth -= landed_square->property_details.house_construction_cost;
                      players[j].net_worth += landed_square->property_details.house_construction_cost;
                      printf("\n%s constructed a house on %s\n", players[j].player_name, landed_square->square_name, landed_square->property_details.house_construction_cost);
                      printf("construction cost : LKR %d\n",landed_square->property_details.house_construction_cost);

                      if (landed_square->property_details.number_of_buildings == 4) {
                           if (players[j].balance >= landed_square->property_details.hotel_construction_cost){
                               landed_square->property_details.no_of_hotels++;
                               players[j].balance -= landed_square->property_details.hotel_construction_cost;
                               players[j].net_worth -= landed_square->property_details.hotel_construction_cost;
                               players[j].net_worth += landed_square->property_details.hotel_construction_cost;
                               printf("\n%s upgraded %s to a hotel\n", players[j].player_name, landed_square->square_name, landed_square->property_details.hotel_construction_cost);
                           }
                        }    
                           }
                  }
            }
    
        }else{
            if(landed_square->property_details.number_of_buildings == 0){
            int rent = landed_square->property_details.rent_price;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);
            }
            for(int i = 1; i<4; i++){
                if(landed_square->property_details.number_of_buildings == i){
                    int rent = landed_square->property_details.rent_price*(i+1);
                    int remaining_balance = players[j].balance - rent;
                    players[j].balance = remaining_balance;
                    players[landed_square->property_details.current_owner_no].balance += rent;
                    players[j].net_worth -= rent;
                    printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
                    printf("Rent paid : LKR %d\n",rent);
                    printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);
                }
            }
        }
    
    }else if(landed_square->square_type == Event){
    
    }else if(landed_square->square_type == Tax){

    }else if(landed_square->square_type == Railway){
        if(landed_square->property_details.current_owner_no == -1){
        int price = landed_square->property_details.purchase_price;
        int remaining_balance = players[j].balance - price;
        if (remaining_balance >= players[j].balance * 0.50){
            landed_square->property_details.current_owner_no = players[j].player_id;
            players[j].balance = remaining_balance;
            players[j].total_railways++;
            players[j].net_worth += landed_square->property_details.purchase_price;
            printf("\n%s purchased %s for LKR %d\n", players[j].player_name, landed_square->square_name, landed_square->property_details.purchase_price);
            printf("Remaining Balance : LKR %d\n",players[j].balance);
        } // no action. he goes to next turn

        }else if(landed_square->property_details.current_owner_no == players[j].player_id){
             printf("This Is Mine");  //for now, the player does not get action

        }else if(players[landed_square->property_details.current_owner_no].total_railways == 1){
            int rent = landed_square->property_details.rent_price;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);

        }else if(players[landed_square->property_details.current_owner_no].total_railways == 2){
            int rent = 500;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);

        }else if(players[landed_square->property_details.current_owner_no].total_railways == 3){
            int rent = 1000;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);

        }else if(players[landed_square->property_details.current_owner_no].total_railways == 4){
            int rent = 2000;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);   
        }
    }else if(landed_square->square_type == Special){
            come_from_jail(j,0,0);

    }else if(landed_square->square_type == Utility){

        if(landed_square->property_details.current_owner_no == -1){
        int price = landed_square->property_details.purchase_price;
        int remaining_balance = players[j].balance - price;
        if (remaining_balance >= players[j].balance * 0.50){
            landed_square->property_details.current_owner_no = players[j].player_id;
            players[j].balance = remaining_balance;
            printf("\n%s purchased %s for LKR %d\n", players[j].player_name, landed_square->square_name, landed_square->property_details.purchase_price);
            printf("Remaining Balance : LKR %d\n",players[j].balance);
            players[j].total_utilities++;
            players[j].net_worth += landed_square->property_details.purchase_price;
        } // no action. he goes to next turn

        }else if(landed_square->property_details.current_owner_no == players[j].player_id){
             printf("This Is Mine");  //for now, the player does not get action

        }else if(players[landed_square->property_details.current_owner_no].total_utilities == 1){
            int rent = 4*players[j].dice_roll;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);

        }else if(players[landed_square->property_details.current_owner_no].total_utilities == 2){
            int rent = 10*players[j].dice_roll;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);    
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);
        }

    }else if(landed_square->square_type == Insurance){

    }else if(landed_square->square_type == Bank){
         take_loan(j);
    }
//printf("\n%s landed on %s for LKR %d\n", players[j].player_name, landed_square->square_name, landed_square->property_details.purchase_price);
   
}



void Player_Conservative_Banker(int j) {

Squares *landed_square = &squares[players[j].current_position];
if(landed_square->square_type == Property){
    if(landed_square->property_details.current_owner_no == -1){
        int price = landed_square->property_details.purchase_price;
        int remaining_balance = players[j].balance - price;
        if (remaining_balance >= players[j].balance * 0.50){
            landed_square->property_details.current_owner_no = players[j].player_id;
            players[j].balance = remaining_balance;
            players[j].total_property++;
            players[j].net_worth = remaining_balance + price;

            printf("\n%s purchased %s for LKR %d\n", players[j].player_name, landed_square->square_name, landed_square->property_details.purchase_price);
            printf("Remaining Balance : LKR %d\n",players[j].balance);
        } else{ auction(j);} // go to the auction

        }else if(landed_square->property_details.current_owner_no == players[j].player_id){

            if(players[j].player_id == property_colour[0].monopoly_owner && landed_square->property_details.mortgage_status == 0){
                 if (landed_square->property_details.number_of_buildings < 4) {
        if (players[j].balance >=landed_square->property_details.house_construction_cost){
            landed_square->property_details.number_of_buildings++;
            players[j].balance -= landed_square->property_details.house_construction_cost;
            players[j].net_worth -= landed_square->property_details.house_construction_cost;
            players[j].net_worth += landed_square->property_details.house_construction_cost;
            printf("\n%s constructed a house on %s\n", players[j].player_name, landed_square->square_name, landed_square->property_details.house_construction_cost);
            printf("construction cost : LKR %d\n",landed_square->property_details.house_construction_cost);

            if (landed_square->property_details.number_of_buildings == 4) {
                if(players[j].loan_amount == 0){
                   if (players[j].balance >= landed_square->property_details.hotel_construction_cost){
                       landed_square->property_details.no_of_hotels++;
                       players[j].balance -= landed_square->property_details.hotel_construction_cost;
                       players[j].net_worth -= landed_square->property_details.hotel_construction_cost;
                       players[j].net_worth += landed_square->property_details.hotel_construction_cost;
                       printf("\n%s upgraded %s to a hotel\n", players[j].player_name, landed_square->square_name, landed_square->property_details.hotel_construction_cost);
                   }
                }    
                   }
            }
        }
        }

             
        }else{
            if(landed_square->property_details.number_of_buildings == 0){
            int rent = landed_square->property_details.rent_price;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);
        } 
        for(int i = 1; i<4; i++){
                if(landed_square->property_details.number_of_buildings == i){
                    int rent = landed_square->property_details.rent_price*(i+1);
                    int remaining_balance = players[j].balance - rent;
                    players[j].balance = remaining_balance;
                    players[landed_square->property_details.current_owner_no].balance += rent;
                    players[j].net_worth -= rent;
                    printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
                    printf("Rent paid : LKR %d\n",rent);
                    printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);
                }
            }
        }
    
    }else if(landed_square->square_type == Event){
    
    }else if(landed_square->square_type == Tax){

    }else if(landed_square->square_type == Railway){
        if(landed_square->property_details.current_owner_no == -1){
        int price = landed_square->property_details.purchase_price;
        int remaining_balance = players[j].balance - price;
        if (remaining_balance >= players[j].balance * 0.50){
            landed_square->property_details.current_owner_no = players[j].player_id;
            players[j].balance = remaining_balance;
            players[j].total_railways++;
            players[j].net_worth += landed_square->property_details.purchase_price;
            printf("\n%s purchased %s for LKR %d\n", players[j].player_name, landed_square->square_name, landed_square->property_details.purchase_price);
            printf("Remaining Balance : LKR %d\n",players[j].balance);
        } // no action. he goes to next turn
        }else if(landed_square->property_details.current_owner_no == players[j].player_id){
             printf("This Is Mine");  //for now, the player does not get action

        }else if(players[landed_square->property_details.current_owner_no].total_railways == 1){
            int rent = landed_square->property_details.rent_price;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);

        }else if(players[landed_square->property_details.current_owner_no].total_railways == 2){
            int rent = 500;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);

        }else if(players[landed_square->property_details.current_owner_no].total_railways == 3){
            int rent = 1000;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);

        }else if(players[landed_square->property_details.current_owner_no].total_railways == 4){
            int rent = 2000;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);   
        }
    }else if(landed_square->square_type == Special){
            come_from_jail(j,0,0);

    }else if(landed_square->square_type == Utility){

        if(landed_square->property_details.current_owner_no == -1){
        int price = landed_square->property_details.purchase_price;
        int remaining_balance = players[j].balance - price;
        if (remaining_balance >= players[j].balance * 0.50){
            landed_square->property_details.current_owner_no = players[j].player_id;
            players[j].balance = remaining_balance;
            printf("\n%s purchased %s for LKR %d\n", players[j].player_name, landed_square->square_name, landed_square->property_details.purchase_price);
            printf("Remaining Balance : LKR %d\n",players[j].balance);
            players[j].total_utilities++;
            players[j].net_worth += landed_square->property_details.purchase_price;
        } // no action. he goes to next turn

        }else if(landed_square->property_details.current_owner_no == players[j].player_id){
             printf("This Is Mine");  //for now, the player does not get action

        }else if(players[landed_square->property_details.current_owner_no].total_utilities == 1){
            int rent = 4*players[j].dice_roll;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);

        }else if(players[landed_square->property_details.current_owner_no].total_utilities == 2){
            int rent = 10*players[j].dice_roll;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);    
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);
        }

    }else if(landed_square->square_type == Insurance){

    }else if(landed_square->square_type == Bank){
           take_loan(j);
    }
//printf("\n%s landed on %s for LKR %d\n", players[j].player_name, landed_square->square_name, landed_square->property_details.purchase_price);
   
}


void Player_Risk_Taker(int j) {
    
Squares *landed_square = &squares[players[j].current_position];

if(landed_square->square_type == Property){
    if(landed_square->property_details.current_owner_no == -1){
        int price = landed_square->property_details.purchase_price;
        int remaining_balance = players[j].balance - price;
        if (players[j].balance >= price){
            landed_square->property_details.current_owner_no = players[j].player_id;
            players[j].balance = remaining_balance;
            players[j].total_property++;
            players[j].net_worth = remaining_balance + price;

            printf("\n%s purchased %s for LKR %d\n", players[j].player_name, landed_square->square_name, landed_square->property_details.purchase_price);
            printf("Remaining Balance : LKR %d\n",players[j].balance);

        } else{ auction(j);} // go to the auction


        }else if(landed_square->property_details.current_owner_no == players[j].player_id){
            if(players[j].player_id == property_colour[0].monopoly_owner && landed_square->property_details.mortgage_status == 0){

                //he like to construct hotel as early as possible. therefore, first of all he try to build hotel.
                 if (landed_square->property_details.number_of_buildings == 4) {
        if (players[j].balance >=landed_square->property_details.hotel_construction_cost){
            landed_square->property_details.no_of_hotels++;
            players[j].balance -= landed_square->property_details.hotel_construction_cost;
            players[j].net_worth -= landed_square->property_details.hotel_construction_cost;
            players[j].net_worth += landed_square->property_details.hotel_construction_cost;
            printf("\n%s upgraded %s to a hotel\n", players[j].player_name, landed_square->square_name, landed_square->property_details.hotel_construction_cost);
        }
    
        }else if (landed_square->property_details.number_of_buildings < 4){  //constructs the house

        if (players[j].balance >=landed_square->property_details.house_construction_cost){
            landed_square->property_details.number_of_buildings++;
            players[j].balance -= landed_square->property_details.house_construction_cost;
            players[j].net_worth -= landed_square->property_details.house_construction_cost;
            players[j].net_worth += landed_square->property_details.house_construction_cost;
            printf("\n%s constructed a house on %s\n", players[j].player_name, landed_square->square_name, landed_square->property_details.house_construction_cost);
            printf("construction cost : LKR %d\n",landed_square->property_details.house_construction_cost);
        }
        }
    }   
        }else {
            if(landed_square->property_details.number_of_buildings == 0){
            int rent = landed_square->property_details.rent_price;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);
        }
        for(int i = 1; i<4; i++){
                if(landed_square->property_details.number_of_buildings == i){
                    int rent = landed_square->property_details.rent_price*(i+1);
                    int remaining_balance = players[j].balance - rent;
                    players[j].balance = remaining_balance;
                    players[landed_square->property_details.current_owner_no].balance += rent;
                    players[j].net_worth -= rent;
                    printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
                    printf("Rent paid : LKR %d\n",rent);
                    printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);
                }
            }
        }
    
    }else if(landed_square->square_type == Event){
    
    }else if(landed_square->square_type == Tax){

    }else if(landed_square->square_type == Railway){

        if(landed_square->property_details.current_owner_no == -1){
        int price = landed_square->property_details.purchase_price;
        int remaining_balance = players[j].balance - price;
        if (remaining_balance >= players[j].balance * 0.50){
            landed_square->property_details.current_owner_no = players[j].player_id;
            players[j].balance = remaining_balance;
            players[j].total_railways++;
            players[j].net_worth += landed_square->property_details.purchase_price;
            printf("\n%s purchased %s for LKR %d\n", players[j].player_name, landed_square->square_name, landed_square->property_details.purchase_price);
            printf("Remaining Balance : LKR %d\n",players[j].balance);
        } // no action. he goes to next turn

        }else if(landed_square->property_details.current_owner_no == players[j].player_id){
             printf("This Is Mine");  //for now, the player does not get action

        }else if(players[landed_square->property_details.current_owner_no].total_railways == 1){
            int rent = landed_square->property_details.rent_price;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);

        }else if(players[landed_square->property_details.current_owner_no].total_railways == 2){
            int rent = 500;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);

        }else if(players[landed_square->property_details.current_owner_no].total_railways == 3){
            int rent = 1000;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);

        }else if(players[landed_square->property_details.current_owner_no].total_railways == 4){
            int rent = 2000;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);   
        }
    }else if(landed_square->square_type == Special){
          come_from_jail(j,0,0);

    }else if(landed_square->square_type == Utility){

        if(landed_square->property_details.current_owner_no == -1){
        int price = landed_square->property_details.purchase_price;
        int remaining_balance = players[j].balance - price;
        if (remaining_balance >= players[j].balance * 0.50){
            landed_square->property_details.current_owner_no = players[j].player_id;
            players[j].balance = remaining_balance;
            printf("\n%s purchased %s for LKR %d\n", players[j].player_name, landed_square->square_name, landed_square->property_details.purchase_price);
            printf("Remaining Balance : LKR %d\n",players[j].balance);
            players[j].total_utilities++;
            players[j].net_worth += landed_square->property_details.purchase_price;
        } // no action. he goes to next turn

        }else if(landed_square->property_details.current_owner_no == players[j].player_id){
             printf("This Is Mine");  //for now, the player does not get action

        }else if(players[landed_square->property_details.current_owner_no].total_utilities == 1){
            int rent = 4*players[j].dice_roll;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);

        }else if(players[landed_square->property_details.current_owner_no].total_utilities == 2){
            int rent = 10*players[j].dice_roll;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);    
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);
        }

    }else if(landed_square->square_type == Insurance){

    }else if(landed_square->square_type == Bank){
          take_loan(j);
    }
   //printf("\n%s landed on %s for LKR %d\n", players[j].player_name, landed_square->square_name, landed_square->property_details.purchase_price);

}

void Player_Opportunistic_Trader(int j) {

Squares *landed_square = &squares[players[j].current_position];

if(landed_square->square_type == Property){
    if(landed_square->property_details.current_owner_no == -1){
        int price = landed_square->property_details.purchase_price;
        int remaining_balance = players[j].balance - price;
        int house_construction_cost = landed_square->property_details.house_construction_cost ;
        int hotel_construction_cost = landed_square->property_details.hotel_construction_cost;
        if (remaining_balance > house_construction_cost || remaining_balance > hotel_construction_cost){
            landed_square->property_details.current_owner_no = players[j].player_id;
            players[j].balance = remaining_balance;
            players[j].total_property++;
            players[j].net_worth = remaining_balance + price;

            printf("\n%s purchased %s for LKR %d\n", players[j].player_name, landed_square->square_name, landed_square->property_details.purchase_price);
            printf("Remaining Balance : LKR %d\n",players[j].balance);

        } else { auction(j);}
        
        // go to the auction
        }else if(landed_square->property_details.current_owner_no == players[j].player_id){

            if(players[j].player_id == property_colour[0].monopoly_owner && landed_square->property_details.mortgage_status == 0){

                //if (inflation_active == 0){ // he construct buldings avoid inflation.

                    if (landed_square->property_details.number_of_buildings < 4) {
                        if (players[j].balance >= landed_square->property_details.house_construction_cost){
                            landed_square->property_details.number_of_buildings++;
                            players[j].balance -= landed_square->property_details.house_construction_cost;
                            players[j].net_worth -= landed_square->property_details.house_construction_cost;
                            players[j].net_worth += landed_square->property_details.house_construction_cost;
                            printf("\n%s constructed a house on %s\n", players[j].player_name, landed_square->square_name, landed_square->property_details.house_construction_cost);
                            printf("construction cost : LKR %d\n",landed_square->property_details.house_construction_cost);

                 if (landed_square->property_details.number_of_buildings == 4) {
                     if (players[j].balance >= landed_square->property_details.hotel_construction_cost){
                     landed_square->property_details.no_of_hotels++;
                    players[j].balance -= landed_square->property_details.hotel_construction_cost;
                     players[j].net_worth -= landed_square->property_details.hotel_construction_cost;
                    players[j].net_worth += landed_square->property_details.hotel_construction_cost;
                     printf("\n%s upgraded %s to a hotel\n", players[j].player_name, landed_square->square_name, landed_square->property_details.hotel_construction_cost);
                                }
                            }
                        }
                    }
//}

                }
            
        }else{
            if(landed_square->property_details.number_of_buildings == 0){
            int rent = landed_square->property_details.rent_price;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);
        }
        for(int i = 1; i<4; i++){
                if(landed_square->property_details.number_of_buildings == i){
                    int rent = landed_square->property_details.rent_price*(i+1);
                    int remaining_balance = players[j].balance - rent;
                    players[j].balance = remaining_balance;
                    players[landed_square->property_details.current_owner_no].balance += rent;
                    players[j].net_worth -= rent;
                    printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
                    printf("Rent paid : LKR %d\n",rent);
                    printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);
                }
            }
        }
    
    }else if(landed_square->square_type == Event){
    
    }else if(landed_square->square_type == Tax){

    }else if(landed_square->square_type == Railway){
        if(landed_square->property_details.current_owner_no == -1){
        int price = landed_square->property_details.purchase_price;
        int remaining_balance = players[j].balance - price;
        int house_construction_cost = landed_square->property_details.house_construction_cost ;
        int hotel_construction_cost = landed_square->property_details.hotel_construction_cost;
        if (remaining_balance > house_construction_cost || remaining_balance > hotel_construction_cost){
            landed_square->property_details.current_owner_no = players[j].player_id;
            players[j].balance = remaining_balance;
            players[j].total_railways++;
            players[j].net_worth = remaining_balance + price;
            printf("\n%s purchased %s for LKR %d\n", players[j].player_name, landed_square->square_name, landed_square->property_details.purchase_price);
            printf("Remaining Balance : LKR %d\n",players[j].balance);
        } // no action. he goes to next turn
        }else if(landed_square->property_details.current_owner_no == players[j].player_id){
             printf("This Is Mine");  //for now, the player does not get action

        }else if(players[landed_square->property_details.current_owner_no].total_railways == 1){
            int rent = landed_square->property_details.rent_price;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);

        }else if(players[landed_square->property_details.current_owner_no].total_railways == 2){
            int rent = 500;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);

        }else if(players[landed_square->property_details.current_owner_no].total_railways == 3){
            int rent = 1000;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);

        }else if(players[landed_square->property_details.current_owner_no].total_railways == 4){
            int rent = 2000;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);   
        }
    }else if(landed_square->square_type == Special){
            come_from_jail(j,0,0);

    }else if(landed_square->square_type == Utility){

        if(landed_square->property_details.current_owner_no == -1){
        int price = landed_square->property_details.purchase_price;
        int remaining_balance = players[j].balance - price;
        int house_construction_cost = landed_square->property_details.house_construction_cost ;
        int hotel_construction_cost = landed_square->property_details.hotel_construction_cost;
        if (remaining_balance > house_construction_cost || remaining_balance > hotel_construction_cost){
            landed_square->property_details.current_owner_no = players[j].player_id;
            players[j].balance = remaining_balance;
            printf("\n%s purchased %s for LKR %d\n", players[j].player_name, landed_square->square_name, landed_square->property_details.purchase_price);
            printf("Remaining Balance : LKR %d\n",players[j].balance);
            players[j].total_utilities++;
            players[j].net_worth = remaining_balance + price;
        } // no action. he goes to next turn

        }else if(landed_square->property_details.current_owner_no == players[j].player_id){
             printf("This Is Mine");  //for now, the player does not get action

        }else if(players[landed_square->property_details.current_owner_no].total_utilities == 1){
            int rent = 4*players[j].dice_roll;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);

        }else if(players[landed_square->property_details.current_owner_no].total_utilities == 2){
            int rent = 10*players[j].dice_roll;
            int remaining_balance = players[j].balance - rent;
            players[j].balance = remaining_balance;
            players[landed_square->property_details.current_owner_no].balance += rent;
            players[j].net_worth -= rent;
            printf("\n%s landed on %s.\n", players[j].player_name, landed_square->square_name);
            printf("Rent paid : LKR %d\n",rent);    
            printf("Owner : %s\n",players[landed_square->property_details.current_owner_no].player_name);
        }

    }else if(landed_square->square_type == Insurance){

    }else if(landed_square->square_type == Bank){
             take_loan(j);
    }
//printf("\n%s landed on %s for LKR %d\n", players[j].player_name, landed_square->square_name, landed_square->property_details.purchase_price);

}