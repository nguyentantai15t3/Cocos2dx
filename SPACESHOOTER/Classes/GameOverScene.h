#ifndef _GAMEOVERSCENE_SCENE_H_
#define _GAMEOVERSCENE_SCENE_H_

#include "cocos2d.h"
USING_NS_CC;

class GameOverScene : public Scene
{
public:
	static Scene* createScene();
	virtual bool init() override;
	CREATE_FUNC(GameOverScene);
};
#endif#pragma once
