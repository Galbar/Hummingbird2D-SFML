OUT    := lib/libhum2d-sfml
CC     := g++
CFLAGS := -std=c++11 -Wall -fpic -O3
ODIR   := obj
LDIR   := lib
LIBS   := -L../Hum2D/lib/ -lhum2d -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
SDIR   := src/Hum2D/SFML
INC    := -I../Hum2D/include -Iinclude/Hum2D/SFML

SOURCES = $(shell find ./$(SDIR) -name '*.cpp')
OBJS = $(patsubst $(SDIR)/%,$(ODIR)/%,$(SOURCES:./%.cpp=%.o))

all: static shared

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) -c $(INC) -o $@ $< $(CFLAGS) $(LIBS)

static: $(OBJS)
	ar rvs $(OUT).a $^

shared: $(OBJS)
	$(CC) -o $(OUT).so $(ODIR)/*.o $(CFLAGS) -shared $(INC) $(LIBS)

.PHONY: clean

clean:
	rm -rf $(ODIR)/*.o $(OUT).a $(OUT).so
