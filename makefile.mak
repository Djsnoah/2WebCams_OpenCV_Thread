OBJS = 2Webcams.o  
CC = x86_64-w64-mingw32-c++.exe 
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) 
LFLAGS = -Wall $(DEBUG)\
		 -Ld:/Test/OpenCV_Include_Lib_x64/x64/mingw/bin
IFLAGS = -Id:/Test/OpenCV_Include_Lib_x64/include
		
LIBS = -llibopencv_highgui401 -llibopencv_core401 -llibopencv_imgcodecs401 -llibopencv_imgproc401 \
	   -llibopencv_videoio401 

p1: $(OBJS)
	$(CC) $(LFLAGS) $(LIBS) $(OBJS) -o p1

2Webcams.o: 2Webcams.cpp
	$(CC) $(CFLAGS) $(IFLAGS) 2Webcams.cpp
	
	
