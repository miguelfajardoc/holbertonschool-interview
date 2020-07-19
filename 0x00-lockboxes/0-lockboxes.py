#!/usr/bin/python3
""" can unlock all boxes?? """


def canUnlockAll(boxes):
    """ can unlock all boxes?? """

    BoxKeys = {0: False}
    keys = set()
    keys.add(0)

    length = len(boxes)
    attemps = 3
    
    while (attemps):
        for boxIndex in range(len(boxes)):
            if boxIndex in keys:
                BoxKeys[boxIndex] = True
                for newKey in boxes[boxIndex]:
                    keys.add(newKey)
            else:
                BoxKeys[boxIndex] = False
                    
        if sum(keys) == ((length - 1) * length ) / 2 :
              return True
        attemps -= 1
    return False
            
    
