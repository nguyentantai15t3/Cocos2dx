
#ifndef _BULLET_SCENE_H_
#define _BULLET_SCENE_H_

#include "Objectt.h"
#include "cocos2d.h"

USING_NS_CC;

class Bullet : public Objectt
{
public:
	Bullet(Scene *scene);
	~Bullet();
	void init() override;
	void update(float deltaTime) override;
};
#endif