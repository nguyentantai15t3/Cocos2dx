#ifndef _MAINMENUSCENE_SCENE_H_
#define _MAINMENUSCENE_SCENE_H_

#include "cocos2d.h"
USING_NS_CC;

class MainMenuScene : public Scene
{
public:
	static Scene* createScene();
	virtual bool init() override;
	CREATE_FUNC(MainMenuScene);
};
#endif