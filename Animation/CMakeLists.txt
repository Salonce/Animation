# CMakeList.txt : CMake project for Animation, include source and define
# project specific logic here.
#

# Add source to this project's executable.
find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED SDL2_image>=2.0.0)


#add_executable (SDL2_Demo WIN32 )
add_executable (Animation "Animation.cpp" "Animation.h" "entities/Obj.h" "entities/Player.cpp" "entities/Player.h" "entities/Sprite.cpp" "entities/Sprite.h" "entities/interfaces/Obstacle.h" "entities/interfaces/Renderable.h" "entities/enums/Direction.h" "entities/enums/Surface.h" "repositories/SpriteRepository.h" "repositories/TextureRepository.h"  "utils/CompareRenderables.h"   "services/ObstaclesService.cpp" "services/RenderablesService.cpp" "services/ObstaclesService.h" "services/RenderablesService.h" "repositories/TextureRepository.cpp" "services/SpriteFactory.h" "services/ObjFactory.h" "services/PlayerService.h" "repositories/PlayerRepository.h" "services/Renderer.h")



target_link_libraries(Animation 
    SDL2::SDL2 
    SDL2::SDL2main 
    SDL2_image::SDL2_image
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Animation PROPERTY CXX_STANDARD 20)
endif()


target_include_directories(Animation PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/entities
    ${CMAKE_CURRENT_SOURCE_DIR}/entities/enums
    ${CMAKE_CURRENT_SOURCE_DIR}/entities/interfaces
    ${CMAKE_CURRENT_SOURCE_DIR}/repositories
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/services
)

