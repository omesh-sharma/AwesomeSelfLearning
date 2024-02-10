from selenium import webdriver as wd  
from selenium.webdriver.common.keys import Keys as ky  
from selenium.webdriver.common.by import By
import pyautogui as pyt  

from selenium.webdriver.chrome.options import Options
chrome_options = Options()
chrome_options.add_experimental_option("detach", True)
#chrome_options.add_argument("C:\\Users\\omesh sharma\\AppData\\Local\\Google\\Chrome\\User Data") #Path to your chrome profile


import pickle

def save_cookie(driver, path):
    with open(path, 'wb') as filehandler:
        pickle.dump(driver.get_cookies(), filehandler)

def load_cookie(driver, path):
     with open(path, 'rb') as cookiesfile:
         cookies = pickle.load(cookiesfile)
         for cookie in cookies:
             driver.add_cookie(cookie)

def login_1(driver):  
    # First, we will get the login element  
    #username_1 = driver.find_element(By.ID,"session_key")    
    username_1 = driver.find_element(By.XPATH,"//input[@name='session_key']")
    # then, we will send the keys for username_1       
    username_1.send_keys("sharmaomesh0@gmail.com")         
    # now, send the password element in it                              
    #password_1 = driver.find_element(By.ID,"session_password")   
    password_1 = driver.find_element(By.XPATH,"//input[@name='session_password']")
    # then, send the keys for password_1     
    password_1.send_keys("Saurav1@3sa")                 
    # then, get the tag for submit button             
    #driver.find_element(By.ID,"btn-md btn-primary flex-shrink-0 cursor-pointer sign-in-form__submit-btn--full-width").click()  
    driver.find_element(By.XPATH,"//button[@type='submit']").click()
def go_to_network(driver):
    #driver.find_element_by("my_network-tab-icon").click()  
    driver.find_element(By.XPATH,"//button[@type='my_network-tab-icon']").click()
def send_requests_1(driver):  

    for itr in range(100,500):
        try:
            driver.find_element(By.XPATH, f'//*[@id="ember{itr}"]').click()
            driver.implicitly_wait(1)   
        except:
            pass

    return

    #driver.implicitly_wait(5)
    #Select 'See All' browser.find_element_by_xpath('/html/body/div[6]/div[3]/div/div/div/div/div[2]/div/div/main/ul/li[1]/div/button/span').click()
    #Obtain the number of items containing the same path
    elements = driver.find_element(By.XPATH,'/html/body/div[3]/div/div/div[2]/section/div/ul/li')
    for i in range(1,len(elements)+2):
        #Send connection request
        driver.find_element(By.XPATH,'/html/body/div[3]/div/div/div[2]/section/div/ul/li[{}]/div/section/div[2]/footer/button/span'.format(str(i))).click()
        #Connections send to 13 people at a time
        print('Connection request sent to person {}'.format(str(i)))
        #Cause a time delay before progressing to next person
        driver.implicitly_wait(1)

    #Cause a delay so it does not throw an error

    # the Nnumber of requests we want to send  
    #n_1 = input("The number of connection requests: ")     
  
    #for k in range(0, n_1):  
        # position(in px) of connection button will be different for different user  
        #pyt.click(810, 670)    
    print("All request are sent!")  
def main():  
    # url of LinkedIn,com  
    url_1 = "http://linkedin.com/"    
    # url of network page of linkedin.com   
    network_url1 = "https://www.linkedin.com/mynetwork/"   
    # path for browser web driver  
    
    driver_1 = wd.Chrome('C:\\Users\\omesh sharma\Downloads\\chromedriver_win32\\chromedriver.exe', chrome_options=chrome_options)  
    driver_1.get(url_1) 

    

    #go_to_network(driver_1)



    #foo = input()

    save_cookie(driver_1, 'cookie')
    #load_cookie(driver_1, 'cookie')

    login_1(driver_1)

    driver_1.get(network_url1) 
    
    send_requests_1(driver_1)

    
  
# Drivers code  
# if __name__ == __main__:  
#     main()  
main()