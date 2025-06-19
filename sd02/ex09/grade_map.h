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

typedef struct GradeNode {
    char grade[8];
    int count;
    struct GradeNode *next;
} GradeNode;

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades);
GradeNode *compute_distribution(const char **mapped_grades, int size);
void print_distribution(GradeNode *head);
void free_distribution(GradeNode *head);