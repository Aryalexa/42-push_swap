# `push_swap` Project

What you will learn: 
- Logical thinking, project organization, case discerning. 
- Data Structures: stack, deque (Deques are great, with them we can represent others as stack, queue, ...)
- Sorting/searching algorithms? Useful but this approach is more of a greedy solution.
- C structs, C Enums, C Pointers, using functions as parameters.

Table of Contents
- [Push swap Problem](https://github.com/Aryalexa/42-push_swap?tab=readme-ov-file#push-swap-problem)
- [Project requirements](https://github.com/Aryalexa/42-push_swap?tab=readme-ov-file#project-requirements)
- [Solving the Push swap Problem](https://github.com/Aryalexa/42-push_swap?tab=readme-ov-file#solving-the-push-swap-problem)
	- One, Two and Three elements cases
	- Minimize the number of operations
	- Algo basics
	- Algo
- [Program execution](https://github.com/Aryalexa/42-push_swap?tab=readme-ov-file#program-execution)
- [Resources/Credits](https://github.com/Aryalexa/42-push_swap?tab=readme-ov-file#resourcescredits)

## Push swap Problem
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


## Project requirements
- We need a program that takes an arbitrary number of integers as input and prints the solution to the "Push swap" problem as if the integers were the elements at stack A from top to bottom.

- The solution must be a sequence of valid operations.

- Input error management

- Bonus: create a checker program that takes the elements in stack A as argument, reads the solution as input (valid operations separated by new lines (use EOF)) and prints "OK" or "KO".


## Solving the Push swap Problem

This approach is fast and uses a simple algorithm to solve the problem.
Let's see some basics and how the algorithm goes.

### One, Two and Three elements cases
These are the smallest cases, and for them the solution is straightforward without needing a second stack.

- For one element, there's nothing to do, it's already sorted.
- For two elements, either it's sorted or we need a swap.

#### Three elements cases
How many ways can we order 3 different elements? `3! = 6` (You have 3 options for first position. Once it is fixed, because there's no repetitions, you have 2 options for second position. And the third is determined by the two first decisions. So `3*2*1 = 3! = 6`)
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

### Minimize the number of operations

Leverage same-time operations: `ss`, `rr`, `rrr`.

For example, instead of doing 2 `ra` ops and 3 `rb` ops (5 ops), do 2 `rr` ops and 1 `rb` (3 ops).
This way we reduce the number of operations from `N + M` to `max(N, M)` operations, where `min(N, M)` ops are same-time ops and the rest are single-stack ops. Same for `rra`, `rrb` and `rrr`.

As for `ss`... The solution approach we have chosen doesn't really use it. But it is true that one `ss` makes the same effect as `sa` + `sb`.

### Algo basics
- Starting point: all elements in stack_A.
- Goal: all elements in stack_A in ascending order.
- If we arrange all elements in stack_B in descending order, it's direct to have stack_A in ascending order.
	- `A: /\ <-- B: \/`
- The algorithm during the process will keep the stacks in *circular* ascending/descending order. The stacks `3,2,1`, `1,3,2` and `2,1,3` are all in circular descending order.
- The algorithm will push everything from one stack to the other stack slowly.
	- It will try to maintain the circular order of the target stack.
	- It chooses the cheapest number to push: for each number in the source stack, how much does it cost to put it at the top and rearrage the target stack, so we can push the number and keep the target stack in circular order?)

### Algo
🔸 check if stack_A is already in asc-order.
- if already sorted, end game
- otherwise, continue

🔸 Check the number of elements in stack_A
- if size <= 3, give straightforward solution
- otherwise, continue

🔸 Move the elements from stack_A to stack_B while the number of elements in stack_A > 3. You will move the **cheapest element**. (Remember to always check if the remainder is already in order!)

- Start moving two elements to stack_B: `pb`, `pb`. Two numbers are always in cicular order.

- For all elements still in stack_A, find the element with minimum cost to move to stack_B while keeping stack_B in circular descending order. For each element `e`:
	- What is the minimum cost to be put at the top?
		- We could use `index of e in A` times the `ra` operation.
		- Or because, `rra` also exists, we could use it `size of A - index of e in A` times to put it at the top.
	- And, where in stack_B should `e` be?
		- stack_B should always be in circular descending order
		- we are searching for the position of the greatest number that is lower than `e`.
		- What is the minimum cost to put it at the top?
- So for each number in stack_A, we have 4 possible ways to rotate both stacks to their desired positions and then execute a push:
	- moving both tops only: using `ra` and `rb` ops. Leverage `rr` when counting.
	- moving both rears only: using `rra` and `rrb` ops. Leverage `rrr` when counting.
	- moving top and rear: using `ra` and `rrb` ops. No leverage here.
	- moving rear and top: using `rra` and `rb` ops. No leverage here.
- Choose the cheapest play, its cost will be the cost for the number.
- Choose the cheapest number, apply the play and push it.

🔸 Move back all elements from stack_B to stack_A
- We have at least 3 elements remaining in stack_A
	- If they are not in ascending order, they are three so apply the straightforward solution.
- Now we'll move every element from stack_B back to stack_A.
	- maintain stack_A in circular ascending order
	- choose the cheapest number to move while keeping stack_A in circular ascending order
	- It's almost the same as moving from stack_A to stack_B, just the order in the target stack changes.

🔸 Rearrange stack_A so that its minimum element is at the top.
- stack_A has all elements and is in circular ascending order, but we don't want the "circular" part.
- rotate stack_A until the minimum element is at the top.


## Program execution

Use ``make`` for generate the `push_swap` program and ``make bonus`` to generate the `checker` program.
Here is an example of their usage:

```bash
ARG="45 23 16 17 8"; ./push_swap $ARG | ./checker $ARG
```

There's a python random numbers generator `random_nums.py` included in this project, it takes as argument the number of different random numbers to be generated. You can use it to evaluate the power of the algorithm.

```bash
ARG=$(python random_nums.py 100); ./push_swap $ARG | ./checker $ARG
ARG=$(python random_nums.py 200); ./push_swap $ARG | wc -w
```

## Resources/Credits
- [Medium: ayogun's push-swap](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
	- Github: [ayogun/push_swap](https://github.com/ayogun/push_swap)
- Radix method: [Brazhnik/Push_swap](https://github.com/VBrazhnik/Push_swap/wiki/Algorithm) (not used but worth mentioning)


## TO-DO
- put headers
- include libft properly to submit the project (79aa440)
- do not submit random_nums.py
