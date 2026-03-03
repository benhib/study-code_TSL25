#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../include/playlist.h"

/* === Unit-tests === */

// example unit test

static Playlist *playlist;

void test_init_playlist(void)
{
    playlist = init_playlist();

    assert(playlist->first_song == NULL);
    assert(playlist->len == 0);
}

void test_add_song(void) {

    add_song(playlist, "This Is a Test", "Armin Van Buuren");

    assert(strcmp(playlist->first_song->artist, "Armin Van Buuren") == 0);
    assert(strcmp(playlist->first_song->title, "This Is a Test") == 0);
    assert(playlist->first_song->next == NULL);
    printf("len: %i\n", playlist->len);
    assert(playlist->len == 1);
}

void test_delete_first_song(void) {

    delete_firstSong(playlist);

    assert(playlist->len == 0);
    assert(playlist->first_song == NULL);

}

void test_delete_first_song_empty(void) {

    delete_firstSong(playlist);

    assert(playlist->len == 0);
    assert(playlist->first_song == NULL);

}

void test_max_songs(void) {

    assert(playlist->len <= MAX_SONGS);

}

void test_delete_playlist(void) {

    delete_playlist(playlist);

    assert(playlist->first_song == NULL);
    assert(playlist->len == 0);
}



/* === Test-Runner === */

int main(void)
{
    test_init_playlist();
    test_add_song();
    test_delete_first_song();
    test_delete_first_song_empty(); // what happens if we delete first song from empty playlist
    
    test_max_songs(); // verify if the limit will be not be surpassed

    test_delete_playlist();

    printf("Alle Playlist-Tests erfolgreich bestanden.\n");
    return 0;
}