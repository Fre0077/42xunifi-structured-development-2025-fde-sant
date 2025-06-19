#include "playlist_creator.h"

struct Playlist *create_playlist(void)
{
	MoodSettings *mood = analyze_user_mood();
	SongData *song;
	if (refine_filters(default_filters()))
		song = fetch_popular_song();
	else
		song = fetch_niche_song();
	Playlist *play = combine_with_mood_playlist(song, mood);
	return (free_mood_settings(mood), free_song_data(song), play);
}