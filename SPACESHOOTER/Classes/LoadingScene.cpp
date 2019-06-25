#include "LoadingScene.h"
#include "ResourceManager.h"
#include "MainMenuScene.h"

USING_NS_CC;

int temp = 0;

Scene * LoadingScene::createScene()
{
	auto scene = Scene::create();
	auto layer = LoadingScene::create();
	scene->addChild(layer);
	return scene;
}
bool LoadingScene::init()
{
	auto screenSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backGround = ResourceManager::GetInstance()->GetSpriteById(0);
	backGround->removeFromParent();
	backGround->setAnchorPoint(Vec2(0, 0));
	backGround->setScale(0.7f);
	addChild(backGround, -1);

	auto labelLoading = ResourceManager::GetInstance()->GetLabelById(0);
	//auto text = ui::Text::create();
	//text->setFontSize(100.0f);
	//text->setString("Loading...");
	//labelLoading->setContentSize();
	labelLoading->setPosition(screenSize.width / 2, screenSize.height/2 + 50);
	labelLoading->setString("Loading...");
	addChild(labelLoading, 0);

	auto loadingBar = ResourceManager::GetInstance()->GetSpriteById(5);
	loadingBar->setAnchorPoint(Vec2(0, 0.5));
	loadingBar->setPosition(screenSize.width/4.5, screenSize.height / 2);
	addChild(loadingBar);

	auto progress = ResourceManager::GetInstance()->GetSpriteById(6);
	progress->setPosition(screenSize.width / 4.5, screenSize.height / 2);
	progress->setAnchorPoint(Vec2(0, 0.5f));
	progress->setScaleX(0.01f);
	addChild(progress);

	auto scale = ScaleBy::create(3, 100.0f, 1.0f);
	scheduleUpdate();
	progress->runAction(scale);
	
	return true;
}

void LoadingScene::update(float deltaTime)
{
	temp++;
	if(temp == 180) // 3s - 60fps/1s
	{
		Director::getInstance()->replaceScene(TransitionFade::create(1.0f, MainMenuScene::create()));
	}
}
