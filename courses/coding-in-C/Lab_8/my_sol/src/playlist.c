#include "../include/playlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// @brief initializes a playlist and returns a pointer to it
Playlist * init_playlist() {
    Playlist* playlist = (Playlist*)malloc(sizeof(Playlist));
    if (playlist == NULL) {
        printf("Memory allocation failed.\n");
        free(playlist);
        return NULL;
    }

    playlist->first_song = NULL;
    playlist->len = 0;
    printf("Playlist initialized.\n");
    return playlist;
}

// @brief takes a pointer to a playlist, a title and an artist and adds the song to the end of the playlist
void add_song(Playlist * playlist, char title[], char artist[]) {
    if(playlist->len >= MAX_SONGS) {
        printf("Maximum playlist length reached!\n");
        return;
    }
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

    if(playlist->first_song == NULL) {
        playlist->first_song = new_song;
        playlist->len++;
        printf("Added %s by %s to the playlist.\n", title, artist);
        return;
    }

    while (iter_song->next != NULL) {
        iter_song = iter_song->next;
    }


    iter_song->next = new_song;


    playlist->len++;

    printf("Added %s by %s to the playlist.\n", title, artist);

    
    
}

// @brief takes a pointer to a playlist and prints every song within or a message if the playlist is empty or does not exist
void print_playlist(Playlist * playlist) {
    if (playlist == NULL || playlist->first_song == NULL) {
        printf("The playlist is empty or does not exist.\n");
        return;
    }

    Song *iter_song = playlist->first_song;

    while (iter_song->next != NULL) {
        printf("Title: %s, Artist: %s\n", iter_song->title, iter_song->artist);
        iter_song = iter_song->next;
    }

    printf("Title: %s, Artist: %s\n", iter_song->title, iter_song->artist);
    
}


// @brief takes a pointer to a playlist and deletes the first song in the playlist or prints a message if the playlist is empty or does not exist
void delete_firstSong(Playlist * playlist) {
    if (playlist == NULL) {
        printf("The playlist is empty or does not exist.\n");
        return;
    }

    if(playlist->first_song == NULL) {
        printf("There is no song in the playlist.\n");
        return;
    }

    Song *song = playlist->first_song;
    playlist->first_song = song->next;

    printf("Removed %s by %s from the playlist.\n", song->title, song->artist);

    free(song->artist);
    free(song->title);
    free(song);

    playlist->len--;
        
}

// @brief takes a pointer to a playlist and deletes the entire playlist or prints a message if the playlist does not exist
void delete_playlist(Playlist * playlist) {
    if (playlist == NULL) {
        printf("The playlist does not exist.\n");
        return;
    }

    while (playlist->first_song != NULL) {
        delete_firstSong(playlist);
    }
    
    free(playlist->first_song);
    free(playlist);
    
    playlist->first_song = NULL;
    playlist->len = 0;

    printf("Deleted the playlist.\n");
}