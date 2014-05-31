all: help
c_release:
	gcc life.c util.c -o life
c_debug:
	gcc life.c util.c -o life -g
cpp_release:
	g++ life.cpp util.c -o life  -lGL -lglut
cpp_debug:
	g++ life.cpp util.c -o life -g -lGL -lglut
wc_release:
	i586-mingw32msvc-gcc life.c util.c -o life.exe
wc_debug:
	i586-mingw32msvc-gcc life.c util.c -o life.exe -g
wcpp_release:
	i586-mingw32msvc-g++ life.cpp util.c -o life.exe
wcpp_debug:
	i586-mingw32msvc-g++ life.cpp util.c -o life.exe -g
debug:
	gdb ./life
run:
	./life
clear:
	rm ./life
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
