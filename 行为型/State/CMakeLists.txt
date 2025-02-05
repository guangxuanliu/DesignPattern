set(SRC main.cpp 
        TCPConnection.cpp TCPOctetStream.cpp
        TCPState.cpp TCPClose.cpp TCPEstablished.cpp TCPListen.cpp )

add_executable(State ${SRC})