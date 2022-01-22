# created with boroveen/automake

all: cookie

cookie:
	mkdir ~/.config/cookie
	touch ~/.config/cookie/cookie.txt
	g++ main.cpp -o cookie

install:
	sudo cp cookie /bin

uninstall:
	sudo rm /bin/cookie

.PHONKY: all cookie install uninstall
