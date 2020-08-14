//
// Created by esaie on 30-07-20.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_EXTRAGAME_SCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_EXTRAGAME_SCENE_H


#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "../Model/BonusModel.h"
#include "../Model/BomModel.h"
#include "../Model/speler.h"




class ExtraGame : public Scene {
private:
    std::unique_ptr<Sprite> speler;
    std::unique_ptr<Speler> spelerModel;

    std::unique_ptr<Sprite> muntSprite;
    std::unique_ptr<Sprite> muntSprite1;
    std::unique_ptr<Sprite> muntSprite2;
    std::unique_ptr<Sprite> muntSprite3;
    std::unique_ptr<Sprite> muntSprite4;

    std::unique_ptr<Sprite> bomSprite;
    std::unique_ptr<Sprite> bomSprite1;
    std::unique_ptr<Sprite> bomSprite2;
    std::unique_ptr<Sprite> bomSprite3;

    std::unique_ptr<BonusModel> maakMunten(int x, int y);
    std::unique_ptr<SpriteBuilder<Sprite>> spriteBuilder;

    int score =0 ;
    bool wisselPlaatst = false;
    bool tegenbonus = false;
    bool tegenbonus1 = false;
    bool tegenbonus2= false;
    bool tegenbonus3= false;
    bool tegenbonus4= false;
    bool tegenbom = false;
    bool tegenbom1 = false;
    bool tegenbom2= false;
    bool tegenbom3= false;
    int  aantalmunten = 5;
    int keuze;

public:
    ExtraGame(std::shared_ptr<GBAEngine> engine, int oudeScore,int keuze) : Scene(engine),score(oudeScore),keuze(keuze) {}
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;
    void load() override;
    void tick(u16 keys) override;
    void moveItems(){
        if(tegenbonus){
            muntSprite->setVelocity(0,0 );
            muntSprite->moveTo(300,300);
        }else{
            if(muntSprite->isOffScreen()){
                muntSprite->moveTo((rand()%(200 + 2) ),(rand()%(140 + 2) ));
                muntSprite->setVelocity(0,1 );
            }
            else{
                muntSprite->setVelocity(0,1 );
            }
        }
        if(tegenbonus1){
            muntSprite1->setVelocity(0,0 );
            muntSprite1->moveTo(300,300);
        }else{
            if(muntSprite1->isOffScreen()){
                muntSprite1->moveTo((rand()%(200 + 2) ),(rand()%(140 + 2) ));
                muntSprite1->setVelocity(0,1 );
            }
            else{
                muntSprite1->setVelocity(0,1 );
            }
        }

       if(tegenbonus2){
           muntSprite2->setVelocity(0,0 );
           muntSprite2->moveTo(300,300);

        }else{
           if(muntSprite2->isOffScreen()){
               muntSprite2->moveTo((rand()%(200 + 2) ),(rand()%(140 + 2) ));
               muntSprite2->setVelocity(0,1 );
           }
           else{
               muntSprite2->setVelocity(0,1 );
           }
       }
        if(tegenbonus3){
            muntSprite3->setVelocity(0,0 );
            muntSprite3->moveTo(300,300);
        }else{
            if(muntSprite3->isOffScreen()){
                muntSprite3->moveTo((rand()%(200 + 2) ),(rand()%(140 + 2) ));
                muntSprite3->setVelocity(0,1 );
            }
            else{
                muntSprite3->setVelocity(0,1 );
            }
        }
        if(tegenbonus4){
            muntSprite4->setVelocity(0,0 );
            muntSprite4->moveTo(300,300);
        }else{
            if(muntSprite4->isOffScreen()){
                muntSprite4->moveTo((rand()%(200 + 2) ),(rand()%(140 + 2) ));
                muntSprite4->setVelocity(0,1 );
            }
            else{
                muntSprite4->setVelocity(0,1 );
            }
        }
        if(tegenbom){
            bomSprite->setVelocity(0,0 );
            bomSprite->moveTo(300,300);

        }else{
            if(bomSprite->isOffScreen()){
                bomSprite->moveTo(30,20);
                bomSprite->setVelocity(0,1 );
            }else{
                bomSprite->setVelocity(0,1 );
            }
        }
        if(tegenbom1){
            bomSprite1->setVelocity(0,0 );
            bomSprite1->moveTo(300,300);
        }else{
            if(bomSprite1->isOffScreen()){
                bomSprite1->moveTo(90,20);
                bomSprite1->setVelocity(0,1 );
            }else{
                bomSprite1->setVelocity(0,1 );
            }
        }

        if(tegenbom2){
            bomSprite2->setVelocity(0,0 );
            bomSprite2->moveTo(300,300);
        }
        else{
            if(bomSprite2->isOffScreen()){
                bomSprite2->moveTo(150,20);
                bomSprite2->setVelocity(0,1 );
            }else{
                bomSprite2->setVelocity(0,1 );
            }
        }
        if(tegenbom3){
            bomSprite3->setVelocity(0,0 );
            bomSprite3->moveTo(300,300);
        }
        else{
            if(bomSprite3->isOffScreen()){
                bomSprite3->moveTo(200,20);
                bomSprite3->setVelocity(0,1 );
            }else{
                bomSprite3->setVelocity(0,1 );
            }
        }

    }
    bool tegenMunt(){
        if(muntSprite->collidesWith(*spelerModel->getSpelerSprite())){
            aantalmunten -=1;
            return tegenbonus =true;
        }
        else if(muntSprite1->collidesWith(*spelerModel->getSpelerSprite())){
            aantalmunten -=1;
            return tegenbonus1 =true;
        }
        else if(muntSprite2->collidesWith(*spelerModel->getSpelerSprite())){
            aantalmunten -=1;
            return tegenbonus2 =true;
        }
        else if(muntSprite3->collidesWith(*spelerModel->getSpelerSprite())){
            aantalmunten -=1;
            return tegenbonus3 =true;
        }
        else if(muntSprite4->collidesWith(*spelerModel->getSpelerSprite())){
            aantalmunten -=1;
            return tegenbonus4 =true;
        }else{
            return false;
        }
    }
    bool tegenBom(){
        if(bomSprite->collidesWith(*spelerModel->getSpelerSprite())){
            return tegenbom =true;
        }
        else if(bomSprite1->collidesWith(*spelerModel->getSpelerSprite())){
            return tegenbom1 =true;
        }
        else if(bomSprite2->collidesWith(*spelerModel->getSpelerSprite())){
            return tegenbom2 =true;
        }
        else if(bomSprite3->collidesWith(*spelerModel->getSpelerSprite())){
            return tegenbom3 =true;
        }else{
            return false;
        }


    }
    void stopGame(){
        TextStream::instance().clear();
        bomSprite->setVelocity(0,0 );
        bomSprite->moveTo(300,300);
        bomSprite1->setVelocity(0,0 );
        bomSprite1->moveTo(300,300);
        bomSprite2->setVelocity(0,0 );
        bomSprite2->moveTo(300,300);
        bomSprite3->setVelocity(0,0 );
        bomSprite3->moveTo(300,300);
        muntSprite->setVelocity(0,0 );
        muntSprite->moveTo(300,300);
        muntSprite1->setVelocity(0,0 );
        muntSprite1->moveTo(300,300);
        muntSprite2->setVelocity(0,0 );
        muntSprite2->moveTo(300,300);
        muntSprite3->setVelocity(0,0 );
        muntSprite3->moveTo(300,300);
        muntSprite4->setVelocity(0,0 );
        muntSprite4->moveTo(300,300);
        TextStream::instance().setText("Druk A voor rubi" , 1, 0);
        TextStream::instance().setText("Druk B voor zelda", 2, 0);

        TextStream::instance().setText(std::string("U extra scoren is : ") + std::to_string(score ), 11, 1);
        TextStream::instance().setText("Druk start ", 10, 1);
        spelerModel->getSpelerSprite()->moveTo(200,90);

    }
    void beweegSpeler(){

    }
};


#endif //GBA_SPRITE_ENGINE_PROJECT_EXTRAGAME_SCENE_H
