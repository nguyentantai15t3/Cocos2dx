
#ifndef _BULLET_SCENE_H_
#define _BULLET_SCENE_H_

#include "Objectt.h"
#include "cocos2d.h"

USING_NS_CC;

class Bullet : public Objectt
{
public:
	Bullet(Scene *scene);
	Bullet(const Bullet* bullet);
	~Bullet();
	void Init() override;
	void Update(float deltaTime) override;
};
#endif