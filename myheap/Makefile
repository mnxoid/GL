all: help
c_release:
	gcc myheap.c util.c -o myheap
c_debug:
	gcc myheap.c util.c -o myheap -g
cpp_release:
	g++ myheap.cpp util.c -o myheap
cpp_debug:
	g++ myheap.cpp util.c -o myheap -g
wc_release:
	i586-mingw32msvc-gcc myheap.c util.c -o myheap.exe
wc_debug:
	i586-mingw32msvc-gcc myheap.c util.c -o myheap.exe -g
wcpp_release:
	i586-mingw32msvc-g++ myheap.cpp util.c -o myheap.exe
wcpp_debug:
	i586-mingw32msvc-g++ myheap.cpp util.c -o myheap.exe -g
debug:
	gdb ./myheap
run:
	./myheap
clear:
	rm ./myheap
commit:
	git commit -a
	git push GL
help:
	@echo "Options:"
	@echo "	c_release"
	@echo "	cpp_release"
	@echo "	c_debug"
	@echo "	cpp_debug"
	@echo "	wc_release"
	@echo "	wc_debug"
	@echo "	wcpp_release"
	@echo "	wcpp_debug"
	@echo "	run"
	@echo "	debug"
	@echo "	clear"
	@echo "	commit"
	@echo "	help"