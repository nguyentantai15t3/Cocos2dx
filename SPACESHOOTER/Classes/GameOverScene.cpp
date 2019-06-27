#include "GameOverScene.h"
#include "ResourceManager.h"
#include "PlayGameScene.h"
#include "MainMenuScene.h"
string scoreCurr= "";
Scene * GameOverScene::createScene(int score)
{
	scoreCurr = to_string(score);
	return GameOverScene::create();
}

bool GameOverScene::init()
{
	if (!Scene::init())
		return false;
	auto screenSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backGround = ResourceManager::GetInstance()->GetSpriteById(0);
	backGround->removeFromParent();
	backGround->setAnchorPoint(Vec2(0, 0));
	backGround->setScale(0.7f);
	addChild(backGround, -100);

	auto labelGameOver = ResourceManager::GetInstance()->GetLabelById(1);
	labelGameOver->removeFromParent();
	labelGameOver->setString("GAME OVER");
	labelGameOver->setPosition(Vec2(screenSize.width / 2, screenSize.height / 1.5));
	this->addChild(labelGameOver, 0);

	auto labelScore = ResourceManager::GetInstance()->GetLabelById(0);
	labelScore->setString("Your Score: " + scoreCurr);
	labelScore->setPosition(Vec2(screenSize.width / 2, screenSize.height / 1.8));
	labelScore->removeFromParent();
	this->addChild(labelScore, 0);

	auto buttonResum = ResourceManager::GetInstance()->GetButtonById(1);
	buttonResum->setPosition(Vec2(screenSize.width / 2 - 70, screenSize.height / 2 - 100));
	buttonResum->removeFromParent();
	buttonResum->setScale(0.5f);
	addChild(buttonResum, 0);
	buttonResum->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
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

	auto buttonHome = ResourceManager::GetInstance()->GetButtonById(2);
	buttonHome->setPosition(Vec2(screenSize.width / 2 + 70, screenSize.height / 2 - 100));
	buttonHome->removeFromParent();
	buttonHome->setScale(0.7f);
	addChild(buttonHome, 1);
	buttonHome->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			Director::getInstance()->replaceScene(TransitionFade::create(1.0f, MainMenuScene::create()));
			break;
		default:
			break;
		}
	});
	return true;
}
