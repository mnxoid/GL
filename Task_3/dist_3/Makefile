all: help
c_release:
	gcc dist_3.c -o dist_3
c_debug:
	gcc dist_3.c -o dist_3 -g
cpp_release:
	g++ dist_3.cpp -o dist_3
cpp_debug:
	g++ dist_3.cpp -o dist_3 -g
wc_release:
	i586-mingw32msvc-gcc dist_3.c -o dist_3.exe
wc_debug:
	i586-mingw32msvc-gcc dist_3.c -o dist_3.exe -g
wcpp_release:
	i586-mingw32msvc-g++ dist_3.cpp -o dist_3.exe
wcpp_debug:
	i586-mingw32msvc-g++ dist_3.cpp -o dist_3.exe -g
debug:
	gdb ./dist_3
run:
	./dist_3
clear:
	rm ./dist_3
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