#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int min;
    int max;
    const char *grade;
} GradeRule;

typedef struct {
    const GradeRule *rules;
    int rule_count;
} GradeMapper;

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades);