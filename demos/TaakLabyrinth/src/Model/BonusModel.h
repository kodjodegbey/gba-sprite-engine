//
// Created by esaie on 16-07-20.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_BONUSMODEL_H
#define GBA_SPRITE_ENGINE_PROJECT_BONUSMODEL_H
#include <libgba-sprite-engine/sprites/sprite.h>

class BonusModel {
private:
    std::unique_ptr<Sprite> BonusSprite;
    int waarde;
    int x;
    int y;
public:
    BonusModel( std::unique_ptr<Sprite> sprite,int nx,int ny) : BonusSprite(std::move(sprite)),x( nx),y( ny){
        waarde=(rand()%(10 + 1) );
        getBonusSprite()->moveTo(x,y);
    }
    int getX(){ return this->x ;}

    int getY(){ return this->y ;}

    void setX(int nx){ this->x = nx ;}

    void setY(int ny){  this->y = ny ;}

    int getWaarde(){return waarde ;}
    bool isOffScreen() { return BonusSprite->isOffScreen(); }

    Sprite* getBonusSprite(){ return this->BonusSprite.get();}
    void tick();

};


#endif //GBA_SPRITE_ENGINE_PROJECT_BONUSMODEL_H
