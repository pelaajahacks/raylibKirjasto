#pragma once

class AudioManager {
  public:
    static AudioManager& instance();

    void init();
    void shutdown();

    void loadSound(const std::string& name, const std::string& path);
    void playSound(const std::string& name);
    void stopSound(const std::string& name);

    void setMasterVolume(float volume);

    template<typename T>
    static constexpr size_t index(T id) {
        return static_cast<size_t>(id);
    }

  private:
    AudioManager() = default;
    ~AudioManager() = default;

    AudioManager(const AudioManager&) = delete;
    AudioManager& operator=(const AudioManager&) = delete;
}
