#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/palette/palette_manager.h>
#include <libgba-sprite-engine/allocator.h>

#include "Scene/start_scene.h"
#include "Scene/extraGame_scene.h"
#include "Scene/game_scene.h"
#include <iostream>
using namespace std;

/**
 * shared palette extracted from grit
 * ./../grit piskel.png piskel2.png kul.png -ftc -pS -gB8 -O shared.c
 * assumes 8bpp sprites
 */
int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    SampleStartScene* startScene = new SampleStartScene(engine);
    engine->setScene(startScene);

//    ExtraGame* extraGame = new ExtraGame(engine);
//    engine->setScene(extraGame);

//Game* game = new Game(engine);
//engine->setScene(game);

    while (true) {
        engine->update();
        engine->delay(1000);
    }



    return 0;
}