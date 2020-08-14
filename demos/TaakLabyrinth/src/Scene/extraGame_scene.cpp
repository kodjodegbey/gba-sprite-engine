//
// Created by esaie on 30-07-20.
//

#include <algorithm>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "extraGame_scene.h"
#include "../Data/spelerSpel.h"
#include "../../../demo3-foodthrowing/src/bullet_data.h"
#include "../Data/sharedPal.h"
#include "../Data/bonusData.h"
#include "../Data/bomData.h"
#include "../Data/rubi.h"
#include "game_scene.h"


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
std::unique_ptr<BonusModel> ExtraGame::maakMunten(int x,int y) {
    return std::unique_ptr<BonusModel>(new BonusModel(spriteBuilder
    ->withLocation(x, y)
    .buildWithDataOf(*muntSprite.get()),x,y));
}

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
    spelerModel = std::unique_ptr<Speler> (new Speler(std::move(speler)));
}

void ExtraGame::tick(u16 keys) {
    if(engine->getTimer()->getTotalMsecs()>30000 || aantalmunten<=0){
        stopGame();
    engine->getTimer()->stop();
        if(keys & KEY_A) {
            if(!engine->isTransitioning()) {
                TextStream::instance() << "entered: starting next scene";
                engine->setScene(new Game (engine,1));
            }
        }else if(keys & KEY_B) {
            if(!engine->isTransitioning()) {
                engine->setScene(new Game (engine,2));
            }
        }
    }else{
        TextStream::instance().setText(std::string("score")+std::to_string(score), 0, 0);
        TextStream::instance().setText(engine->getTimer()->to_string(), 1, 0);
        TextStream::instance().setText(std::string("Aantal munten: ")+std::to_string(aantalmunten), 2, 0);


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
            score+= (rand()%(10 + 1) );
        }else if(tegenBom()){
            score+= -(rand()%(10 + 1) );
        }
        moveItems();
        spelerModel->tick(keuze);
    }

}
