#include "PlayGameScene.h"
#include "ResourceManager.h"

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

	spaceship = ResourceManager::GetInstance()->GetSpriteById(4);
	spaceship->setPosition(screenSize.width / 2, 50);
	addChild(spaceship, 0);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(PlayGameScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(PlayGameScene::onTouchMoved, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void PlayGameScene::update(float deltaTime)
{
}

void PlayGameScene::GenerateRock()
{
}

bool PlayGameScene::onTouchBegan(Touch *touch, Event *event)
{
	Point touchLocation = touch->getLocation();

	if (spaceship->getBoundingBox().containsPoint(touchLocation))
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
	spaceship->setPosition(spaceship->getPosition() + touch->getDelta());
}
