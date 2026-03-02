#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../include/playlist.h"

/* === Unit-tests === */

// example unit test
void test_init_playlist(void)
{
    Playlist *p = init_playlist();

    assert(p->first_song == NULL);
}

void test_add_song(void) {
    Playlist *p = init_playlist();

    add_song(p, "This Is a Test", "Armin Van Buuren");

    assert(p->first_song->artist == "Armin Van Buuren")
    assert(p->first_song->title == "This Is a Test");
    assert(p->first_song->next == NULL);
}

/* === Test-Runner === */

int main(void)
{
    test_init_playlist();
    test_add_song();
    test_delete_firstSong();
    test_delete_firstSong_empty(); // what happens if we delete first song from empty playlist
    test_delete_playlist();
    test_max_songs_limit(); // verify if the limit will be not be surpassed

    printf("Alle Playlist-Tests erfolgreich bestanden.\n");
    return 0;
}