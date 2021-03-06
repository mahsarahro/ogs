set(SOURCES
    VtkPickCallback.cpp
    VtkCustomInteractorStyle.cpp
)

set(HEADERS
    VtkPickCallback.h
    VtkCustomInteractorStyle.h
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../../BaseLib
    ${CMAKE_CURRENT_SOURCE_DIR}/../../GeoLib
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Applications/FileIO
    ${CMAKE_CURRENT_SOURCE_DIR}/../../GeoLib/IO/Gmsh
    ${CMAKE_CURRENT_SOURCE_DIR}/../../MeshLib
    ${CMAKE_CURRENT_SOURCE_DIR}/../../MathLib
    ${CMAKE_CURRENT_SOURCE_DIR}/../VtkVis
)

add_library( VtkAct
    ${SOURCES}
    ${HEADERS}
)

ADD_VTK_DEPENDENCY(VtkAct)

target_link_libraries( VtkAct
    Qt4::QtCore
    ${VTK_LIBRARIES}
    logog
    )

set_property(TARGET VtkAct PROPERTY FOLDER "DataExplorer")
