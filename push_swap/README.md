# push_swap

This project is part of the 42 School curriculum. It consists of writing a sorting algorithm with the least number of operations, using two stacks and a restricted set of commands.

## Overview

The `push_swap` program sorts a stack of integers using a second auxiliary stack and a limited set of operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`). The goal is to produce the most efficient sequence of operations.

It handles:
- Small stacks (2 to 5 elements) with hand-crafted logic.
- Large stacks (e.g., 100 or 500 elements) using a chunk-based algorithm with value indexing and smart rotations.

## Algorithm

The core sorting logic is implemented in the `push_swap` function. Here's how it works:

1. **Small inputs**:
   - 2 elements → simple swap if needed.
   - 3 elements → hardcoded sort logic.
   - ≤5 elements → push smallest values to stack B, sort A, then push back.

2. **Larger inputs**:
   - Each node is first indexed by its sorted position.
   - A **chunk-based algorithm** is used:
     - Elements are pushed to stack B in chunks of a certain size.
     - Low values are rotated inside stack B for better final order.
     - Then the maximum elements are found in B and pushed back to A in sorted order.

```c
void push_swap(t_node **a) {
    t_node *b = NULL;
    int size = stack_size(*a);
    int chunk_size = 20;

    if (size == 2)
        sort_two(a);
    else if (size == 3)
        sort_three(a);
    else if (size <= 5)
        sort_five(a, &b);
    else {
        index_stack(*a);
        chunk_sort(a, &b, chunk_size);
    }
}