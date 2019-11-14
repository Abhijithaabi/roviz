import aiml
import sys
import os
from gtts import gTTS
import time 
import azure.cognitiveservices.speech as speechsdk
speech_key, service_region = "201bc1811d45427c967c3b5efa4907f4", "centralindia"
speech_config = speechsdk.SpeechConfig(subscription=speech_key, region=service_region)
def chat():
	while True:
		speech_recognizer = speechsdk.SpeechRecognizer(speech_config=speech_config)
		try:
			result = speech_recognizer.recognize_once()
			text=format(result.text)
			if text=='Bye.':
				welcometext = 'okay bye have a nice meal'
				language = 'en'
				myobj = gTTS(text=welcometext, lang=language, slow=False) 
	 
				myobj.save("welcome.mp3") 

				os.system("mpg321 welcome.mp3") 
				time.sleep(1)
				sys.exit()

			mytext = mybot.respond(text)
			language='en'
			myobj = gTTS(text=mytext, lang=language, slow=False) 

			myobj.save("welcome.mp3") 

			os.system("mpg321 welcome.mp3") 
			time.sleep(1)
		except result.reason == speechsdk.ResultReason.NoMatch:
			print("No speech could be recognized: {}".format(result.no_match_details))

os.chdir('/home/jocker/bot/aiml')

# Create the kernel and learn AIML files
mybot = aiml.Kernel()
mybot.learn("std-startup.xml")
mybot.respond("load aiml b")

while True:
	speech_recognizer = speechsdk.SpeechRecognizer(speech_config=speech_config)
	print("Say HI")
	try:

		result = speech_recognizer.recognize_once()
		robotext=format(result.text)
		if robotext == 'Hi.':
				welcometext = 'hi iam roviz. what can i do for you '

				language = 'en'
				myobj = gTTS(text=welcometext, lang=language, slow=False) 
	 
				myobj.save("welcome.mp3") 

				os.system("mpg321 welcome.mp3") 
				time.sleep(1)
				chat()
		elif robotext=='Bye.':
				welcometext = 'okay bye have a nice meal'
				language = 'en'
				myobj = gTTS(text=welcometext, lang=language, slow=False) 
	 
				myobj.save("welcome.mp3") 

				os.system("mpg321 welcome.mp3") 
				time.sleep(1)

		else:
				print('Sorry')
	except result.reason == speechsdk.ResultReason.NoMatch:
		print("No speech could be recognized: {}".format(result.no_match_details))
