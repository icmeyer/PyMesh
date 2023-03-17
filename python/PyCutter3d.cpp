#include <memory>

#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <Cutter3d/Cutter3d.h>

namespace py = pybind11;

void init_Cutter3d(py::module& m) {
    using namespace PyMesh;
    py::class_<Cutter3d, std::shared_ptr<Cutter3d> > cutter3d(m, "cutter3d");
    cutter3d 
        .def(py::init<>())
        // .def_property("nodes",
        //         &Cutter3d::get_nodes,
        //         // &Cutter3d::set_vertices,
        //         py::return_value_policy::reference_internal)
        .def_property_readonly("nodes",
                &Cutter3d::get_nodes,
                // &Cutter3d::set_vertices,
                py::return_value_policy::reference_internal)
        .def_property_readonly("tetrahedra",
                &Cutter3d::get_tetrahedra,
                py::return_value_policy::reference_internal)
        .def_property_readonly("surf_nodes",
                &Cutter3d::get_surf_nodes,
                py::return_value_policy::reference_internal)
        .def_property("triangles",
                &Cutter3d::get_triangles,
                py::return_value_policy::reference_internal)
        .def("Cutter3d", &TetgenWrapper::Cutter3d)
        .def("run", &TetgenWrapper::run)
        ;
}
