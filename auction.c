#include <stdio.h>
#include "types.h"


int auction(int j){
 
   Squares *landed_square = &squares[players[j].current_position];
    int bid_start_price = landed_square->property_details.purchase_price*0.5;
    int bid_minimum_increment = 250;
    int highest_bid = bid_start_price;
    int highest_bidder =-1; 
    int active_players = 0;
    int maximum_bid =0;
    int new_bid;

int active[4]={1,1,1,1};
active[j] = 0;

     for (int i = 0; i < 4; i++) // count the number of active players
    {
        if (active[i] == 1)
        {
            active_players++;
        }
    }

printf("\n>>> Auction Started <<<\n");
printf("\nProperty : %s\n",landed_square->square_name);
printf("Opening Bid : LKR %d\n",bid_start_price);



while(active_players > 1) break;

    for(int i = 0; i<4; i++){

        if(active[i]==0){
            active_players--;
        }

        if(i==0){ //aggressive investor
            maximum_bid = landed_square->property_details.purchase_price*1.20;
                    new_bid = bid_start_price + bid_minimum_increment;
            if(players[i].balance >= new_bid){   //aggressive investor's behaviors about auction
                if(maximum_bid >= highest_bid){
                    
                    highest_bid = new_bid;
                    highest_bidder = i;
                
                }else{
                    active[i]=0;
                    active_players--;
                }
            }

        }else if(i==1){ //conservative banker
            maximum_bid = landed_square->property_details.purchase_price;
                    new_bid = highest_bid + bid_minimum_increment;
            if(players[i].balance >= new_bid){   //conservative banker's behaviors about auction
                if(maximum_bid >= highest_bid){
                    
                    highest_bid = new_bid;
                    highest_bidder = i;
                }else{
                    active[i]=0;
                    active_players--;
                }
                    
                }
            }else if(i==2){//risk taker
                maximum_bid = players[i].balance;
                    new_bid =  highest_bid + bid_minimum_increment;

                if(players[i].balance >= highest_bid){    //risk taker's behaviors about auction
                                       
                     highest_bid = new_bid;
                    highest_bidder = i;
                }else{
                    active[i]=0;
                    active_players--;
                }

            }else if(i==3){//opportunistic trader
                maximum_bid = landed_square->property_details.purchase_price*0.90;
                        new_bid = highest_bid + bid_minimum_increment; 

                if(players[i].balance >= new_bid){ //opportunistic trader's behaviors about auction
                    if(landed_square->property_details.purchase_price*0.90 > highest_bid){ // this is not correct condition. to calculate correct i want make economic status. 
                        
                        highest_bid = new_bid;              
                        highest_bidder = i;
                    }else{
                        active[i]=0;
                        active_players--;
                    }
                }
        
    }  
        
    }




players[highest_bidder].balance -= highest_bid;
players[highest_bidder].net_worth += landed_square->property_details.purchase_price;
landed_square->property_details.current_owner_no = players[highest_bidder].player_id;

printf("\n%s bids LKR %d\n",players[highest_bidder].player_name,highest_bid);
printf("\n%s wins the auction.\n",players[highest_bidder].player_name);
printf("\n>>> Auction Ended <<<\n");

return highest_bidder;

}