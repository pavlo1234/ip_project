include(D:/WorkFiles/4_year/image_processing/project/build/.qt/QtDeploySupport.cmake)
include("${CMAKE_CURRENT_LIST_DIR}/ip_tool-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_ALL_MODULES_FOUND_VIA_FIND_PACKAGE "ZlibPrivate;EntryPointPrivate;Core;Gui;QmlIntegration;Network;Qml;QmlModels;OpenGL;Quick;Widgets;OpenGLWidgets;Charts;ChartsQml")

qt_deploy_qml_imports(TARGET ip_tool PLUGINS_FOUND plugins_found)
qt_deploy_runtime_dependencies(
    EXECUTABLE D:/WorkFiles/4_year/image_processing/project/build/ip_tool.exe
    ADDITIONAL_MODULES ${plugins_found}
    GENERATE_QT_CONF
)