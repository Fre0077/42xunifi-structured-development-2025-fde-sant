#include "filesystem.h"

int compute_total_size(FSNode *node)
{
    int total = 0;
    if (!node)
        return (0);
    if (!node->is_folder)
        return (node->size);
    FSNode *child = node->childrens;
    for (int i = 0; i < node->size; i++)
    {
        total += compute_total_size(child);
        child = child->sibling;
    }
    return (total);
}

void print_structure(const FSNode *node, int indent)
{
    if (!node)
        return;
    for (int i = 0; i < indent; i++)
        printf("  ");
    printf("%s%s\n", node->name, node->is_folder ? "/" : "");
    if (!node->is_folder)
        return ;
    FSNode *child = node->childrens;
    for (int i = 0; i < node->size; i++)
    {
        print_structure(child, indent + 1);
        child = child->sibling;
    }
}

void free_filesystem(FSNode *node)
{
    if (!node)
        return;
    if (!node->is_folder)
    {
        free(node);
        return ;
    }
    FSNode *child = node->childrens;
    FSNode *temp;
    for (int i = 0; i < node->size; i++)
    {
        temp = child;
        child = child->sibling;
        free_filesystem(temp);
    }
    free(node);
}