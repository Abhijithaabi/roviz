import aiml
import sys
import os
from gtts import gTTS
import time 
import speech_recognition as sr 
def chat():
	while True:

	    r = sr.Recognizer() 
	    with sr.Microphone() as source:

	        
	        r.adjust_for_ambient_noise(source) 
	        print("Say Something")
	        #listens for the user's input 
	        audio = r.listen(source) 
	        try: 
	                text = r.recognize_google(audio) 
	                print(text)
	                mytext = mybot.respond(text)
	                language = 'en'
	                myobj = gTTS(text=mytext, lang=language, slow=False) 

	                myobj.save("welcome.mp3") 

	                os.system("mpg321 welcome.mp3") 
	                time.sleep(1)
	                

	                #error occurs when google could not understand what was said 

	        except sr.UnknownValueError: 
	                print("Google Speech Recognition could not understand audio") 

	        except sr.RequestError as e: 
	                print("Could not request results from Google Speech Recognition service; {0}".format(e)) 

os.chdir('/home/jocker/bot/aiml')

# Create the kernel and learn AIML files
mybot = aiml.Kernel()
mybot.learn("std-startup.xml")
mybot.respond("load aiml b")

while True:


	r = sr.Recognizer() 
	with sr.Microphone() as source:

	        
	    r.adjust_for_ambient_noise(source) 
	    print("Say HI ROBOT")
	    #listens for the user's input 
	    audio = r.listen(source) 
	    try: 
	        robotext = r.recognize_google(audio) 
	        if robotext == 'hi robot':
	            welcometext = 'hi iam roviz. what can i do for you '

	            language = 'en'
	            myobj = gTTS(text=welcometext, lang=language, slow=False) 
	 
	            myobj.save("welcome.mp3") 

	            os.system("mpg321 welcome.mp3") 
	            time.sleep(1)
	            chat()
	        else:
	            print('Sorry')
	    except sr.UnknownValueError: 
	        print("Google Speech Recognition could not understand audio") 

	    except sr.RequestError as e: 
	    	print("Could not request results from Google Speech Recognition service; {0}".format(e)) 



            