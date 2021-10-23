import subprocess
import os

chmod = subprocess.run(["sudo", "chmod", "a+rw", "/dev/ttyACM0"])
"""ros = subprocess.run(["roscore"])
rosserial = subprocess.run(["rosrun", "rosserial_python", "serial_node.py", "_port:=/dev/ttyACM0", "_baud:=115200"])
main = subprocess.run(["rosrun", "lolkek", "printHello"])"""
