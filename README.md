# UE5_Seeder
Seeder control software



http://www.seeder.com/


![image](https://github.com/StormS0/UE5_Seeder/blob/main/UE.png)


If you use plug-ins, please refer to the following tcp instructions  
Example 1: MSG   p1c2   
If you click Ready, it means sending p1c20t.  
If you click Start, it means sending p1c21t.  















      ------杭州聚视通网络技术有限公司版权所有V1.5
seeder软件场景远程控制协议
一、协议类型：TCP/IP 网络协议连接
远端：client （外部控制设备）
本地：server （seeder机器人设备）
绑定端口：默认（5000）在seeder软件界面可调  
注：不同的机器人设备对应不同的端口
二、协议规则
1、保持心跳  
作用：判断双方是否处于连接状态。
内容：往返发送”Heart\r\n”字符保持心跳，机器人设备默认发送字符’Heart\r\n’。

2、数据格式
数据包：  p<参数一>c<参数二>t<参数三>\r\n     (ASCII)  
说明：数据包以'p'开头， 回车符（‘\r’）和换行符（‘\n’）结尾，以字符’p’ 、‘c’、’t’为参数的间隔。
<参数一>：表示节目号 范围：1-32  (ASCII)
<参数二>：表示序列号 范围：10，11    20，21 .....160,161 (ASCII)
<参数三>：预留指令，可根据客户需求定制。
例1：p1c10t  表示启动节目1的第1个序列的起点。其中c10中的10的第一位1表示序列号，0表示序列起点。
例2：p1c21t  表示启动节目1的第2个序列的轨迹。其中c21中的21的第一位2表示序列号，1表示序列轨迹运动。
例3：p3c71t  表示启动节目3的第7个序列的轨迹。  
特殊开关指令： p1c200t 代表停止。
                   P1c201t 代表回零。
3、数据应答
如数据包正确： 回复 “Good\r\n”.   Good表示数据正确。
      如数据包错误： 回复 “Error\r\n”.  Error表示格式错误或数据范围超出。
      运 动  开 始：  回复 t（时间）s\r\n表示运动时间。
      运 动  结 束：  回复 “p（节目）c（序列）end\r\n”表示运动结束。
      例1：t10.5s   表示序列开始运动，预计时间10.5秒。
      例2：p3c71end  表示启动节目3的第7个序列的轨迹运动结束。
常见错误格式：
例1：p1c2\r\n    忘记写t属于错误。
例2：P42C2T\r\n  参数一的范围超出。
例3：p1sqc2it\r\n 数据中存在其他未定义字符也会返回错误。
4、数据间隔
数据包发送间隔是大约25毫秒到3秒，这种类型的通信不需要大量的带宽，但需要低延迟。控制卡默认判断掉线时间间隔10秒。
5、机位号确认
机位号由TCP/IP绑定的端口号来决定，不同的端口号对应不同的机位，每台机器人设备都可以设置唯一的端口号。



EN:
------Hangzhou jushitong Network Technology Co., Ltd. copyright v1.5
Remote control protocol of seeder software scene
1、 Protocol type: TCP / IP network protocol connection
Remote: client (external control device)
Local: server (seeder robot)
Binding port: default (5000) adjustable in the seeder software interface
Note: different robot devices correspond to different ports
2、 Agreement rules
1. Keep your heart beating
Function: judge whether the two parties are connected.
Content: send the "heart \ R \ n" character back and forth to keep the heartbeat. The robot device sends the character 'heart \ R \ n' by default.
2. Data format:
Packet: P < parameter 1 > C < parameter 2 > T < parameter 3 > \ R \ n (ASCII)
Description: the data packet starts with 'p', ends with a carriage return character ('\ R') and a line feed character ('\ n'), and takes the characters' p ',' C 'and't' as the parameter intervals.
< parameter 1 >: indicates the program number range: 1-32 (ASCII)
< parameter 2 >: indicates the range of serial number: 10, 11, 20, 21..... 160161 (ASCII)
< parameter 3 >: reservation command, which can be customized according to customer needs.
Example 1: p1c10t represents the to start the starting point of the first sequence of program 1. Where the first bit 1 of 10 in C10 represents the sequence number and 0 represents the sequence starting point.
Example 2: p1c21t represents to start the trajectory of the second sequence of program 1. Where the first digit 2 of 21 in C21 represents the sequence number and 1 represents the sequence trajectory motion.
Example 3: p3c71t represents to start the trajectory of the seventh sequence of the program 3.
Special switch command: p1c200t represents stop.
P1c201t represents return to zero.
3. Data response
If the data packet is correct, reply "good \ R \ n" Good indicates that the data is correct.
If the packet is wrong, reply "error \ R \ n" Error indicates format error or data range is out of range.
Exercise start: reply t (time) s \ R \ n indicates exercise time.
End of movement: Reply "P (program) C (sequence) end \ R \ n" to indicate the end of movement.
Example 1: t10.5s indicates that the sequence starts to move, and the estimated time is 10.5s.
Example 2: p3c71end indicates the end of the trajectory movement of the seventh sequence of the start program 3.
Common error format:
Example 1: p1c2 \ R \ n forgetting to write “t” is an error.
Example 2: p42c2t \ R \ n the range of parameter 1 is out of range.
Example 3: p1sqc2it \ R \ n an error will also be returned if there are other undefined characters in the data.
4. Data interval
The packet transmission interval is about 25 milliseconds to 3 seconds. This type of communication does not require a large amount of bandwidth, but requires low latency. By default, the control card judges that the time interval for disconnection is 10 seconds.
5. Confirmation of machine position number
The slot number is determined by the port number bound by TCP / IP. Different port numbers correspond to different slots. Each robot device can set a unique port number.
