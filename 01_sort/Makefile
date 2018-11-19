SRC_DIR = ./src/

insert:
	gcc $(SRC_DIR)main.c $(SRC_DIR)insert_sort.c -o sort
heap:
	gcc $(SRC_DIR)main.c $(SRC_DIR)heap_sort.c -o sort
fast:
	gcc $(SRC_DIR)main.c $(SRC_DIR)fast_sort.c -o sort
merge:
	gcc $(SRC_DIR)main.c $(SRC_DIR)merge_sort.c -o sort
count:
	gcc $(SRC_DIR)main.c $(SRC_DIR)count_sort.c -o count_sort
test1:
	python test1.py > res
test2:
	python test2.py > res
clear:
	@rm sort count_sort randix_sort res
who:
	@echo "insert: insert sort"
	@echo "heap: heap sort"
	@echo "fast: fast sort"
	@echo "merge: merge sort"
	@echo "test1: run the test script to test insert, heap, fast, merge sort"
	@echo "test2: run the test script to test count-sort"
	@echo "clear: clean exe-file"
