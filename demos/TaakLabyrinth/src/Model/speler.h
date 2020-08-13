//
// Created by esaie on 16-07-20.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_SPELER_H
#define GBA_SPRITE_ENGINE_PROJECT_SPELER_H
#include <libgba-sprite-engine/sprites/sprite.h>


class Speler {
private:
    std::unique_ptr<Sprite> spelerSprite;
    int dx = 0;
    int dy = 0;
    int x=0,y=0;
    bool dood = false;
    int score;
public :
    Speler(std::unique_ptr<Sprite> sprite) :spelerSprite(std::move(sprite)){};
    int getDx(){ return dx ;}
    int getDy() { return  dy;}
    void setDx(int nx){this->dx = nx ;}
    void setDy(int ny){this->dy= ny ;}
    int getX(){ return getSpelerSprite()->getX();}
    int getY(){ return getSpelerSprite()->getY();}
    bool isDood(){return dood ;}
    void setDood(bool dood){this->dood = dood ;}
    void move();
    Sprite* getSpelerSprite() { return spelerSprite.get(); }
    void tick(int getal);
    void moveSpelerInGame(int x, int y);
};


#endif //GBA_SPRITE_ENGINE_PROJECT_SPELER_H
