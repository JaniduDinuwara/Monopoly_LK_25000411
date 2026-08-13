#ifndef PLAYERS_H
#define PLAYERS_H



typedef struct {
    int player_id;
    char player_name[40];
    int balance;
    int current_position;
    int first_roll;
    int dice_roll;
    int player_round;
    //int game_round;
} Players;


extern Players players[4];
#endif // PLAYERS_H