all: help
c_release:
	gcc auto_4.c -o auto_4
c_debug:
	gcc auto_4.c -o auto_4 -g
#cpp_release:
	#g++ auto_4.cpp -o auto_4
#cpp_debug:
	#g++ auto_4.cpp -o auto_4 -g
wc_release:
	i586-mingw32msvc-gcc auto_4.c -o auto_4.exe
wc_debug:
	i586-mingw32msvc-gcc auto_4.c -o auto_4.exe -g
#wcpp_release:
	#i586-mingw32msvc-g++ auto_4.cpp -o auto_4.exe
#wcpp_debug:
	#i586-mingw32msvc-g++ auto_4.cpp -o auto_4.exe -g
debug:
	gdb ./auto_4
run:
	./auto_4
clear:
	rm ./auto_4
commit:
	git commit -a
	git push GL
help:
	@echo "Options:"
	@echo "	c_release"
	#@echo "	cpp_release"
	@echo "	c_debug"
	#@echo "	cpp_debug"
	@echo "	wc_release"
	@echo "	wc_debug"
	#@echo "	wcpp_release"
	#@echo "	wcpp_debug"
	@echo "	run"
	@echo "	debug"
	@echo "	clear"
	@echo "	commit"
	@echo "	help"