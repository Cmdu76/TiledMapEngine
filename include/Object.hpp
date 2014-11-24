#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <memory>
#include <string>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Vertex.hpp>

#include "Properties.hpp"
#include "Tileset.hpp"

class Map;

namespace tme
{

class Object : public Properties, public sf::Drawable, public sf::Transformable
{
    public:
        typedef std::shared_ptr<Object> Ptr;

        enum Type
        {
            Rectangle,
            Ellipse,
            Polygon,
            Polyline,
            Tile,
        };

    public:
        Object(Map* map);

        std::string getName() const;
        Type getType() const;
        sf::Vector2i getPosition() const;
        sf::Vector2i getSize() const;
        float getRotation() const;
        int getGid() const;
        bool isVisible() const;
        std::string getPoints() const;

        sf::Vertex* getVertex(int id);

        void setName(std::string const& name);
        void setType(Type type);
        void setPosition(sf::Vector2i position);
        void setSize(sf::Vector2i size);
        void setRotation(float rotation);
        void setGid(int gid);
        void setVisible(bool visible);
        void setPoints(std::string const& points);

        void setVertex(sf::Vertex vertex, int id);

        void applyColor(sf::Color color);

    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        Map* mMap;

        std::string mName; // The name of the object. An arbitrary string.
        Type mType; // The type of the object. An arbitrary string.
        sf::Vector2i mPosition; // Coordinate
        sf::Vector2i mSize; // Size
        float mRotation; // The rotation of the object in degrees clockwise (defaults to 0). (on git master)
        int mGid; // An reference to a tile (optional).
        bool mVisible; // Whether the object is shown (1) or hidden (0). Defaults to 1. (since 0.9.0)

        std::string mPoints;
        std::vector<sf::Vertex> mVertices;
        Tileset::Ptr mTileset;
};

} // namespace tme

#endif // OBJECT_HPP
