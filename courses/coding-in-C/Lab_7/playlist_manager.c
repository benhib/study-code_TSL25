#include <stdio.h>
#include <stdlib.h>

typedef struct Song {
    char title[100];
    char artist[100];
    struct Song* next;
} Song;

typedef struct Playlist {
    char name[100];
    Song* head;
} Playlist;

Playlist *init_playlist(const char* name) {
    Playlist* playlist = (Playlist*)malloc(sizeof(Playlist));
    if (playlist == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    snprintf(playlist->name, sizeof(playlist->name), "%s", name);
    playlist->head = NULL;
    return playlist;
}

void add_song(Playlist* playlist, const char* title, const char* artist) {
    Song* new_song = (Song*)malloc(sizeof(Song));
    if (new_song == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    new_song->title = title;
    new_song->artist = artist;
    new_song->next = playlist->head;
    playlist->head = new_song;
}

