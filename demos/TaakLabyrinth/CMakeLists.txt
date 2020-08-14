project(TaakLabyrinth)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/Scene/start_scene.cpp
        src/Scene/start_scene.h
        src/Scene/game_scene.h
        src/Scene/game_scene.cpp

        src/Data/spelerSpel.h
        src/Data/bomData.h
        src/Data/bonusData.h

        src/Model/speler.cpp
        src/Model/speler.h
        src/Model/BomModel.cpp
        src/Model/BomModel.h
        src/Model/BonusModel.cpp
        src/Model/BonusModel.h

        src/gameMap/GameMap.h src/gameMap/Richting.h src/Data/bgSpel.h src/Data/sharedPal.h src/Data/rubi.h src/Data/box.h src/Scene/extraGame_scene.cpp src/Scene/extraGame_scene.h src/Data/titleData.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
