#ifndef __RESOURCEMANAGER_H__
#define __RESOURCEMANAGER_H__

#include "../Texture/Texture.hpp"

#include <string>
#include <unordered_map>

class ResourceManager
{
private:
    static std::unordered_map< std::string, Texture* > map_path_to_texture;

public:
    ~ResourceManager();

    // Will return nullptr if will fail to load
    static Texture *load_texture( const char* path );
    static void unload_texture( const char *path );
};

#endif // __RESOURCEMANAGER_H__