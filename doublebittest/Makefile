all: help
c_release:
	gcc doublebittest.c -o doublebittest
c_debug:
	gcc doublebittest.c -o doublebittest -g
cpp_release:
	g++ doublebittest.cpp -o doublebittest
cpp_debug:
	g++ doublebittest.cpp -o doublebittest -g
wc_release:
	i586-mingw32msvc-gcc doublebittest.c -o doublebittest.exe
wc_debug:
	i586-mingw32msvc-gcc doublebittest.c -o doublebittest.exe -g
wcpp_release:
	i586-mingw32msvc-g++ doublebittest.cpp -o doublebittest.exe
wcpp_debug:
	i586-mingw32msvc-g++ doublebittest.cpp -o doublebittest.exe -g
debug:
	gdb ./doublebittest
run:
	./doublebittest
clear:
	rm ./doublebittest
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