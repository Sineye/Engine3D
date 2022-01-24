#include "ResourceManager.hpp"

#include "Engine/Engine.hpp"

#include "../External/stb_image.h"


std::unordered_map< std::string, Texture* > ResourceManager::map_path_to_texture;

Texture* ResourceManager::load_texture( const char* path ) 
{
    auto it = map_path_to_texture.find( path );
    if( it != map_path_to_texture.end() )
    {
        return it->second;
    }

    Texture *tex = new Texture();
    if( tex->load( path ) )
    {
        map_path_to_texture[path] = tex;
        return tex;
    }
    else
    {
        delete tex;
        return nullptr;
    }
}

void ResourceManager::unload_texture( const char *path ) 
{
    auto it = map_path_to_texture.find( path );
    if( it != map_path_to_texture.end() )
    {
        delete it->second;
        map_path_to_texture.erase( it );
    }
}
