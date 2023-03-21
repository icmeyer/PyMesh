/* This file is part of PyMesh. Copyright (c) 2015 by Qingnan Zhou */
/* Author of this file: Isaac Meyer */
#pragma once
#include <Core/EigenTypedef.h>

namespace PyMesh {

class Cutter3d {
    public:
        /**
         * Set input
         */
        Cutter3d(const MatrixFr& nodes, const MatrixIr& tetrahedra, 
                 const MatrixFr& surf_nodes, const MatrixIr& triangles):
                 m_nodes(nodes), m_tets(tetrahedra), m_surf_nodes(surf_nodes),
                 m_triangles(triangles) {}
        const MatrixFr& get_nodes() const { return m_nodes; }
        const MatrixIr& get_tetrahedra() const { return m_tets; }
        const MatrixFr& get_surf_nodes() const { return m_surf_nodes; }
        const MatrixIr& get_triangles() const { return m_triangles; }

        /**
         * Example flag
         */
        // void set_merge_coplanar(bool val) { m_merge_coplanar = val; }
        // bool get_merge_coplanar() const { return m_merge_coplanar; }

        void run();

        const MatrixFr& get_vertices() const { return m_out_vertices; }
        const MatrixIr& get_voxels() const { return m_out_voxels; }
        const VectorI& get_regions() const { return m_out_regions; }

    private:
        // inputs
        MatrixFr m_nodes;
        MatrixIr m_tets;
        MatrixFr m_surf_nodes;
        VectorI m_triangles;

        // outputs
        MatrixFr m_out_vertices;
        MatrixIr m_out_voxels;
        VectorI  m_out_regions;
};

}
