#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "game.h"



int dynamic_property_market(int game_round){

  //  if (game_round %10 != 0){

    //    return ;
   // }
    
    
if(game_round %10 == 0){
    int market_boom_group = -1;
    int random_group = (rand() % 8) ;
    if (random_group != market_boom_group && game_round - property_colour[random_group].last_boom_round >= 30){
        market_boom_group = random_group;

property_colour[random_group].last_boom_round = game_round;
property_colour[random_group].property_details.mortgage_value *= 1.15;
property_colour[random_group].property_details.house_construction_cost *= 1.10;
property_colour[random_group].property_details.hotel_construction_cost *= 1.10;
squares[property_colour[random_group].property_group].property_details.rent_price *= 1.25;
squares[property_colour[random_group].property_group].property_details.purchase_price *= 1.15;
printf("\nMarket Boom Group : %d\n",market_boom_group);
printf("\nmortgage value : %d\n",property_colour[market_boom_group].property_details.mortgage_value);
 printf("\nhouse construction cost : %d\n",property_colour[market_boom_group].property_details.house_construction_cost);
 printf("\nhotel construction cost : %d\n",property_colour[market_boom_group].property_details.hotel_construction_cost);
 printf("\nrent price : %d\n",squares[property_colour[market_boom_group].property_group].property_details.rent_price);
 printf("\npurchase price : %d\n",squares[property_colour[market_boom_group].property_group].property_details.purchase_price);
        //break;
    }
}
 if(game_round %10 == 0){
    int market_decline_group = -1;
    int random_group = (rand() % 8);
    if (random_group != market_decline_group && game_round - property_colour[random_group].last_decline_round >= 30){
        market_decline_group = random_group;
        property_colour[random_group].last_decline_round = game_round;
        property_colour[random_group].property_details.mortgage_value *= 0.90;
    squares[property_colour[random_group].property_group].property_details.rent_price *= 0.80;
    printf("\nMarket Decline Group : %d\n",market_decline_group);       

        //break;
    }
}


}