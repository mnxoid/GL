all: help
c_release:
	gcc onetoten.c -o onetoten
c_debug:
	gcc onetoten.c -o onetoten -g
cpp_release:
	g++ onetoten.cpp -o onetoten
cpp_debug:
	g++ onetoten.cpp -o onetoten -g
wc_release:
	i586-mingw32msvc-gcc onetoten.c -o onetoten.exe
wc_debug:
	i586-mingw32msvc-gcc onetoten.c -o onetoten.exe -g
wcpp_release:
	i586-mingw32msvc-g++ onetoten.c -o onetoten.exe
wcpp_debug:
	i586-mingw32msvc-g++ onetoten.c -o onetoten.exe -g
debug:
	gdb ./onetoten
run:
	./onetoten
clear:
	rm ./onetoten
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