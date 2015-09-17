//
//  Tools.cpp
//  tutian
//
//  Created by student on 15/8/23.
//
//

#include "Tools.h"

double  Tools::DistanceForPoint(const Vec2& p1,const Vec2& p2){
   
    double dx = pow(p2.x - p1.x,2);
    double dy = pow(p2.y - p1.y,2);
    return  sqrt(dx+dy);
}
