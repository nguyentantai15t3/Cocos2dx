#include "ResourceManager.h"
#include <fstream>
#include <iostream>

USING_NS_CC;
using namespace std;

ResourceManager::ResourceManager()
{
	this->Init("res");
}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::Init(const string path)
{
	this->m_dataFolderPath = path;
	this->Load(this->m_dataFolderPath + "\Data.bin");
}

void ResourceManager::Load(string fileName)
{
	ifstream inFile;
	inFile.open(fileName);
	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			string temp;
			string normal_path;
			string pressed_path;
			int size;
			char id;
			inFile >> temp;
			if (temp == "#SPRITE")
			{
				inFile >> size;
				for (int i = 0; i < size; i++);
				{
					inFile >> temp;
					inFile >> id;
					inFile >> temp;
					inFile >> normal_path;
					normal_path.replace(normal_path.find_first_of("%s"), 2, this->m_dataFolderPath);
					auto sprite = Sprite::create(normal_path);
					this->m_sprites.insert(pair<char, Sprite*>(id, sprite));
				}
			}
			else if (temp == "#BUTTON")
			{
				inFile >> size;
				for (int i = 0; i < size; i++);
				{
					inFile >> temp;
					inFile >> id;
					inFile >> temp;
					inFile >> normal_path;
					inFile >> temp;
					inFile >> pressed_path;
					normal_path.replace(normal_path.find_first_of("%s"), 2, this->m_dataFolderPath);
					auto button = ui::Button::create(normal_path, pressed_path);
					this->m_button.insert(pair<char, ui::Button*>(id, button));
				}
			}
			else
			{
				inFile >> size;
				for (int i = 0; i < size; i++);
				{
					inFile >> temp;
					inFile >> id;
					inFile >> temp;
					inFile >> normal_path;
					normal_path.replace(normal_path.find_first_of("%s"), 2, this->m_dataFolderPath);
					auto lable = Label::createWithTTF(normal_path,"");
					this->m_lable.insert(pair<char, Label*>(id, lable));
				}
			}
		}
	}
	else
	{
		cout << "Load file error" << endl;
	}
}

Sprite * ResourceManager::GetSpriteById(char id)
{
	auto sprite = this->m_sprites.at(id);
	sprite->retain();
	return sprite;
}

ui::Button * ResourceManager::GetButtonById(char id)
{
	auto button = this->m_button.at(id);
	button->retain();
	return button;
}

Label * ResourceManager::GetLabelById(char id)
{
	auto label = this->m_lable.at(id);
	label->retain();
	return label;
}

ResourceManager * ResourceManager::GetInstance()
{
	if (!s_instance)
	{
		s_instance = new ResourceManager();
	}
	return s_instance;
}
