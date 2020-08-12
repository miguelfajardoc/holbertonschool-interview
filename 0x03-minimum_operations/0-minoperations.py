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
    i = 2
    while i <= n:
        while n % i == 0:
            n = n / i
            operations += i
            # print("n = {} operations with i{} = {}".format(n, i, operations))
        i += 1
    return operations
