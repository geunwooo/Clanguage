#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ROOMS 300
#define MAX_PLAYERS 300
#define MAX_NICK_LENGTH 17

char room_list_nick[MAX_ROOMS][MAX_PLAYERS][MAX_NICK_LENGTH], temp_nick[MAX_NICK_LENGTH];
int room_list_level[MAX_ROOMS][MAX_PLAYERS], room_length[MAX_ROOMS], total_room = 0;

void add_player_to_room(int lv, char nick[], int max_players) {
    for (int i = 0; i < total_room; i++) {
        if (room_length[i] < max_players && abs(room_list_level[i][0] - lv) <= 10) {
            room_list_level[i][room_length[i]] = lv;
            strcpy(room_list_nick[i][room_length[i]], nick);
            room_length[i]++;
            return;
        }
    }
    room_list_level[total_room][0] = lv;
    strcpy(room_list_nick[total_room][0], nick);
    room_length[total_room]++;
    total_room++;
}

void sort_players_in_room() {
    for (int i = 0; i < total_room; i++) {
        for (int j = 0; j < room_length[i]; j++) {
            for (int k = j + 1; k < room_length[i]; k++) {
                if (strcmp(room_list_nick[i][j], room_list_nick[i][k]) > 0) {
                    strcpy(temp_nick, room_list_nick[i][j]);
                    strcpy(room_list_nick[i][j], room_list_nick[i][k]);
                    strcpy(room_list_nick[i][k], temp_nick);

                    int temp_lv = room_list_level[i][j];
                    room_list_level[i][j] = room_list_level[i][k];
                    room_list_level[i][k] = temp_lv;
                }
            }
        }
    }
}

void print_rooms(int max_players) {
    for (int i = 0; i < total_room; i++) {
        if (room_length[i] == max_players) {
            printf("Started!\n");
        } else {
            printf("Waiting!\n");
        }
        for (int j = 0; j < room_length[i]; j++) {
            printf("%d %s\n", room_list_level[i][j], room_list_nick[i][j]);
        }
    }
}

int main() {
    int p, m;
    scanf("%d %d", &p, &m);

    for (int player = 0; player < p; player++) {
        int lv;
        char nick[MAX_NICK_LENGTH];
        scanf("%d %s", &lv, nick);

        add_player_to_room(lv, nick, m);
    }

    sort_players_in_room();
    print_rooms(m);

    return 0;
}