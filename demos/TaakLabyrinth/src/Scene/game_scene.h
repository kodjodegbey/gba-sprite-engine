//
// Created by Wouter Groeneveld on 28/07/18.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GAME_H
#define GBA_SPRITE_ENGINE_PROJECT_GAME_H



#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/background/background.h>
#include "../gameMap/GameMap.h"
#include "../Model/BonusModel.h"
#include "../Model/BomModel.h"
#include "list"
#include "../Model/speler.h"
#include "start_scene.h"
#include <iostream>
using namespace std ;
#define factor 8



class Game : public Scene {
private:

    std::unique_ptr<Sprite> bomSprite1;
    std::unique_ptr<Sprite> bomSprite2;
    std::unique_ptr<Sprite> bomSprite3;

    std::unique_ptr<Sprite> bonusSprite1;
    std::unique_ptr<Sprite> bonusSprite2;
    std::unique_ptr<Sprite> bonusSprite3;
    std::unique_ptr<Sprite> bonusSprite4;
    std::unique_ptr<Sprite> box;

    std::unique_ptr<Sprite> spelerSprite;

    std::unique_ptr<Background> bg;


    GameMap gameMap ;
    Richting richting;
    int score =100 ;
    bool dood=false;
    int spelerX=0;
    int spelerY = 0;
    int levens=3;
    int scrollX;
    int scrollY;
    int aantalMunten=4;
    int keuzeSpeler=0;
    int boxGeraakt =1;
    bool tegengenMunt3 =false;


public:
    Game(std::shared_ptr<GBAEngine> engine,int keuze) : Scene(engine),keuzeSpeler(keuze) {}
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void load() override;
    void tick(u16 keys) override;
    void resetGame() ;
    void tegenBom(){
        if(spelerSprite->collidesWith(*bomSprite1)){
            bomSprite1->moveTo(-100,10);
            if(score>0){
                score-= (rand()%(15 + 1) );
            }
            if(levens>0){
                levens--;
            }else{
               dood=true;

            }
        }else if(spelerSprite->collidesWith(*bomSprite2)){
            bomSprite2->moveTo(-150,10);
            if(score>0){
                score-= (rand()%(15 + 1) );
            }
            if(levens>0){
                levens--;
            }else{
                dood=true;

            }
        }else if(spelerSprite->collidesWith(*bomSprite3)){
            bomSprite3->moveTo(-200,10);
            if(score>0){
                score-= (rand()%(15 + 1) );
            }
            if(levens>0){
                levens--;
            }else{
                dood=true;

            }
        }
    }
    void tegenMunt(){
        if(spelerSprite->collidesWith(*bonusSprite1)){
            bonusSprite1->moveTo(-100,20);
                score+= (rand()%(15 + 1) );
            aantalMunten -=1;
        }else if(spelerSprite->collidesWith(*bonusSprite2)){
            bonusSprite2->moveTo(-100,40);
            score+= (rand()%(15 + 1) );
            aantalMunten -=1;
        }else if(spelerSprite->collidesWith(*bonusSprite3)){
            bonusSprite3->moveTo(-100,60);
            score+= (rand()%(15 + 1) );
            tegengenMunt3=true;
            aantalMunten -=1;
        }else if(spelerSprite->collidesWith(*bonusSprite4)){
        bonusSprite4->moveTo(-100,80);
        score+= (rand()%(15 + 1) );
            aantalMunten -=1;
        }
    }
    void restart(){


    }

    void tegenBox();
};


#endif //GBA_SPRITE_ENGINE_FLYING_STUFF_SCENE_H
