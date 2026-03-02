#ifndef PLAYLIST_H
#define PLAYLIST_H

#define MAX_SONGS


typedef struct Song {
    char *title;
    char *artist;
    struct Song* next;
} Song;

typedef struct Playlist {
    Song* first_song;
} Playlist;

// @brief initializes a playlist and returns a pointer to it
Playlist * init_playlist();


// @brief takes a pointer to a playlist, a title and an artist and adds the song to the end of the playlist
void add_song(Playlist * playlist, char title[], char artist[]);


// @brief takes a pointer to a playlist and prints every song within or a message if the playlist is empty or does not exist
void print_playlist(Playlist * playlist);


// @brief takes a pointer to a playlist and deletes the first song in the playlist or prints a message if the playlist is empty or does not exist
void delete_firstSong(Playlist * playlist);


// @brief takes a pointer to a playlist and deletes the entire playlist or prints a message if the playlist does not exist
void delete_playlist(Playlist * playlist);

#endif