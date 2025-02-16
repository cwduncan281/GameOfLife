target_sources(game
    PRIVATE
        GameLogic.cpp
    PUBLIC
        GameLogic.hpp
)

# Make sure the include directory is properly set
target_include_directories(game 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}
)