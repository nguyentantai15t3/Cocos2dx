#include "SpaceShooter.h"
#include "ResourceManager.h"
#include "Bullet.h"
#include "GameOverScene.h"
#include "LoadingScene.h"
#define SizeOfList 20

int count=0;

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

void SpaceShooter::Collision(vector <Rock*> rocks,float deltaTime)
{
	//	If (a->getBoundingBox()->intersectsRect(b-> getBoundingBox()))
	log("%f", deltaTime);
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
						//Director::getInstance()->getRunningScene()->pause();
						//Director::getInstance()->replaceScene(TransitionZoomFlipAngular::create(1, GameOverScene::createScene()));
					}
					if (getBRock.intersectsRect(getBBullet))
					{
						rocks.at(j)->GetSprite()->setVisible(false);
						(*member_bullets)->GetSprite()->setVisible(false);
					}
				}
			}			
		}
		member_bullets++;
	}
}

