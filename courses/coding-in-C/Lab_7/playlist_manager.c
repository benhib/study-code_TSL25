#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char *title;
    char *artist;
    struct Song* next;
} Song;

typedef struct Playlist {
    Song* first_song;
} Playlist;

Playlist * init_playlist() {
    Playlist* pplaylist = (Playlist*)malloc(sizeof(Playlist));
    if (pplaylist == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    pplaylist->first_song = NULL;
    return pplaylist;
}

void add_song(Playlist * playlist, char title[], char artist[]) {
    Song* new_song = malloc(sizeof(Song));
    if (new_song == NULL) {
        printf("Memory allocation failed.\n");
        free(new_song);
        return;
    }
    new_song->title = malloc(strlen(title) + 1);
    new_song->artist = malloc(strlen(artist) + 1);
    new_song->next = NULL;

    if (new_song->title == NULL || new_song->artist == NULL) {
        printf("Memory allocation failed.\n");
        free(new_song->title);
        free(new_song->artist);
        return;
    }

    strcpy(new_song->title, title);
    strcpy(new_song->artist, artist);
    Song* iter_song = playlist->first_song;

    while (iter_song != NULL) {
        iter_song = iter_song->next;
    }

    iter_song->next = new_song;

    printf("Added %s from %s to the playlist.\n", title, artist);
    
}

// @brief takes a pointer to a playlist and prints every song within
void print_playlist(Playlist * playlist) {
    Song *iter_song = playlist->first_song;

    while (iter_song != NULL) {
        printf("Title: %s, Artist: %s", iter_song->title, iter_song->artist);
        iter_song = iter_song->next;
    }

    printf("Title: %s, Artist: %s\n", iter_song->title, iter_song->artist);
    
}


void delete_firstSong(Playlist * playlist) {
        Song *song = playlist->first_song;
        playlist->first_song = song->next;

        char *artist = song->artist;
        char *title = song->title;
        free(song->artist);
        free(song->title);
        free(song->next);
        free(song);

        printf("Removed %s by %s from the playlist.\n", title, artist);
}

void delete_playlist(Playlist * playlist) {
    
    while (playlist->first_song != NULL) {
        delete_firstSong(playlist);
    }
    
    free(playlist->first_song);
    free(playlist);

    printf("Deleted the playlist.\n");
}

int main() {
    Playlist *playlist = init_playlist();

    /*
    add_song(playlist, "Blurry", "Crown the Empire");
    add_song(playlist, "medicine", "Bring me the Horizon");
    add_song(playlist, "Take Me To The Beach", "Imagine Dragons");
    add_song(playlist, "Bow Down", "I Prevail");
    add_song(playlist, "Supernova", "Electric Callboy");
    add_song(playlist, "Silent Anchor", "Annisokay");
    add_song(playlist, "bad decisions", "Bad Omens");
    
    print_playlist(playlist);

    delete_firstSong(playlist);
    */

    add_song(playlist, "test", test);
    print_playlist(playlist);

    delete_playlist(playlist);
}