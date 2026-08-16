#include "types.h"

Squares squares[40] =
{
    /* 0 */ 
    {
        .square_id = 0,
        .square_type = Start,
        .square_name = "GO",
        .property_group = None
    },

    /* 1 */
    {
        .square_id = 1,
        .square_type = Property,
        .square_name = "Pettah",
        .property_group = Brown,
        .property_details = {
            .purchase_price = 1500,
            .mortgage_value = 750,
            .rent_price = 100,
            .house_construction_cost = 500,
            .hotel_construction_cost = 2000,
            .current_owner_no = -1,
        
        }
    },

    /* 2 */
    {
        .square_id = 2,
        .square_type = Event,
        .square_name = "Community Development Fund",
        .property_group = None
    },

    /* 3 */
    {
        .square_id = 3,
        .square_type = Property,
        .square_name = "Maradana",
        .property_group = Brown,
        .property_details = {
            .purchase_price = 1800,
            .mortgage_value = 750,
            .rent_price = 120,
            .house_construction_cost = 500,
            .hotel_construction_cost = 2000,
            .current_owner_no = -1,
            
        }
    },

    /* 4 */
    {
        .square_id = 4,
        .square_type = Tax,
        .square_name = "Income Tax",
        .property_group = None
    },

    /* 5 */
    {
        .square_id = 5,
        .square_type = Railway,
        .square_name = "Colombo Fort Railway Station",
        .property_group = None,
        .property_details = {
            .purchase_price = 1500,
            .mortgage_value = 750,
            .rent_price = 250,
            .current_owner_no = -1,
        }
    },

    /* 6 */
    {
        .square_id = 6,
        .square_type = Property,
        .square_name = "Bambalapitiya",
        .property_group = LightBlue,
        .property_details = {
            .purchase_price = 2500,
            .mortgage_value = 1250,
            .rent_price = 180,
            .house_construction_cost = 750,
            .hotel_construction_cost = 3000,
            .current_owner_no = -1,
            
        }
    },

    /* 7 */
    {
        .square_id = 7,
        .square_type = Event,
        .square_name = "National Event Card",
        .property_group = None
    },

    /* 8 */
    {
        .square_id = 8,
        .square_type = Property,
        .square_name = "Wellawatte",
        .property_group = LightBlue,
        .property_details = {
            .purchase_price = 2700,
            .mortgage_value = 1250,
            .rent_price = 200,
            .house_construction_cost = 750,
            .hotel_construction_cost = 3000,
            .current_owner_no = -1,
        
        }
    },

    /* 9 */
    {
        .square_id = 9,
        .square_type = Property,
        .square_name = "Mount Lavinia",
        .property_group = LightBlue,
        .property_details = {
            .purchase_price = 3000,
            .mortgage_value = 1250,
            .rent_price = 220,
            .house_construction_cost = 750,
            .hotel_construction_cost = 3000,
            .current_owner_no = -1,
        
        }
    },

    /* 10 */
    {
        .square_id = 10,
        .square_type = Special,
        .square_name = "Jail / Just Visiting",
        .property_group = None
    },

    /* 11 */
    {
        .square_id = 11,
        .square_type = Property,
        .square_name = "Nugegoda",
        .property_group = Pink,
        .property_details = {
            .purchase_price = 3500,
            .mortgage_value = 1750,
            .rent_price = 260,
            .house_construction_cost = 1000,
            .hotel_construction_cost = 4000,
            .current_owner_no = -1,
        }
    },

    /* 12 */
    {
        .square_id = 12,
        .square_type = Utility,
        .square_name = "Ceylon Electricity Board",
        .property_group = None,
        .property_details = {
            .purchase_price = 1500,
            .mortgage_value = 750,
            .current_owner_no = -1,
        }
    },

    /* 13 */
    {
        .square_id = 13,
        .square_type = Property,
        .square_name = "Maharagama",
        .property_group = Pink,
        .property_details = {
            .purchase_price = 3800,
            .mortgage_value = 1750,
            .rent_price = 280,
            .house_construction_cost = 1000,
            .hotel_construction_cost = 4000,
            .current_owner_no = -1,
        }
    },

    /* 14 */
    {
        .square_id = 14,
        .square_type = Property,
        .square_name = "Kottawa",
        .property_group = Pink,
        .property_details = {
            .purchase_price = 4000,
            .mortgage_value = 1750,
            .rent_price = 300,
            .house_construction_cost = 1000,
            .hotel_construction_cost = 4000,
            .current_owner_no = -1,
        }
    },

    /* 15 */
    {
        .square_id = 15,
        .square_type = Railway,
        .square_name = "Kandy Railway Station",
        .property_group = None,
        .property_details = {
            .purchase_price = 1500,
            .mortgage_value = 750,
            .rent_price = 250,
            .current_owner_no = -1,
        }
    },

    /* 16 */
    {
        .square_id = 16,
        .square_type = Property,
        .square_name = "Negombo",
        .property_group = Orange,
        .property_details = {
            .purchase_price = 4500,
            .mortgage_value = 2250,
            .rent_price = 350,
            .house_construction_cost = 1250,
            .hotel_construction_cost = 5000,
            .current_owner_no = -1,
        }
    },

    /* 17 */
    {
        .square_id = 17,
        .square_type = Insurance,
        .square_name = "Sri Lanka Insurance",
        .property_group = None,
        .property_details = {
            .purchase_price = 1500,
            .mortgage_value = 750,
            .current_owner_no = -1,
        }
    },

    /* 18 */
    {
        .square_id = 18,
        .square_type = Property,
        .square_name = "Katunayake",
        .property_group = Orange,
        .property_details = {
            .purchase_price = 4700,
            .mortgage_value = 2250,
            .rent_price = 370,
            .house_construction_cost = 1250,
            .hotel_construction_cost = 5000,
            .current_owner_no = -1,
        }
    },

    /* 19 */
    {
        .square_id = 19,
        .square_type = Property,
        .square_name = "Ja-Ela",
        .property_group = Orange,
        .property_details = {
            .purchase_price = 5000.,
            .mortgage_value = 2250,
            .rent_price = 400,
            .house_construction_cost = 1250,
            .hotel_construction_cost = 5000,
            .current_owner_no = -1,
        }
    },

    /* 20 */
    {
        .square_id = 20,
        .square_type = Special,
        .square_name = "Free Parking",
        .property_group = None
    },

    /* 21 */
    {
        .square_id = 21,
        .square_type = Property,
        .square_name = "Kandy City",
        .property_group = Red,
        .property_details = {
            .purchase_price = 5500,
            .mortgage_value = 2750,
            .rent_price = 450,
            .house_construction_cost = 1500,
            .hotel_construction_cost = 6000,
            .current_owner_no = -1,
        }
    },

    /* 22 */
    {
        .square_id = 22,
        .square_type = Event,
        .square_name = "National Event Card",
        .property_group = None
    },

    /* 23 */
    {
        .square_id = 23,
        .square_type = Property,
        .square_name = "Peradeniya",
        .property_group = Red,
        .property_details = {
            .purchase_price = 5800,
            .mortgage_value = 2750,
            .rent_price = 480,
            .house_construction_cost = 1500,
            .hotel_construction_cost = 6000,
            .current_owner_no = -1,
        }
    },

    /* 24 */
    {
        .square_id = 24,
        .square_type = Property,
        .square_name = "Katugastota",
        .property_group = Red,
        .property_details = {
            .purchase_price = 6000,
            .mortgage_value = 2750,
            .rent_price = 500,
            .house_construction_cost = 1500,
            .hotel_construction_cost = 6000,
            .current_owner_no = -1,
        }
    },

    /* 25 */
    {
        .square_id = 25,
        .square_type = Railway,
        .square_name = "Galle Railway Station",
        .property_group = None,
        .property_details = {
            .purchase_price = 1500,
            .mortgage_value = 750,
            .rent_price = 250,
            .current_owner_no = -1,
        }
    },

    /* 26 */
    {
        .square_id = 26,
        .square_type = Property,
        .square_name = "Galle Fort",
        .property_group = Yellow,
        .property_details = {
            .purchase_price = 6500,
            .mortgage_value = 3250,
            .rent_price = 600,
            .house_construction_cost = 2000,
            .hotel_construction_cost = 8000,
            .current_owner_no = -1,
        }
    },

    /* 27 */
    {
        .square_id = 27,
        .square_type = Property,
        .square_name = "Unawatuna",
        .property_group = Yellow,
        .property_details = {
            .purchase_price = 6800,
            .mortgage_value = 3250,
            .rent_price = 620,
            .house_construction_cost = 2000,
            .hotel_construction_cost = 8000,
            .current_owner_no = -1,
        }
    },

    /* 28 */
    {
        .square_id = 28,
        .square_type = Utility,
        .square_name = "National Water Supply and Drainage Board",
        .property_group = None,
        .property_details = {
            .purchase_price = 1500,
            .mortgage_value = 750,
            .rent_price = 250,
            .current_owner_no = -1,
        }
    },

    /* 29 */
    {
        .square_id = 29,
        .square_type = Property,
        .square_name = "Hikkaduwa",
        .property_group = Yellow,
        .property_details = {
            .purchase_price = 7000,
            .mortgage_value = 3250,
            .rent_price = 650,
            .house_construction_cost = 2000,
            .hotel_construction_cost = 8000,
            .current_owner_no = -1,
        }
    },

    /* 30 */
    {
        .square_id = 30,
        .square_type = Special,
        .square_name = "Go To Jail",
        .property_group = None
    },

    /* 31 */
    {
        .square_id = 31,
        .square_type = Property,
        .square_name = "Jaffna Town",
        .property_group = Green,
        .property_details = {
            .purchase_price = 8000,
            .mortgage_value = 4000,
            .rent_price = 750,
            .house_construction_cost = 2500,
            .hotel_construction_cost = 10000,
            .current_owner_no = -1,
        }
    },

    /* 32 */
    {
        .square_id = 32,
        .square_type = Property,
        .square_name = "Nallur",
        .property_group = Green,
        .property_details = {
            .purchase_price = 8300,
            .mortgage_value = 4000,
            .rent_price = 780,
            .house_construction_cost = 2500,
            .hotel_construction_cost = 10000,
            .current_owner_no = -1,
        }
    },

    /* 33 */
    {
        .square_id = 33,
        .square_type = Insurance,
        .square_name = "Ceylinco Insurance",
        .property_group = None
    },

    /* 34 */
    {
        .square_id = 34,
        .square_type = Property,
        .square_name = "Trincomalee",
        .property_group = Green,
        .property_details = {
            .purchase_price = 8500,
            .mortgage_value = 4000,
            .rent_price = 800,
            .house_construction_cost = 2500,
            .hotel_construction_cost = 10000,
            .current_owner_no = -1,
        }
    },

    /* 35 */
    {
        .square_id = 35,
        .square_type = Railway,
        .square_name = "Jaffna Railway Station",
        .property_group = None,
        .property_details = {
            .purchase_price = 1500,
            .mortgage_value = 750,
            .rent_price = 250,
            .current_owner_no = -1,
        }
    },

    /* 36 */
    {
        .square_id = 36,
        .square_type = Event,
        .square_name = "National Event Card",
        .property_group = None
    },

    /* 37 */
    {
        .square_id = 37,
        .square_type = Property,
        .square_name = "Nuwara Eliya",
        .property_group = DarkBlue,
        .property_details = {
            .purchase_price = 10000,
            .mortgage_value = 5000,
            .rent_price = 1000,
            .house_construction_cost = 3000,
            .hotel_construction_cost = 12000,
            .current_owner_no = -1,
        }
    },

    /* 38 */
    {
        .square_id = 38,
        .square_type = Bank,
        .square_name = "Bank of Ceylon",
        .property_group = None
    },

    /* 39 */
    {
        .square_id = 39,
        .square_type = Property,
        .square_name = "Galle Face",
        .property_group = DarkBlue,
        .property_details = {
            .purchase_price = 12000,
            .mortgage_value = 5000,
            .rent_price = 1200,
            .house_construction_cost = 3000,
            .hotel_construction_cost = 12000,
            .current_owner_no = -1,
        }
    }
};


/*
 * Returns a pointer to the first square of the board.
 * The board can then be accessed using:
 *
 * board[0]
 * board[1]
 * ...
 * board[39]
 
Squares *getBoard(void)
{
    return squares;
}*/

PropertyColour property_colour[8] = 
{ 
     {.property_group = Brown, 
        .last_boom_round = 0,
         .last_decline_round = 0,
         .monopoly_owner = -1,
        .property_details = {
            .mortgage_value = 750,
            .house_construction_cost = 500,
            .hotel_construction_cost = 2000,
        }
        },

    {.property_group = LightBlue,
         .last_boom_round = 0, 
         .last_decline_round = 0,
         .monopoly_owner= -1,
        .property_details = {
            .mortgage_value = 1250,
            .house_construction_cost = 750, 
            .hotel_construction_cost = 3000,
        }
        },

    {.property_group = Pink,
         .last_boom_round = 0, 
         .last_decline_round = 0,
         .monopoly_owner= -1,
        .property_details = {
            .mortgage_value = 1750,
            .house_construction_cost = 1000, 
            .hotel_construction_cost = 4000,
        }
        },

    {.property_group = Orange, 
        .last_boom_round = 0, 
        .last_decline_round = 0,
        .monopoly_owner= -1,
    .property_details = {
            .mortgage_value = 2250,
            .house_construction_cost = 1250, 
            .hotel_construction_cost = 5000,
        }
    },

    {.property_group = Red, 
        .last_boom_round = 0, 
        .last_decline_round = 0,
        .monopoly_owner= -1,
    .property_details = {
            .mortgage_value = 2750,
            .house_construction_cost = 1500, 
            .hotel_construction_cost = 6000,
        }
    },

    {.property_group = Yellow, 
        .last_boom_round = 0, 
        .last_decline_round = 0,
        .monopoly_owner = -1,
    .property_details = {
            .mortgage_value = 3250,
            .house_construction_cost = 2000, 
            .hotel_construction_cost = 8000,
        }
    },

    {.property_group = Green, 
        .last_boom_round = 0, 
        .last_decline_round = 0,
        .monopoly_owner = -1,
    .property_details = {
            .mortgage_value = 4000,
            .house_construction_cost = 2500, 
            .hotel_construction_cost = 10000,
        }
    },

    {.property_group = DarkBlue, 
        .last_boom_round = 0,
         .last_decline_round = 0,
         .monopoly_owner= -1,
        .property_details = {
            .mortgage_value = 5000,
            .house_construction_cost = 3000, 
            .hotel_construction_cost = 12000,
        }
    }
};