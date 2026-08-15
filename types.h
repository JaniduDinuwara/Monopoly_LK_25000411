#ifndef TYPE_H
#define TYPE_H

typedef enum {        //create an enumeration for defining square types
    Start,
    Property,
    Event,
    Tax,
    Railway,
    Special,
    Utility,
    Insurance,
    Bank
} SquareType;

typedef enum {       // create an enumeration for defining property groups
    None,
    Brown,
    LightBlue,
    Pink,
    Orange,
    Red,
    Yellow,
    Green,
    DarkBlue
} PropertyGroup;


typedef struct {                  //create a structure for defining properties of each square
    int purchase_price;
    int rent_price;
    int current_owner_no;
    int mortgage_status;
    int insurance_status;
    int number_of_buildings;
     int mortgage_value;
     int house_construction_cost;
    int hotel_construction_cost;
    
    
} Properties;

typedef enum {  //create an enumeration for defining player types to identify each player and go to the corresponding function
    Aggressive_Investor,
    Conservative_Banker,
    Risk_Taker,
    Opportunistic_Trader
} PlayerType;







typedef struct {            //create a structure for defining each square on the board

    SquareType square_type;
    PropertyGroup property_group;
    Properties property_details;
     char square_name[50];
     int square_id;

} Squares;

typedef struct {
    int player_id;
    char player_name[40];
    int balance;
    int current_position;
    int first_roll;
    int dice_roll;
    int player_round;
    int total_property;
    int total_railways;
    int total_utilities;
    int net_worth;

    PlayerType player_type;
    int game_round;
} Players;

typedef struct {
    PropertyGroup property_group;
    Properties property_details;
    int last_boom_round;
    int last_decline_round;
    

} PropertyColour;

int rolldice(); //Funtion call from dice.c to main.c
void dice(); //Funtion call from dice.c to main.c
void tie_breaker(); //Funtion call from dice.c to main.c
int dynamic_property_market(int game_round); //Funtion call from economy.c to main.c
void apply_market_boom(PropertyGroup group);
void apply_market_decline(PropertyGroup group);

extern Squares squares[40];
extern Players players[4];
extern PropertyColour property_colour[8];
//Squares* getBoard()
#endif 