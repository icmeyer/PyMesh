#include <memory>

#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <Cutter3d/Cutter3d.h>

namespace py = pybind11;
using namespace PyMesh;
using namespace pybind11::literals;

void init_Cutter3d(py::module& m) {
    using namespace PyMesh;
    py::class_<Cutter3d, std::shared_ptr<Cutter3d> > cutter3d(m, "cutter3d");
    cutter3d 
        .def(py::init<const MatrixFr&, const MatrixIr&, const MatrixFr&, const VectorI&>())
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
        .def("run", &Cutter3d::run)
        ;
}
