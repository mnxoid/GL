all: help
c_release:
	gcc sport_2.c -o sport_2
c_debug:
	gcc sport_2.c -o sport_2 -g
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
	@echo "	run"
	@echo "	debug"
	@echo "	clear"
	@echo "	commit"
	@echo "	help"