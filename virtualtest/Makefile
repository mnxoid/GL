all: help
c_release:
	gcc virtualtest.c util.c -o virtualtest
c_debug:
	gcc virtualtest.c util.c -o virtualtest -g
cpp_release:
	g++ virtualtest.cpp util.c -o virtualtest
cpp_debug:
	g++ virtualtest.cpp util.c -o virtualtest -g
wc_release:
	i586-mingw32msvc-gcc virtualtest.c util.c -o virtualtest.exe
wc_debug:
	i586-mingw32msvc-gcc virtualtest.c util.c -o virtualtest.exe -g
wcpp_release:
	i586-mingw32msvc-g++ virtualtest.cpp util.c -o virtualtest.exe
wcpp_debug:
	i586-mingw32msvc-g++ virtualtest.cpp util.c -o virtualtest.exe -g
debug:
	gdb ./virtualtest
run:
	./virtualtest
clear:
	rm ./virtualtest
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