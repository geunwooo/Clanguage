#include <stdio.h>
#include "group_9-3-1_20006.h"

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