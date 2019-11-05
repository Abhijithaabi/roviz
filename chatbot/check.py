import aiml
import sys
import os

os.chdir('/home/jocker/bot/aiml')

# Create the kernel and learn AIML files
mybot = aiml.Kernel()
mybot.learn("std-startup.xml")
mybot.respond("load aiml b")

# Press CTRL-C to break this loop
while True:
    print(mybot.respond(input("Enter your message >> ")))