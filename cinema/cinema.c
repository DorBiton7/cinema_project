
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cinema.h"
struct movie {
    char title[MAX_STR_LENGTH];
    int length;
    double rating;

    struct movie *next;
};

struct genre {
    char name[MAX_STR_LENGTH];

    struct movie *movies;
    struct genre *next;
};

struct cinema {
    struct genre *genres;
};

struct cinema *create_cinema() {
    struct cinema *new = malloc(sizeof(struct cinema));
    new->genres = NULL;

    return new;
}

void add_genre(struct cinema *cinema, char *genre_name) {
    struct genre *new = malloc(sizeof(struct genre));
    strcpy(new->name, genre_name);
    new->movies = NULL;
    new->next = NULL;

    new->next = cinema->genres;
    cinema->genres = new;
}

int add_movie(
        struct cinema *cinema,
        char *genre_name,
        char *movie_name,
        int length,
        double rating
) {
    struct genre *genre = cinema->genres;

    while (genre != NULL) {
        if (strcmp(genre->name, genre_name) == 0) {
            break;
        }
        genre = genre->next;
    }

    if (genre == NULL) {
        return NOT_FOUND;
    }

    struct movie *new_movie = malloc(sizeof(struct movie));
    strcpy(new_movie->title, movie_name);
    new_movie->length = length;
    new_movie->rating = rating;
    new_movie->next = NULL;

    new_movie->next = genre->movies;
    genre->movies = new_movie;

    return SUCCESS;
}


void print_genre(struct cinema *cinema, char *genre_name) {
    struct genre *genre = cinema->genres;

    while (genre != NULL) {
        if (strcmp(genre->name, genre_name) == 0) {
            break;
        }
        genre = genre->next;
    }

    if (genre == NULL) {
        printf("Genre not found\n");
        return;
    }

    printf("Movies in genre %s:\n", genre_name);

    struct movie *movie = genre->movies;
    while (movie != NULL) {
        printf("%s (length: %d, rating: %.1f)\n", movie->title, movie->length, movie->rating);
        movie = movie->next;
    }
}
