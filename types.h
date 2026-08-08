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
    double purchase_price;
    double mortgage_value;
    double rent_price;
    double house_construction_cost;
    double hotel_construction_cost;
    int current_owner_no;
    int mortgage_status;
    int insurance_status;
    int number_of_buildings;
} Properties;







typedef struct {            //create a structure for defining each square on the board

    SquareType square_type;
    PropertyGroup property_group;
    Properties property_details;
     char square_name[50];
     int square_id;

} Squares;

int rolldice(); //Funtion call from dice.c to main.c
void dice(int sum[4]); //Funtion call from dice.c to main.c

extern Squares squares[40];
//Squares* getBoard()
#endif 