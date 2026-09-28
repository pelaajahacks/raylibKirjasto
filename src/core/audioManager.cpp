#include "core/audioManager.hpp"

AudioManager& AudioManager::instance() {
  static AudioManager instance;
  return instance;
}

void AudioManager::init() {
    InitAudioDevice();
}

void AudioManager::shutdown() {
    for (auto& [name, sound] : sounds)
        UnloadSound(sound);

    sounds.clear();

    CloseAudioDevice();
}

void AudioManager::loadSound(const std::string& name, const std::string& path) {
    sounds[name] = LoadSound(path.c_str());
}

void AudioManager::playSound(const std::string& name) {
    auto it = sounds.find(name);

    if (it != sounds.end())
        PlaySound(it->second);
}

void AudioManager::stopSound(const std::string& name) {
    auto it = sounds.find(name);

    if (it != sounds.end())
        StopSound(it->second);
}

void AudioManager::setMasterVolume(float volume) {
    masterVolume = volume;
    SetMasterVolume(volume);
}
