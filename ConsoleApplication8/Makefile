OUTPUT = test_BookRecord

.PHONY: all
all: test

.PHONY: compile
compile: $(OUTPUT)

$(OUTPUT): *.cpp *.h
	@g++ -g -o $(OUTPUT) *.cpp *.h

.PHONY: test
test: compile
	@./$(OUTPUT)

.PHONY: clean
clean:
	@rm $(OUTPUT)
