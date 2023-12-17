# HOW TO USE -----------------------------------------------------------------#
# ----------------------------------------------------------------------------#

# Click the play button to the left
# Enter the number of numbers you wish to generate
# Double click on the line of generated numbers to easily copy

import random

x = int(input())
#x = 100
min_int = -2147483648
max_int = 2147483647

unique_numbers = set()


while len(unique_numbers) < x:
    rand_num = random.randint(min_int, max_int)
    unique_numbers.add(rand_num)

unique_numbers_list = list(unique_numbers)

result = " ".join(map(str, unique_numbers_list))

print(result)
