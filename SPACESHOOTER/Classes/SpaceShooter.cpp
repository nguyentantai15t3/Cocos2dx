#include "SpaceShooter.h"
#include "ResourceManager.h"
#include "Bullet.h"
#define SizeOfList 10

int count;

SpaceShooter::SpaceShooter(Scene * scene)
{
	this->Init();
	this->m_sprite->removeFromParent();
	scene->addChild(this->m_sprite, 1);
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

void SpaceShooter::Init()
{
	auto screenSize = Director::getInstance()->getVisibleSize();

	this->m_sprite = ResourceManager::GetInstance()->GetSpriteById(4);
	this->m_sprite->setPosition(screenSize.width / 2, 50);

}

void SpaceShooter::Update(float deltaTime)
{
	// 
}

void SpaceShooter::Shoot()
{
	auto member_bullets = this->m_bullets.begin();
	for (int i = 0; i < SizeOfList; i++)
	{
		if (!(*member_bullets)->GetSprite()->isVisible)
		{
			(*member_bullets)->GetSprite()->setVisible(true);
			(*member_bullets)->GetSprite()->setPosition(this->m_sprite->getPosition);
		}
		(*member_bullets)++;
	}
}

void SpaceShooter::Collision(vector <Rock*>)
{
}
