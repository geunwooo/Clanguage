#include <stdio.h>
#include "group_9-3-1_20006.h"

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