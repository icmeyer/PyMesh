/* This file is part of PyMesh. Copyright (c) 2015 by Qingnan Zhou */
/* Author of this file: Isaac Meyer */
#ifdef WITH_TETGEN
#include "Cutter3d.h"
#include <iostream>
#include <vector>
#include <Cutter.h>

#include <Mesh.h>

using namespace PyMesh;

void Cutter3d::run() {
    const size_t num_nodes = m_nodes.rows();
    const size_t num_tets = m_tets.rows();
    const size_t num_surf_nodes = m_surf_nodes.rows();
    const size_t num_triangles = m_triangles.rows();

    // Convert to formats for 3d-cutter
    std::vector<std::array<float, 3>> in_nodes, in_surf_nodes;
    std::vector<std::array<int, 4>> in_tets;
    std::vector<std::array<int, 3>> in_triangles;
    for (size_t i=0; i<num_nodes; i++) {
        in_nodes.push_back(m_nodes.block(i,0,0,3).data());
    }
    for (size_t i=0; i<num_test; i++) {
        in_tets.push_back(m_tets.block(i,0,0,4).data());
    }
    for (size_t i=0; i<num_surf_nodes; i++) {
        in_surf_nodes.push_back(m_surf_nodes.block(i,0,0,3).data());
    }
    for (size_t i=0; i<num_triangles; i++) {
        in_triangles.push_back(m_triangles.block(i,0,0,3).data());
    }

    Cutter3D<float> cutter(in_nodes, in_test, in_surf_nodes, in_triangles);
    cutter.runPlainOut()

    // Convert output to eigen types
    // See tetgen wrapper for better memory management
    m_out_vertices.resize(cutter.outNodes->size(), 3)
    m_out_voxels.resize(cutter.outVoxels->size(), 4)
    m_out_regions.resize(cutter.outIDs->size(), 1)
    for (size_t i=0; i<cutter.outNodes->size(); i++){
        m_out_vertices.block(i,0,0,3) = cutter->outNodes[i];
    }
    for (size_t i=0; i<cutter.outVoxels->size(); i++){
        m_out_voxels.block(i,0,0,4) = cutter->outVoxels[i];
    }
    m_out_regions = *cutter.outIDs;
}

#endif
