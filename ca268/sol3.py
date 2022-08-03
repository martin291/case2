#
#   Return an empty list to get your list of binary numbers.
#
#   Then return a list of strings representing the binary numbers in the correct positions
#
def sol():
    return ["0000", "1001", "1100", "1101", "0110", "0111"]
    # 1001, 0000, 1100, 0111, 1101, 0110
    # first pass: 0000, 1100, 0110, 1001, 0111, 1101
    # second pass: 0000, 1100, 1001, 1101, 0110, 0111
    # third pass: 0000, 1001, 1100, 1101, 0110, 0111
