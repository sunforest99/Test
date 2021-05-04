#include "stdafx.h"

Monster::Monster()
{
	_hp = 1;
}

void Monster::InitObject()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto mainsprite = SpriteFrameCache::getInstance();
	mainsprite->addSpriteFramesWithFile("monster.plist");
	srand(time(NULL));
	_rand = rand() % 3;
	switch (_rand) {
	case 0:
		_monster = Sprite::createWithSpriteFrameName("dragon_1_body.png");
		_lwing = Sprite::createWithSpriteFrameName("dragon_1_wing.png");
		_rwing = Sprite::createWithSpriteFrameName("dragon_1_wing.png");
		_leyebrow = Sprite::createWithSpriteFrameName("dragon_1_eyebrow.png");
		_reyebrow = Sprite::createWithSpriteFrameName("dragon_1_eyebrow.png");
		_hp = 20;
		break;
	case 1:
		_hp = 40;
		_monster = Sprite::createWithSpriteFrameName("dragon_2_body.png");
		_lwing = Sprite::createWithSpriteFrameName("dragon_2_wing.png");
		_rwing = Sprite::createWithSpriteFrameName("dragon_2_wing.png");
		_leyebrow = Sprite::createWithSpriteFrameName("dragon_2_eyebrow.png");
		_reyebrow = Sprite::createWithSpriteFrameName("dragon_2_eyebrow.png");
		break;
	case 2:
		_monster = Sprite::createWithSpriteFrameName("dragon_3_body.png");
		_lwing = Sprite::createWithSpriteFrameName("dragon_3_wing.png");
		_rwing = Sprite::createWithSpriteFrameName("dragon_3_wing.png");
		_leyebrow = Sprite::createWithSpriteFrameName("dragon_3_eyebrow.png");
		_reyebrow = Sprite::createWithSpriteFrameName("dragon_3_eyebrow.png");
		_hp = 100;
		break;

	}

	_monster->setScale(D_BASE_SACLE);
	_monster->setPositionY(D_DESIGN_HEIGHT);
	


	
	// --- ����
	

	_parent = _monster->getContentSize();

	_lwing->setPosition(Vec2(_parent.width / 2.f - 43.f, _parent.height / 2.f));
	_rwing->setPosition(Vec2(_parent.width / 2.f + 43.f, _parent.height / 2.f));

	_rwing->setFlipX(true);

	auto rwingreduce = ScaleTo::create(0.5f, 0.9f);
	auto rwingincrease = ScaleTo::create(0.5f, 1.2f);
	auto rseq = Sequence::create(rwingreduce, rwingincrease, nullptr);

	auto lwingreduce = ScaleTo::create(0.5f, 0.9f);
	auto lwingincrease = ScaleTo::create(0.5f, 1.2f);
	auto lseq = Sequence::create(lwingreduce, lwingincrease, nullptr);

	RepeatForever* ractionrepeat = RepeatForever::create(rseq);
	RepeatForever* lactionrepeat = RepeatForever::create(lseq);

	_rwing->runAction(ractionrepeat);
	_lwing->runAction(lactionrepeat);

	_monster->addChild(_lwing, INGAME_ZORDER::E_WINGS);
	_monster->addChild(_rwing, INGAME_ZORDER::E_WINGS);

	// ---- ��
	_leye = Sprite::createWithSpriteFrameName("dragon_eye.png");
	_reye = Sprite::createWithSpriteFrameName("dragon_eye.png");

	_reye->setFlipX(true);
	_parent = _monster->getContentSize();

	_leye->setPosition(Vec2(_parent.width / 2.f - 15.f, _parent.height / 2.f));
	_reye->setPosition(Vec2(_parent.width / 2.f + 15.f, _parent.height / 2.f));

	_monster->addChild(_leye, INGAME_ZORDER::E_MONSTER_EYE);
	_monster->addChild(_reye, INGAME_ZORDER::E_MONSTER_EYE);

	// ---- ����
	_leyebrow = Sprite::createWithSpriteFrameName("dragon_1_eyebrow.png");
	_reyebrow = Sprite::createWithSpriteFrameName("dragon_1_eyebrow.png");

	_reyebrow->setFlipX(true);
	_parent = _monster->getContentSize();

	_leyebrow->setPosition(Vec2(_parent.width / 2.f - 15.f, _parent.height / 2.f));
	_reyebrow->setPosition(Vec2(_parent.width / 2.f + 15.f, _parent.height / 2.f));

	_monster->addChild(_leyebrow, INGAME_ZORDER::E_MONSTER_EYE);
	_monster->addChild(_reyebrow, INGAME_ZORDER::E_MONSTER_EYE);

	this->addChild(_monster);
}

void Monster::Update()
{
	_monster->setPositionY(_monster->getPositionY() - 10.f);
}