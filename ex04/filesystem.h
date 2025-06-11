#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct FSNode {
    const char *name;
    int size;
    int is_folder;
    struct FSNode *parent;
    struct FSNode *childrens;
    struct FSNode *sibling;
} FSNode;

FSNode *create_file(const char *name, int size);
FSNode *create_folder(const char *name);
void add_child(FSNode *parent, FSNode *child);
FSNode *get_children(const FSNode *parent);
FSNode *get_sibling(const FSNode *node);