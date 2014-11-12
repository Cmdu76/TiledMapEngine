#ifndef TME_TILESET_HPP
#define TME_TILESET_HPP

#include <memory>
#include <string>
//#include <vector>

#include <SFML/Graphics/Texture.hpp>

#include "Image.hpp"
#include "Properties.hpp"


/*

To Do :

-Understand TileOffset
-Understand Terrain
-Understand TerrainTypes
-Understand Terrain member in Tile
-Use & handle mSource for .tsx file

*/

class Map;

class Tileset : public Image, public Properties
{
    public:
        typedef std::shared_ptr<Tileset> Ptr;

        /*
        struct TileOffset
        {
            TileOffset();

            int x; // Horizontal offset in pixels
            int y; // Vertical offset in pixels (positive is down)
        };
        */

        /*
        class Terrain : public Properties
        {
            public:
                Terrain();

                std::string getName() const;
                int getTile() const;

                void setName(std::string const& name);
                void setTile(int tile);

            private:
                std::string mName; // The name of the terrain type.
                int mTile; // The local tile-id of the tile that represents the terrain visually.
        };

        typedef std::vector<Terrain> TerrainTypes;
        */

        class Tile : /*public Image,*/ public Properties
        {
            public:
                Tile();

                int getId() const;
                //std::string getTerrain() const;
                float getProbability() const;

                void setId(int id);
                //void setTerrain(std::string const& terrain);
                void setProbability(float probability);

            private:
                int mId; // The local tile ID within its tileset.
                //std::string mTerrain; // Defines the terrain type of each corner of the tile, given as comma-separated indexes in the terrain types array in the order top-left, top-right, bottom-left, bottom-right. Leaving out a value means that corner has no terrain. (optional) (since 0.9.0)
                float mProbability; // A percentage indicating the probability that this tile is chosen when it competes with others while editing with the terrain tool. (optional) (since 0.9.0)
        };

    public:
        Tileset(Map* map);

        int getFirstGid() const;
        //std::string getSource() const;
        std::string getName() const;
        int getTileWidth() const;
        int getTileHeight() const;
        int getSpacing() const;
        int getMargin() const;
        //TileOffset& getTileOffset();
        //TerrainTypes& getTerrainsTypes() const;

        void setFirstGid(int first);
        //void setSource(std::string const& source);
        void setName(std::string const& name);
        void setWidth(int width);
        void setHeight(int height);
        void setSpacing(int spacing);
        void setMargin(int margin);
        //void setTileOffset(TileOffset offset);
        //void setTerrainType(TerrainTypes ttypes);

    private:
        Map* mMap;

        int mFirstGid; // The first global tile ID of this tileset (this global ID maps to the first tile in this tileset).
        //std::string mSource; // If this tileset is stored in an external TSX (Tile Set XML) file, this attribute refers to that file. That TSX file has the same structure as the <tileset> element described here. (There is the firstgid attribute missing and this source attribute is also not there. These two attributes are kept in the TMX map, since they are map specific.)
        std::string mName; // The name of this tileset.
        int mWidth; // The (maximum) width of the tiles in this tileset.
        int mHeight; // The (maximum) height of the tiles in this tileset.
        int mSpacing; // The spacing in pixels between the tiles in this tileset (applies to the tileset image).
        int mMargin; // The margin around the tiles in this tileset (applies to the tileset image).
        //TileOffset mTileOffset;
        //TerrainTypes mTerrainTypes;
};

#endif // TME_TILESET_HPP