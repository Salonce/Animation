#ifndef COMPARE_TEXTURE_H
#define COMPARE_TEXTURE_H

#include "Texture.h"


struct CompareRenderables {
    const bool operator()(Renderable* t1, Renderable* t2) {
        int a = t1->getSurface();
        int b = t2->getSurface();
        // printf("comparator: %i, %i", a, b);

        if (a != b) {
            if (a > b)
                return true;
            else if (b > a)
                return false;
        }
        return t1->getY() < t2->getY();
    }
};

#endif