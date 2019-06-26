#include "Bullet.h"
#include "ResourceManager.h"

Bullet::Bullet(Scene * scene)
{
	this->Init();
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

void Bullet::Init()
{
	this->m_sprite = (ResourceManager::GetInstance()->GetSpriteById(2));
	ResourceManager::GetInstance()->DuplicateSprite(this->m_sprite);
}

void Bullet::Update(float deltaTime)
{
	// 10 frame - 1 đạn
	
}

