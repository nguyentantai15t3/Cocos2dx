#include "Bullet.h"
#include "ResourceManager.h"

Bullet::Bullet(Scene * scene)
{
	this->Init();

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
}
