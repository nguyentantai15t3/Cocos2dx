#ifndef _SPACESHOOTER_SCENE_H_
#define _SPACESHOOTER_SCENE_H_

#include "cocos2d.h"
#include <vector>
#include "Rock.h"
#include "Objectt.h"

using namespace std;
USING_NS_CC;

class SpaceShooter: public Objectt
{
public:
	SpaceShooter(Scene *scene);
	~SpaceShooter();
	void init() override;
	void update(float deltaTime) override;
	void Shoot();
	void Collision(vector < Rock*>);
private:
	list<Objectt*> m_bullets;
};
#endif