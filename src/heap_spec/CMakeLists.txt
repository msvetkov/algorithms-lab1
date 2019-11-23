project(heap_spec)

add_executable(
        heap_spec index.cpp ../algorithms/algorithms.h ../heap/heap.h ../heap/heap.cpp ../heap/heap_node.h ../heap/heap_node.cpp ../heap/BftIterator.h ../heap/BftIterator.cpp ../heap/DftIterator.h ../heap/DftIterator.cpp ../heap/Iterator.h
)

target_link_libraries(heap_spec gtest gtest_main)