import os
import random

def do_test(func_str, arg, res):
    cmd = func_str + " " + arg
    ret = os.popen(cmd).read().strip()
    if res != ret:
        print "Error case\n" + "case: " + arg
        print "res:  " + res
        print "get:  " + ret
        return -1
    return 0

MAX = 10000
MIN = -10000
SUM_MIN = -2147483648
# test 10000 times
TIMES = 1000
# we will input 'number_len', which is between 1 and MAX_NUMBER, numbers into the sort program
MAX_NUMBER = 100

if __name__ == '__main__':
    func = "./max_subarray"
    for i in range(TIMES):
        number_len = random.randint(1, MAX_NUMBER)
	# get input number array
        number = [random.randint(MIN, MAX) for i in range(number_len)]
	# get sorted input number array
        array_sum = SUM_MIN
        for i in range(0, number_len):
            for j in range(i, number_len):
                tmp = 0
                for k in range(i, j + 1):
                    tmp = tmp + number[k]
                if tmp > array_sum:
                    array_sum = tmp
                    left = i
                    right = j
        # exchange number to string, as input srting
        arg = ' '.join(str(n) for n in number)
	# exchange sorted number to string, as result
        res = str(array_sum)
	# do test
        ret = do_test(func, arg, res)
        if ret == -1:
            break
    if ret != -1:
        print "test success"
