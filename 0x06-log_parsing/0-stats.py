#!/usr/bin/python3
""" module that do stats """

import sys
import signal


def main():
    file_size = 0
    status_code_dict = {}
    possible_status_code = [200, 301, 400, 401, 403, 404, 405, 500]
    counter = 0
    try:
        for line in sys.stdin:
            if counter != 10:
                data = line.split()
                if len(data) >= 2:
                    file_size += (int)(data[-1])
                    add_status_code_to_dict((int)(data[-2]), status_code_dict)
                    counter += 1
            else:
                print_logs(file_size, status_code_dict, possible_status_code)
                counter = 0
    except KeyboardInterrupt:
        pass
    finally:
        print_logs(file_size, status_code_dict, possible_status_code)


def add_status_code_to_dict(status_code, status_code_dict):

    if status_code in status_code_dict:
        status_code_dict[status_code] += 1
    else:
        status_code_dict[status_code] = 1


def print_logs(file_size, status_codes, status_posibilities):

    print("File size: {}".format(file_size))
    for status in status_posibilities:
        if status in status_codes:
            print("{}: {}".format(status, status_codes[status]))


if __name__ == '__main__':
    main()
