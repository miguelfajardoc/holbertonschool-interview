#!/usr/bin/python3
""" can unlock all boxes?? """


def canUnlockAll(boxes):
    """ can unlock all boxes?? """

    if boxes is None:
        return False
    unusedK = [0]
    usedKeys = set()

    length = len(boxes)

    while (unusedK):
        useKey = unusedK.pop(0)
        newKeys = boxes[useKey]
        usedKeys.add(useKey)
        for key in newKeys:
            if key not in usedKeys and key < len(boxes) and key not in unusedK:
                unusedK.append(key)

    suma = sum(usedKeys)
    if suma == ((length - 1) * length) / 2:
        return True

    return False
