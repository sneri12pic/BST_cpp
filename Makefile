all: run_test run_replace clean_obj_o

run_test:
	cl /EHsc BSTtest.cpp BST.cpp
	BSTTest.exe

run_replace:
	cl /EHsc replace.cpp BST.cpp
	replace.exe test1.c
	replace.exe test2.c

clean:
	del *.obj
	del *.exe
	del *.o

clean_obj_o:
	del *.obj
