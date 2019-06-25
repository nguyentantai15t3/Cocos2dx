#ifndef _OBJECTT_SCENE_H_
#define _OBJECTT_SCENE_H_

#include "cocos2d.h"

USING_NS_CC;

class Objectt
{
public:
	Objectt();
	~Objectt();
	Sprite * GetSprite();
	virtual void Update(float deltaTime)=0;
	virtual void Init()=0;
protected:
	Sprite* m_sprite;
};
#endif