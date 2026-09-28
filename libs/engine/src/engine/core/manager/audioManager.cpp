#include "core/manager/audioManager.hpp"

AudioManager& AudioManager::instance() {
    static AudioManager instance;
    return instance;
}

void AudioManager::init() {
    InitAudioDevice();
}

void AudioManager::shutdown() {
    CloseAudioDevice();
}

void AudioManager::play(Sound& sound) {
    PlaySound(sound);
}

void AudioManager::stop(Sound& sound) {
    StopSound(sound);
}

void AudioManager::setMasterVolume(float volume) {
    SetMasterVolume(volume);
}
