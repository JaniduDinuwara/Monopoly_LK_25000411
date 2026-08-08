#include <stdio.h>
#include "types.h"     //Include the header file to access the structures and enumerations defined in types.h


Squares squares[40]  =
{
    {.square_id = 0,  .square_type = Start,     .square_name = "GO", .property_group = None,
    .property_details={.purchase_price=0.00,.mortgage_value=0.00,.rent_price=0.00,.house_construction_cost=0.00,.hotel_construction_cost=0.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 1,  .square_type = Property,  .square_name = "Pettah",.property_group = Brown,
    .property_details={.purchase_price=1500.00,.mortgage_value=750.00,.rent_price=100.00,.house_construction_cost=500.00,.hotel_construction_cost=2000.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},
    
    {.square_id = 2,  .square_type = Event,     .square_name = "Community Development Fund", .property_group = None,
    .property_details={.purchase_price=0.00,.mortgage_value=0.00,.rent_price=0.00,.house_construction_cost=0.00,.hotel_construction_cost=0.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 3,  .square_type = Property,  .square_name = "Maradana", .property_group = Brown,
    .property_details={.purchase_price=1800.00,.mortgage_value=750.00,.rent_price=120.00,.house_construction_cost=500.00,.hotel_construction_cost=2000.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 4,  .square_type = Tax,       .square_name = "Income Tax", .property_group = None,
    .property_details={.purchase_price=0.00,.mortgage_value=0.00,.rent_price=0.00,.house_construction_cost=0.00,.hotel_construction_cost=0.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 5,  .square_type = Railway,   .square_name = "Colombo Fort Railway Station", .property_group = None,
    .property_details={.purchase_price=1500.00,.mortgage_value=750.00,.rent_price=250.00,.house_construction_cost=0.00,.hotel_construction_cost=0.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 6,  .square_type = Property,  .square_name = "Bambalapitiya", .property_group = LightBlue,
    .property_details={.purchase_price=2500.00,.mortgage_value=1250.00,.rent_price=180.00,.house_construction_cost=750.00,.hotel_construction_cost=3000.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 7,  .square_type = Event,     .square_name = "National Event Card", .property_group = None,
    .property_details={.purchase_price=0.00,.mortgage_value=0.00,.rent_price=0.00,.house_construction_cost=0.00,.hotel_construction_cost=0.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 8,  .square_type = Property,  .square_name = "Wellawatte", .property_group = LightBlue,
    .property_details={.purchase_price=2700.00,.mortgage_value=1250.00,.rent_price=200.00,.house_construction_cost=750.00,.hotel_construction_cost=3000.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},
   
    {.square_id = 9,  .square_type = Property,  .square_name = "Mount Lavinia", .property_group = LightBlue,
    .property_details={.purchase_price=3000.00,.mortgage_value=1250.00,.rent_price=220.00,.house_construction_cost=750.00,.hotel_construction_cost=3000.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 10, .square_type = Special,   .square_name = "Jail / Just Visiting", .property_group = None,
    .property_details={.purchase_price=0.00,.mortgage_value=0.00,.rent_price=0.00,.house_construction_cost=0.00,.hotel_construction_cost=0.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 11, .square_type = Property,  .square_name = "Nugegoda", .property_group = Pink,
    .property_details={.purchase_price=3500.00,.mortgage_value=1750.00,.rent_price=260.00,.house_construction_cost=1000.00,.hotel_construction_cost=4000.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 12, .square_type = Utility,   .square_name = "Ceylon Electricity Board", .property_group = None,
    .property_details={.purchase_price=1500.00,.mortgage_value=750.00,.rent_price=0.00,.house_construction_cost=0.00,.hotel_construction_cost=0.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 13, .square_type = Property,  .square_name = "Maharagama", .property_group = Pink,
    .property_details={.purchase_price=3800.00,.mortgage_value=1750.00,.rent_price=280.00,.house_construction_cost=1000.00,.hotel_construction_cost=4000.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 14, .square_type = Property,  .square_name = "Kottawa", .property_group = Pink,
    .property_details={.purchase_price=4000.00,.mortgage_value=1750.00,.rent_price=300.00,.house_construction_cost=1000.00,.hotel_construction_cost=4000.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 15, .square_type = Railway,   .square_name = "Kandy Railway Station", .property_group = None,
    .property_details={.purchase_price=1500.00,.mortgage_value=750.00,.rent_price=250.00,.house_construction_cost=0.00,.hotel_construction_cost=0.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 16, .square_type = Property,  .square_name = "Negombo", .property_group = Orange,
    .property_details={.purchase_price=4500.00,.mortgage_value=2250.00,.rent_price=350.00,.house_construction_cost=1250.00,.hotel_construction_cost=5000.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 17, .square_type = Insurance, .square_name = "Sri Lanka Insurance", .property_group = None,
    .property_details={.purchase_price=1500.00,.mortgage_value=750.00,.rent_price=0.00,.house_construction_cost=0.00,.hotel_construction_cost=0.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 18, .square_type = Property,  .square_name = "Katunayake", .property_group = Orange,
    .property_details={.purchase_price=4700.00,.mortgage_value=2250.00,.rent_price=370.00,.house_construction_cost=1250.00,.hotel_construction_cost=5000.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 19, .square_type = Property,  .square_name = "Ja-Ela", .property_group = Orange,
    .property_details={.purchase_price=5000.00,.mortgage_value=2250.00,.rent_price=400.00,.house_construction_cost=1250.00,.hotel_construction_cost=5000.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 20, .square_type = Special,   .square_name = "Free Parking", .property_group = None,
    .property_details={.purchase_price=0.00,.mortgage_value=0.00,.rent_price=0.00,.house_construction_cost=0.00,.hotel_construction_cost=0.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 21, .square_type = Property,  .square_name = "Kandy City", .property_group = Red,
    .property_details={.purchase_price=5500.00,.mortgage_value=2750.00,.rent_price=450.00,.house_construction_cost=1500.00,.hotel_construction_cost=6000.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 22, .square_type = Event,     .square_name = "National Event Card", .property_group = None,
    .property_details={.purchase_price=0.00,.mortgage_value=0.00,.rent_price=0.00,.house_construction_cost=0.00,.hotel_construction_cost=0.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 23, .square_type = Property,  .square_name = "Peradeniya", .property_group = Red,
    .property_details={.purchase_price=5800.00,.mortgage_value=2750.00,.rent_price=480.00,.house_construction_cost=1500.00,.hotel_construction_cost=6000.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 24, .square_type = Property,  .square_name = "Katugastota", .property_group = Red,
    .property_details={.purchase_price=6000.00,.mortgage_value=2750.00,.rent_price=500.00,.house_construction_cost=1500.00,.hotel_construction_cost=6000.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 25, .square_type = Railway,   .square_name = "Galle Railway Station", .property_group = None,
    .property_details={.purchase_price=1500.00,.mortgage_value=750.00,.rent_price=250.00,.house_construction_cost=0.00,.hotel_construction_cost=0.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 26, .square_type = Property,  .square_name = "Galle Fort", .property_group = Yellow,
    .property_details={.purchase_price=6500.00,.mortgage_value=3250.00,.rent_price=600.00,.house_construction_cost=2000.00,.hotel_construction_cost=8000.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 27, .square_type = Property,  .square_name = "Unawatuna", .property_group = Yellow,
    .property_details={.purchase_price=6800.00,.mortgage_value=3250.00,.rent_price=620.00,.house_construction_cost=2000.00,.hotel_construction_cost=8000.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 28, .square_type = Utility,   .square_name = "National Water Supply and Drainage Board", .property_group = None,
    .property_details={.purchase_price=1500.00,.mortgage_value=750.00,.rent_price=250.00,.house_construction_cost=0.00,.hotel_construction_cost=0.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 29, .square_type = Property,  .square_name = "Hikkaduwa", .property_group = Yellow,
    .property_details={.purchase_price=7000.00,.mortgage_value=3250.00,.rent_price=650.00,.house_construction_cost=2000.00,.hotel_construction_cost=8000.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 30, .square_type = Special,   .square_name = "Go To Jail", .property_group = None,
    .property_details={.purchase_price=0.00,.mortgage_value=0.00,.rent_price=0.00,.house_construction_cost=0.00,.hotel_construction_cost=0.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 31, .square_type = Property,  .square_name = "Jaffna Town", .property_group = Green,
    .property_details={.purchase_price=8000.00,.mortgage_value=4000.00,.rent_price=750.00,.house_construction_cost=2500.00,.hotel_construction_cost=10000.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 32, .square_type = Property,  .square_name = "Nallur",.property_group = Green,
    .property_details={.purchase_price=8300.00,.mortgage_value=4000.00,.rent_price=780.00,.house_construction_cost=2500.00,.hotel_construction_cost=10000.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 33, .square_type = Insurance, .square_name = "Ceylinco Insurance", .property_group = None ,
    .property_details={.purchase_price=0.00,.mortgage_value=0.00,.rent_price=0.00,.house_construction_cost=0.00,.hotel_construction_cost=0.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 34, .square_type = Property,  .square_name = "Trincomalee", .property_group = Green,
    .property_details={.purchase_price=8500.00,.mortgage_value=4000.00,.rent_price=800.00,.house_construction_cost=2500.00,.hotel_construction_cost=10000.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 35, .square_type = Railway,   .square_name = "Jaffna Railway Station", .property_group = None,
    .property_details={.purchase_price=1500.00,.mortgage_value=750.00,.rent_price=250.00,.house_construction_cost=0.00,.hotel_construction_cost=0.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 36, .square_type = Event,     .square_name = "National Event Card", .property_group = None,
    .property_details={.purchase_price=0.00,.mortgage_value=0.00,.rent_price=0.00,.house_construction_cost=0.00,.hotel_construction_cost=0.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 37, .square_type = Property,  .square_name = "Nuwara Eliya", .property_group = DarkBlue,
    .property_details={.purchase_price=10000.00,.mortgage_value=5000.00,.rent_price=1000.00,.house_construction_cost=3000.00,.hotel_construction_cost=12000.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 38, .square_type = Bank,      .square_name = "Bank of Ceylon", .property_group = None,
    .property_details={.purchase_price=0.00,.mortgage_value=0.00,.rent_price=0.00,.house_construction_cost=0.00,.hotel_construction_cost=0.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}},

    {.square_id = 39, .square_type = Property,  .square_name = "Galle Face", .property_group = DarkBlue,
    .property_details={.purchase_price=12000.00,.mortgage_value=5000.00,.rent_price=1200.00,.house_construction_cost=3000.00,.hotel_construction_cost=12000.00,.current_owner_no=0,.mortgage_status=0,.insurance_status=0,.number_of_buildings=0}}
};

//Squares* getBoard(){
   // return squares;
//}



