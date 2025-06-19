#include "recipe_generator.h"

struct Recipe *create_custom_recipe(void)
{
    Recipe *recipe = create_recipe(get_current_ingredients(), get_user_taste_profile());
    return get_user_approval(recipe) ? recipe : NULL;
}