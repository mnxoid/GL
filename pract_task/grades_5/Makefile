all: help
c_release:
	gcc grades_5.c -o grades_5
c_debug:
	gcc grades_5.c -o grades_5 -g
#cpp_release:
	#g++ grades_5.cpp -o grades_5
#cpp_debug:
	#g++ grades_5.cpp -o grades_5 -g
wc_release:
	i586-mingw32msvc-gcc grades_5.c -o grades_5.exe
wc_debug:
	i586-mingw32msvc-gcc grades_5.c -o grades_5.exe -g
#wcpp_release:
	#i586-mingw32msvc-g++ grades_5.cpp -o grades_5.exe
#wcpp_debug:
	#i586-mingw32msvc-g++ grades_5.cpp -o grades_5.exe -g
debug:
	gdb ./grades_5
run:
	./grades_5
clear:
	rm ./grades_5
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