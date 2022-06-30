set( CMAKE_BUILD_TYPE Debug )
cmake_minimum_required(VERSION 3.21)
project(HIRender)

set(CMAKE_CXX_STANDARD 17)
#set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
#set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
#set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=leak")
#set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=leak")

add_executable(
        HIRender Math/Vec3.cpp Math/Vec3.h Privitives/Point.cpp Privitives/Point.h Privitives/Primitive.cpp
        Privitives/3D/Sphere.h Privitives/3D/Sphere.cpp Math/Ray.h Math/Ray.cpp
        Privitives/Primitive.h Materials/Material.cpp Materials/Material.h Renderer/Renderer.cpp Renderer/Renderer.h
        Renderer/RenderParams.cpp Renderer/RenderParams.h Scene/Scene.cpp Scene/Scene.h Cameras/Camera.cpp Cameras/Camera.h
        Privitives/Lights/Light.cpp Privitives/Lights/Light.h Privitives/Color.cpp Privitives/Color.h Renderer/stb_image_write.h
        Privitives/Lights/PointLight.cpp Privitives/Lights/PointLight.h Renderer/JpegSaver.cpp Renderer/JpegSaver.h main.cpp
        Privitives/2D/Plane.cpp Privitives/2D/Plane.h Privitives/2D/Rectangle.cpp Privitives/2D/Rectangle.h
        Privitives/3D/Box.cpp Privitives/3D/Box.h Math/PixelRayCollection.cpp Math/PixelRayCollection.h)

add_executable(temp_tests_exec tests/TempTests.cpp)
add_executable(vec3_operators_tests_exec tests/Math/Vec3/Vec3OperatorsTests.cpp)
add_executable(point_tests_exec tests/Primitives/Point/PointGettersTests.cpp)
add_executable(point_getters_tests_exec tests/Primitives/Point/PointGettersTests.cpp)
add_executable(point_operators_tests_exec tests/Primitives/Point/PointOperatorsTests.cpp)
add_executable(lights_exec tests/Primitives/Lights/PointLightTests.cpp)
add_executable(cameras_exec tests/Cameras/CamerasTests.cpp)
add_executable(sphere_exec tests/Primitives/SphereTests.cpp)


enable_testing()
add_test(temp_tests temp_tests_exec)
add_test(vec3_operators_tests vec3_operators_tests_exec)
add_test(point_tests point_tests_exec)
add_test(point_getters_tests point_getters_tests_exec)
add_test(point_operators_tests point_operators_tests_exec)
#add_test(lights_tests lights_exec)
add_test(sphere_tests sphere_exec)