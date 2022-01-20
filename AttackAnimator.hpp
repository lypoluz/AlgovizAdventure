// Created by Lypoluz (Dominik) on 20.01.2022.

#ifndef ALGOVIZADVENTURE_ATTACKANIMATOR_HPP
#define ALGOVIZADVENTURE_ATTACKANIMATOR_HPP

#include <utility>

#include "GameComponent.hpp"
#include "SpriteRenderer.hpp"
#include "Engine.hpp"

class AttackAnimator : public GameComponent {

    SpriteRenderer* playerRenderer;
    SpriteRenderer* attackRenderer;
    Position* position{};
    GTime* gTime{};

    float attackTime = .7;
    float timer{};
    std::string psd;
    std::string psa;
    std::string asd;
    std::string as1;
    std::string as2;
    std::string as3;



public:
    AttackAnimator(ObjectStructure* os, SpriteRenderer* psr, SpriteRenderer* asr) : GameComponent(os) {
        playerRenderer = psr;
        attackRenderer = asr;
    }

    void onStart() override {
        position = ((GameObject*) gameObject)->position;
        gTime = Engine::getInstance()->getGTime();
        psd = playerRenderer->getSpritePath();
        asd = attackRenderer->getSpritePath();
    }

    void update() override {
        timer += gTime->deltaTime();
        if (timer <= attackTime / 3 and (playerRenderer->getSpritePath() != psa or attackRenderer->getSpritePath() != as1)) {
            playerRenderer->setSprite(psa);
            attackRenderer->setSprite(as1);
        } else if (timer <= attackTime * 2/3 and (playerRenderer->getSpritePath() != psa or attackRenderer->getSpritePath() != as2)) {
            playerRenderer->setSprite(psa);
            attackRenderer->setSprite(as2);
        } else if (timer <= attackTime and (playerRenderer->getSpritePath() != psa or attackRenderer->getSpritePath() != as3)) {
            playerRenderer->setSprite(psa);
            attackRenderer->setSprite(as3);
        } else if (playerRenderer->getSpritePath() != psd or attackRenderer->getSpritePath() != asd) {
            playerRenderer->setSprite(psd);
            attackRenderer->setSprite(asd);
        }
    }

    void setPlayerAttackSprite(std::string s) {psa = std::move(s);}
    void setAttackSprites(std::string s1, std::string s2, std::string s3) {as1=std::move(s1);as2=std::move(s2);as3=std::move(s3);}

    void startAnimation() {
        timer = 0;
        attackRenderer->setPositionOffset(position->facing());
        if(position->facing() == Vector2::up())
            attackRenderer->setRotationOffset(0);
        else if(position->facing() == Vector2::down())
            attackRenderer->setRotationOffset(180);
        else if(position->facing() == Vector2::left())
            attackRenderer->setRotationOffset(270);
        else if(position->facing() == Vector2::right())
            attackRenderer->setRotationOffset(90);
    }
};

#endif //ALGOVIZADVENTURE_ATTACKANIMATOR_HPP
