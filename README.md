# **Set up time synchronization server** 


[//]: # (Image References)

[screenshot]: ./screenshot/screenshot.JPG


1. Pull source code from git using command:
```console
	foo@bar:~ $ git clone git://github.com/JiangboYu13/TimeSynLinux.git
```
2. Go to directory /TimeSynLinux
```console
	foo@bar:~ $ cd /TimeSynLinux
```
3. Make a new directory called build and go into using command:
```console
	foo@bar:~/TimeSynLinux $ mkdir build && cd build
```
4. build from source using follow command:
```console
	foo@bar:~/TimeSynLinux/build $cmake .. && make
```
4. go into file bin using command:
```console
	foo@bar:~/TimeSynLinux/build $ cd ../bin
```
5. run time synchronization server using command:
```console
	foo@bar:~/TimeSynLinux/bin $ ./TimeSync server 5001
```

![screenshot][screenshot]
	

