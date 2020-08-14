//
// Created by Wouter Groeneveld on 02/08/18.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "start_scene.h"


#include "../Data/spelerSpel.h"
#include "game_scene.h"
#include "../Data/bonusData.h"
#include "../Data/bomData.h"
#include "../Data/sharedPal.h"
#include "extraGame_scene.h"
#include "../Data/titleData.h"
#include "../Data/rubi.h"


std::vector<Background *> SampleStartScene::backgrounds() {
    return {bg.get()};
}
std::vector<Sprite *> SampleStartScene::sprites() {
    return {spelerStartScreen.get(),munt.get(),animation.get()};
}

void SampleStartScene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(speltitelPal, sizeof(speltitelPal)));

    SpriteBuilder<Sprite> builder;

    spelerStartScreen = builder
            .withLocation(110, 130)
            .withData(spelerSpelTiles, sizeof(spelerSpelTiles))
            .withSize(SIZE_16_16)
            .withAnimated(9, 3,15)
            .buildPtr();
    animation = builder
            .withLocation(150, 130)
            .withData(rubiTiles, sizeof(rubiTiles))
            .withSize(SIZE_16_16)
            .buildPtr();
    munt = builder
            .withData(bonusTiles, sizeof(bonusTiles))
            .withSize(SIZE_16_16)
            .withLocation(130, 130)
            .buildPtr();
    bg = std::unique_ptr<Background>(new Background(0, speltitelTiles, sizeof(speltitelTiles), speltitelMap, sizeof(speltitelMap)));
    bg.get()->useMapScreenBlock(24);
}

void SampleStartScene::tick(u16 keys) {
    int keuze=0;
    if(keys & KEY_A) {
        keuze = 1;
        if(!engine->isTransitioning()) {
            engine->transitionIntoScene(new Game (engine,keuze), new FadeOutScene(2));
        }
    }else if(keys & KEY_B) {
        keuze =2;
        if(!engine->isTransitioning()) {
            engine->transitionIntoScene(new Game (engine,keuze), new FadeOutScene(2));
        }
    }
    else if(keys & KEY_LEFT) {
        spelerStartScreen->flipHorizontally(true);
        munt->moveTo(90,130);
    } else if(keys & KEY_RIGHT) {
        spelerStartScreen->flipHorizontally(false);
        munt->moveTo(130,130);
    }else if(keys & KEY_START){
        keuze =2;
        if(!engine->isTransitioning()) {
            engine->transitionIntoScene(new Game (engine,keuze), new FadeOutScene(2));
        }
    }
}
