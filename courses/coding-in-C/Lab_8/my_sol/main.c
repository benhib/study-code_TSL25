#include <stdio.h>
#include "include/playlist.h"


int main() {

    printf("------------------------------\n");

    Playlist *playlist = init_playlist();

    print_playlist(playlist);

    printf("------------------------------\n");

    add_song(playlist, "Blurry", "Crown the Empire");
    add_song(playlist, "medicine", "Bring me the Horizon");
    add_song(playlist, "Take Me To The Beach", "Imagine Dragons");
    add_song(playlist, "Bow Down", "I Prevail");
    add_song(playlist, "Supernova", "Electric Callboy");
    add_song(playlist, "Silent Anchor", "Annisokay");
    add_song(playlist, "bad decisions", "Bad Omens");

    printf("------------------------------\n");

    print_playlist(playlist);

    printf("------------------------------\n");

    delete_firstSong(playlist);

    printf("------------------------------\n");
    
    print_playlist(playlist);

    printf("------------------------------\n");

    add_song(playlist, "Trip to Ireland", "Dr. Peacock");

    printf("------------------------------\n");

    delete_playlist(playlist);

    printf("------------------------------\n");

    print_playlist(playlist);
}