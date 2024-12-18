#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char room_list_nick[300][300][17], temp_nick[17];
int room_list_level[300][300], room_length[300], temp_lv;
int total_room = 0;

int main() {
    int p, m;
    scanf("%d %d", &p, &m);

    int lv = 12;
    char nick[17];
    
    for (int player = 0 ; player < p ; player++) {
        scanf("%d %s", &lv, nick);

        int stat = 0;

        for (int i = 0 ; i < p ; i++) {
            if (room_list_level[i][0] == 0) {
                room_list_level[i][0] = lv; strcpy(room_list_nick[i][0], nick);
                total_room += 1; room_length[i] += 1;
                break;
            } else {
                for (int j = 1 ; j < m ; j++) {
                    if (room_list_level[i][j] == 0 && abs(room_list_level[i][0] - lv) <= 10) {
                        room_list_level[i][j] = lv; strcpy(room_list_nick[i][j], nick);
                        room_length[i] += 1;
                        stat = 1;
                        break;
                    }
                }
            }

            if (stat == 1) {
                break;
            }
        }
    }

    for (int i = 0 ; i < total_room ; i++) {
        for (int j = 0 ; j < room_length[i] ; j++) {
            for (int k = j + 1 ; k < room_length[i] ; k++) {
                if (strcmp(room_list_nick[i][j], room_list_nick[i][k]) > 0) {
                    strcpy(temp_nick, room_list_nick[i][j]);
                    strcpy(room_list_nick[i][j], room_list_nick[i][k]);
                    strcpy(room_list_nick[i][k], temp_nick);
                    temp_lv = room_list_level[i][j];
                    room_list_level[i][j] = room_list_level[i][k];
                    room_list_level[i][k] = temp_lv;
                }
            }
        }
    }
    for (int i = 0 ; i < total_room ; i++) {
        if (room_length[i] == m) {
            printf("Started!\n");
        } else {
            printf("Waiting!\n");
        }

        for (int j = 0 ; j < room_length[i] ; j++) {
            printf("%d %s\n", room_list_level[i][j], room_list_nick[i][j]);
        }
    }
}