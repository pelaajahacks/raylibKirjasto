#pragma once

#include <raylib.h>
#include <map>
#include <string>
#include <vector>

class textureManager {
  public:
    Texture2D* getTexture(std::string name) const;
    int addTexture(std::string name, Texture2D* tex) const;
    int delTexture(std::string name, Texture2D* tex) const;
    int loadTexture(std::string name, Texture2D* tex) const;
    int unloadAll() const;

  private:
    std::map<std::string, Texture2D> textures;
}
