#include "SFML/Graphics/Texture.hpp"
#include <map>
#include <string_view>

#define OBJECT_TEXTURE_PATH "../Resources/Textures/Map/Object/"

class ObjectTextureManager
{
public:
	ObjectTextureManager();
	~ObjectTextureManager();

	static bool AddTexture(std::string_view _name, std::string_view _path);
	static sf::Texture* GetTexture(std::string_view _name);

	static inline std::map<std::string_view, sf::Texture*>& Get() { return m_Texture; }

private:
	static std::map<std::string_view, sf::Texture*> m_Texture;

};