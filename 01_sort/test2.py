import os
import random

def do_test(func_str, arg, res):
    cmd = func_str + " " + arg
    ret = os.popen(cmd).read().strip()
    if res != ret:
        print "Error case\n" + "case: " + arg
        print "res:  " + ret
        return -1
    return 0

MAX = 100
MIN = 0
# test 10000 times
TIMES = 10000
# we will input 'number_len', which is between 1 and MAX_NUMBER, numbers into the sort program
MAX_NUMBER = 10000

if __name__ == '__main__':
    func = "./count_sort"
    for i in range(TIMES):
        number_len = random.randint(1, MAX_NUMBER)
	# get input number array
        number = [random.randint(MIN, MAX) for i in range(number_len)]
	# get sorted input number array
        number_s = sorted(number)
	# exchange number to string, as input srting
        arg = ' '.join(str(n) for n in number)
	# exchange sorted number to string, as result
        res = ' '.join(str(n) for n in number_s)
	# do test
        ret = do_test(func, arg, res)
        if ret == -1:
            break
    if ret != -1:
        print "test success"
