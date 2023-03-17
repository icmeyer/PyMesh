# Enumerate source files
file(GLOB_RECURSE SRC_FILES *.cpp)
file(GLOB_RECURSE INC_FILES *.h)

if (TARGET PyMesh::third_party::Cutter3d)
    add_library(lib_Cutter3d SHARED ${SRC_FILES} ${INC_FILES})
    set_target_properties(lib_Cutter3d PROPERTIES OUTPUT_NAME "PyMesh-Cutter3d")
    target_link_libraries(lib_Cutter3d
        PUBLIC
            PyMesh::Mesh
            PyMesh::Tools
            PyMesh::third_party::Cutter3d
    )
    add_library(PyMesh::Cutter3d ALIAS lib_Cutter3d)
endif ()
