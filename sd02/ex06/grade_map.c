#include "grade_map.h"

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades)
{
    for (int i = 0; i < size; i++)
    {
        mapped_grades[i] = "F";
        for (int j = 0; j < mapper.rule_count; j++)
        {
            if (scores[i] >= mapper.rules[j].min && scores[i] <= mapper.rules[j].max)
            {
                mapped_grades[i] = mapper.rules[j].grade;
                break;
            }
        }
    }
}

int main()
{
    int scores[] = {100, 95, 82, 77, 61, 50};
    int size = sizeof(scores) / sizeof(scores[0]);
    const char *mapped_grades[size];

    GradeRule plusminus_rules[] = {
        {97, 100, "A+"}, {93, 96, "A"}, {90, 92, "A-"}, {87, 89, "B+"}, {83, 86, "B"}, {80, 82, "B-"}, {77, 79, "C+"}, {73, 76, "C"}, {70, 72, "C-"}, {67, 69, "D+"}, {63, 66, "D"}, {60, 62, "D-"}, {0, 59, "F"}};
    GradeMapper plusminus_mapper = {plusminus_rules, sizeof(plusminus_rules) / sizeof(plusminus_rules[0])};

    map_scores(scores, size, plusminus_mapper, mapped_grades);

    printf("Plusminus mapping:\n");
    for (int i = 0; i < size; i++)
        printf("Score: %d -> Grade: %s\n", scores[i], mapped_grades[i]);

    GradeRule passfail_rules[] = {
        {60, 100, "P"},
        {0, 59, "F"}};
    GradeMapper passfail_mapper = {passfail_rules, sizeof(passfail_rules) / sizeof(passfail_rules[0])};

    map_scores(scores, size, passfail_mapper, mapped_grades);

    printf("\nPassfail mapping:\n");
    for (int i = 0; i < size; i++)
        printf("Score: %d -> Grade: %s\n", scores[i], mapped_grades[i]);

    GradeRule standard_rules[] = {
        {90, 100, "A"}, {80, 89, "B"}, {70, 79, "C"}, {60, 69, "D"}, {0, 59, "F"}};
    GradeMapper standard_mapper = {standard_rules, sizeof(standard_rules) / sizeof(standard_rules[0])};

    map_scores(scores, size, standard_mapper, mapped_grades);

    printf("\nStandard mapping:\n");
    for (int i = 0; i < size; i++)
        printf("Score: %d -> Grade: %s\n", scores[i], mapped_grades[i]);

    return 0;
}