#include "Bullet.h"
#include "ResourceManager.h"

Bullet::Bullet(Scene * scene)
{
	this->Init();
	this->m_sprite->setVisible(false);
	this->m_sprite->removeFromParent();
	this->m_sprite->setScale(0.7);
	scene->addChild(this->m_sprite,0);
}


Bullet::~Bullet()
{
}

void Bullet::Init()
{
	this->m_sprite = (ResourceManager::GetInstance()->GetSpriteById(2));
	this->m_sprite= ResourceManager::GetInstance()->DuplicateSprite(this->m_sprite);
	this->m_sprite->setVisible(false);
}

void Bullet::Update(float deltaTime)
{
	auto move = MoveBy::create(deltaTime, Vec2(0, 15));
	this->m_sprite->runAction(move);
	if (this->m_sprite->getPositionY() > Director::getInstance()->getVisibleSize().height)
	{
		this->m_sprite->setVisible(false);
	}
}

