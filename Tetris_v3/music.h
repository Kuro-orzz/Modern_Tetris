#ifndef MUSIC_H
#define MUSIC_H

#include <SDL_mixer.h>
#include <iostream>

class Music{
private:
    Mix_Music* m_music = NULL;
public:
    Music(std::string file);
    ~Music();
    void PlayMusic(int loops);
    void PauseMusic();
    void setVolumeMusic(int volume);
};

#endif // MUSIC_H
