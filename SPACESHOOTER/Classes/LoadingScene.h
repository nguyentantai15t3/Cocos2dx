#ifndef _LOADING_SCENE_H_
#define _LOADING_SCENE_H_

#include "cocos2d.h"
USING_NS_CC;

class LoadingScene : public Scene
{
public:
	static Scene* createScene();
	virtual bool init() override;
	void update(float deltaTime) override;
	CREATE_FUNC(LoadingScene);
};
#endif

