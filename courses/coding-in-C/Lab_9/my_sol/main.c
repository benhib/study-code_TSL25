#include <stdio.h>
#include "../include/playlist.h"


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

    printf("There are %i songs in the playlist.\n", count_songs_recursive(playlist->first_song));

    printf("------------------------------\n");

    delete_firstSong(playlist);

    printf("------------------------------\n");

    printf("There are %i songs in the playlist.\n", count_songs_recursive(playlist->first_song));

    find_song_by_title(playlist, "Silent Anchor");

    printf("------------------------------\n");
    
    print_playlist(playlist);

    printf("------------------------------\n");

    add_song(playlist, "Trip to Ireland", "Dr. Peacock");

    printf("------------------------------\n");

    sort_playlist_by_title(playlist);

    printf("------------------------------\n");

    print_playlist(playlist);

    printf("------------------------------\n");

    delete_playlist(playlist);

    printf("------------------------------\n");

    print_playlist(playlist);
}