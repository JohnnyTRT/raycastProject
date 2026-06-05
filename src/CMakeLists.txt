add_executable(${PROJECT_NAME} 
	main.cpp 
	game.cpp 
	maze.cpp 
	menuState.cpp
	playState.cpp
	stateMachine.cpp
	raycast.cpp)


add_library(imgui_backend imgui/imgui_impl_sdlrenderer3.cpp imgui/imgui_impl_sdl3.cpp)
target_include_directories(imgui_backend PUBLIC ${PROJECT_SOURCE_DIR}/include/imgui)
target_link_libraries(imgui_backend PUBLIC imgui::imgui SDL3::SDL3)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3 imgui::imgui)
