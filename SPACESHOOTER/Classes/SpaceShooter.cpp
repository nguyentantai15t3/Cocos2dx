#include "SpaceShooter.h"
#include "ResourceManager.h"

SpaceShooter::SpaceShooter(Scene * scene)
{
	this->Init();
	this->m_sprite->removeFromParent();
	scene->addChild(this->m_sprite, 1);
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
}

void SpaceShooter::Shoot()
{
}

void SpaceShooter::Collision(vector <Rock*>)
{
}
