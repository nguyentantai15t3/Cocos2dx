#include "Bullet.h"
#include "ResourceManager.h"

Bullet::Bullet(Scene * scene)
{
	this->Init();
	this->m_sprite->setVisible(false);
	scene->addChild(this->m_sprite);
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
	this->m_sprite = ResourceManager::GetInstance()->GetSpriteById(4);
}

void Bullet::Update(float deltaTime)
{
	// 10 frame - 1 đạn
	
}
