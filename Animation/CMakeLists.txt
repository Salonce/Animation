# CMakeList.txt : CMake project for Animation, include source and define
# project specific logic here.
#

# Add source to this project's executable.
find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED SDL2_image>=2.0.0)


#add_executable (SDL2_Demo WIN32 )
add_executable (Animation "Animation.cpp" "Animation.h" "entities/Obj.h" "players/Player.cpp" "players/Player.h" "sprites/Sprite.cpp" "sprites/Sprite.h" "obstacles/Obstacle.h" "renderables/Renderable.h" "entities/enums/Direction.h" "entities/enums/Surface.h" "sprites/SpriteRepository.h" "textures/TextureRepository.h"  "utils/CompareRenderables.h"     "obstacles/ObstaclesService.h" "renderables/RenderablesService.h" "textures/TextureRepository.cpp" "sprites/SpriteFactory.h" "services/ObjFactory.h" "players/PlayerService.h" "players/PlayerRepository.h" "renderables/Renderer.h" "movingSprites/MovingSprite.h" "movingSprites/MovingSpriteRepository.h" "entities/interfaces/Repository.h" "services/MovablesService.h")



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
    ${CMAKE_CURRENT_SOURCE_DIR}/services
    ${CMAKE_CURRENT_SOURCE_DIR}/sprites
    ${CMAKE_CURRENT_SOURCE_DIR}/players
    ${CMAKE_CURRENT_SOURCE_DIR}/textures
    ${CMAKE_CURRENT_SOURCE_DIR}/obstacles
    ${CMAKE_CURRENT_SOURCE_DIR}/renderables
)

