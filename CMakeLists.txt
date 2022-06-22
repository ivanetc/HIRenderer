cmake_minimum_required(VERSION 3.21)
project(HIRender)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=leak")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=leak")

add_executable(
        HIRender main.cpp Math/Vec3.cpp Math/Vec3.h Privitives/Point.cpp Privitives/Point.h Privitives/Primitive.cpp
        Privitives/Primitive.h Materials/Material.cpp Materials/Material.h Renderer/Renderer.cpp Renderer/Renderer.h
        Renderer/RenderParams.cpp Renderer/RenderParams.h Scene/Scene.cpp Scene/Scene.h Cameras/Camera.cpp Cameras/Camera.h
        Privitives/Lights/Light.cpp Privitives/Lights/Light.h Privitives/Color.cpp Privitives/Color.h stb_image_write.h
        Privitives/Lights/PointLight.cpp Privitives/Lights/PointLight.h)

add_executable(temp_tests_exec tests/TempTests.cpp)
add_executable(vec3_operators_tests_exec tests/Math/Vec3/Vec3OperatorsTests.cpp)
add_executable(point_tests_exec tests/Primitives/Point/PointGettersTests.cpp)
add_executable(point_getters_tests_exec tests/Primitives/Point/PointGettersTests.cpp)
add_executable(point_operators_tests_exec tests/Primitives/Point/PointOperatorsTests.cpp)
add_executable(lights_exec tests/Primitives/Lights/PointLightTests.cpp)


enable_testing()
add_test(temp_tests temp_tests_exec)
add_test(vec3_operators_tests vec3_operators_tests_exec)
add_test(point_tests point_tests_exec)
add_test(point_getters_tests point_getters_tests_exec)
add_test(point_operators_tests point_operators_tests_exec)
add_test(lights_tests lights_exec)