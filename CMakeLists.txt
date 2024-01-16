project("interflop_vprec")

set (INTERFLOP_VPREC_SRC
    "common/vprec_tools.c"
    "interflop_vprec.c"
    "interflop_vprec_function_instrumentation.c"
)

set (INTERFLOP_VVPREC_SRC
    "x86_64/interflop_vector_vprec.c"

)

add_library(interflop_vprec_obj OBJECT ${INTERFLOP_VPREC_SRC})
target_compile_definitions(interflop_vprec_obj PRIVATE  ${CRT_COMPILE_DEFINITIONS})
target_compile_options (interflop_vprec_obj PRIVATE ${CRT_PREPROCESS_OPTIONS} ${CRT_COMPILE_OPTIONS})


add_library(interflop_vprec_scalar_obj OBJECT ${INTERFLOP_VVPREC_SRC})
target_compile_definitions(interflop_vprec_scalar_obj PRIVATE  ${CRT_COMPILE_DEFINITIONS})
target_compile_options (interflop_vprec_scalar_obj PRIVATE ${CRT_PREPROCESS_OPTIONS} ${CRT_COMPILE_OPTIONS})

add_library(interflop_vprec_sse_obj OBJECT ${INTERFLOP_VVPREC_SRC})
target_compile_definitions(interflop_vprec_sse_obj PRIVATE  ${CRT_COMPILE_DEFINITIONS} "VECT128")
target_compile_options (interflop_vprec_sse_obj PRIVATE ${CRT_PREPROCESS_OPTIONS} ${CRT_COMPILE_OPTIONS} "-msse4.2")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})
add_library (interflop_vprec SHARED $<TARGET_OBJECTS:interflop_vprec_obj>
                                    $<TARGET_OBJECTS:interflop_vprec_scalar_obj>
                                    $<TARGET_OBJECTS:interflop_vprec_sse_obj>
)
target_link_options (interflop_vprec PRIVATE ${CRT_LINK_OPTIONS})
target_link_libraries (interflop_vprec ${CRT_LINK_LIBRARIES} interflop_stdlib)
