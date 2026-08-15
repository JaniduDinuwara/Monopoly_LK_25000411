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
    Red,
    LightBlue,
    Green,
    Yellow,
    Orange,
    DarkBlue,
    Pink,
    Brown
} PropertyGroup;


typedef struct {                  //create a structure for defining properties of each square
    int purchase_price;
    int mortgage_value;
    int rent_price;
    int house_construction_cost;
    int hotel_construction_cost;
    int current_owner_no;
    int mortgage_status;
    int insurance_status;
    int number_of_buildings;
    
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
    //int game_round;
} Players;



int rolldice(); //Funtion call from dice.c to main.c
void dice(); //Funtion call from dice.c to main.c
void tie_breaker(); //Funtion call from dice.c to main.c

extern Squares squares[40];
extern Players players[4];

//Squares* getBoard()
#endif 