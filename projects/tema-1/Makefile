# Exemplu de Makefile pentru soluții scrise în C++.

CC = g++
CCFLAGS = -Wall -Wextra -std=c++17 -O0 -lm

.PHONY: build clean

build: feribot nostory sushi semnale badgpt 

run-p1:
	./feribot
run-p2:
	./nostory
run-p3:
	./sushi
run-p4:
	./semnale
run-p5:
	./badgpt

# Nu uitați să modificați numele surselor și, eventual, ale executabilelor.
p1: feribot.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p2: nostory.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p3: sushi.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p4: semnale.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p5: badgpt.cpp
	$(CC) -o $@ $^ $(CCFLAGS)

# Vom șterge executabilele.
clean:
	rm -f feribot nostory sushi semnale badgpt
