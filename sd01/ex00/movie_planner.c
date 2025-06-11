#include "movie_planner.h"

struct Plan *create_movie_night_plan(void)
{
    return (build_plan(find_movies(get_user_preferences())));
}