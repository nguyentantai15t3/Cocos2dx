#include "LoadingScene.h"
#include "ResourceManager.h"

USING_NS_CC;

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
	auto background = ResourceManager::GetInstance()->GetBackgroundSprite();
	background->removeFromParent();
	background->setAnchorPoint(Vec2(0, 0));
	background->setScale(0.7f);
	addChild(background, -1);
	return true;
}

void LoadingScene::Update(float deltaTime)
{
}
