/* This file is part of PyMesh. Copyright (c) 2015 by Qingnan Zhou */
/* Author of this file: Isaac Meyer */
#include "Cutter3d.h"

#include <iostream>
#include <vector>

#include <Mesh.h>
#include <Eigen/Core>
#include <Core/EigenTypedef.h>
#include <Cutting.h>

using namespace PyMesh;

void Cutter3d::run() {
    const size_t num_nodes = m_nodes.rows();
    const size_t num_tets = m_tets.rows();
    const size_t num_surf_nodes = m_surf_nodes.rows();
    const size_t num_triangles = m_triangles.rows();

    // Convert to formats for 3d-cutter
    std::vector<std::array<double, 3>> in_nodes, in_surf_nodes;
    std::vector<std::array<int, 4>> in_tets;
    std::vector<std::array<int, 3>> in_triangles;

    in_nodes.resize(num_nodes);
    MatrixFr::Map(in_nodes[0].data()) = m_nodes;
    in_tets.resize(num_tets);
    MatrixIr::Map(in_tets[0].data()) = m_tets;
    in_surf_nodes.resize(num_surf_nodes);
    MatrixFr::Map(in_surf_nodes[0].data()) = m_surf_nodes;
    in_triangles.resize(num_triangles);
    MatrixIr::Map(in_triangles[0].data()) = m_triangles;

    // for (size_t i=0; i<num_nodes; i++) {
    //     float row [4] = {m_nodes(i, 0), m_nodes(i, 1), m_nodes(i, 2), m_nodes(i, 3)};
    //     in_nodes.push_back(row);
    //     // in_nodes.push_back(m_nodes.block(i,0,0,3).data());
    // }
    // for (size_t i=0; i<num_test; i++) {
    //     in_tets.push_back(m_tets.block(i,0,0,4).data());
    // }
    // for (size_t i=0; i<num_surf_nodes; i++) {
    //     in_surf_nodes.push_back(m_surf_nodes.block(i,0,0,3).data());
    // }
    // for (size_t i=0; i<num_triangles; i++) {
    //     in_triangles.push_back(m_triangles.block(i,0,0,3).data());
    // }

    Cutter3D<double> cutter(in_nodes, in_tets, in_surf_nodes, in_triangles);
    cutter.runPlainOut();

    // Convert output to eigen types
    // See tetgen wrapper for better memory management
    //
    m_out_vertices = MatrixFr::Map(cutter.outNodes[0].data(), cutter.outNodes.size(), 3)
    m_out_voxels = MatrixFr::Map(cutter.outVoxels[0].data(), cutter.outVoxels.size(), 4)
    m_out_regions = MatrixIr::Map(cutter.outIDs.data(), -1, -1)

    // m_out_vertices.resize(cutter.outNodes->size(), 3);
    // m_out_voxels.resize(cutter.outVoxels->size(), 4);
    // m_out_regions.resize(cutter.outIDs->size(), 1);
    // for (size_t i=0; i<cutter.outNodes->size(); i++){
    //     for (int j=0; j<4; j++){
    //         // m_out_vertices.block(i,j,0,0) = cutter.outNodes[i][j];
    //         m_out_vertices(i,j) = cutter.outNodes[i][j];
    //     }
    // }
    // for (size_t i=0; i<cutter.outVoxels->size(); i++){
    //     for (int j=0; j<4; j++){
    //         m_out_voxels(i,j) = cutter.outVoxels[i][j];
    //     }
    // }
    // m_out_regions = *(cutter.outIDs);
}
