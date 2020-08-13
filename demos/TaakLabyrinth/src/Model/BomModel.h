//
// Created by esaie on 16-07-20.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_BOMMODEL_H
#define GBA_SPRITE_ENGINE_PROJECT_BOMMODEL_H
#include <libgba-sprite-engine/sprites/sprite.h>


class BomModel {
private:
    std::unique_ptr<Sprite> bomSprite;
    int waarde;
    int x;
    int y;
public:
    BomModel( std::unique_ptr<Sprite> sprite,int nx,int ny) : bomSprite(std::move(sprite)),x( nx),y( ny){

        waarde=(-rand()%(10 + 1) );
    }

    int getX(){ return this->x ;}

    int getY(){ return this->y ;}

    void setX(int nx){ this->x = nx ;}

    void setY(int ny){  this->y = ny ;}
    bool isOffScreen() { return bomSprite->isOffScreen(); }

    int getWaarde(){ return this->waarde;}

    Sprite* getBomSprite(){ return this->bomSprite.get();}
    void tick();




};


#endif //GBA_SPRITE_ENGINE_PROJECT_BOMMODEL_H
