import cv2
import mediapipe as mp
import time
import os
import HandTrackingModule as htm
import serial

# Initialize serial communication on COM port 3
#ser = serial.Serial('COM3', 9600)
Wcam,Hcam = 640,480

cap = cv2.VideoCapture(0)  # Capture from camera
cap.set(3,Wcam)
cap.set(4,Hcam)
pTime = 0
FolderPath = "finger_image"
Mylist = os.listdir(FolderPath)
overlaylist =[]

for imPath in Mylist:
    image= cv2.imread(f'{FolderPath}/{imPath}')
    overlaylist.append(image)

detector = htm.handDetector(detectionCon=0.7)

tipIds=[4, 8, 12 , 16 , 20]

while True:
    success, img = cap.read()


    img = detector.findHands(img)
    lmList = detector.findPosion(img, draw=False)
    if len(lmList) != 0:
       fingers = []
       #Thunb
       if lmList[tipIds[0]][1] > lmList[tipIds[0] - 1][1]:
           fingers.append(1)
       else:
           fingers.append(0)
      #4 other fongers
       for id in range (1,5):
        if lmList[tipIds[id]][2]<lmList[tipIds[id]-2][2]:
            fingers.append(1)
        else:
            fingers.append(0)

       #print(fingers)
       totalFingers = fingers.count(1)
       print(totalFingers)
       # Send the totalFingers value to the serial port
       #ser.write(f'{str(totalFingers)}'.encode())

       w, h, c = overlaylist[totalFingers-1].shape
       img[0:w, 0:h] = overlaylist[totalFingers-1]
       cv2.putText(img,str(totalFingers),(20,400),cv2.FONT_HERSHEY_COMPLEX,5,(0,0,255))


    cTime = time.time()
    fps = 1 / (cTime - pTime)
    pTime = cTime
    cv2.putText(img, f'FPS: {int(fps)}', (400, 70), cv2.FONT_HERSHEY_COMPLEX,
                1, (255, 0, 255), 2)

    cv2.imshow("image", img)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()  # Release the camera
cv2.destroyAllWindows()  # Close all OpenCV windows