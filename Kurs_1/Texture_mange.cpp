#include"Texture_manage.h"
#include"functions.h"

TextureManager::TextureManager()
{
	pTexture = nullptr;
	cout << "Texturemanage const" << endl;
}

TextureManager::TextureManager(string path, SDL_Renderer* pRenderer)
{
	pTexture = loadimage_png(path, pRenderer);
	cout << "Texturemanage const with args"<< endl;
}

bool TextureManager::load(string fileName, SDL_Renderer* pRenderer)
{
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
	if (pTempSurface == 0)
	{
		return false;
	}
	 pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
	// everything went ok, add the texture to our list
	if (pTexture != 0)
	{
		return true;
	}
	// reaching here means something went wrong
	return false;
}

void TextureManager::draw( int x, int y, int width, int height, SDL_Renderer* pRenderer,SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, pTexture, &srcRect,	&destRect, 0, 0, flip);
}

void TextureManager::drawFrame( int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, pTexture, &srcRect,	&destRect, 0, 0, flip);
}

TextureManager::~TextureManager()
{
	SDL_DestroyTexture(pTexture);
	cout << "Texturemanage destruct ~ " << endl;
}
