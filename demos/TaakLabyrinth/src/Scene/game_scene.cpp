//
// Created by Wouter Groeneveld on 28/07/18.
//

#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_memmap.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>


#include "game_scene.h"
#include "../Data/spelerSpel.h"
#include "../Data/bomData.h"
#include "../Data/bonusData.h"
#include "../Data/bgSpel.h"
#include "../Data/sharedPal.h"
#include "../Scene/extraGame_scene.h"
#include "../../../demo1-basicfeatures/src/ff.h"
#include "../Data/rubi.h"
#include "../Data/box.h"


std::vector<Sprite *> Game::sprites() {
    std::vector<Sprite *> sprites;
    sprites.push_back(bomSprite1.get());
    sprites.push_back(bomSprite2.get());
    sprites.push_back(bomSprite3.get());
    sprites.push_back(bonusSprite1.get());
    sprites.push_back(bonusSprite2.get());
    sprites.push_back(bonusSprite3.get());
    sprites.push_back(bonusSprite4.get());
    sprites.push_back(spelerSprite.get());
    sprites.push_back(box.get());


    return sprites;
}

std::vector<Background *> Game::backgrounds() {
    std::vector<Background *> backgrounds;
    backgrounds.push_back(bg.get());

    return{backgrounds};
}

void Game::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(bgPal,sizeof(bgPal)));
    SpriteBuilder<Sprite> builder;
        box = builder
            .withData(boxTiles, sizeof(boxTiles))
            .withSize(SIZE_16_16)
            .withLocation(200, 140)
            .buildPtr();

    if(keuzeSpeler==1){
        spelerSprite = builder
                .withData(spelerSpelTiles, sizeof(spelerSpelTiles))
                .withSize(SIZE_16_16)
                .withLocation(100, 100)
                .withinBounds()
                .buildPtr();
    }else if(keuzeSpeler==2){
        spelerSprite = builder
                .withData(rubiTiles, sizeof(rubiTiles))
                .withSize(SIZE_16_16)
                .withLocation(100, 100)
                .withinBounds()
                .buildPtr();

    }


    bomSprite1 = builder
            .withData(bomTiles, sizeof(bomTiles))
            .withSize(SIZE_16_16)
            .withLocation(16,45)
            .buildPtr();
    bomSprite2 = builder
            .withData(bomTiles, sizeof(bomTiles))
            .withSize(SIZE_16_16)
            .withLocation(140,40)
            .buildPtr();
    bomSprite3 = builder
            .withData(bomTiles, sizeof(bomTiles))
            .withSize(SIZE_16_16)
            .withLocation(115, 82)
            .buildPtr();
    bonusSprite1 = builder
            .withData(bonusTiles, sizeof(bonusTiles))
            .withSize(SIZE_16_16)
            .withLocation(120, 140)
            .buildPtr();
    bonusSprite2 = builder
            .withData(bonusTiles, sizeof(bonusTiles))
            .withSize(SIZE_16_16)
            .withLocation(200, 125)
            .buildPtr();
    bonusSprite3 = builder
            .withData(bonusTiles, sizeof(bonusTiles))
            .withSize(SIZE_16_16)
            .withLocation(68, 30)
            .buildPtr();
    bonusSprite4 = builder
            .withData(bonusTiles, sizeof(bonusTiles))
            .withSize(SIZE_16_16)
            .withLocation(50, 120)
            .buildPtr();
    TextStream::instance().setText("Scoren", 0, 0);
    spelerX=spelerSprite->getX();
    spelerY=spelerSprite->getY();
    scrollX=30;
    scrollY=95;
    bg->scroll(scrollX,scrollY);

    bg = std::unique_ptr<Background>(new Background(1, bgData, sizeof(bgData), bgMap, sizeof(bgMap)));
    bg.get()->useMapScreenBlock(16);

spelerSprite->setStayWithinBounds(true);
}


void Game::tick(u16 keys) {
    if(isText){
            TextStream::instance().clear();
    }
    isText=false;
    if(levens>0){
        if( aantalMunten ==0){
            if(!engine->isTransitioning()) {

                engine->transitionIntoScene(new ExtraGame (engine,score,keuzeSpeler), new FadeOutScene(3));
            }
        }else{
            if (spelerY < 35) {
                if (scrollY > 0) {
                    scrollY = scrollY - 1;
                    bg->scroll(0, scrollY);
                    spelerY = 35;
                }
            } else if (spelerY > 100) {
                if (scrollY < 96) {
                    scrollY = scrollY + 1;
                    bg->scroll(0, scrollY);
                    spelerY = 110;
                }
            }
            if (spelerX < 50) {
                if (scrollX > 0) {
                    scrollX = scrollX - 1;
                    bg->scroll(scrollX, 0);
                    spelerX = 50;
                }
            } else if (spelerX > 150) {
                if (scrollX < 11) {
                    scrollX = scrollX + 1;
                    bg->scroll(scrollX, 0);
                    spelerX = 150;
                }
            }
            TextStream::instance().setText("Scoren : " +std::to_string(score), 0, 0);
            TextStream::instance().setText("Levens : " +std::to_string(levens), 0, 20);
            TextStream::instance().setText(std::string("Aantal munten: ")+std::to_string(aantalMunten), 1, 0);
            tegenBom();
            tegenMunt();
            tegenBox();
            if(keys & KEY_LEFT) {
                spelerX-=1;
                if( keuzeSpeler==1){
                    spelerSprite->makeAnimated(3,3,5);
                }
            } else if(keys & KEY_RIGHT) {
                spelerX+=1;
                if(keuzeSpeler==1){
                    spelerSprite->makeAnimated(9,3,5);
                }
            }else if(keys & KEY_UP){
                spelerY-=1;
                if(keuzeSpeler==1){
                    spelerSprite->makeAnimated(0,3,5);
                }
            } else if(keys & KEY_DOWN){
                spelerY+=1;
                if(keuzeSpeler==1){
                    spelerSprite->makeAnimated(6,3,5);
                }
            }else if(!keys){
                spelerSprite->stopAnimating();
            } else if(keys &KEY_START){
                restart();
            }
            box.get()->moveTo(200,50-scrollY);

            if(tegengenMunt3){

            }else{
                bonusSprite3->moveTo(68,50-scrollY);
            }
            spelerOpScherm();

            spelerSprite->moveTo(spelerX,spelerY);
        }


    }else{
        TextStream::instance().setText("U totaal scoren is:  " +std::to_string(score), 0, 0);
        TextStream::instance().setText("Druk A voor rubi" , 1, 0);
        TextStream::instance().setText("Druk B voor zelda", 2, 0);
        engine->delay(5000);
        if(keys & KEY_A) {
            if(!engine->isTransitioning()) {
                TextStream::instance() << "entered: starting next scene";
                engine->transitionIntoScene(new Game (engine,1), new FadeOutScene(2));
            }
        }else if(keys & KEY_B) {
            if(!engine->isTransitioning()) {
                TextStream::instance() << "entered: starting next scene";
                engine->transitionIntoScene(new Game (engine,2), new FadeOutScene(2));
            }
        }

    }

}


void Game::tegenBox() {
    if(spelerSprite->collidesWith(*box)){
        if(boxGeraakt>0){
            isText=true;
            boxGeraakt--;
            TextStream::instance().setText("U heb de box gevonden " , 9, 0);
            TextStream::instance().setText("U krijgt 20 extra punten ", 10, 0);
            engine->delay(500000);
            score +=20;
        }

    }

}

