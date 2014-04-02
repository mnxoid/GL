all: help
c_release:
	gcc coins_3.c util.c -o coins_3
c_debug:
	gcc coins_3.c util.c -o coins_3 -g
cpp_release:
	g++ coins_3.cpp util.c -o coins_3
cpp_debug:
	g++ coins_3.cpp util.c -o coins_3 -g
wc_release:
	i586-mingw32msvc-gcc coins_3.c util.c -o coins_3.exe
wc_debug:
	i586-mingw32msvc-gcc coins_3.c util.c -o coins_3.exe -g
wcpp_release:
	i586-mingw32msvc-g++ coins_3.cpp util.c -o coins_3.exe
wcpp_debug:
	i586-mingw32msvc-g++ coins_3.cpp util.c -o coins_3.exe -g
debug:
	gdb ./coins_3
run:
	./coins_3
clear:
	rm ./coins_3
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