#include "task_scheduler.h"

struct ScheduleResult *schedule_tasks(struct TaskList *tasks)
{
    TaskProfile *task = profile_tasks(tasks);
    int core = select_best_task(task);
    if (core > get_available_core_count())
        return NULL;
    ScheduleResult *sched = create_schedule_result(core);
    update_schedule_entry(sched, get_available_core_count(), core);
    return (free_task_profile(task), sched);
}