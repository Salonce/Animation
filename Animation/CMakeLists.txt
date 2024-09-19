# CMakeList.txt : CMake project for Animation, include source and define
# project specific logic here.
#

# Add source to this project's executable.
find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED SDL2_image>=2.0.0)


#add_executable (SDL2_Demo WIN32 )
add_executable (Animation 
    "Animation.cpp" 
    "Animation.h" 
    "movingSprites/MovingSprite.h" 
    "movingSprites/MovingSpriteRepository.h" 
    "movingSprites/MovablesService.h" 
    "obstacles/Obstacle.h" 
    "obstacles/ObstaclesService.h" 
    "objs/Obj.h"
    "objs/ObjFactory.h"
    "objs/ObjRepository.h"
    "players/Player.cpp" 
    "players/Player.h" 
    "players/PlayerRepository.h" 
    "players/PlayerService.h" 
    "renderables/Renderable.h" 
    "renderables/RenderablesService.h" 
    "renderables/Renderer.h" 
    "renderables/CompareRenderables.h"
    "sprites/Sprite.cpp" 
    "sprites/Sprite.h" 
    "sprites/SpriteFactory.h" 
    "sprites/SpriteRepository.h" 
    "textures/TextureRepository.cpp" 
    "textures/TextureRepository.h"
)



target_link_libraries(Animation 
    SDL2::SDL2 
    SDL2::SDL2main 
    SDL2_image::SDL2_image
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Animation PROPERTY CXX_STANDARD 20)
endif()


target_include_directories(Animation PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/enums
    ${CMAKE_CURRENT_SOURCE_DIR}/interfaces
    ${CMAKE_CURRENT_SOURCE_DIR}/sprites
    ${CMAKE_CURRENT_SOURCE_DIR}/players
    ${CMAKE_CURRENT_SOURCE_DIR}/textures
    ${CMAKE_CURRENT_SOURCE_DIR}/obstacles
    ${CMAKE_CURRENT_SOURCE_DIR}/renderables
    ${CMAKE_CURRENT_SOURCE_DIR}/objs
    ${CMAKE_CURRENT_SOURCE_DIR}/movingSprites
)

