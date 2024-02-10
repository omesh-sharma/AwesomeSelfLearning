# connect python with webbrowser-chrome
from selenium import webdriver
from selenium.webdriver.common.keys import Keys

from selenium.webdriver.common.by import By
import pyautogui as pag


def login(driver):

	# Getting the login element
	username = driver.find_element(By.ID,"session_key")

	# Sending the keys for username	
	username.send_keys("sharmaomesh0@gmail.com")

	# Getting the password element								
	password = driver.find_element(By.ID,"session_password")

	# Sending the keys for password
	password.send_keys("Saurav1@3sa")	

	# Getting the tag for submit button					
	driver.find_element("login-submit").click()		

def goto_network():
	driver.find_element_by_id("mynetwork-tab-icon").click()

def send_requests():

	# Number of requests you want to send
	n = input("Number of requests: ")

	for i in range(0, n):
		# position(in px) of connection button
		pag.click(880, 770)
	print("Done !")

def main():

	# url of LinkedIn
	url = "http://linkedin.com/"

	# url of LinkedIn network page
	network_url = "http://linkedin.com / mynetwork/"

	# path to browser web driver
	driver = webdriver.Chrome('C:\\Users\\omesh sharma\Downloads\\chromedriver_win32\\chromedriver.exe')	
	driver.get(url)
	login(driver)

# Driver's code
# if __name__ == __main__:
main()
