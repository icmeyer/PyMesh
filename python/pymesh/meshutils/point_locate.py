from PyMesh import PointLocator

def point_locate(mesh, points):
    """ Wrapper function of :func:`PointLocator::locate`

    Args:
        mesh (:class:`Mesh`): Mesh to use for locating.
        point (``numpy.ndarray``): Point array. One point per row.

    Returns two values:
        * ``vertex_idxs`` (``nump.ndarray``): the vector of voxel ids of points
        * ``coords`` (``nump.ndarray``): the matrix of barycentric coordinates
    """
    locator = PointLocator(mesh.raw_mesh)
    locator.locate(points) 
    vertex_index = locator.get_enclosing_voxels()
    coords = locator.get_barycentric_coords()
    del locator
    return vertex_idxs, coords
