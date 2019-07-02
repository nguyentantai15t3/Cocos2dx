#include "PlayGameScene.h"
#include "ResourceManager.h"
#include <ctime>

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
	srand(time(NULL));
	auto screenSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backGround = ResourceManager::GetInstance()->GetSpriteById(0);
	backGround->removeFromParent();
	backGround->setAnchorPoint(Vec2(0, 0));
	backGround->setScale(screenSize.width / backGround->getContentSize().width, screenSize.height / backGround->getContentSize().width);
	addChild(backGround, -1);
	labelscore = ResourceManager::GetInstance()->GetLabelById(0);
	labelscore->removeFromParent();
	labelscore->setPosition(screenSize.width / 2, screenSize.height * 2 / 2.5);
	addChild(labelscore);

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
	m_spaceShip->setScore(0);
	scheduleUpdate();
	return true;
}

void PlayGameScene::update(float deltaTime)
{
	static int countt = 0;
	m_spaceShip->Collision(m_rocks);
	m_spaceShip->Update(deltaTime);
	countt++;
	if (countt == 20)
	{
		GenerateRock();
		countt = 0;
	}
	for (int i = 0; i < m_rocks.size(); i++)
	{
		if (m_rocks[i]->GetSprite()->isVisible())
		{
			m_rocks[i]->Update(deltaTime);
		}
	}
	labelscore->setString(to_string(m_spaceShip->getScore()));
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
			m_rocks[i]->GetSprite()->setPosition(rand() % width, screenSize.height *1.1);
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
