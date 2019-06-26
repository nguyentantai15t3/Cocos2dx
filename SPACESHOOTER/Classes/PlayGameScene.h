#ifndef _PLAYGAMESCENE_SCENE_H_
#define _PLAYGAMESCENE_SCENE_H_

#include "cocos2d.h"
#include <vector>
#include <Rock.h>
#include <SpaceShooter.h>

using namespace std;
USING_NS_CC;

class PlayGameScene : public Scene
{
public:
	static Scene* createScene();
	virtual bool init() override;
	void update(float deltaTime) override;
	void GenerateRock();
	bool onTouchBegan(Touch*, Event*);
	bool onTouchEnded(Touch*, Event*);
	void onTouchMoved(Touch*, Event*);
	CREATE_FUNC(PlayGameScene);
private:
	vector <Rock*> m_rocks;
	SpaceShooter *m_spaceShip; // kế thừa object
};
#endif
