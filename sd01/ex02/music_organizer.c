#include "music_organizer.h"

struct MusicLibrary *organize_music_library(const char *directory_path)
{
    MusicLibrary *lib = create_music_library();
    char **scan = scan_directory(directory_path);
    for (int i = 0; scan[i]; i++)
        update_music_library(lib, process_music_file(directory_path, scan[i]));
    return lib;
}