import random
import sys

# how to use in console:
# ```bash
# output_variable=$(python random_nums.py 5)
# ````

def generate_and_print_numbers(num):
    unique_numbers = set()
    while len(unique_numbers) < num:
        random_number = random.randint(1, 1000000)  # You can adjust the range as needed
        unique_numbers.add(random_number)
    return list(unique_numbers)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python random_nums.py <number_of_numbers>")
        sys.exit(1)

    try:
        num_of_numbers = int(sys.argv[1])
    except ValueError:
        print("Please provide a valid integer as the argument.")
        sys.exit(1)

    nums = generate_and_print_numbers(num_of_numbers)
    for n in nums:
        print(n, end=" ")

