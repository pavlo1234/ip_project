
cmake_minimum_required(VERSION 3.26)

project(ip_tool)


#встановлення автоматичного використання мета-компілятора, компілятора ресурсів
#та компілятора інтерфейсу користувача
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#встановлення шляхів знаходження Qt фреймворку
set(Qt6_DIR "C:\\Qt\\6.5.1\\mingw_64\\lib\\cmake\\Qt6")
set(Qt6_SHARED_LIB_DIR "C:\\Qt\\6.5.1\\mingw_64\\bin")

#знаходження бібліотек Qt
find_package(Qt6 REQUIRED COMPONENTS Quick Core Gui Charts ChartsQml)

#стандартне налаштування Qt-проекту
qt_standard_project_setup()

#отримання усіх заголовкових та реалізаційних файлів проекту
file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS include/*.hpp)

file(GLOB UIS ui/*.qml)


#створення Qt-застосунку, підключення файлів
qt_add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
)

#створення QML-модуля з файлів компонент проекту
qt_add_qml_module(${PROJECT_NAME}
    URI main
    QML_FILES
        ui/default.qml
        ui/tools/filter/FilterTool.qml
        ui/tools/filter/Matrix.qml
        ui/tools/filter/Cell.qml
        ui/tools/color/ColorTool.qml
        ui/tools/color/ParamBox.qml
        ui/tools/color/DistPlotView.qml
)

#встановлення папки для підключення файлів
target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)
#встановлення шляху підключення динамічних бібліотек
target_link_directories(${PROJECT_NAME}
    PUBLIC ${Qt6_SHARED_LIB_DIR}
)
#підключення Qt-бібліотек до проекту
target_link_libraries(${PROJECT_NAME}
    PUBLIC Qt6::Quick Qt6::Core Qt6::Gui Qt6::Charts Qt6::ChartsQml
)

#встановлення шляху та правил розгортки проекту
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/bin)

INSTALL(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
)

#генерація та підключення сценарію розгортки Qt-проекту
qt_generate_deploy_qml_app_script(
    TARGET ${PROJECT_NAME}
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)

install(SCRIPT ${deploy_script})