//
// Created by esaie on 24-07-20.
//

#include "Richting.h"

#ifndef GBA_SPRITE_ENGINE_PROJECT_LEVELMAP_H
#define GBA_SPRITE_ENGINE_PROJECT_LEVELMAP_H

/*
 *      x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x
        x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x
        x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x
        x						x									x						x										x
        x						x									x						x										x
        x			x			x			x	x	x	x			x			x			x			x	x	x	x				x
        x			x			x						x						x						x			x				x
        x			x			x						x						x						x			x				x
        x	x	x	x			x	x	x	x			x			x	x	x	x	x	x	x	x	x	x			x				x
        x									x			x			x									x							x
        x									x			x			x									x							x
        x			x	x	x	x			x			x	x	x	x			x	x	x	x			x			x	x	x	x	x
        x						x									x						x						x				x
        x						x									x						x						x				x
        x	x	x	x			x			x	x	x	x	x	x	x	x	x	x			x	x	x	x	x	x	x				x
        x						x						x									x										x
        x						x						x									x										x
        x			x	x	x	x	x	x	x			x			x	x	x	x	x	x	x				x	x	x	x	x	x	x
        x									x			x						x										x			x
        x									x			x						x										x			x
        x	x	x	x	x	x	x			x	x	x	x	x	x	x						x	x	x					x			x
        x						x									x								x								x
        x						x									x	x	x	x					x								x
        x	x	x	x			x	x	x	x	x	x	x			x						x	x	x	x	x	x	x	x			x
        x						x						x			x						x										x
        x						x						x			x			x	x	x	x										x
        x			x						x						x						x			x	x	x	x	x	x	x	x
        x			x						x						x						x			x							x
        x			x	x	x				x	x	x	x	x	x	x	x	x	x			x			x							x
        x					x							x									x							x			x
        x					x							x									x							x			x
        x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x	x
 *
 */

class GameMap{
private:
    int gameMatrix[32][32] = {{0, 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,},
                            {0, 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,},
                            {0, 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,},
                            {0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,},
                            {0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,},
                            {0,	1,	1,	0,	1,	1,	0,	1,	1,	0,	0,	0,	0,	1,	1,	0,	1,	1,	0,	1,	1,	0,	1,	1,	0,	0,	0,	0,	1,	1,	1,	0,},
                            {0,	1,	1,	0,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	0,	1,	1,	1,	0,},
                            {0,	1,	1,	0,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	0,	1,	1,	1,	0,},
                            {0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	1,	1,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	0,	1,	1,	1,	0,},
                            {0,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	0,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	0,},
                            {0,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	0,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	0,},
                            {0,	1,	1,	0,	0,	0,	0,	1,	1,	0,	1,	1,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	1,	1,	0,	1,	1,	0,	0,	0,	0,	0,},
                            {0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	0,},
                            {0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	0,},
                            {0,	0,	0,	0,	1,	1,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	0,},
                            {0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,},
                            {0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,},
                            {0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	1,	1,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,},
                            {0,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	0,},
                            {0,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	0,},
                            {0,	0,	0,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	1,	1,	0,	0,	0,	1,	1,	1,	1,	0,	1,	1,	0,},
                            {0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	0,},
                            {0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	0,},
                            {0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	1,	1,	0,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	0,},
                            {0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,},
                            {0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	0,	1,	1,	0,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,},
                            {0,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,},
                            {0,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	0,	1,	1,	1,	1,	1,	1,	0,},
                            {0,	1,	1,	0,	0,	0,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	0,	1,	1,	0,	1,	1,	1,	1,	1,	1,	0,},
                            {0,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	0,	1,	1,	0,},
                            {0,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	0,	1,	1,	0,},
                            {0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,}};
public:

 bool isBewegingMogelijk(int spelerX,int spelerY,Richting huidigRichting){
     int huidigeX=(spelerX+4)/8;
     int huidigeY=(spelerY+4)/8;
    int volgendeX = 0;
    int volgendeY =0 ;
    if (huidigRichting == Richting::BOVEN){
        volgendeX=huidigeX;
        volgendeY=huidigeY-1;
        if(gameMatrix[volgendeX][volgendeY]==1){
            return true;
        }
    }else if (huidigRichting == Richting::BENEDEN){
         volgendeX=huidigeX;
         volgendeY=huidigeY+1;
        if(gameMatrix[volgendeX][volgendeY]==1){
            return true;
        }
     }
    else if (huidigRichting == Richting::LINKS){
        volgendeX=huidigeX-1;
        volgendeY=huidigeY;
        if(gameMatrix[volgendeX][volgendeY]==1){
            return true;
        }
    }
    else if (huidigRichting == Richting::RECHTS){
        volgendeX=spelerX+1;
        volgendeY=huidigeY;
        if(gameMatrix[volgendeX][volgendeY]==1){
            return true;
        }
    }
    return false;
 }

};

#endif //GBA_SPRITE_ENGINE_PROJECT_LEVELMAP_H