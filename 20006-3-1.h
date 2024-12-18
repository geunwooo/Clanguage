#ifndef ROOM_MANAGER_H
#define ROOM_MANAGER_H

#define MAX_ROOMS 300
#define MAX_PLAYERS 300
#define MAX_NICK_LENGTH 17

extern char room_list_nick[MAX_ROOMS][MAX_PLAYERS][MAX_NICK_LENGTH];
extern int room_list_level[MAX_ROOMS][MAX_PLAYERS];
extern int room_length[MAX_ROOMS];
extern int total_room;

void add_player_to_room(int lv, char nick[], int max_players);
void sort_players_in_room();
void print_rooms(int max_players);

#endif