#include "GameOverScene.h"

Scene * GameOverScene::createScene()
{
	return GameOverScene::create();
}

bool GameOverScene::init()
{
	if (!Scene::init())
		return false;
}
