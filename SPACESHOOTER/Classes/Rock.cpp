#include "Rock.h"
#include "ResourceManager.h"

Rock::Rock(Scene * scene)
{
	this->Init();
	this->m_sprite->setVisible(false);
	this->m_sprite->removeFromParent();
	this->m_sprite->setPosition(-555,-555);
	scene->addChild(this->m_sprite, 1);
}

Rock::~Rock()
{
}

void Rock::Init()
{
	this->m_sprite = (ResourceManager::GetInstance()->GetSpriteById(3));
	this->m_sprite = ResourceManager::GetInstance()->DuplicateSprite(this->m_sprite);
	this->m_sprite->setVisible(false);
}

void Rock::Update(float deltaTime)
{
	auto move = MoveBy::create(deltaTime, Vec2(0, -5));
	this->m_sprite->runAction(move);
	if (this->m_sprite->getPositionY() < 0)
	{
		this->m_sprite->setVisible(false);
	}
}
