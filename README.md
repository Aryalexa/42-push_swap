# `push_swap` project

What you will learn: 
- Logical thinking, project organization, case discerning. 
- Data Structures: stack, deque (Deques are great, with them we can represent others as stack, queue, ...)
- Sorting/searching algorithms. In this project approach a binary search will be used.
- C structs, C Enums, C Pointers

Table of Contents
- Push swap Problem
- Project requirements
- Resolving the Push swap Problem
	- One, Two and Three elements cases
	- Minimize the number of operations
	- Algo basics
	- Algo

### Push swap Problem
It is an optimized-sorting problem using a pair of a special stack, stack A and stack B, with its own operations.

Given a number of integers already in stack A, we must find a sequence of operations, as short as possible, to have all elements sorted in A in ascending order.

Operations:

 * `sa` swap a: swap first two elemets in stack a, when there are 2 elements or more.
 * `sb` swap b: swap first two elemets in stack b, when there are 2 elements or more.
 * `ss` swap a and swap b at the same time.
 * `pa` push a: take the first element from b and push it first into a, when there is one or more elements in b.
 * `pb` push b: take the first element from a and push it first into b, when there is at least one element in a.
 * `ra` rotate a: move the first element to the last position so the rest of the elements move one position up.
 * `rb` rotate b: move the first element to the last position so the rest of the elements move one position up.
 * `rr` rotate a and b at the same time.
 * `rra` reverse rotate a: moves the last element to the first position so the rest of the elements move one position down.
 * `rrb` reverse rotate b: moves the last element to the first position so the rest of the elements move one position down.
 * `rrr` reverse rotate a and b at the same time.


### Project requirements
- We need a program that takes an arbitrary number of integers as input and prints the solution to the "Push swap" problem as if the integers were inserted into stack A.

- The solution must be a sequence of instructions.

- Input error management


### Resolving the Push swap Problem

Let's see some basics and how the algorithm goes.

#### One, Two and Three elements cases
These are the smallest cases, and for them the solution is straightforward without needing a second stack.

- For one element, there's nothing to do.
- For two elements, we will need a swap or not.

##### Three elements cases
This is the smallest scenario we will let happen when moving elements from one stack to the other.

How many ways can we order 3 different elements? `3! = 6`.

(You have 3 options for first position. Once it is fixed, because there's no repetitions, you have 2 options for second position. And the third is determined by the two first decisions. So `3*2*1 = 3! = 6`)
``` python
# For stack_A
[1,2,3] -> ok
[2,3,1] -> rra -> [1,2,3] -> ok
[3,1,2] -> ra  -> [1,2,3] -> ok

[3,2,1] -> sa  -> [2,3,1] -> rra -> [1,2,3] -> ok
[2,1,3] -> sa  -> [1,2,3] -> ok
[1,3,2] -> rra -> [2,1,3] -> sa  -> [1,2,3] -> ok
```

In total we have 6 cases: 
- one already sorted
- two with a solution of 3 steps
- three with a solution of 2 steps

#### Minimize the number of operations

Leverage same-time operations: `ss`, `rr`, `rrr`.

Instead of doing 2 `ra` ops and 3 `rb` ops (5 ops), do 2 `rr` ops and 1 `rb` (3 ops).
This way we reduce the number of operations from `N + M` to `max(N, M)`: `min(N, M)` same-time ops and the rest being single-stack ops.

#### Algo basics
- Starting point: all elements in stack_A.
- Goal: all elements in stack_A in ascending order.
- If we arrange all elements in stack_B in descending order, it's direct to have stack_A in ascending order.
	- `A: /\ <-- B: \/`
- The algorithm considers the stacks are circular. So the stacks `3,2,1`, `1,3,2` and `2,1,3` are all in descending order (The final result does not do this consideration).
- The algorithm will push everything from stack_A to stack_B in descending order, slowly.
	- 🔴 Is the head of stack_A a new MIN or MAX in stack_B? move it to the head of stack_B
		- If it is the MIN, we consider that it's correctly in desc order (consider the stacks are circular)
	- Otherwise, we will find its position withing stack_B manually.

#### Algo
🔸 check if stack is already in asc-order.
- set ini and end of the longest subarray already sorted.
- if end-ini+1 == number of elemts 
	- -> already sorted!
	- else, continue
		```
		OR if end-ini+1 > 3: //jugaremos con este num: > 3? > % del total?
		- -> fix [ini, end] -> set game.a_ini, game.a_end, game.a_sorted=T
		- else, set game.a_ini=n-4, game.a_end=n-1, game.a_sorted=F```

🔸 Start moving two elements to stack_B: `pb`, `pb`.

🔸 Move the cheapest element from stack_A to stack_B.

Move one by one while the number os elements is stack_A > 3

✨OR: averiguar el cacho mas grande ordenado y dejarlo en A. mover lo demas a B ordenadamente.

- For all elements still in stack_A, find the element with minimum cost to move to stack_B and make stack_B descending ordered. We have 2 elements in stack_B.
	- Consider how many ops we need to get each element to the head (`ra` ops for the upper half, `rra` ops for the other half) and then push it to stack_B (`pb`). Also don't forget that if stack_B is not in desc order, you need a `rb`/`rrb` (or you can use `rr` or `rrr` instead of the first `ra`/`rra`).
	- The candidates are... the head:
		- head (pos=0) needs pb or rb,pb (1 or 2)
		- pos=1 needs ra(+rb),  pb (min 2)
		- pos=3 needs ra, ra(+rb), pb (min 3)
		- ..
		- pos=n-2 needs rra, rra(+rrb), pb (min 3)
		- tail (pos=n-1) need rra(+rrb), pb (min 2)
- Continue finding the min cost element to move while maintaining stack B descendingly ordered. Now we have 3 elements in stack_B.
	- to find its position in stack_B, we need 0 or 1 (`rb`/`rrb`) ops.
	- 1 op to push it `pb`
	- to get it out of stack_A, the number of ops needed are its position for the first half (`ra`) and len-position for the other half (`rra`).
	- So, 1 + position + rb/rrb ops -> 1+pos or 1+pos+1 ops
- Continue finding the min cost element to move while maintaining stack B descendingly ordered. Now we have B elements in stack_B and A in stack_A.
	- there are B number of possible new positions, 0-B/2 ops. or >B/2 ops
	- 1 op to push it `pb`
	- to get it out of stack_A, 0-A/2 ops or >A/2 ops.
	- So, we choose the minimum between 
		- if 0-B/2 and 0-A/2 are the same op: max(0-B/2, 0-A/2) + 1
		- if 0-B/2 and 0-A/2 are not the same op: min (max(0-B/2, >A/2), max(>B/2, 0-A/2)) + 1

🔸 Move back all elements from stack_B to stack_A


🔸 Check that the minimum element of stack_A is at the top.




### Resources/Credits
- [Medium: ayogun's push-swap](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
	- Github: [ayogun/push_swap](https://github.com/ayogun/push_swap)
- Radix method: [Brazhnik/Push_swap](https://github.com/VBrazhnik/Push_swap/wiki/Algorithm)