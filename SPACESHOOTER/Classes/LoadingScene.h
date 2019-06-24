#ifndef _LOADING_SCENE_H_
#define _LOADING_SCENE_H_

#include "cocos2d.h"
USING_NS_CC;

class LoadingScene : public Scene
{
public:
	static Scene* createScene();
	virtual bool init();
	void Update(float deltaTime);
	CREATE_FUNC(LoadingScene);
};
#endif

