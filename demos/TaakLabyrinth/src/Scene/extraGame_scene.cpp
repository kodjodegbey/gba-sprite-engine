//
// Created by esaie on 30-07-20.
//

#include <algorithm>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include "extraGame_scene.h"
#include "../Data/spelerSpel.h"
#include "../../../demo3-foodthrowing/src/bullet_data.h"
#include "../Data/sharedPal.h"
#include "../Data/bonusData.h"
#include "../Data/bomData.h"
#include "../Data/rubi.h"


std::vector<Background *> ExtraGame::backgrounds() {
    return {};
}

std::vector<Sprite *> ExtraGame::sprites() {
    std::vector<Sprite*> sprites;
    sprites.push_back(muntSprite.get());
    sprites.push_back(muntSprite1.get());
    sprites.push_back(muntSprite2.get());
    sprites.push_back(muntSprite3.get());
    sprites.push_back(muntSprite4.get());
    sprites.push_back(bomSprite.get());
    sprites.push_back(bomSprite1.get());
    sprites.push_back(bomSprite2.get());
    sprites.push_back(bomSprite3.get());
    sprites.push_back(spelerModel->getSpelerSprite());
    return sprites;
}
//return std::unique_ptr<Sprite>(new BonusModel(spriteBuilder->withLocation(GBA_SCREEN_WIDTH/2, 0).buildWithDataOf(*muntSprite.get()),0,0));
std::unique_ptr<BonusModel> ExtraGame::maakMunten(int x,int y) {
    return std::unique_ptr<BonusModel>(new BonusModel(spriteBuilder
    ->withLocation(x, y)
    .buildWithDataOf(*muntSprite.get()),x,y));
}


//void ExtraGame ::verwijderMunten() {
//    munten.erase(
//            std::remove_if(munten.begin(), munten.end(), [](std::unique_ptr<BonusModel> &s) { return s->isOffScreen(); }),
//            munten.end());
//}
//void ExtraGame::verwijderBommen() {
//    bommen.erase(
//            std::remove_if(bommen.begin(), bommen.end(), [](std::unique_ptr<BomModel> &s) { return s->isOffScreen(); }),
//            bommen.end());
//
//}

//std::unique_ptr<BomModel> ExtraGame::maakBommen(){
//    return std::unique_ptr<BomModel>(new BomModel(spriteBuilder->withLocation(GBA_SCREEN_WIDTH/2, 0).buildWithDataOf(*bomsprite.get()),0,0));
//}


void ExtraGame::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());
    spriteBuilder = std::unique_ptr<SpriteBuilder<Sprite>>(new SpriteBuilder<Sprite>);
    SpriteBuilder<Sprite> builder;

    if(keuze==1){
        speler = builder
                .withData(spelerSpelTiles, sizeof(spelerSpelTiles))
                .withSize(SIZE_16_16)
                .withLocation(100, 100)
                .withinBounds()
                .buildPtr();
    }else if(keuze==2){
        speler = builder
                .withData(rubiTiles, sizeof(rubiTiles))
                .withSize(SIZE_16_16)
                .withLocation(100, 100)
                .withinBounds()
                .buildPtr();

    }

    muntSprite = builder
            .withData(bonusTiles, sizeof(bonusTiles))
            .withSize(SIZE_16_16)
            .withLocation(0 , 0)
            .buildPtr();

    muntSprite1 = builder
            .withData(bonusTiles, sizeof(bonusTiles))
            .withSize(SIZE_16_16)
            .withLocation(60, 0)
            .buildPtr();
    muntSprite2 = builder
            .withData(bonusTiles, sizeof(bonusTiles))
            .withSize(SIZE_16_16)
            .withLocation(120, 0)
            .buildPtr();
    muntSprite3 = builder
            .withData(bonusTiles, sizeof(bonusTiles))
            .withSize(SIZE_16_16)
            .withLocation(180, 0)
            .buildPtr();
    muntSprite4 = builder
            .withData(bonusTiles, sizeof(bonusTiles))
            .withSize(SIZE_16_16)
            .withLocation(GBA_SCREEN_WIDTH-16 , 0)
            .buildPtr();
    bomSprite = builder
            .withData(bomTiles, sizeof(bomTiles))
            .withSize(SIZE_16_16)
            .withLocation(30, 20)
            .buildPtr();

    bomSprite1 = builder
            .withData(bomTiles, sizeof(bomTiles))
            .withSize(SIZE_16_16)
            .withLocation(90, 20)
            .buildPtr();
    bomSprite2 = builder
            .withData(bomTiles, sizeof(bomTiles))
            .withSize(SIZE_16_16)
            .withLocation(150, 20)
            .buildPtr();
    bomSprite3 = builder
            .withData(bomTiles, sizeof(bomTiles))
            .withSize(SIZE_16_16)
            .withLocation(200, 20)
            .buildPtr();
    engine->getTimer()->start();
//    bomCooldown = Item_Cooldown_start;
//    muntCooldown = Item_Cooldown_start;
    spelerModel = std::unique_ptr<Speler> (new Speler(std::move(speler)));
}

void ExtraGame::tick(u16 keys) {
    if(engine->getTimer()->getTotalMsecs()>30000 || aantalmunten<=0){
        stopGame();
    engine->getTimer()->stop();
    }else{
        TextStream::instance().setText(std::to_string(score), 0, 1);
        TextStream::instance().setText(engine->getTimer()->to_string(), 2, 1);
        TextStream::instance().setText(std::to_string(spelerModel->getSpelerSprite()->getX()), 3, 1);
        TextStream::instance().setText(std::to_string(spelerModel->getSpelerSprite()->getY()), 4, 1);
        TextStream::instance().setText(std::to_string(aantalmunten), 5, 1);


        if(keys & KEY_LEFT) {
            spelerModel->setDx(-1);

        } else if(keys & KEY_RIGHT) {
            spelerModel->setDx(1);
        }else if(keys & KEY_UP){
            spelerModel->setDy(-1);

        } else if(keys & KEY_DOWN){
            spelerModel->setDy(1);

        }else{
            spelerModel->setDx(0);
            spelerModel->setDy(0);
        }
        if(tegenMunt()){
            TextStream::instance().setText("bingo-L", 15, 1);
            score+= (rand()%(10 + 1) );
        }else if(tegenBom()){
            TextStream::instance().setText("SHIT-L", 15, 1);
            score+= -(rand()%(10 + 1) );
        }
        moveItems();
        spelerModel->tick(1);
    }

}
