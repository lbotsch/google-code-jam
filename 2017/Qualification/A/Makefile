CC=g++
CFLAGS=--std=c++11
TARGET=A

SOURCE = A.cpp

all: small large
	@true

clean:
	@-rm -f $(TARGET) *.out

$(TARGET):
	@$(CC) $(CFLAGS) -o $@ $(SOURCE)

small: $(TARGET)
	@./$(TARGET) < $(TARGET)-small-practice.in > $(TARGET)-small-practice.out

large: $(TARGET)
	@./$(TARGET) < $(TARGET)-large-practice.in > $(TARGET)-large-practice.out
