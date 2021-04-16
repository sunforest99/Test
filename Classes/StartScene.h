#ifndef _START_SCENE_H__
#define _START_SCENE_H__

#include "stdafx.h"

class StartScene : public Layer
{
private:
    // 배경 이미지 이름
    std::string _bgname[4] = { "background/01.png", "background/02.png", "background/03.png", "background/04.png" };
    // 캐릭터 이미지 이름
    std::string _charname[4] = { "ui/character_01.png", "ui/character_02.png", "ui/character_03.png", "ui/character_04.png" };
    int _bgindex;
    int _charindex;

    // 배경 이미지
    Sprite* _bg1;
    Sprite* _bg2;

    // 로고 이미지
    Sprite* _logo;

    // 캐릭터 이미지
    Sprite* _character;

    // touch to start 글씨
    Label* _label;

public:
    /**
    * @brief StartScene 생성
    */
    static Scene* createScene();

    /**
    * @brief Layer 초기화
    */
    virtual bool init();

    /**
    * @brief InGameScene 업데이트
    */
    void SceneUpdate(float dt);

    /**
    * @brief 터치 되었을때 (마우스 눌렀을때)
    */
    virtual bool onTouchBegan(Touch* touch, Event* unused_event);

    // implement the "static create()" method manually
    CREATE_FUNC(StartScene);
};

#endif //_START_SCENE_H__
