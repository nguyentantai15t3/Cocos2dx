#include "ResourceManager.h"
#include <fstream>
#include <iostream>

USING_NS_CC;
using namespace std;

ResourceManager * ResourceManager::s_instance = nullptr;	// biến static = nullptr

ResourceManager::ResourceManager()
{
	this->init("res");
}
ResourceManager::~ResourceManager()
{
}

void ResourceManager::init(const string path)
{
	this->m_dataFolderPath = path;						// gán m_dataFolderPath = res
	this->Load(this->m_dataFolderPath+ "/Data1.bin");	// Load file bin nằm trong res
}

void ResourceManager::Load(string fileName)
{
//#if 0
//
//
//	ifstream inFile;
//	inFile.open(fileName);
//	if (FileUtils::getInstance()->isFileExist(fileName))
//	{
//		
//		while (!inFile.eof()) // end of file
//		{
//			string temp, normal_path, pressed_path, ignore;
//			int size, id;
//			inFile >> temp;
//			if (temp == "#SPRITE")
//			{
//				inFile >> size;
//				for (int i = 0; i < size; i++)
//				{
//					inFile >> ignore;		// bỏ qua
//					inFile >> id;			// lấy id của sprite
//					inFile >> ignore;
//					inFile >> normal_path;
//					normal_path.replace(0, 2, this->m_dataFolderPath); // thay %s = res
//					auto sprite = Sprite::create(normal_path); // tạo sprite = path
//					sprite->retain();
//					this->m_sprites.insert(pair<char, Sprite*>(id, sprite));
//				}
//			}
//			else if (temp == "#BUTTON")
//			{
//				inFile >> size;
//				for (int i = 0; i < size; i++)
//				{
//					inFile >> ignore;		// bỏ qua 
//					inFile >> id;			// lấy id của button
//					inFile >> ignore;
//					inFile >> normal_path;	// lấy đường dẫn 1
//					inFile >> ignore;
//					inFile >> pressed_path;	// lấy đường dẫn 2
//					normal_path.replace(0, 2, this->m_dataFolderPath);	// thay %s = res
//					pressed_path.replace(0, 2, this->m_dataFolderPath);	// thay %s = res
//					auto button = ui::Button::create(normal_path, pressed_path);
//					button->retain();
//					this->m_button.insert(pair<char, ui::Button*>(id, button));
//				}
//			}
//			else
//			{
//				inFile >> size;
//				for (int i = 0; i < size; i++)
//				{
//					auto text = ui::Text::create();
//					text->setFontSize(50);
//					inFile >> ignore;		// bỏ qua 
//					inFile >> id;			// lấy id của label
//					inFile >> ignore;
//					inFile >> normal_path;	// lấy đường dẫn
//					normal_path.replace(0, 2, this->m_dataFolderPath);	// thay %s = res
//					auto label = Label::createWithTTF("",normal_path,30);
//					label->retain();
//					this->m_label.insert(pair<char, Label*>(id, label));
//				}
//			}
//		}
//	}
//	else
//	{
//		cout << "Load file error" << endl;
//	}
//#endif // 0
	if (FileUtils::getInstance()->isFileExist(fileName))
	{
		auto data = FileUtils::getInstance()->getStringFromFile(fileName);
		istringstream newdata(data);
		string temp;
		int size;
		newdata >> temp >> size;
		for (int i = 0; i < size; i++)
		{
			int id;
			string ignore, normal_path;
			newdata >> ignore >> id >> ignore >> normal_path;			// lấy id của sprite
			normal_path.replace(0, 2, this->m_dataFolderPath);			// thay %s = res
			auto sprite = Sprite::create(normal_path);					// tạo sprite = path
			sprite->retain();
			this->m_sprites.insert(pair<char, Sprite*>(id, sprite));
		}
		newdata >> temp >> size;
		for (int i = 0; i < size; i++)
		{
			int id;
			string ignore, normal_path, pressed_path;
			newdata >> ignore >> id >> ignore >> normal_path >> ignore >> pressed_path;
			normal_path.replace(0, 2, this->m_dataFolderPath);	// thay %s = res
			pressed_path.replace(0, 2, this->m_dataFolderPath);	// thay %s = res
			auto button = ui::Button::create(normal_path, pressed_path);
			button->retain();
			this->m_button.insert(pair<char, ui::Button*>(id, button));
		}
		newdata >> temp >> size;
		for (int i = 0; i < size; i++)
		{
			int id;
			string ignore, normal_path;
			newdata >> ignore >> id >> ignore >> normal_path;
			normal_path.replace(0, 2, this->m_dataFolderPath);	// thay %s = res
			auto label = Label::createWithTTF("",normal_path,30);
			label->retain();
			this->m_label.insert(pair<char, Label*>(id, label));
		}
	}
}

Sprite * ResourceManager::GetSpriteById(int id)
{
	auto sprite = this->m_sprites[id];
	auto tmp = m_sprites.find(id);
	while (tmp != m_sprites.end())
	{
		return tmp->second;
	}
}

ui::Button * ResourceManager::GetButtonById(int id)
{
	auto button = this->m_button[id];
	auto tmp = m_button.find(id);
	while (tmp != m_button.end())
	{
		return tmp->second;
	}
}

Label * ResourceManager::GetLabelById(int id)
{
	auto label = this->m_label[id];
	auto tmp = m_label.find(id);
	while (tmp != m_label .end())
	{
		return tmp->second;
	}
}

ResourceManager * ResourceManager::GetInstance()
{
	if (!s_instance)	// false
	{
		s_instance = new ResourceManager();	// tạo mới
	}
	return s_instance;
}

Sprite * ResourceManager::DuplicateSprite(Sprite * sprite)
{
	Sprite* pRet = Sprite::createWithTexture(sprite->getTexture());
	if (sprite->getChildrenCount() > 0)
	{
		for (int child = 0; child < sprite->getChildrenCount(); child++)
		{
			Sprite* spriteChild = (Sprite*)sprite->getChildren().at(child);
			Sprite* clone = DuplicateSprite((Sprite*)spriteChild);
			clone->boundingBox() = spriteChild->boundingBox();
			clone->setContentSize(spriteChild->getContentSize());
			clone->setPosition(spriteChild->getPosition());
			clone->setAnchorPoint(sprite->getAnchorPoint());
			pRet->addChild(clone, spriteChild->getZOrder(), sprite->getTag());
		}
	}
	return pRet;
}