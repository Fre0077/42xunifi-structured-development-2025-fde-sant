#pragma once

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct Preferences
{
    char *film;
    struct Preferences *next;
} Preferences;

typedef struct MovieList
{
    char *film;
    struct Preferences *next;
} MovieList;

typedef struct Plan
{
    char *film;
    struct Preferences *next;
} Plan;

struct Preferences *get_user_preferences(void);
struct MovieList *find_movies(struct Preferences *prefs);
struct Plan *build_plan(struct MovieList *list);
struct Plan *create_movie_night_plan(void);