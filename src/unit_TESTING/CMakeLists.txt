
message(STATUS "==== Unit Test programs ====")

ADD_SUBDIRECTORY(core)
ADD_SUBDIRECTORY(benchmark)

#IF (ENABLE_UNIT_POSTPROCESS)
#  ADD_SUBDIRECTORY(unit_POSTPROCESS)
#ENDIF()

IF (ENABLE_UNIT_MATLAB)
  ADD_SUBDIRECTORY(unit_MATLAB)
ENDIF()

IF (ENABLE_UNIT_PARALLEL)
  ADD_SUBDIRECTORY(unit_PARALLEL)
ENDIF()
