from random import randint

import serial
import time

leftHand = serial.Serial('com1', 9600)
time.sleep(1)
print(leftHand.readline())
rightHand = serial.Serial('com2', 9600)
time.sleep(1)
print(rightHand.readline())


def Action(impAction: str):
    """Передается действие в виде строки
    При передаче действия Hello рандомно определяется вид приветствия - рукопожатие или брофист
    При передаче неизвестного действия выполняется Unknown action"""

    if impAction == 'Hello':

        helloType = str(randint(0, 1))

        if helloType == '0':
            print('Python response: Brofist action')
        else:
            print('Python response: Handshake action')

        rightHand.write(helloType.encode())
        print(rightHand.readline())

    elif impAction == 'Pathfinder':

        print('Python response: Pathfinder action')

        rightHand.write('2'.encode())
        print(rightHand.readline())

        leftHand.write('2'.encode())
        print(leftHand.readline())

    elif impAction == 'Bye':

        print('Python response: Bye action')

        rightHand.write('3'.encode())
        print(rightHand.readline())

    else:

        print('Python response: Unknown action')

        rightHand.write('4'.encode())
        print(rightHand.readline())

        leftHand.write('4'.encode())
        print(leftHand.readline())
