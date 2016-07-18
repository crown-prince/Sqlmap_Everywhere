#Sqlmap_Everywhere
项目概述：最新版本（1.0.7.25#dev）的无需Python环境的Sqlmap 及未来如何制作属于自己的、最新的、无需Python环境的Sqlmap的方法介绍
<br>
Sqlmap项目地址：https://github.com/sqlmapproject/sqlmap

----
###　　　　　　　　　　　　Coder:crown prince
###　　　　　　　　　 E-mail:crownprince@windpunish.net

===========================
##前言：

###这份项目实现了什么？
笔者在近日编写一款提取POST SQL注入的数据包的程序时，需要通过一些案例，验证数据包的可行性，而sqlmap是便捷及准确的方式，但由于sqlmap目前仅支持Python 2.x，笔者自己对Python 3的许多语法特性十分偏爱，于是不希望在本机上同时载有Python 2.x及Python 3.x，在虚拟机中使用Python  2.7又有一些不便，笔者便希望能制作一款无需Python环境，直接为可执行程序的Sqlmap，但在制作中发现，仅使用相关转换工具(py2exe)并不足以实现我们的目标，且网络上相关的资源极少，目前最新的Sqlmap免Python版也是几月前的了<br>
而在复杂的渗透测试环境中，或许，一款免Python环境的Sqlmap，会成为工具包中的利刃。于是，在不断地探索中，笔者找到了打造无需Python环境的Sqlmap的方法，希望将程序及经验分享出来 ：） 欢迎小伙伴们一起交流

###github布局：
`1.Release部分`：<br>
  在Release部分，小伙伴们可以直接下载后，同时和已编译好的run.exe放置在一起（run.exe与Bin文件夹放在一起，请勿放置于其中），直接运行run.exe
即可按照习惯的方式，使用sqlmap.exe
<br>
`2.Source部分：`<br>
  在Source部分，包括了程序的所有源码，主要体现的是：https://github.com/crown-prince/Sqlmap_Everywhere/blob/master/Source/run.cpp
run.exe的源码，这是联系sqlmap与使用者的桥梁

###程序截图：
1.运行截图：
![](https://github.com/crown-prince/Sqlmap_Everywhere/blob/master/%E7%A8%8B%E5%BA%8F%E6%88%AA%E5%9B%BE/1.png)

##受以渔：
sqlmap在不断的更新中，笔者希望通过将制作方法公开的方式，帮助更多小伙伴们，打造出属于自己的、最新的、无需Python环境的Sqlmap

制作方法：<br>
* 1.安装py2exe <br><br>
* 2.下载最新版本的sqlmap <br><br>
![](https://github.com/crown-prince/Sqlmap_Everywhere/blob/master/%E7%A8%8B%E5%BA%8F%E6%88%AA%E5%9B%BE/2.png)
<br><br>
* 3.在sqlmap文件夹下建立setup.py（转换sqlmap中的py文件）和make.bat（方便执行转换命令）<br>
setup.py:     https://github.com/crown-prince/Sqlmap_Everywhere/blob/master/Source/Bin/setup.py<br>
make.bat:   https://github.com/crown-prince/Sqlmap_Everywhere/blob/master/Source/Bin/make.bat<br><br>
![](https://github.com/crown-prince/Sqlmap_Everywhere/blob/master/%E7%A8%8B%E5%BA%8F%E6%88%AA%E5%9B%BE/3.png)
<br><br>
* 4.运行，make.bat键入setup.py  py2exe
<br>
![](https://github.com/crown-prince/Sqlmap_Everywhere/blob/master/%E7%A8%8B%E5%BA%8F%E6%88%AA%E5%9B%BE/4.png)
<br>
完成后，当前文件夹下，会出现一个dist和build文件夹,此时，py2exe已经将sqlmap的py文件转换为可执行程序，但运行dist中的sqlmap.exe，确是失败的
<br>
根据经验笔者推测如下：<br>
A.py2exe的转换存在文件缺失的情况<br>
B.我们在使用sqlmap时，是通过诸如python sqlmap.y -u等命令操作sqlmap的，但，转换成exe的sqlmap该如何接收指令？<br>
针对以上问题，以下为笔者的解决办法<br><br>
* 5.在sqlmap源码文件夹外，新建一个Bin文件夹<br>
将dist文件夹中全部文件，及一个新的sqlmap源文件（只原生的，这一步具体导入哪些，因为项目的时间关系，笔者可能需要暂时搁浅，小伙伴们可以一起讨论下哈）全部导入Bin中<br>
![](https://github.com/crown-prince/Sqlmap_Everywhere/blob/master/%E7%A8%8B%E5%BA%8F%E6%88%AA%E5%9B%BE/5.png)<br><br>
* 6.接下来，笔者用C++制作了一个run.exe，以此实现sqlmap.exe与使用者的交互<br><br>
https://github.com/crown-prince/Sqlmap_Everywhere/blob/master/Source/run.cpp<br>
![](https://github.com/crown-prince/Sqlmap_Everywhere/blob/master/%E7%A8%8B%E5%BA%8F%E6%88%AA%E5%9B%BE/6.png) <br><br>
* 7.将run.cpp进行编译，之后，将run.exe与Bin文件夹放在一起（请勿放置于其中）直接运行run.exe，即可按照习惯的方式，使用sqlmap.exe <br>
![](https://github.com/crown-prince/Sqlmap_Everywhere/blob/master/%E7%A8%8B%E5%BA%8F%E6%88%AA%E5%9B%BE/7.png) <br><br>
===========================
![](https://github.com/crown-prince/Sqlmap_Everywhere/blob/master/%E7%A8%8B%E5%BA%8F%E6%88%AA%E5%9B%BE/8.png) <br><br>

至此，一款最新版本（1.0.7.25#dev）的无需Python环境的Sqlmap，打造完成 <br><br>


##意见与建议：

----

欢迎大家在使用过程中提出各种宝贵的意见和建议，以及各种bug，不胜感激

反馈邮箱crownprince@windpunish.net

