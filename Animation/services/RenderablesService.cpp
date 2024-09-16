#include <vector>
#include <Renderable.h>
#include <Sprite.h>
#include <Obj.h>
#include <Player.h>
#include <RenderablesService.h>

std::vector<Renderable*> getRenderable(std::vector<Sprite*> spritesVector, std::vector<Obj*> objectsVector, Player* character) {

    std::vector<Renderable*> renderablesVector;

    renderablesVector.push_back(character);

    for (Obj* obj : objectsVector) {
        renderablesVector.push_back(obj);
    }

    for (Renderable* renderable : spritesVector) {
        renderablesVector.push_back(renderable);
    }

    return renderablesVector;
}