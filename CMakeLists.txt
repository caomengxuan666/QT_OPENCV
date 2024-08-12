cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0144 NEW)
# 项目信息
project(cmx)
# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置QT的标准
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Boost标准
set(VCPKG_TARGET_TRIPLET "x64-mingw-dynamic")
set(BOOST_ROOT "D:/MyLibs/boost_1_85_0/boost_lib/")
set(Boost_USE_STATIC_LIBS ON)    # 设置使用Boost静态库
set(Boost_COMPILER "-mgw8")      #指定编译器版本
set(Boost_ARCHITECTURE "-x64")   # 指定boost库架构为x64
set(FMT_HEADER_ONLY ON)

include_directories("D:/MyLibs/fmt-10.2.0/include")

include_directories(include)


#set(boost_mysql_DIR D:/MyLibs/boost_1_85_0/boost_lib/include/boost-1_85/boost/mysql)

# 查找Boost库
find_package(Boost REQUIRED COMPONENTS regex thread chrono)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
else ()
    message(FATAL_ERROR "Boost not found!")
endif ()

# 设置头文件和库搜索路径
set(CMAKE_PREFIX_PATH
        ${QT_DIR}
        ${OPENCV_DIR}
)

# 设置参与构建的文件
set(PROJECT_FILES
        res.qrc
        main.cpp
        launchmenu.cpp
        launchmenu.hpp
        launchmenu.ui
        imageframe.cpp
        imageframe.hpp
        imageframe.ui
        ImgStack.hpp
        QImage2Mat.hpp
        cv_gray.cpp
        cv_gray.hpp
        CV_OBJECT.cpp
        CV_OBJECT.hpp
        ImgOperations.hpp
)

# 静态链接boost::Asio库
#include_directories(D:/MyLibs/boost_1_85_0/boost_lib/include/boost-1_85/boost/asio)
# 通过手动添加一些windows下的socket库来使用Asio库
#link_libraries(libgdi32.a libwsock32.a libws2_32.a)


find_package(fmt REQUIRED PATHS "D:/MyLibs/fmt-10.2.0/lib")


# 查找Qt6库
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

# 查找OpenCV库
find_package(OpenCV REQUIRED)

# 查找openssl
set(OpenSSL_INCLUDE_DIRS D:/MyLibs/openssl/OpenSSL-Win64/include)
include_directories(${OpenSSL_INCLUDE_DIRS})
set(OPENSSL_ROOT_DIR D:/MyLibs/openssl/OpenSSL-Win64)
find_package(OpenSSL REQUIRED)

# 添加可执行文件


add_executable(cmx ${PROJECT_FILES}
    )

# 链接Qt6库
target_link_libraries(cmx PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

# 链接Boost库
target_link_libraries(cmx PRIVATE ${Boost_LIBRARIES})

# 链接OpenCV库
target_link_libraries(cmx PRIVATE ${OpenCV_LIBS})

target_link_libraries(cmx PRIVATE OpenSSL::Crypto OpenSSL::SSL)

target_link_libraries(cmx PRIVATE fmt::fmt)
