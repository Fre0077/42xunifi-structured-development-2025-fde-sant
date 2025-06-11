#include "grade_map.h"

GradeNode *compute_distribution(const char **mapped_grades, int size)
{
    GradeNode *head = NULL;
    for (int i = 0; i < size; i++) {
        GradeNode *curr = head;
        while (curr) {
            if (strcmp(curr->grade, mapped_grades[i]) == 0) {
                curr->count++;
                break;
            }
            curr = curr->next;
        }
        if (!curr) {
            GradeNode *new_node = malloc(sizeof(GradeNode));
            strncpy(new_node->grade, mapped_grades[i], sizeof(new_node->grade) - 1);
            new_node->grade[sizeof(new_node->grade) - 1] = '\0';
            new_node->count = 1;
            new_node->next = head;
            head = new_node;
        }
    }
    return head;
}

void print_distribution(GradeNode *head)
{
    printf("Grade distribution:\n");
    for (GradeNode *curr = head; curr; curr = curr->next)
        printf("Grade %s: %d\n", curr->grade, curr->count);
}

void free_distribution(GradeNode *head)
{
    while (head) {
        GradeNode *tmp = head;
        head = head->next;
        free(tmp);
    }
}