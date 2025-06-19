#include "workout_scheduler.h"

struct WorkoutPlan *create_workout_schedule(char *username)
{
    UserData *data = get_user_data(username);
    WorkoutPlan *plan = refine_plan(build_base_plan(data), data);
    int day = determine_duration(plan);
    return (assign_daily_exercises(plan, day), assign_daily_tips(plan, day), free_user_data(data), plan);
}