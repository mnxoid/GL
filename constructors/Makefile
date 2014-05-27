all: help
c_release:
	gcc constructors.c util.c -o constructors
c_debug:
	gcc constructors.c util.c -o constructors -g
cpp_release:
	g++ constructors.cpp util.c -o constructors -std=c++11
cpp_debug:
	g++ constructors.cpp util.c -o constructors -g -std=c++11
wc_release:
	i586-mingw32msvc-gcc constructors.c util.c -o constructors.exe
wc_debug:
	i586-mingw32msvc-gcc constructors.c util.c -o constructors.exe -g
wcpp_release:
	i586-mingw32msvc-g++ constructors.cpp util.c -o constructors.exe -std=c++11
wcpp_debug:
	i586-mingw32msvc-g++ constructors.cpp util.c -o constructors.exe -g -std=c++11
debug:
	gdb ./constructors
run:
	./constructors
clear:
	rm ./constructors
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
