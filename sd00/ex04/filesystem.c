#include "filesystem.h"

int main()
{
	FSNode *Desktop = create_folder("Desktop");
	FSNode *hello = create_folder("hello");
	FSNode *games = create_folder("games");
	FSNode *world = create_folder("world");
	FSNode *Minecraft = create_folder("Minecraft");
	add_child(Desktop, hello);
	add_child(Desktop, world);
	add_child(Desktop, games);
	add_child(games, Minecraft);
	printf("%s\n", get_children(Desktop)->name);
	printf("%s\n", get_sibling(hello)->name);
	printf("%s\n", get_sibling(hello)->sibling->name);
	free(Desktop);
	free(hello);
	free(games);
	free(Minecraft);
	free(world);
}

FSNode *create_file(const char *name, int size)
{
	FSNode *file = malloc(sizeof(FSNode));
	file->is_folder = 0;
	file->size = size;
	file->name = name;
	file->childrens = NULL;
	file->sibling = NULL;
	file->parent = NULL;
	return file;
}

FSNode *create_folder(const char *name)
{
	FSNode *folder = malloc(sizeof(FSNode));
	folder->is_folder = 1;
	folder->size = 0;
	folder->name = name;
	folder->childrens = NULL;
	folder->sibling = NULL;
	folder->parent = NULL;
	return folder;
}

void add_child(FSNode *parent, FSNode *child)
{
	if (parent->is_folder == 0)
		return;

	FSNode *head;
	if (parent->childrens == NULL)
		parent->childrens = child;
	else
	{
		child->sibling = parent->childrens;
		head = parent->childrens;
		for (int i = 0; i < parent->size - 1; i++)
			parent->childrens = parent->childrens->sibling;
		parent->childrens->sibling = child;
		parent->childrens = head;
	}
	parent->size += 1;
}

FSNode *get_children(const FSNode *parent)
{
	return parent->childrens;
}

FSNode *get_sibling(const FSNode *node)
{
	return node->sibling;
}