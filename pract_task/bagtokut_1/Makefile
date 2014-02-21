all: help
c_release:
	gcc bagtokut_1.c -o bagtokut_1
c_debug:
	gcc bagtokut_1.c -o bagtokut_1 -g
cpp_release:
	g++ bagtokut_1.cpp -o bagtokut_1
cpp_debug:
	g++ bagtokut_1.cpp -o bagtokut_1 -g
wc_release:
	i586-mingw32msvc-gcc bagtokut_1.c -o bagtokut_1.exe
wc_debug:
	i586-mingw32msvc-gcc bagtokut_1.c -o bagtokut_1.exe -g
wcpp_release:
	i586-mingw32msvc-g++ bagtokut_1.cpp -o bagtokut_1.exe
wcpp_debug:
	i586-mingw32msvc-g++ bagtokut_1.cpp -o bagtokut_1.exe -g
debug:
	gdb ./bagtokut_1
run:
	./bagtokut_1
clear:
	rm ./bagtokut_1
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