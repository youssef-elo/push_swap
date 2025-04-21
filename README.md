# 🌐 Overview
Push Swap is a project that challenges you to sort data on two stacks (Stack A and Stack B) using a limited set of operations with the fewest moves possible. The goal is to devise an efficient sorting algorithm that can handle varying input sizes (from 3 to 500+ numbers) while adhering to strict constraints.

Key Concepts Demonstrated

✔️ Algorithm design (sorting under constraints)

✔️ Stack operations (push, pop, swap, rotate)

✔️ Optimization (minimizing move count)

✔️ Input validation (error handling)

# 🎯 Features

Sorts integers using only allowed stack operations

Visualizes sorting steps (bonus)

Handles duplicates & non-integer inputs (error cases)

Optimized for speed (minimizes operations)

Supported Operations
Operation	Description
sa	Swap top 2 elements of Stack A
sb	Swap top 2 elements of Stack B
ss	sa + sb simultaneously
pa	Push top element from B to A
pb	Push top element from A to B
ra	Rotate Stack A upward
rb	Rotate Stack B upward
rr	ra + rb simultaneously
rra	Reverse rotate Stack A downward
rrb	Reverse rotate Stack B downward
rrr	rra + rrb simultaneously


# 🕹️ Usage
Basic Sorting

./push_swap 3 1 4 2 5
Outputs sequence of operations to sort the stack:

ra
pb
sa
pa

With Checker (Bonus)
ARG="3 1 4 2 5"; ./push_swap $ARG | ./checker $ARG

Outputs:

OK if sorted correctly

KO if sorting failed

# ⚙️ Algorithm
Sorting Strategy
Small stacks (3-5 numbers)

Hardcoded optimal sequences

Medium stacks (~100 numbers)

Chunk-based sorting:

Divide stack into chunks

Push elements to B based on chunk ranges

Smartly merge back to A

Large stacks (500+ numbers)

Optimized version of chunk sort

Dynamic chunk sizing

Advanced rotation strategies

5 Number sort example:

./push_swap 3 1 4 2 5
	sa
	pb
	rra
	rra
	pb
	ra
	pa
	pa

# ✅ Compliance
42 Norminette: Strict coding style

Memory Management: Zero leaks (Valgrind-approved)

Error Handling: Graceful exits for invalid input

Performance: Meets 42's operation limits
