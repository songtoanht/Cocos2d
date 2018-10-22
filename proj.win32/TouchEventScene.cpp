#include "TouchEventScene.h"

USING_NS_CC;

Scene* TouchEvent::createScene()
{
	auto scene = Scene::create();
	auto layer = TouchEvent::create();
	scene->addChild(layer);

	return scene;
}

bool TouchEvent::init()
{
	if (!Layer::init())
	{
		return false;
	}

	labelTouchInfo = Label::createWithSystemFont("Touch or clicksomewhere to begin", "Arial", 30);

	labelTouchInfo->setPosition(Vec2(
		Director::getInstance()->getVisibleSize().width / 2,
		Director::getInstance()->getVisibleSize().height / 2));

	auto touchListener = EventListenerTouchOneByOne::create();

	touchListener->onTouchBegan = CC_CALLBACK_2(TouchEvent::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(TouchEvent::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(TouchEvent::onTouchMoved, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(TouchEvent::onTouchCancelled, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	this->addChild(labelTouchInfo);
	return true;
}

bool TouchEvent::onTouchBegan(Touch* touch, Event* event)
{
	labelTouchInfo->setPosition(touch->getLocation());
	labelTouchInfo->setString("You Touched Here");
	return true;
}

void TouchEvent::onTouchEnded(Touch* touch, Event* event)
{
	cocos2d::log("touch ended");
}

void TouchEvent::onTouchMoved(Touch* touch, Event* event)
{
	cocos2d::log("touch moved");
}

void TouchEvent::onTouchCancelled(Touch* touch, Event* event)
{
	cocos2d::log("touch cancelled");
}
