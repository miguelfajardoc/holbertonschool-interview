#!/usr/bin/python3
'''
Script for log parsing
'''
import sys


if __name__ == "__main__":
    a = []
    codes = ["200", "301", "400", "401", "403", "404", "405", "500"]
    dictio = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0, "404": 0,
              "405": 0, "500": 0}
    i = 0
    file_size = 0
    try:
        for lines in sys.stdin:
            i += 1
            a = lines.split(" ")
            if len(a) > 2:
                file_size += int(a[-1])
                if a[-2] in codes:
                    dictio[a[-2]] += 1
            if i % 10 == 0:
                print("File size: {}".format(file_size))
                for code in codes:
                    if dictio[code] > 0:
                        print("{}: {}".format(code, dictio[code]))
    except Exception:
        pass
    finally:
        print("File size: {}".format(file_size))
        for code in codes:
            if dictio[code] > 0:
                print("{}: {}".format(code, dictio[code]))
