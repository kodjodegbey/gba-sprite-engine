//
// Created by esaie on 16-07-20.
//

#include "BomModel.h"

void BomModel::tick() {
    if(!bomSprite->isOffScreen()){
        bomSprite->setVelocity(0,1);
    }
}

