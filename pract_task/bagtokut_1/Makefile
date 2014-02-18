all: help
c_release:
	gcc bagtokut_1.c -o bagtokut_1 -lm
c_debug:
	gcc bagtokut_1.c -o bagtokut_1 -g -lm
debug:
	gdb ./bagtokut_1
run:
	./bagtokut_1
clear:
	rm ./bagtokut_1
commit:
	git commit -a
	git push GL
help:
	@echo "Options:"
	@echo "	c_release"
	@echo "	c_gebug"
	@echo "	run"
	@echo "	debug"
	@echo "	clear"
	@echo "	commit"
	@echo "	help"