#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "game.h"



void apply_market_boom(PropertyGroup group)
{
    for (int i = 0; i < 40; i++) {
        if (squares[i].property_group == group) {

            squares[i].property_details.mortgage_value = (squares[i].property_details.mortgage_value * 1.15);
            squares[i].property_details.house_construction_cost =(squares[i].property_details.house_construction_cost * 1.10);
            squares[i].property_details.hotel_construction_cost =(squares[i].property_details.hotel_construction_cost * 1.10);
            squares[i].property_details.rent_price =(squares[i].property_details.rent_price * 1.25);
            squares[i].property_details.purchase_price = (squares[i].property_details.purchase_price * 1.15);
      }
}
}

void apply_market_decline(PropertyGroup group)
{
    for (int i = 0; i < 40; i++){
        if (squares[i].property_group == group) {

            squares[i].property_details.mortgage_value =(squares[i].property_details.mortgage_value * 0.90);
            squares[i].property_details.rent_price =(squares[i].property_details.rent_price * 0.80);
            squares[i].property_details.purchase_price =(squares[i].property_details.purchase_price * 0.85);

     }
 }
}


int dynamic_property_market(int game_round)
{
    if (game_round % 10 != 0)
    {
        return 0;
    }

    int market_boom_group = -1;
    int random_group = rand() % 8;

    if (game_round -property_colour[random_group].last_boom_round >= 30)
    {
        market_boom_group = random_group;
        property_colour[random_group].last_boom_round =game_round;

        apply_market_boom(property_colour[random_group].property_group);

        printf("\nProperty Group : %d\n", property_colour[random_group].property_group);
        printf("Boom Round : %d\n",game_round);

        
    }

    int market_decline_group = -1;
    random_group = rand() % 8;

    if (game_round - property_colour[random_group].last_decline_round >= 30)
    {
        market_decline_group = random_group;
        property_colour[random_group].last_decline_round =game_round;

        apply_market_decline(property_colour[random_group].property_group);

        printf("Property Group : %d\n", property_colour[random_group].property_group);

        printf("Decline Round : %d\n",game_round);

    
    }


    return 1;
}