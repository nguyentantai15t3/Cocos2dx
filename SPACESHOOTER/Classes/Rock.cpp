#include "Rock.h"
#include "ResourceManager.h"

Rock::Rock(Scene * scene)
{
	this->init();
	this->m_sprite->setVisible(false);
	this->m_sprite->removeFromParent();
	scene->addChild(this->m_sprite, 0);
}

Rock::~Rock()
{
}

void Rock::init()
{
	this->m_sprite = (ResourceManager::GetInstance()->GetSpriteById(3));
	this->m_sprite = ResourceManager::GetInstance()->DuplicateSprite(this->m_sprite);
	this->m_sprite->setVisible(false);
}

void Rock::update(float deltaTime)
{
	m_sprite->setPosition(this->m_sprite->getPositionX(), m_sprite->getPositionY() - 7);
}
