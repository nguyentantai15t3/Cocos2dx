#ifndef _RESOURCEMANAGER_SCENE_H_
#define _RESOURCEMANAGER_SCENE_H_

#include "cocos2d.h"
#include <map>
#include <string>
#include <ui\CocosGUI.h>

using namespace std;
USING_NS_CC;

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
	void Init(const string path);
	void Load(string fileName);
	Sprite* GetSpriteById(char id);
	ui::Button* GetButtonById(char id);
	Label* GetLabelById(char id);
	static ResourceManager* GetInstance();

private:
	ResourceManager* s_instance;
	string m_dataFolderPath;
	map<char, Sprite*> m_sprites;
	map<char, ui::Button*> m_button;
	map<char, Label*> m_lable;
};
#endif