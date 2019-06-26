#include "SpaceShooter.h"
#include "ResourceManager.h"
#include "Bullet.h"
#include "GameOverScene.h"
#include "PlayGameScene.h"
#define SizeOfList 20

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
int temp = 0;
void SpaceShooter::Update(float deltaTime)
{
	auto height = Director::getInstance()->getVisibleSize().height + 10;
	if (temp == 10)
	{
		Shoot();
		temp = 0;
	}
	else
	{
		temp++;
	}
	auto member_bullets = this->m_bullets.begin();
	for (int i = 0; i < SizeOfList; i++)
	{
		if ((*member_bullets)->GetSprite()->isVisible())
		{
			(*member_bullets)->Update(deltaTime);
			if ((*member_bullets)->GetSprite()->getPositionY() > height)
			{
				(*member_bullets)->GetSprite()->setVisible(false);
			}
		}
		member_bullets++;
	}
}

void SpaceShooter::Shoot()
{
	auto member_bullets = this->m_bullets.begin();
	for (int i = 0; i < SizeOfList; i++)
	{
		if (!((*member_bullets)->GetSprite()->isVisible()))
		{
			(*member_bullets)->GetSprite()->setVisible(true);
			(*member_bullets)->GetSprite()->setPosition(this->m_sprite->getPosition());
			break;
		}
		member_bullets++;
	}
}
int score = 0;
void SpaceShooter::Collision(vector <Rock*> rocks)
{
	//	If (a->getBoundingBox()->intersectsRect(b-> getBoundingBox()))
	auto getBSpaceShip = this->m_sprite->getBoundingBox();
	auto member_bullets = this->m_bullets.begin();
	for (int i = 0; i < SizeOfList; i++)
	{
		if ((*member_bullets)->GetSprite()->isVisible())
		{
			for (int j = 0; j < rocks.size(); j++)
			{
				auto getBRock = rocks.at(j)->GetSprite()->getBoundingBox();
				auto getBBullet = (*member_bullets)->GetSprite()->getBoundingBox();
				if (rocks.at(i)->GetSprite()->isVisible())
				{
					if (getBSpaceShip.intersectsRect(getBRock))
					{
						Director::getInstance()->getRunningScene()->pause();
						Director::getInstance()->replaceScene(TransitionFade::create(2.0f, GameOverScene::createScene(score)));
						break;
					}
					if (getBRock.intersectsRect(getBBullet))
					{
						rocks.at(j)->GetSprite()->setVisible(false);
						(*member_bullets)->GetSprite()->setVisible(false);
						score++;
					}
				}
			}			
		}
		member_bullets++;
	}
}


