#include "PlayGameScene.h"
#include "ResourceManager.h"
#define SizeOfRock 20
USING_NS_CC;

Scene * PlayGameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = PlayGameScene::create();
	scene->addChild(layer);
	return scene;
}

bool PlayGameScene::init()
{
	auto screenSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backGround = ResourceManager::GetInstance()->GetSpriteById(0);
	backGround->removeFromParent();
	backGround->setAnchorPoint(Vec2(0, 0));
	backGround->setScale(0.7f);
	addChild(backGround, -1);

	for (int i = 0; i < SizeOfRock ; i++) // add rock into list
	{
		Rock* rock = new Rock(this);
		m_rocks.push_back(rock);
	}

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(PlayGameScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(PlayGameScene::onTouchMoved, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	m_spaceShip = new SpaceShooter(this);
	scheduleUpdate();
	return true;
}
int temp2 = 0;
void PlayGameScene::update(float deltaTime)
{
	m_spaceShip->update(deltaTime);
	if (temp2 == 10)
	{
		GenerateRock();
		temp2 = 0;
	}
	else
	{
		temp2++;
	}
	for (int i = 0; i < m_rocks.size(); i++)
	{
		if (m_rocks[i]->GetSprite()->isVisible())
		{
			m_rocks[i]->update(deltaTime);
			if (m_rocks[i]->GetSprite()->getPositionY()<0 )
			{
				m_rocks[i]->GetSprite()->setVisible(false);
				auto screenSize = Director::getInstance()->getVisibleSize();
				int width = screenSize.width;
				m_rocks[i]->GetSprite()->setPosition(rand() % width, screenSize.height + 50);
			}
		}
	}
}

void PlayGameScene::GenerateRock()
{
	for (int i = 0; i < m_rocks.size(); i++)
	{
		if (!m_rocks[i]->GetSprite()->isVisible())
		{
			auto screenSize = Director::getInstance()->getVisibleSize();
			int width = screenSize.width;
			m_rocks[i]->GetSprite()->setVisible(true);
			m_rocks[i]->GetSprite()->setPosition(rand() % width, screenSize.height + 50);
			break;
		}
	}
}

bool PlayGameScene::onTouchBegan(Touch *touch, Event *event)
{
	Point touchLocation = touch->getLocation();

	if (m_spaceShip->GetSprite()->getBoundingBox().containsPoint(touchLocation))
	{
		return true;
	}

	return false;
}

bool PlayGameScene::onTouchEnded(Touch *, Event *)
{
	return false;
}

void PlayGameScene::onTouchMoved(Touch *touch, Event *event)
{	
	//m_spaceShip->GetSprite()->setPosition(m_spaceShip->GetSprite()->getPosition() + touch->getDelta());
	m_spaceShip->GetSprite()->setPosition(touch->getLocation());
}
