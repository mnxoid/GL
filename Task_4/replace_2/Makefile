all: help
c_release:
	gcc replace_2.c util.c -o replace_2
c_debug:
	gcc replace_2.c util.c -o replace_2 -g
cpp_release:
	g++ replace_2.cpp util.c -o replace_2
cpp_debug:
	g++ replace_2.cpp util.c -o replace_2 -g
wc_release:
	i586-mingw32msvc-gcc replace_2.c util.c -o replace_2.exe
wc_debug:
	i586-mingw32msvc-gcc replace_2.c util.c -o replace_2.exe -g
wcpp_release:
	i586-mingw32msvc-g++ replace_2.cpp util.c -o replace_2.exe
wcpp_debug:
	i586-mingw32msvc-g++ replace_2.cpp util.c -o replace_2.exe -g
debug:
	gdb ./replace_2
run:
	./replace_2
clear:
	rm ./replace_2
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