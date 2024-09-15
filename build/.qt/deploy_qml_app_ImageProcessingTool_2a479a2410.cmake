include(D:/WorkFiles/4_year/image_processing/project/build/.qt/QtDeploySupport.cmake)
include("${CMAKE_CURRENT_LIST_DIR}/ImageProcessingTool-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_ALL_MODULES_FOUND_VIA_FIND_PACKAGE "ZlibPrivate;EntryPointPrivate;Core;Gui;QmlIntegration;Network;Qml;QmlModels;OpenGL;Quick")

qt_deploy_qml_imports(TARGET ImageProcessingTool PLUGINS_FOUND plugins_found)
qt_deploy_runtime_dependencies(
    EXECUTABLE D:/WorkFiles/4_year/image_processing/project/build/ImageProcessingTool.exe
    ADDITIONAL_MODULES ${plugins_found}
    GENERATE_QT_CONF
)