#include "music.h"

Music::Music(std::string file){
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
            std::cout << Mix_GetError();
        m_music = Mix_LoadMUS(file.c_str());
}

Music::~Music(){
    Mix_FreeMusic(m_music);
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
