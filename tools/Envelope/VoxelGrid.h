/* This file is part of PyMesh. Copyright (c) 2015 by Qingnan Zhou */
#pragma once
#include <functional>
#include <vector>

#include <Core/EigenTypedef.h>
#include <Mesh.h>
#include <Misc/HashGrid.h>

#include "Grid.h"

namespace PyMesh {

template<int DIM>
class VoxelGrid : public Grid<DIM, short>{
    public:
        std::shared_ptr<VoxelGrid<DIM> > Ptr;
        typedef Grid<DIM, short> Parent;
        typedef typename Grid<DIM, short>::Vector_f Vector_f;
        typedef typename Grid<DIM, short>::Vector_i Vector_i;

    public:
        VoxelGrid(Float cell_size);
        virtual ~VoxelGrid() = default;

    public:
        void insert_mesh(Mesh::Ptr mesh);
        void create_grid();
        void erode(size_t iterations);
        void dilate(size_t iterations);
        void remove_cavities();

        const Vector_i& get_size() const { return this->size(); }
        const Vector_f& get_base_coordinates() const { return this->base_coordinates(); }
        const Vector_f& get_cell_size() const { return this->cell_size(); }

        Mesh::Ptr get_voxel_mesh();
        VectorI get_voxel_vector();


    protected:
        typedef Grid<DIM, bool> Mask;

        void insert_triangle_mesh(Mesh::Ptr mesh);
        void insert_quad_mesh(Mesh::Ptr mesh);

        Mask create_mask() const;
        void flood_from_base_cell(Mask& mask);

    private:
        size_t m_margin;
        HashGrid::Ptr m_hash_grid;
};

}

#include "VoxelGrid.inl"

namespace PyMesh {
typedef VoxelGrid<2> VoxelGrid2D;
typedef VoxelGrid<3> VoxelGrid3D;
}

