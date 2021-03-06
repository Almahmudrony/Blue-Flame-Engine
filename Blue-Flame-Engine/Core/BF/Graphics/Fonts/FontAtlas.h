#pragma once
#include <string>
#include "BF/Graphics/API/Texture2D.h"
#include "BF/Math/Math.h"
#include "BF/Graphics/Fonts/Character.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Fonts
		{
			class BF_API FontAtlas
			{
				public:
					std::string fontName;
					unsigned int textSize;
					const API::Texture2D* texture;
					const std::vector<Character>* characters;

				FontAtlas(const std::string& fontName, unsigned int textSize, const API::Texture2D* texture, const std::vector<Character>* characters) :
					fontName(fontName), textSize(textSize), texture(texture), characters(characters)
				{
				}
			};
		}
	}
}