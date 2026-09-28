#pragma once

#include <raylib.h>

class AudioManager {
public:
    static AudioManager& instance();

    void init();
    void shutdown();

    void play(Sound& sound);
    void stop(Sound& sound);

    void setMasterVolume(float volume);

private:
    AudioManager() = default;
    ~AudioManager() = default;

    AudioManager(const AudioManager&) = delete;
    AudioManager& operator=(const AudioManager&) = delete;
};
