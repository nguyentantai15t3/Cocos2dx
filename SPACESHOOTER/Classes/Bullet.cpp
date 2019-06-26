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
	this->m_sprite->setVisible(false);
}

void Bullet::update(float deltaTime)
{
	m_sprite->setPosition(m_sprite->getPositionX(), m_sprite->getPositionY() + 7);
}

