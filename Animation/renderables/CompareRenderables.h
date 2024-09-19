
#ifndef COMPARE_TEXTURE_H
#define COMPARE_TEXTURE_H

#include <Renderable.h>

struct CompareRenderables {
    const bool operator()(Renderable* t1, Renderable* t2) {
        int a = t1->getSurface();
        int b = t2->getSurface();
        // printf("comparator: %i, %i", a, b);

        if (a != b) {
            if (a > b)
                return true;
            return false;
        }
        a = t1->getY();
        b = t2->getY();
        if (a != b) {
            if (a < b)
                return true;
            return false;
        }
        return t1->getX() < t2->getX();
    }
};

#endif