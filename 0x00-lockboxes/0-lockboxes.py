#!/usr/bin/python3
""" can unlock all boxes?? """


def canUnlockAll(boxes):
    """ can unlock all boxes?? """

    unusedKeys = [0]
    usedKeys = set()

    length = len(boxes)
    
    while (unusedKeys):
        #print("unusedKeys:")
        #print(unusedKeys)
        useKey = unusedKeys.pop(0)
        newKeys = boxes[useKey]
        usedKeys.add(useKey)
        for key in newKeys:
            if key not in usedKeys and key < len(boxes):
                unusedKeys.append(key)
        
    if sum(usedKeys) == ((length - 1) * length) / 2:
        return True
    
    return False
