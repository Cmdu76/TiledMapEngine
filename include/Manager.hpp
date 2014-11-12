#ifndef TME_MANAGER_HPP
#define TME_MANAGER_HPP

#include <map>
#include <memory>
#include <string>

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Time.hpp>

#include "Map.hpp"

class Manager : public sf::Transformable
{
    public:
        Manager();
        ~Manager();

        void update(sf::Time dt);
        void render(unsigned int layer, sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates());

        bool loadMap(std::string const& filename);
        Map::Ptr getMap(std::string const& filename);

        bool loadTexture(std::string const& filename);
        void addTexture(std::shared_ptr<sf::Texture> texture, std::string const& filename);
        std::shared_ptr<sf::Texture> getTexture(std::string const& filename);

    private:
        std::map<std::string,Map::Ptr> mMaps;
        std::map<std::string,std::shared_ptr<sf::Texture>> mTextures;
};

#endif // TME_MANAGER_HPP