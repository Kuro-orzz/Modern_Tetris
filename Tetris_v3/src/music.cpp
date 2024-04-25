#include "music.h"

Music::Music(std::string file){
    SDL_INIT_AUDIO;
    if( Mix_OpenAudio( MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096  ) < 0 )
        std::cout << Mix_GetError();
    m_music = Mix_LoadMUS(file.c_str());
}

Music::~Music(){
    Mix_FreeMusic(m_music);
    Mix_Quit();
}

void Music::PlayMusic(int loops){
    if(m_music != NULL)
        Mix_PlayMusic(m_music, loops);
}

void Music::PauseMusic(){
    Mix_PauseMusic();
}

void Music::setVolumeMusic(int volume){
    Mix_VolumeMusic(volume);
}
