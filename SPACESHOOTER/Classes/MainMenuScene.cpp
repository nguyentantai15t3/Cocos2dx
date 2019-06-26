#include "MainMenuScene.h"
#include "ResourceManager.h"
#include "PlayGameScene.h"

Scene * MainMenuScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MainMenuScene::create();
	scene->addChild(layer);
	return scene;
}

bool MainMenuScene::init()
{
	auto screenSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backGround = ResourceManager::GetInstance()->GetSpriteById(0);
	backGround->removeFromParent();
	backGround->setAnchorPoint(Vec2(0, 0));
	backGround->setScale(0.7f);
	addChild(backGround, -1);

	auto logoGame = ResourceManager::GetInstance()->GetSpriteById(1);
	logoGame->setPosition(screenSize.width / 2, screenSize.height*2 / 3 );
	logoGame->setScaleY(0.5);
	logoGame->setScaleX(0.7);
	addChild(logoGame,0);

	auto buttonPlay = ResourceManager::GetInstance()->GetButtonById(0);
	buttonPlay->setPosition(Vec2(screenSize.width/2,screenSize.height/2));
	buttonPlay->setScale(0.5f);
	addChild(buttonPlay, 0);
	buttonPlay->addTouchEventListener([&](Ref* sender,ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			Director::getInstance()->replaceScene(TransitionFade::create(1.0f, PlayGameScene::create()));
			break;
		default:
			break;
		}
	});
	
	return true;
}
