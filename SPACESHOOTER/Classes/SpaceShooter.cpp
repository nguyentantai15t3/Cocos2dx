#include "SpaceShooter.h"
#include "ResourceManager.h"
#include "Bullet.h"
#define SizeOfList 20

int count=0;

SpaceShooter::SpaceShooter(Scene * scene)
{
	this->init();
	this->m_sprite->removeFromParent();
	scene->addChild(this->m_sprite, 5);
	for (int i = 0; i < SizeOfList; i++)
	{
		// tạo list đạn
		auto bullet = new Bullet(scene);
		this->m_bullets.push_back(bullet);
	}
}

SpaceShooter::~SpaceShooter()
{
}

void SpaceShooter::init()
{
	auto screenSize = Director::getInstance()->getVisibleSize();

	this->m_sprite = ResourceManager::GetInstance()->GetSpriteById(4);
	this->m_sprite->setPosition(screenSize.width / 2, 50);

}
int temp = 0;
void SpaceShooter::update(float deltaTime)
{
	
	if (temp == 15)
	{
		Shoot();
		temp = 0;
	}
	else
	{
		temp++;
	}
	auto member_bullets = this->m_bullets.begin();
	for (int i = 0; i < SizeOfList; i++)
	{
		if ((*member_bullets)->GetSprite()->isVisible())
		{
			(*member_bullets)->update(deltaTime);
		}
		member_bullets++;
	}
}

void SpaceShooter::Shoot()
{
	auto member_bullets = this->m_bullets.begin();
	for (int i = 0; i < SizeOfList; i++)
	{
		if (!((*member_bullets)->GetSprite()->isVisible()))
		{
			(*member_bullets)->GetSprite()->setVisible(true);
			(*member_bullets)->GetSprite()->setPosition(this->m_sprite->getPosition());
			break;
		}
		member_bullets++;
	}
}

void SpaceShooter::Collision(vector <Rock*> rocks)
{
	//	If (a->getBoundingBox()->intersectsRect(b-> getBoundingBox()))
	auto getboundingboxSpaceShooter = this->m_sprite->getBoundingBox();
	for (int i = 0; i < rocks.size(); i++)
	{
		if (rocks[i]->GetSprite()->isVisible())
		{
		}
	}
}

