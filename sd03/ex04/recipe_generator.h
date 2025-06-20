#pragma once

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ingredients
{
    char **ingredients;
} Ingredients;

typedef struct TasteProfile
{
    char *taste;
} TasteProfile;

typedef struct Recipe
{
    char *instruction;
    char **ingredients;
} Recipe;

// Fetch current ingredients from fridge. Returns a new Ingredients* or NULL on failure.
struct Ingredients *get_current_ingredients(void);
// Fetch user taste profile. Returns a new TasteProfile* or NULL on failure.
struct TasteProfile *get_user_taste_profile(void);
// Generate a new recipe candidate based on ingredients & taste. Returns a new Recipe* or NULL on failure.
struct Recipe *create_recipe(struct Ingredients *ingredients, struct TasteProfile *taste);
// Ask user approval for the given recipe. Returns 1 if approved, 0 otherwise.
int get_user_approval(struct Recipe *recipe);
// Free functions for cleanup:
void free_ingredients(struct Ingredients *ing);
void free_taste_profile(struct TasteProfile *tp);
void free_recipe(struct Recipe *recipe);
struct Recipe *create_custom_recipe(void);