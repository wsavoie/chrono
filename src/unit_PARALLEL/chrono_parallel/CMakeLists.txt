#===============================================================================
# CMake configuration file for the ChronoEngine_Parallel library
#
# Invoked from the main CMakeLists.txt using ADD_SUBDIRECTORY()
#===============================================================================

# ------------------------------------------------------------------------------
# LIST THE FILES in the ChronoEngine_Parallel LIBRARY
# ------------------------------------------------------------------------------

SET(ChronoEngine_Parallel_BASE
    ChApiParallel.h
    ChParallelDefines.h
    ChSettings.h
    ChMeasures.h
    ChDataManager.h
    ChTimerParallel.h
    ChDataManager.cpp
    )

SOURCE_GROUP("" FILES ${ChronoEngine_Parallel_BASE})

SET(ChronoEngine_Parallel_PHYSICS
    physics/ChSystemParallel.h
    physics/ChNodeFluid.h
    physics/ChSystemParallel.cpp
    physics/ChSystemParallelDVI.cpp
    physics/ChSystemParallelDEM.cpp
    physics/ChNodeFluid.cpp
    )

SOURCE_GROUP(physics FILES ${ChronoEngine_Parallel_PHYSICS})

SET(ChronoEngine_Parallel_LCP
    lcp/ChLcpSolverParallel.h
    lcp/ChLcpSystemDescriptorParallel.h
    lcp/ChLcpSolverParallel.cpp
    lcp/ChLcpSolverParallelDVI.cpp
    lcp/ChLcpSolverParallelDEM.cpp
    )

SOURCE_GROUP(lcp FILES ${ChronoEngine_Parallel_LCP})

SET(ChronoEngine_Parallel_MATH
    math/ChParallelMath.h
    math/ChThrustLinearAlgebra.h
    math/mat33.h
    math/real.h
    math/real2.h
    math/real3.h
    math/real4.h
    )

SOURCE_GROUP(math FILES ${ChronoEngine_Parallel_MATH})

SET(ChronoEngine_Parallel_SOLVER
    solver/ChSolverParallel.h
    solver/ChSolverJacobi.h
    solver/ChSolverCG.h
    solver/ChSolverCGS.h
    solver/ChSolverPGS.h
    solver/ChSolverGD.h
    solver/ChSolverSD.h
    solver/ChSolverAPGD.h
    solver/ChSolverAPGDREF.h
    solver/ChSolverMinRes.h
    solver/ChSolverBiCG.h
    solver/ChSolverBiCGStab.h
    solver/ChSolverPDIP.h
    solver/ChSolverParallel.cpp
    solver/ChSolverJacobi.cpp
    solver/ChSolverCG.cpp
    solver/ChSolverCGS.cpp
    solver/ChSolverPGS.cpp
    solver/ChSolverGD.cpp
    solver/ChSolverSD.cpp
    #solver/ChSolverFN.cpp
    solver/ChSolverAPGD.cpp
    solver/ChSolverAPGDREF.cpp
    solver/ChSolverMinRes.cpp
    solver/ChSolverBiCG.cpp
    solver/ChSolverBiCGStab.cpp
    solver/ChSolverPDIP.cpp
    )

SOURCE_GROUP(solver FILES ${ChronoEngine_Parallel_SOLVER})

SET(ChronoEngine_Parallel_CONSTRAINTS
    constraints/ChConstraintRigidRigid.cpp
    constraints/ChConstraintRigidRigid.h
    constraints/ChConstraintBilateral.cpp
    constraints/ChConstraintBilateral.h
    )

SOURCE_GROUP(constraints FILES ${ChronoEngine_Parallel_CONSTRAINTS})

SET(ChronoEngine_Parallel_COLLISION
    collision/ChCAABBGenerator.h
    collision/ChCAABBGenerator.cpp
    collision/ChCBroadphase.h
    collision/ChCBroadphase.cpp
    collision/ChCBroadphaseUtils.h
    collision/ChCDataStructures.h
    collision/ChCNarrowphaseUtils.h
    collision/ChCNarrowphaseMPR.h
    collision/ChCNarrowphaseMPR.cpp
    collision/ChCNarrowphaseDispatch.h
    collision/ChCNarrowphaseDispatch.cpp
    collision/ChCNarrowphaseGJK_EPA.h
    collision/ChCNarrowphaseGJK_EPA.cpp
    collision/ChCNarrowphaseVoronoiSimplex.h
    collision/ChCNarrowphaseVoronoiSimplex.cpp
    collision/ChCNarrowphaseRUtils.h
    collision/ChCNarrowphaseR.h
    collision/ChCNarrowphaseR.cpp
    collision/ChCCollisionModelParallel.h
    collision/ChCCollisionModelParallel.cpp
    collision/ChCCollisionSystemParallel.h
    collision/ChCCollisionSystemParallel.cpp
    collision/ChCCollisionSystemBulletParallel.h
    collision/ChCCollisionSystemBulletParallel.cpp
    collision/ChContactContainerParallel.h
    collision/ChContactContainerParallel.cpp
    )

SOURCE_GROUP(collision FILES ${ChronoEngine_Parallel_COLLISION})

# Windows doesn't automatically pick up Bullet sources from Chrono
IF (MSVC)
    SET(ChronoEngine_Parallel_COLLISION_BULLET
    # CollisionDispatch
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btActivatingCollisionAlgorithm.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btActivatingCollisionAlgorithm.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btBoxBoxCollisionAlgorithm.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btBoxBoxCollisionAlgorithm.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btCollisionDispatcher.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btCollisionDispatcher.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btCollisionObject.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btCollisionObject.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btCollisionWorld.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btCollisionWorld.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btManifoldResult.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btManifoldResult.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btSphereTriangleCollisionAlgorithm.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btSphereTriangleCollisionAlgorithm.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btSphereSphereCollisionAlgorithm.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btSphereSphereCollisionAlgorithm.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btEmptyCollisionAlgorithm.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btEmptyCollisionAlgorithm.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btCompoundCollisionAlgorithm.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btCompoundCollisionAlgorithm.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btConvexConcaveCollisionAlgorithm.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btConvexConcaveCollisionAlgorithm.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btConvexPlaneCollisionAlgorithm.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btConvexPlaneCollisionAlgorithm.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btConvexConvexAlgorithm.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btConvexConvexAlgorithm.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/SphereTriangleDetector.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/SphereTriangleDetector.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btBoxBoxDetector.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionDispatch/btBoxBoxDetector.cpp
    # CollisionShapes
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btBvhTriangleMeshShape.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btBvhTriangleMeshShape.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btBvhTriangleMeshShape.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btBvhTriangleMeshShape.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btCollisionShape.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btCollisionShape.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btConvexInternalShape.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btConvexInternalShape.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btConcaveShape.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btConcaveShape.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btConvexShape.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btConvexShape.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btOptimizedBvh.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btOptimizedBvh.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btPolyhedralConvexShape.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btPolyhedralConvexShape.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btSphereShape.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btSphereShape.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btTetrahedronShape.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btTetrahedronShape.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btTriangleCallback.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btTriangleCallback.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btTriangleMeshShape.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/CollisionShapes/btTriangleMeshShape.cpp
    # BroadphaseCollision
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/BroadphaseCollision/btAxisSweep3.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/BroadphaseCollision/btAxisSweep3.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/BroadphaseCollision/btDbvt.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/BroadphaseCollision/btDbvt.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/BroadphaseCollision/btDispatcher.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/BroadphaseCollision/btDispatcher.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/BroadphaseCollision/btCollisionAlgorithm.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/BroadphaseCollision/btCollisionAlgorithm.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/BroadphaseCollision/btDbvtBroadphase.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/BroadphaseCollision/btDbvtBroadphase.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/BroadphaseCollision/btOverlappingPairCache.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/BroadphaseCollision/btOverlappingPairCache.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/BroadphaseCollision/btMultiSapBroadphase.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/BroadphaseCollision/btMultiSapBroadphase.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/BroadphaseCollision/btQuantizedBvh.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/BroadphaseCollision/btQuantizedBvh.cpp
    # NarrowPhaseCollision
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/NarrowPhaseCollision/btContinuousConvexCollision.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/NarrowPhaseCollision/btContinuousConvexCollision.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/NarrowPhaseCollision/btConvexCast.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/NarrowPhaseCollision/btConvexCast.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/NarrowPhaseCollision/btGjkConvexCast.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/NarrowPhaseCollision/btGjkConvexCast.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/NarrowPhaseCollision/btGjkEpa2.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/NarrowPhaseCollision/btGjkEpa2.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/NarrowPhaseCollision/btGjkEpaPenetrationDepthSolver.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/NarrowPhaseCollision/btGjkEpaPenetrationDepthSolver.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/NarrowPhaseCollision/btGjkPairDetector.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/NarrowPhaseCollision/btGjkPairDetector.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/NarrowPhaseCollision/btMinkowskiPenetrationDepthSolver.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/NarrowPhaseCollision/btMinkowskiPenetrationDepthSolver.cpp	
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/NarrowPhaseCollision/btPersistentManifold.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/NarrowPhaseCollision/btPersistentManifold.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/NarrowPhaseCollision/btRaycastCallback.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/NarrowPhaseCollision/btRaycastCallback.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/NarrowPhaseCollision/btSubSimplexConvexCast.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/NarrowPhaseCollision/btSubSimplexConvexCast.cpp	
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/NarrowPhaseCollision/btVoronoiSimplexSolver.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/BulletCollision/NarrowPhaseCollision/btVoronoiSimplexSolver.cpp	
    # gimpact
        ${CMAKE_SOURCE_DIR}/collision/gimpact/GIMPACT/Bullet/btGImpactCollisionAlgorithm.h
        ${CMAKE_SOURCE_DIR}/collision/gimpact/GIMPACT/Bullet/btGImpactCollisionAlgorithm.cpp
        ${CMAKE_SOURCE_DIR}/collision/gimpact/GIMPACT/Bullet/btGImpactQuantizedBvh.h
        ${CMAKE_SOURCE_DIR}/collision/gimpact/GIMPACT/Bullet/btGImpactQuantizedBvh.cpp
        ${CMAKE_SOURCE_DIR}/collision/gimpact/GIMPACT/Bullet/btTriangleShapeEx.h
        ${CMAKE_SOURCE_DIR}/collision/gimpact/GIMPACT/Bullet/btTriangleShapeEx.cpp
    # LinearMath
        ${CMAKE_SOURCE_DIR}/collision/bullet/LinearMath/btAlignedAllocator.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/LinearMath/btAlignedAllocator.cpp
        ${CMAKE_SOURCE_DIR}/collision/bullet/LinearMath/btQuickprof.h
        ${CMAKE_SOURCE_DIR}/collision/bullet/LinearMath/btQuickprof.cpp
        )

    SOURCE_GROUP(collision\\bullet FILES ${ChronoEngine_Parallel_COLLISION_BULLET})

    SET(ChronoEngine_Parallel_COLLISION
        ${ChronoEngine_Parallel_COLLISION}
        ${ChronoEngine_Parallel_COLLISION_BULLET}
        )
ENDIF()


# ------------------------------------------------------------------------------
# ADD THE ChronoEngine_Parallel LIBRARY
# ------------------------------------------------------------------------------

ADD_LIBRARY(ChronoEngine_Parallel SHARED
            ${ChronoEngine_Parallel_BASE}
            ${ChronoEngine_Parallel_PHYSICS}
            ${ChronoEngine_Parallel_LCP}
            ${ChronoEngine_Parallel_COLLISION}
            ${ChronoEngine_Parallel_CONSTRAINTS}
            ${ChronoEngine_Parallel_SOLVER}
            ${ChronoEngine_Parallel_MATH}
            )


IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    SET_TARGET_PROPERTIES( ChronoEngine_Parallel PROPERTIES XCODE_ATTRIBUTE_ENABLE_OPENMP_SUPPORT YES)
    FIND_LIBRARY(CUDA_FRAMEWORK CUDA)
ENDIF()

SET_TARGET_PROPERTIES(ChronoEngine_Parallel PROPERTIES
                      COMPILE_FLAGS "${CH_BUILDFLAGS}"
                      LINK_FLAGS "${CH_LINKERFLAG_GPU}"
                      COMPILE_DEFINITIONS "CH_API_COMPILE_PARALLEL")

TARGET_LINK_LIBRARIES(ChronoEngine_Parallel ChronoEngine ${CUDA_FRAMEWORK} ${MPI_LIBRARIES})

INSTALL(TARGETS ChronoEngine_Parallel
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)

mark_as_advanced(FORCE
    CUDA_BUILD_CUBIN
    CUDA_BUILD_EMULATION
    CUDA_SEPARABLE_COMPILATION
    CUDA_SDK_ROOT_DIR
    CUDA_VERBOSE_BUILD
    CUDA_HOST_COMPILER)







