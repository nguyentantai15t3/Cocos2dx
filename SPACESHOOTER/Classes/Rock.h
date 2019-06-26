#ifndef _ROCK_SCENE_H_
#define _ROCK_SCENE_H_

#include "Objectt.h"
#include "cocos2d.h"

USING_NS_CC;

class Rock: public Objectt
{
public:
	Rock(Scene *scene);
	~Rock();
	void Init() override;
	void Update(float deltaTime) override;
};
#endif
