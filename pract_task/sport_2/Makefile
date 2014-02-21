all: help
c_release:
	gcc sport_2.c -o sport_2
c_debug:
	gcc sport_2.c -o sport_2 -g
wc_release:
	i586-mingw32msvc-gcc sport_2.c -o sport_2.exe
wc_debug:
	i586-mingw32msvc-gcc sport_2.c -o sport_2.exe -g
debug:
	gdb ./sport_2
run:
	./sport_2
clear:
	rm ./sport_2
commit:
	git commit -a
	git push GL
help:
	@echo "Options:"
	@echo "	c_release"
	@echo "	c_debug"
	@echo "	wc_release"
	@echo "	wc_debug"
	@echo "	run"
	@echo "	debug"
	@echo "	clear"
	@echo "	commit"
	@echo "	help"