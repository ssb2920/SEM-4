import socket   #import socket module
import time
def Main():
      host = "8.6.5.9 "#localhost IP address
      port = 6004      #port number > 1024 for server application      
      mySocket = socket.socket()#create a socket
      mySocket.bind((host,port)) #bind it to the host IP and socket address
                
      mySocket.listen(2)  #server listens to incoming request for connection
      conn, addr = mySocket.accept()#accepts the connection request from client IP addr
      print ("Connection from: " + str(addr))
      while True:
             data = conn.recv(1024).decode()
             if not data:
                      break
             print ("from connected  user: " + str(data))                                              
             data = str(data).upper()
             print ("Received from User: " + str(data))
             data = input(" ? ")
             conn.send(data.encode())#send data                                               
      conn.close()
                
Main()