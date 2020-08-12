#!/usr/bin/python3
"""
module that contains minOperations
"""


def minOperations(n):
    """
    define the minumun operations to represent n number of elements
    starting with 1 and implement the copyall and paste operations
    return the minumun number of operations or 0 if the number to represent
    its not possible
    """
    if not isinstance(n, int) or n <= 0:
        return 0
    operations = 0
    for i in range(2, n + 1):
        while n % i == 0:
            n = n / i
            operations += i
            # print("n = {} operations with i{} = {}".format(n, i, operations))
    return operations
