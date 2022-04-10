cmake_minimum_required(VERSION 3.21)
project(HIRender)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=leak")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=leak")

add_executable(HIRender main.cpp Math/Vec3.cpp Math/Vec3.h Privitives/Point.cpp Privitives/Point.h Privitives/Primitive.cpp Privitives/Primitive.h Materials/Material.cpp Materials/Material.h Renderer/Renderer.cpp Renderer/Renderer.h Renderer/RenderParams.cpp Renderer/RenderParams.h Scene/Scene.cpp Scene/Scene.h Cameras/Camera.cpp Cameras/Camera.h)
add_executable(vec3tests_exec tests/Vec3Tests.cpp)

enable_testing()
add_test(Vec3Tests vec3tests_exec)
