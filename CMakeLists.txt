cmake_minimum_required(VERSION 3.21)
project(HIRender)

set(CMAKE_CXX_STANDARD 17)

add_executable(HIRender main.cpp Math/Vec3.cpp Math/Vec3.h Privitives/Point.cpp Privitives/Point.h Privitives/Primitive.cpp Privitives/Primitive.h Materials/Material.cpp Materials/Material.h Renderer/Renderer.cpp Renderer/Renderer.h Renderer/RenderParams.cpp Renderer/RenderParams.h )
