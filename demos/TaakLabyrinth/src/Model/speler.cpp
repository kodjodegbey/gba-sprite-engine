//
// Created by esaie on 16-07-20.
//

#include "speler.h"

void::Speler::move() {
    if (getDx() == 1) {
        getSpelerSprite()->setVelocity(+2, 0);
//        getSpelerSprite()->animateToFrame(3);
    } else if (getDx() == -1) {
        getSpelerSprite()->setVelocity(-2, 0);
//        getSpelerSprite()->animateToFrame(3);

    } else if (getDy() == 1){
        getSpelerSprite()->setVelocity(0, +2);
//        getSpelerSprite()->animateToFrame(3);
    }
    else if (getDy() == -1){
        getSpelerSprite()->setVelocity(0, -2);
//        getSpelerSprite()->animateToFrame(3);
    }
    else {
        getSpelerSprite()->setVelocity(0, 0);
        getSpelerSprite()->animateToFrame(0);
    }
}

void::Speler::moveSpelerInGame(int x, int y) {
 getSpelerSprite()->moveTo(x,y);
}
void::Speler::tick(int getal) {
    if(getal==0){
    }else if(getal==1){
        move();
    }else{

    }

//    if(!getSpelerSprite()->isOffScreen()){
//        move();
//    }

}