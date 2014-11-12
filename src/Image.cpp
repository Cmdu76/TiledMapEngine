#include "../include/Image.hpp"

////////////////////////////////////////////////////////////
Image::Image() : mTexture(nullptr)
{
}

////////////////////////////////////////////////////////////
bool Image::load(std::string const& filename)
{
    std::string file = filename;
    if (file == "")
    {
        file = mSource;
    }

    sf::Image img;
    if (!img.loadFromFile(file))
    {
        return false;
    }
    mFormat = Image::getFormat(file);
    mSource = file;

    if (mTrans != "")
    {
        img.createMaskFromColor(Image::getColor(mTrans));
    }

    mWidth = static_cast<int>(img.getSize().x);
    mHeight = static_cast<int>(img.getSize().y);

    mTexture = std::shared_ptr<sf::Texture>(new sf::Texture());
    if (mTexture == nullptr)
    {
        return false;
    }

    if (!mTexture->loadFromImage(img, sf::IntRect(0,0,mWidth,mHeight)))
    {
        return false;
    }

    return true;
}

////////////////////////////////////////////////////////////
Image::TexturePtr Image::getTexture() const
{
    return mTexture;
}

////////////////////////////////////////////////////////////
std::string Image::getFormat() const
{
    return mFormat;
}

////////////////////////////////////////////////////////////
std::string Image::getSource() const
{
    return mSource;
}

////////////////////////////////////////////////////////////
std::string Image::getTrans() const
{
    return mTrans;
}

////////////////////////////////////////////////////////////
int Image::getWidth() const
{
    return mWidth;
}

////////////////////////////////////////////////////////////
int Image::getHeight() const
{
    return mHeight;
}

////////////////////////////////////////////////////////////
void Image::setTexture(TexturePtr texture)
{
    mTexture = texture;
}

////////////////////////////////////////////////////////////
void Image::setFormat(std::string const& format)
{
    mFormat = format;
}

////////////////////////////////////////////////////////////
void Image::setSource(std::string const& source)
{
    mSource = source;
}

////////////////////////////////////////////////////////////
void Image::setTrans(std::string const& trans)
{
    mTrans = trans;
}

////////////////////////////////////////////////////////////
void Image::setWidth(int width)
{
    mWidth = width;
}

////////////////////////////////////////////////////////////
void Image::setHeight(int height)
{
    mHeight = height;
}

////////////////////////////////////////////////////////////
std::string Image::getFormat(std::string const& filename)
{
    return (filename.rfind(".") != std::string::npos) ? filename.substr(filename.rfind(".")+1,filename.size()) : "";
}

////////////////////////////////////////////////////////////
sf::Color Image::getColor(std::string const& hexColor)
{
    return sf::Color::Transparent;
}

