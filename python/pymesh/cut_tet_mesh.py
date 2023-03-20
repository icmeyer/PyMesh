from PyMesh import cutter3d

from .meshio import form_mesh

def cut_tet_mesh(mesh, surface):
    """ Wrapper function of :class:`Cutter3d`
    Args:
        mesh (:class:`Mesh`): Mesh to be cut
        surface (:class:`Mess`): Surface used to cut the mesh
    Return:
        :class:`Mesh` with 'ID' attribute for regions
    """
    cutter = cutter3d(mesh.raw_mesh.get_vertices(), mesh.raw_mesh.get_voxels(),
                      surface.raw_mesh.get_vertices(), surface.raw_mesh.get_voxels())
    cutter.run()
    outmesh = form_mesh(cutter.get_vertices(), np.array([]), cutter.get_voxels())
    outmesh.add_attribute('ID')
    outmesh.set_attribute('ID', cutter.get_regions())
    return outmesh
