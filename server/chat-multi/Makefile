CC = g++ $(STD)
STD = -std=c++11
LIBS = -pthread
IDIR = includes
SDIR = src
BDIR = .
OBJDIR = ./build
DEPS = $(OBJDIR)/http_session.o  $(OBJDIR)/listener.o $(OBJDIR)/shared_state.o $(OBJDIR)/websocket_session.o
TARGET = $(BDIR)/websocket-chat-multi

.PHONY: clean run

$(TARGET): $(DEPS) $(OBJDIR)/main.o
	$(CC) -o $@ $^ $(LIBS)

$(OBJDIR)/shared_state.o: $(SDIR)/shared_state.cpp $(IDIR)/shared_state.hpp
	$(CC) -c -o $@ $<

$(OBJDIR)/http_session.o: $(SDIR)/http_session.cpp $(IDIR)/http_session.hpp $(IDIR)/net.hpp $(IDIR)/beast.hpp $(IDIR)/shared_state.hpp
	$(CC) -c -o $@ $<

$(OBJDIR)/websocket_session.o:$(SDIR)/websocket_session.cpp $(IDIR)/websocket_session.hpp $(IDIR)/net.hpp $(IDIR)/beast.hpp $(IDIR)/shared_state.hpp
	$(CC) -c -o $@ $<

$(OBJDIR)/listener.o: $(SDIR)/listener.cpp $(IDIR)/listener.hpp $(IDIR)/net.hpp $(IDIR)/beast.hpp
	$(CC) -c -o $@ $<

$(OBJDIR)/main.o: $(SDIR)/main.cpp $(IDIR)/listener.hpp $(IDIR)/shared_state.hpp
	$(CC) -c -o $@ $<

clean:
	@echo "Cleaning up..."
	rm -f $(TARGET)
	rm -f $(OBJDIR)/*.o

run:
	$(TARGET) 0.0.0.0 6785 . 5