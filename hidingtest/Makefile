all: help
c_release:
	gcc hidingtest.c -o hidingtest
c_debug:
	gcc hidingtest.c -o hidingtest -g
cpp_release:
	g++ hidingtest.cpp -o hidingtest
cpp_debug:
	g++ hidingtest.cpp -o hidingtest -g
wc_release:
	i586-mingw32msvc-gcc hidingtest.c -o hidingtest.exe
wc_debug:
	i586-mingw32msvc-gcc hidingtest.c -o hidingtest.exe -g
wcpp_release:
	i586-mingw32msvc-g++ hidingtest.cpp -o hidingtest.exe
wcpp_debug:
	i586-mingw32msvc-g++ hidingtest.cpp -o hidingtest.exe -g
debug:
	gdb ./hidingtest
run:
	./hidingtest
clear:
	rm ./hidingtest
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