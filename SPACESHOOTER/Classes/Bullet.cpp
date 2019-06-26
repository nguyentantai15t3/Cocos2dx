#include "Bullet.h"
#include "ResourceManager.h"

Bullet::Bullet(Scene * scene)
{
	this->init();
	this->m_sprite->setVisible(false);
	this->m_sprite->removeFromParent();
	scene->addChild(this->m_sprite,0);
}

Bullet::Bullet(const Bullet * bullet)
{
	this->m_sprite = bullet->m_sprite;
}

Bullet::~Bullet()
{
}

void Bullet::init()
{
	this->m_sprite = (ResourceManager::GetInstance()->GetSpriteById(2));
	this->m_sprite= ResourceManager::GetInstance()->DuplicateSprite(this->m_sprite);
}

void Bullet::update(float deltaTime)
{
	this->m_sprite->setPosition(this->m_sprite->getPositionX(),this->m_sprite->getPositionY() + 10);
}

