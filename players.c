#include <stdio.h>
#include "players.h"


Players players[4] =
 {
//Aggresive Investor
    {.player_id = 1, 
     .player_name = "Aggresive Investor", 
     .balance = 30000, 
     .current_position = 0,
     .first_roll = 0,
     .dice_roll=0,
     .player_round=0,
     .game_round=0},

//Conservative Banker
    {.player_id = 2, 
     .player_name = "Conservative Banker", 
     .balance = 30000, 
     .current_position = 0, 
     .first_roll = 0,
     .dice_roll=0,
     .player_round=0,
     .game_round=0},

//Risk Taker
    {.player_id = 3, 
     .player_name = "Risk Taker", 
     .balance = 30000, 
     .current_position = 0, 
     .first_roll = 0,
     .dice_roll=0,
     .player_round=0,
     .game_round=0},
  
//Opportunistic Trader
    {.player_id = 4, 
     .player_name = "Opportunistic Trader", 
     .balance = 30000, 
     .current_position = 0, 
     .first_roll = 0,
     .dice_roll=0,
     .player_round=0,
     .game_round=0}
};