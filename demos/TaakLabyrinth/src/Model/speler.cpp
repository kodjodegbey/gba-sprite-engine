//
// Created by esaie on 16-07-20.
//

#include "speler.h"

void::Speler::move(int getal) {
    if (getDx() == 1) {
        if(getal==1){
            spelerSprite->makeAnimated(9,3,5);
        }
        getSpelerSprite()->setVelocity(+2, 0);

    } else if (getDx() == -1) {
        getSpelerSprite()->setVelocity(-2, 0);
        if(getal==1){
            spelerSprite->makeAnimated(3,3,5);
        }

    } else if (getDy() == 1){
        getSpelerSprite()->setVelocity(0, +2);
        if(getal==1){
            spelerSprite->makeAnimated(6,3,5);
        }

    }
    else if (getDy() == -1){
        getSpelerSprite()->setVelocity(0, -2);
        if(getal==1){
            spelerSprite->makeAnimated(0,3,5);
        }

    }
    else {
        getSpelerSprite()->setVelocity(0, 0);
        spelerSprite->stopAnimating();
    }
}

void::Speler::moveSpelerInGame(int x, int y) {
 getSpelerSprite()->moveTo(x,y);
}
void::Speler::tick(int getal) {
    move(getal);
}





